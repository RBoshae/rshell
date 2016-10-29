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


using namespace std;

int main(){

	bool continue_shell = true;
	string user_input; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string token = "";

	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell){

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.


		cout << "This is what was received from the user: " << endl << user_input << endl;//verify that we have recieved the correct user input
		
		token = user_input.substr(0, user_input.find(and_delimeter));
		cout << token << endl;			

	}

return 0;
}
