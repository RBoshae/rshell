/*
 * File: Semicolon.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 10/30/2016
 *
 */
#include "Semicolon.h"

Semicolon::Semicolon(Command* left_passed_command, Command* right_passed_command)
{
	//run_status = passed_run_status;
	this->left_command = left_passed_command;
	this->right_command = right_passed_command;
}

int Semicolon::execute()
{	
	//Always execute left_command
	left_command->execute();
	
	//Execute and return right command boolean
	
	return right_command->execute();
	
}
