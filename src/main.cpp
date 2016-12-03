/*
 * File: main.cpp
 * ----------------
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/29/16.
 */
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <climits>
#include <cstring>
#include <string>
#include "Command.h"
#include "Statement.h"
#include "Parser.h"
#include "And.h"
#include "Or.h"
#include <algorithm> 

using namespace std;

Command* myCmd;

//0 = true 1 = false
void userInfo()
{
	//get the users name
  // register struct passwd *p;
  // register uid_t uid;
  // uid = geteuid ();
  // p = getpwuid (uid);
  // if (p)
  //   {
  //     cout << p->pw_name;
  //   }
  // //get the users hostname
  // char host[500];
  // host[499] = '\0';
  // gethostname(host, 499);
  // printf("@%s", host);
  
  ///Everything below is updatingn current PWD
	char* hPath;
	hPath = getenv("PWD");
	if (hPath!=NULL)
  		printf (":~%s",hPath);
  
	cout << " $ ";
}

bool parentCheck(string user_input)
{
	int rp_count = 0;
	int lp_count = 0;
	
	for(unsigned int i = 0; i < user_input.size(); i++)
	{
		if(user_input.at(i) == '(') lp_count++;
		if(user_input.at(i) == ')') rp_count++;
	}
	if(lp_count == rp_count)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	string user_input = "";
	string tmpInput;


	
	while(true)
	{
    	userInfo();
    	
    	getline(cin, user_input);
    	
    	if((user_input == "") || (user_input.at(0) == '#')) continue;
    	
    	while(true)
    	{
    		
    		if(parentCheck(user_input))
    		{
    			break;
    		}
    		else
    		{
    			cout << "> ";
    			getline(cin, tmpInput);
    			user_input += tmpInput;
    			
    			/////////////////
    			tmpInput.clear();//clear user input
    		}
    	}
    	
		Parser* myParser = new Parser();
		
		myCmd = myParser->parse(user_input);
		myCmd->execute();
		//user_input = ""; //reset value of user_input
		
		if(user_input == "exit") exit(0);
		user_input.clear();

	}

return 0;
}
