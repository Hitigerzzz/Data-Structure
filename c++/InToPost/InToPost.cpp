//============================================================================
// Name        : InToPost.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include "Calculator.h"

using namespace std;
int isp(char c){
	switch(c){
		case '#' : return 0;
		case '(' : return 1;
		case '*' : return 5;
		case '/' : return 5;
		case '%' : return 5;
		case '+' : return 3;
		case '-' : return 3;
		case ')' : return 6;
		default : return -1;
	}
}

int icp(char c){
	switch(c){
		case '#' : return 0;
		case '(' : return 6;
		case '*' : return 4;
		case '/' : return 4;
		case '%' : return 4;
		case '+' : return 2;
		case '-' : return 2;
		case ')' : return 1;
		default : return -1;
	}
}

string postfix(){
	stack <char> s;
	char ch , y;
	string post="";

	s.push('#');
	while (cin.get(ch),ch != '#'){
		if(isdigit(ch)){
			cout << ch;
			post += ch;
		}else if(ch == ')'){
			for(y = s.top(),s.pop();y != '('; y = s.top(),s.pop()){
				cout << y;
				post += y;
			}
		}else{
			for(y = s.top(),s.pop(); isp(y) > icp(ch);y = s.top(),s.pop()){
				cout << y;
				post += y;
			}
			s.push(y);
			s.push(ch);
		}
	}

	while(!s.empty()){
		y = s.top();
		s.pop();
		cout << y;
		post += y;
	}

	return post;
}
int main() {
	string postString = postfix();
	cout << endl;
	Calculator calculator;
	calculator.run(postString);

	return 0;
}
