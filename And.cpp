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

And::And(Argument* x, Argument* y)
{
	this->left_argument = x;
	this->right_argument = y;
}

int And::execute()
{	
	//Always execute left_argument
	int run_status = left_argument->execute();
	
	//Only execute right_argument if left_argument is true
	if(run_status == 0)
		right_argument->execute();
	return 0;
}
