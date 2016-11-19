/*
* File: Test.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/12/16.
*
*/

#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "Command.h"
#include <string>
//Libraries needed for stat()
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Test :
	public Command
{
protected:
	std::string single_command; 
	char* arg;
public:
	Test();
	Test(std::string passed_in_command); 
	~Test();
	
	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails. Also prints the true or false value.
	int execute();
};

#endif