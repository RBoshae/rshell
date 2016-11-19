/*
 * File: And.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/29/16.
 *
 */

#include "And.h"

And::And(Command* left_passed_command, Command* right_passed_command)
{
	//run_status = passed_run_status;
	this->left_command = left_passed_command;
	this->right_command = right_passed_command;
}

int And::execute()
{	
	//Always execute left_command
	int success = left_command->execute();
	
	//Only execute right_command if left_Command is true
	if(success == 0)
		return right_command->execute();
	else 
		return 1;
}
