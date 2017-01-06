/*
 * Calculator.h
 *
 *  Created on: 2016年11月7日
 *      Author: jone
 */
#include <iostream>
#include <stack>
using namespace std;
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

class Calculator{
	public :
		void run(string post);
	private :
		void addOperand(double value);
		bool get2Operands(double &left,double &right);
		void doOperator(char op);
		stack<double> s;
};

#endif /* CALCULATOR_H_ */
