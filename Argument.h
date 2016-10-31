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
	
public:
	/* Constructors */
	Argument(){};
	~Argument(){};

	virtual void execute() = 0;
};

#endif 
