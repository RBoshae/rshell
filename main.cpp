/*
 * File: main.cpp
 * ----------------
 *
 * Created by Rick Boshae on 10/29/16.
 *
 */



#include <iostream>
#include <string>
#include "Arguement.h"
#include "Statement.h"

using namespace std;

int main(){
	
	//some code that will be incorpated into the parser
	bool continue_shell = true;
	string user_input; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string token = "";


	//test to check Statement class
	string str = "Some String";
	Statement* test_Statement;
	
	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell){

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "q") break;

		cout << "This is what was received from the user: " << endl << user_input << endl;//verify that we have recieved the correct user input
		
		token = user_input.substr(0, user_input.find(and_delimeter));
		test_Statement = new Statement(token);

		test_Statement->print();	
		cout << endl;

		cout << "BEGIN EXECUTE" << endl;
		test_Statement->execute();		

	}

return 0;
}
