 /*
 * File: Parser.h
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/07/2016
 *
 */
#pragma once

#include <stdio.h>

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm> 

#include <boost/algorithm/string/classification.hpp>  // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>           // Include for boost::split

#include "and.h"
#include "cd.h"
#include "command.h"
#include "or.h"
#include "semicolon.h"
#include "statement.h"
#include "test.h"

using namespace std;
//forward declaration
class Command;

class Parser {
    
 public:
   Parser();
   ~Parser();
    
   // Parse returns a tree of type command*/
   Command* Parse(string user_input);
	 
	 std::string RemoveComments(const string &input);

 private:
   vector<string> commands_; //contains list of parsed arguments
    
   // Vectorize converts string into a vector
   void Vectorize(string user_input);

   unsigned int BuildParentheses(unsigned int index);
    
   //serves as temporary command object to construct our tree
   Command* left_command_; 
   Command* right_command_; 
     
};