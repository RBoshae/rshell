/*
 * File: main.cpp
 * ----------------
 * Created by Rick Boshae on 10/29/16.
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


void userInfo()
{
	//get the users name
  register struct passwd *p;
  register uid_t uid;
  uid = geteuid ();
  p = getpwuid (uid);
  if (p)
    {
      cout << p->pw_name;
    }
  //get the users hostname
  char host[500];
  host[499] = '\0';
  gethostname(host, 499);
  printf("@%s", host);
  cout << "$ ";
}

int main()
{
	string user_input = "";
	
	while(true)
	{
		userInfo();
		
		getline(cin, user_input);//getline will allow us to record and print the string in one line.
		if(user_input == "exit") break;
		
		Parser* myParser = new Parser();
		
		myCmd = myParser->parse(user_input);
		myCmd->execute();

	}

return 0;
}
