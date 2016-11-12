/*
 * File: And.cpp
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#include "And.h"

And::And(Command* left_passed_command, Command* right_passed_command)
{
	//run_status = passed_run_status;
	this->left_command = left_passed_command;
	this->right_command = right_passed_command;
}

bool And::execute()
{	
	//Always execute left_command
	bool success = left_command->execute();
	
	//Only execute right_command if left_Command is true
	if(success == true)
	{
		return right_command->execute();
		
	}
	else return false;
}
