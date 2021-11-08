/*
 * File: and.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh  on 10/29/16.
 *
 */

#pragma once 

#include "command.h"

class And : public Command {
 public:
	And() {};
	And(Command* left_passed_command, Command* right_passed_command);
	~And() {};

	bool Execute() override;

	protected:
	//Command class has a bool value called success that is inherited here.
	Command* left_command_;
	Command* right_command_;

};