/*
 * File: Arguement_List.h
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#ifndef ARGUEMENT_LIST_H
#define ARGUEMENT_LIST_H

#include "Arguement.h"
#include <iostream>
#include <vector>

using namespace std;

class Arguement_List : public Arguement

{
	protected:
	vector<Arguement*> arguement_trees;
	
	public:
	/* Constructors */
	Arguement_List();
	~Arguement_List();
	
	void Add_Element(Arguement* some_arguement);
	void execute();

};
#endif
