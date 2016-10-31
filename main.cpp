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

using namespace std;

int main(){
	
	//some code that will be incorporated into the parser class
	bool continue_shell = true;
	string user_input; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string token = "";


	//test to check Statement class
	string str = "Some String";
	Statement* test_Statement;
	Argument_List* args = new Argument_List();
	
	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell){

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "q") break;

		//VERIFY WE RECIEVED USER INPUT
		token = user_input.substr(0, user_input.find(and_delimeter));
		test_Statement = new Statement(token);
		test_Statement->print();
		cout << endl;

		//Run Leaf Execute
		cout << "LEAF execution call" << endl;
		test_Statement->execute();
		
		//Check Compositor Execution
		cout << endl << "COMPOSITOR execution call" <<endl;
		args->Add_Element(test_Statement);
		args->execute();		

	}

return 0;
}
