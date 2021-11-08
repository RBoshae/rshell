/*
 * File: And.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/29/16.
 *
 */

#include "and.h"

And::And(Command* left_passed_command, Command* right_passed_command) {
	this->left_command_  = left_passed_command;
	this->right_command_ = right_passed_command;
}

bool And::Execute() {

	//Always execute left_command_
	int success = left_command_->Execute();
	
	// Only execute right_command_ if left_Command is true
	if(success == 0)
		return right_command_->Execute();
	else 
		return 1;
}
