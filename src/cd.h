/*
* File: Cd.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/28/16.
*
*/

#ifndef Cd_H
#define Cd_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <string>

#include "command.h"

using namespace std;

class Cd : public Command {
 public:
	Cd();
	Cd(std::string passed_in_command); 
	~Cd();
	
	bool Execute() override;
 protected:
	std::string single_command_; 
	char* arg;
};

#endif