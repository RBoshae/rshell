/*
 * File: Argument_List.cpp
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#include "Argument_List.h"

Argument_List::Argument_List()
{}

Argument_List::~Argument_List()
{}

void Argument_List::Add_Element(Argument* some_argument)
{
	argument_trees.push_back(some_argument);
}

int Argument_List::execute()
{
	for (int i; i < argument_trees.size(); i++)
		argument_trees.at(i)->execute();
	return 0;
}
