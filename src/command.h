/*
* File: Command.h
* ------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/29/16.
*
*/
#pragma once

// Abstract base class for rshell. 
class Command {
 public:
	Command();
	virtual ~Command();
	
	// Execute returns true if success otherwise false. 
	virtual bool Execute() = 0;

};