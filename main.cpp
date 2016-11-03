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
#include "Or.h"
#include <algorithm> 
//#include <boost/algorithm/string.hpp> //boost library

using namespace std;

int main()
{
	
	//some code that will be incorporated into the parser class
	bool continue_shell = true;
	bool global_truth = true;
	
	string user_input; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string comment_delimeter = "#";
	string token = "";
	string command = "";
	
	Statement* st;
	And* and_temp;
	Or* or_temp;

	int or_pos = -1;
	int and_pos = -1;
	int arg_pos = -1;
	int comment_pos = -1;
	
	int min_pos = 0;

	//vector<std::string> v;
	//boost::split(v, line, boost::is_any_of(""));
	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell)
	{

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "q") break;

		if (user_input.find(comment_delimeter) != -1)
		{
			user_input.erase(user_input.find(comment_delimeter), user_input.size());
		}
		while (user_input != "")
		{
			or_pos = user_input.find(or_delimeter);
			and_pos = user_input.find(and_delimeter);
			arg_pos = user_input.find(arg_delimeter);
			
			//run if no Delimeters
			if ((or_pos == -1) && (arg_pos == -1) && (and_pos == -1))
			{
			
				st = new Statement(user_input.substr(0, user_input.find(and_delimeter)) );
				global_truth = st->execute();
				user_input.erase(0, user_input.size());
			}
			else
			{//has delimeters
				//if find pos returns npos set it to 255
				if (or_pos == -1) or_pos = 2550;
				if (and_pos == -1) and_pos = 2550;
				if (arg_pos == -1) arg_pos = 2550;
				min_pos = min(or_pos, and_pos);
				
				command = user_input.substr(0, min_pos);
				//cout << "this is command: " << command << endl;
				user_input = user_input.substr(min_pos, user_input.size());
				//cout << "this is user_input: " << user_input << endl;
				st = new Statement(command);
				global_truth = st->execute();
				
				//cout << "This is user input: " << user_input <<endl;
				if (user_input.at(0) == '&')
				{
					user_input.erase(0,3);
					//cout << user_input << endl;
					command = user_input.substr(0, min_pos - 2);
					st = new Statement(command);
					and_temp = new And(global_truth, st);
					global_truth = and_temp->execute();
					user_input.erase(0, command.size());
					//cout << user_input << endl;
				}
				
				if (user_input.at(0) == '|')
				{
					user_input.erase(0,3);
					command = user_input.substr(0, min_pos - 2);
					st = new Statement(command);
					or_temp = new Or(global_truth, st);
					global_truth = or_temp->execute();
					user_input.erase(0, command.size()); 
				}
			
				if ((user_input.size() != 0) || (user_input.at(0) == ';'))
				{
					user_input.erase(0,2);
				}
				
			}
			//if(user_input == "q") break;///////////////injectted
		}
	}

/********************************PARSER************************************************************************/

return 0;
}
