/*
* File: Statement.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/16.
*
*/

#ifndef STATEMENT_H
#define STATEMENT_H
#include "Command.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

class Statement :
	public Command
{
protected:
	char* arg;
	std::string single_command; //stores string that will be passed to exec vp to run
public:
	Statement();
	Statement(std::string passed_in_command); //sets single_command data member
	~Statement();

	int execute();
};

#endif