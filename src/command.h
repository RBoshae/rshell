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
	
	// Execute returns true if success otherwise false. 
	virtual bool Execute() = 0;

protected:

	bool success; 
	std::vector<std::string> cd_history;
};