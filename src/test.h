/*
* File: Test.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/12/16.
*
*/

#pragma once

#include <iostream>
#include <string>

//Libraries needed for stat()
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "command.h"

using namespace std;

class Test : public Command {
protected:
	std::string single_command; 
	char* arg;
public:
	Test();
	Test(std::string passed_in_command); 
	~Test();
	
	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails. Also prints the true or false value.
	bool Execute() override;
};
