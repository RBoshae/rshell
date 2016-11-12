/*
 * File: And.h
 * -------------------------
 *
 * Created by Rick Boshae on 11/10/2016
 *
 */

#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Command.h"

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

	bool execute();


};
#endif
