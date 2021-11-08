/*
 * File: And.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh  on 10/29/16.
 *
 */

#ifndef AND_H
#define AND_H

#include "command.h"

class And : public Command

{
	protected:
	//Command class has a bool value called success that is inherited here.
	Command* left_command;
	Command* right_command;

	public:
	/* Contructors */
	And() {};
	~And() {};
	And(Command* left_passed_command, Command* right_passed_command);

	int execute();


};
#endif
