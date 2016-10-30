/*
 * File: Statement.h
 * ---------------------
 * 
 * Created by Rick Boshae on 10/29/16.
 *
 */

#ifndef STATEMENT_H
#define STATEMENT_H

#include "Arguement.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

class Statement : public Arguement {

protected:
	char* arg;
	std::string statement;

public:
	/*Constructors*/
	Statement();
	Statement(std::string statement); //sets statement memeber
 	~Statement();

	void print();
	void execute();

};

#endif
