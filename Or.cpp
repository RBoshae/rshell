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

Or::Or(Argument* x, Argument* y)
{
	this->left_argument = x;
	this->right_argument = y;
}

int Or::execute()
{	
	//Always execute left_argument
	int run_status = left_argument->execute();
	
	//Only execute right_argument if left_argument is false
	if(run_status == 0)
		return 0; //Left side ran fine, no need to run the second side
	else
		right_argument->execute(); //first command didnt run fine, 0 was not returned so run right side.
	return 0;
}
