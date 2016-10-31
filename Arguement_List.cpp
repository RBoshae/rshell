/*
 * File: Arguement_List.cpp
 * -------------------------
 *
 * Created by Rick Boshae on 10/30/2016
 *
 */

#include "Arguement_List.h"

Arguement_List::Arguement_List()
{}

Arguement_List::~Arguement_List()
{}

void Arguement_List::Add_Element(Arguement* some_arguement)
{
	arguement_trees.push_back(some_arguement);
}

void Arguement_List::execute()
{
	for (int i; i < arguement_trees.size(); i++)
		arguement_trees.at(i)->execute();
}
