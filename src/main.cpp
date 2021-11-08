/*
 * File: main.cpp
 * ----------------
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 
 * 10/29/16.
 */
#include <algorithm> 
#include <climits>
#include <cstring>
#include <iostream>
#include <string>

#include <stdio.h>

#include "And.h"
#include "command.h"
#include "Or.h"
#include "Parser.h"
#include "shell-utilities.h"
#include "Statement.h"

using namespace std;

int main() {

	Command* command;
	Parser*  parser = new Parser();
  
	string input = "";
  string addition_input = "";
	
	while (true) {

		cout << shell_utilities::Username() << "@" << shell_utilities::Hostname() << ":";
		cout << shell_utilities::WorkingDir() << "$ ";
		
    getline(cin, input);
    	
    if ((input == "") || (input.at(0) == '#')) continue;
    	
		while (true) {
			
			if (shell_utilities::BalancedParenthesis(input)) {
				break;
			}	else {
				cout << "> ";
				getline(cin, addition_input);

				input += addition_input;
				
				addition_input.clear(); //clear user input
			}
		}    	
		
		command = parser->parse(input);
		command->execute();
		
		if(input == "exit") exit(0);
		input.clear();

	}

	return 0;
}
