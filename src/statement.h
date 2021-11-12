/*
* File: Statement.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/16.
*
*/

#pragma once

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class Statement : public Command {
 public:
	Statement();
	Statement(std::string command); //sets single_command data member
	~Statement();

	bool Execute() override;
 
 protected:
	std::string command_; //stores string that will be passed to exec vp to run
};
