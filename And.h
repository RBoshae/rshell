/*
 * File: And.h
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#ifndef AND_H
#define AND_H

class And

{

	public:
	/* Contructors */
	And();
	~And();
	And(Argument* left_argument, Argument* right_argument);

	void And::execute();


};
#endif
