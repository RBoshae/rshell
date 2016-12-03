/*
* File: Cd.h
* ---------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/28/16.
*
*/

#ifndef Cd_H
#define Cd_H

#include "Command.h"
#include <iostream>
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

class Cd :
	public Command
{
protected:
	std::string single_command; 
	char* arg;
public:
	Cd();
	Cd(std::string passed_in_command); 
	~Cd();
	
	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails. Also prints the true or false value.
	int execute();
};

#endif