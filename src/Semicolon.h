/*
 * File: Semicolon.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 *
 */

#ifndef SEMICOLON_H
#define SEMICOLON_H

#include <iostream>

#include "command.h"

class Semicolon : 
	public Command

{
	protected:
	//Command class has a bool value called success that is inherited here.
	Command* left_command;
	Command* right_command;

	public:
	/* Contructors */
	Semicolon() {};
	~Semicolon() {};
	Semicolon(Command* left_passed_command, Command* right_passed_command);
	
	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails.
	int execute();


};
#endif
