/*
 * Calculator.cpp
 *
 *  Created on: 2016年11月7日
 *      Author: jone
 */

#include <iostream>
#include <stack>
using namespace std;
class Calculator{
	public :
		void run(string post);
	private :
		void addOperand(double value);
		bool get2Operands(double &left,double &right);
		void doOperator(char op);
		stack<double> s;
};

void Calculator :: addOperand(double value){
	s.push(value);
}

bool Calculator :: get2Operands(double &left,double &right){
	if(s.empty()){
		cerr << "Missing Operand!" <<endl;
		return false;
	}
	right = s.top();
	s.pop();
	if(s.empty()){
		cerr << "Missing Operand!" <<endl;
		return false;
	}
	left = s.top();
	s.pop();
	return true;
}

void Calculator :: doOperator(char op){
	double left,right;
	bool result = get2Operands(left,right);
	if(result){
		switch(op){
			case '+': s.push(left + right); break;
			case '-': s.push(left - right); break;
			case '*': s.push(left * right); break;
			case '/':
				if(right == 0){
					cerr << "divide by 0!" <<endl;
				}else{
					s.push(left / right);
				}
				 break;
		}
	}


}

void Calculator ::run(string post){
	int i = 0;
	while(post[i] != '#'){
		switch (post[i]){
			case '+' : case '-' : case '*' : case '/' :
				doOperator(post[i]);
				break;
			default:
				cout << (double)(post[i] - '0') <<endl;
				addOperand((double)(post[i] - '0'));
				break;
		}
		i++;
	}

	if(s.size() == 1){
		double result = s.top();
		s.pop();
		cout << result;
	};

}
