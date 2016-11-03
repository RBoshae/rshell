/*
 * File: And.cpp
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#include "And.h"

And::And()
{
}

And::~And()
{
}

And::And(bool passed_run_status, Argument* y)
{
	run_status = passed_run_status;
	this->right_argument = y;
}

bool And::execute()
{	
	//Always execute left_argument
	//bool run_status = left_argument->execute();
	
	//Only execute right_argument if left_argument is true
	if(run_status == true)
	{
		return right_argument->execute();
		
	}
	else return false;
}
