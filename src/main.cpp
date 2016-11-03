/*
 * File: main.cpp
 * ----------------
 *
 * Created by Rick Boshae on 10/29/16.
 *
 */
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <climits>
#include <cstring>
#include <string>
#include "Argument.h"
#include "Statement.h"
#include "And.h"
#include "Or.h"
#include <algorithm> 
//#include <boost/algorithm/string.hpp> //boost library

using namespace std;

void info()
{
  register struct passwd *p;
  register uid_t uid;
  uid = geteuid ();
  p = getpwuid (uid);
  if (p)
    {
      cout << p->pw_name;
    }

  //retrieve host name
  char host[500];
  host[499] = '\0';
  gethostname(host, 499);
  printf("@%s", host);
  cout << "$ ";
}

int main()
{	//some code that will be incorporated into the parser class
	bool continue_shell = true;
	bool global_truth = true;
	
	string user_input = ""; 
	string and_delimeter = "&&";
	string or_delimeter = "||";
	string arg_delimeter = ";";
	string comment_delimeter = "#";
	string token = "";
	string command = "";
	string exiter = "exit";
	
	Statement* st;
	And* and_temp;
	Or* or_temp;

	int or_pos = -1;
	int and_pos = -1;
	int arg_pos = -1;
	int comment_pos = -1;
	int exiter_pos = -1;
	
	int min_pos = 0;




	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell)
	{

		//Prompt User
		cout << "$ ";
		info();
		
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "exit") break;
		
		comment_pos = user_input.find(comment_delimeter);
		
		//cout << "comment_pos: " << comment_pos << endl;

		if (comment_pos >= 0)
		{
			user_input.erase(comment_pos, user_input.size());
		}
		while (user_input != "")
		{
			or_pos = user_input.find(or_delimeter);
			and_pos = user_input.find(and_delimeter);
			arg_pos = user_input.find(arg_delimeter);
			
			
			
			//run if no Delimeters
			if ((or_pos == -1) && (arg_pos == -1) && (and_pos == -1))
			{
				st = new Statement(user_input.substr(0, user_input.size()));
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
				min_pos = min(min_pos, arg_pos);
				
				command = user_input.substr(0, min_pos);
				user_input = user_input.substr(min_pos, user_input.size());
				st = new Statement(command);
				global_truth = st->execute();
				
				if (user_input.at(0) == '&')
				{
					user_input.erase(0,3);
					command = user_input.substr(0, min_pos - 1);
					exiter_pos = command.find(exiter);
					if (exiter_pos >= 0) exit(0);
					st = new Statement(command);
					and_temp = new And(global_truth, st);
					global_truth = and_temp->execute();
					user_input.erase(0, command.size());
					if(user_input.size() == 0) break;
					
				}
				
				if (user_input.at(0) == '|')
				{
					user_input.erase(0,3);
					command = user_input.substr(0, min_pos - 1);
					
					exiter_pos = command.find(exiter);
					if (exiter_pos >= 0) exit(0);
					st = new Statement(command);
					or_temp = new Or(global_truth, st);
					global_truth = or_temp->execute();
					user_input.erase(0, command.size()); 
					if(user_input.size() == 0) break;
					
				}
				if ((user_input.size() != 0) || (user_input.at(0) == ';'))
				{
					user_input.erase(0,1);
				}
				
			}
			if(user_input == "exit") break;///////////////injectted
		}
	}


return 0;
}
