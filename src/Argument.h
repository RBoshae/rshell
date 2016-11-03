/*
 * File: Argument.h
 * ------------------
 * 
 * Created by Rick Boshae on 10/29/16.
 *
 */ 


#ifndef ARGUMENT_H
#define ARGUMENT_H

class Argument
{
protected:
bool run_status;
	
public:
	/* Constructors */
	Argument(){};
	~Argument(){};

	virtual bool execute() = 0;
};

#endif 
