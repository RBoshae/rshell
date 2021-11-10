/*
 * File: or.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 
 * 11/10/2016
 *
 */
#pragma once

#include "command.h"
class Or : public Command {
 public:
	/* Contructors */
	Or();
	Or(Command* left_command, Command* right_command);
	~Or();

	//This command returns 0 (TRUE) if succeeds and 1 (FALSE) if fails.
	bool Execute() override;

 protected:
	//Command class has a bool value called success that is inherited here.
	Command* left_command_;
	Command* right_command_;

};
