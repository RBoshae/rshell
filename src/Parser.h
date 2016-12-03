/*
 * File: Parser.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 * 
 *
 */
 
 /*
 * File: Parser.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/07/2016
 *
 */
#ifndef PARSER_H
#define PARSER_H

#include "Command.h"
#include "Statement.h"
#include "And.h"
#include "Or.h"
#include "Test.h"
#include "Cd.h"
#include "Semicolon.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <cstring>
//needed for vectorize
#include <iostream>
#include <algorithm> 
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split

using namespace std;
//forward declaration
class Command;

class Parser {
    
    private:
    vector<string> commands; //contains list of parsed arguments
    
    //helper function: vectorize will be called to store store a string into a vector
    void vectorize(string user_input);
    // int build_and(int index);
    // int build_or(int index);
    // int build_semicolon(int index);
    unsigned int build_parentheses(unsigned int index);
    
    //serves as temporary command object to construct our tree
    Command* leftCmd; 
    Command* rightCmd; 
    
    
    public:
    /* Constructos */
    Parser();
    ~Parser();
    
    /*parse will return a tree of type command to the caller*/
    Command* parse(string user_input);
    
    
};
#endif