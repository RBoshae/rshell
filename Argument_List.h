/*
 * File: Argument_List.h
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#ifndef ARGUMENT_LIST_H
#define ARGUMENT_LIST_H

#include "Argument.h"
#include <iostream>
#include <vector>

using namespace std;

class Argument_List : public Argument

{
	protected:
	vector<Argument*> argument_trees;
	
	public:
	/* Constructors */
	Argument_List();
	~Argument_List();
	
	void Add_Element(Argument* some_argument);
	void execute();

};
#endif
