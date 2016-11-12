/*
 * File: Parser.h
 * -------------------------
 *
 * Created by Rick Boshae and Sammy Macaluso on 11/07/2016
 *
 */
#ifndef PARSER_H
#define PARSER_H

#include "Command.h"
#include "Statement.h"
#include "And.h"
#include "Or.h"
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
    
    //Various delimeters that we will search for in the parser
    

    //helper function: vectorize will be called to store store a string into a vector
    void vecotrize(string user_input);
    
    //protected:
    //Commented out to try out new tree strategy
    
    //queue<string> queue_PostFix;
    //stack<string> theStack;
    
    
    
    public:
    //parse will return a tree of type command to the caller
    Parser();
    ~Parser();
    
    Command* parse(string user_input);
    
    
    
    
    //more stuff that might not be used
    //void execute();
    //void userInfo();
    
    
    
};
#endif