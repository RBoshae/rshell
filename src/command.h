/*
* File: Command.h
* ------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/29/16.
*
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

//Abstract base class for rshell. 
class Command {
 public:
	Command();
	
	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails. 
	virtual int execute() = 0;

protected:

	int success; // used to determine whether rhs command will execute. This will be dependent on the data type.
	std::vector<std::string> cd_history;
};