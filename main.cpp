/*
 * File: main.cpp
 * ----------------
 *
 * Created by Rick Boshae on 10/29/16.
 *
 */



#include <iostream>
#include <string>
#include "Argument.h"
#include "Statement.h"
#include "Argument_List.h"
#include "And.h"

using namespace std;

int main(){
	
	//some code that will be incorporated into the parser class
	bool continue_shell = true;
	string user_input; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string token = "";


	//test to check Add class
	Statement* left_test_statement;
	Statement* right_test_statement;

	And* test_and;

	Argument_List* args = new Argument_List();
	
	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell){

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "q") break;

		//VERIFY WE RECIEVED USER INPUT
		token = user_input.substr(0, user_input.find(and_delimeter));//set up left child with command
		left_test_statement = new Statement(token);
		user_input.erase(0,user_input.find(and_delimeter) + 3);
		cout << "ERASE FUNCTION"  << user_input << endl;
		token = user_input.substr(0, user_input.find(and_delimeter));
		right_test_statement = new Statement(token);
		
		//populate And leaf
		test_and = new And(left_test_statement, right_test_statement);		

		cout << "This is the left child: "; left_test_statement->print();
		cout << endl;

		cout << "This is the right child: "; right_test_statement->print();
		cout << endl;
		

		//Run Leaf Execute
		//cout << "LEAF execution call" << endl;
		//test_statement->execute();
		
		//Run AND class
		cout << "AND execution call" <<endl;
		test_and->execute();
		cout << endl;
		
		//Check COMPOSITION class
		cout << endl << "COMPOSITION execution call" <<endl;
		args->Add_Element(test_and);
		args->execute();		
		cout << endl;
	}

return 0;
}
