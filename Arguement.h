/*
 * File: Arguement.h
 * ------------------
 * 
 * Created by Rick Boshae on 10/29/16.
 *
 */ 


#ifndef ARGUEMENT_H
#define ARGUEMENT_H

class Arguement
{
protected:
	
public:
	/* Constructors */
	Arguement(){};
	~Arguement(){};

	virtual void execute() = 0;
};

#endif 
