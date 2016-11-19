/*
 * File: Or.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 *
 */

#include "Or.h"

Or::Or()
{
	
}

Or::Or(Command* left_passed_command, Command* right_passed_command)
{
	this->left_command = left_passed_command;
	this->right_command = right_passed_command;
}

int Or::execute()
{	
	//Always execute left_Command
	int success = left_command->execute();
	
	//Only execute right_Command if left_Command is false
	if(success == 0)
		return 0; //Left side ran fine, no need to run the second side
	else
		return right_command->execute(); //first command didnt run fine, 0 was not returned so run right side.
	
}
