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

#include "and.h"
#include "command.h"
#include "or.h"
#include "parser.h"
#include "shell-utilities.h"
#include "statement.h"

using namespace std;

int main() {

  
	string input = "";
  string addition_input = "";
	
	while (true) {

		// The funny symbols add color to the output. 
		// For more info see https://en.wikipedia.org/wiki/ANSI_escape_code
		cout << "\033[1;35m" << shell_utilities::Username() << "@" << shell_utilities::Hostname() << "\033[0m:";
		cout << "\033[1;33m" << shell_utilities::WorkingDir() << "\033[0m$ ";
		
		getline(cin, input);

		if ((input == "") || (input.at(0) == '#')) continue;

		while (!shell_utilities::BalancedParenthesis(input)) {
				cout << "> ";
				getline(cin, addition_input);

				input += addition_input;
				
				addition_input.clear(); //clear user input
		}
		
		Parser parser;
	  Command* command = parser.Parse(input);

		command->Execute();
		
		if(input == "exit") exit(0);
		input.clear();
	}

	return 0;
}
