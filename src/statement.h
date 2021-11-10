/*
* File: Statement.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/16.
*
*/

#pragma once

#include "command.h"

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

class Statement : public Command {
 public:
	Statement();
	Statement(std::string command); //sets single_command data member
	~Statement();

	bool Execute() override;
 
 protected:
	char* arg;
	std::string command_; //stores string that will be passed to exec vp to run
};
