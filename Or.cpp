/*
 * File: Or.cpp
 * -------------------------
 *
 * Created by Salvatore Macaluso on 10/30/2016
 *
 */

#include "Or.h"

Or::Or()
{
}

Or::~Or()
{
}

Or::Or(bool passed_run_status, Argument* y)
{
	//this->left_argument = x;
	this->right_argument = y;
	run_status = passed_run_status;
}

bool Or::execute()
{	
	//Always execute left_argument
	//int run_status = left_argument->execute();
	
	//Only execute right_argument if left_argument is false
	if(run_status == true)
		return true; //Left side ran fine, no need to run the second side
	else
	return right_argument->execute(); //first command didnt run fine, 0 was not returned so run right side.
	
}
