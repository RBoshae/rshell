/*
 * File: And.h
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#ifndef AND_H
#define AND_H

#include "Argument.h"

class And : public Argument

{
	protected:
	Argument* left_argument;
	Argument* right_argument;

	public:
	/* Contructors */
	And();
	~And();
	And(Argument* x, Argument* y);

	int execute();


};
#endif
