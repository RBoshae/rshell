/*
 * File: Parser.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 * 
 *
 */

#include "parser.h"

Parser::Parser() {
}

Parser::~Parser() {
}

Command* Parser::Parse(string user_input) {
	
	std::string clean_input = Cleanse(user_input);
	
  ToVector(clean_input);

  /**********************************************
     * Token Bank
     * --------------------------------------------
     * list of tokens/delimeters used to build tree
     **********************************************/
  string and_delimeter       = "&&";
  string or_delimeter        = "||";
  string semicolon_delimeter = ";";
  string comment_delimeter   = "#";
  string exiter              = "exit";
  string test                = "test";
  string blank               = "";
  string left_parentheses    = "(";
  string right_parentheses   = ")";
  //***********End of Token Bank****************

  int lp_count = 0;
  int rp_count = 0;

  string token       = "";
  string command     = "";
  string sub_command = "";

  /*****************************************************************************
     * Build Command Tree
     * ------------------------------------------------------------
     * Iterate through commands vector until it is empty. The loop
     * will contstruct a Command Tree based on the command or 
     * delimeter it receives.
     * 
     **************************************************************************/
  for (unsigned int index = 0; index < commands_.size(); index++) {
    // Workaround - Getting an empty string at index 0 for some reason. We may 
    //              need to investigate the vectorize function.
    // if (index > commands.size()) break;
    // if (blank.c_str() == commands.at(index)) index++;
    // if (index >= commands.size()) break;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // ---------------------Parentheses Handler---------------------------------
    // If commands at index is a parentheses jump in
    if (left_parentheses.c_str() == commands_.at(index)) {
      ++lp_count; // Increment left parentheses count
      ++index;		// Increment past left parentheses

      // Run while left parentheses does not have a matching right parentheses
      while (lp_count != rp_count) 
      {
        if (commands_.at(index) == left_parentheses.c_str())
          lp_count++; //if we find another left parenthese, increment

        if (commands_.at(index) == right_parentheses.c_str())
          rp_count++; //if we find a right parenthese, increment

        //build a substring until hitting the right parentheses

        if (lp_count != rp_count)
        {
          sub_command.append(commands_.at(index));
          //sub_command.append(" ");
        }
        index++;

        /*if ((lp_count != rp_count) && ( commands.at(index) == right_parentheses.c_str()))
                       {
                           rp_count++;
                       }*/
      }

      if (index < commands_.size() && (commands_.at(index) == right_parentheses.c_str()))
      {
        index++; //skip past right parentheses
      }

      lp_count = 0; //reset sub_command after use
      rp_count = 0; //reset sub_command after use

      //recursive call parse -- takes care of nested parentheses
      Parser *sub_parser = new Parser();

      left_command_ = sub_parser->Parse(sub_command); //expect command to be returned then store in tree

      sub_command = ""; //reset sub_command after use
    }
    //-----------------------END OF Parentheses---------------------------------------------------

    //first Statement Build
    //---------------------------------------------Statement Handler---------------------------------------------------
    //if commands at index is not a delimeter then it is a statement.
    if ((index < commands_.size()) && (and_delimeter.c_str() != commands_.at(index)) && (or_delimeter.c_str() != commands_.at(index)) && (semicolon_delimeter.c_str() != commands_.at(index)) && (blank.c_str() != commands_.at(index)) && (index < commands_.size()) && (left_parentheses.c_str() != commands_.at(index)))
    {
      //********************TEST OBJECT PSUEDO CODE********************************************
      //string compare index with 'test' or'[', true - set object as test object
      // string test = "test"
      // test.c_str() == commands.at(index).substr(0,3) || left_sqr_bracket.c_str() == commands.at(index).substr(0,3)
      //leftCmd = new Test(commands.at(index));
      //index++;
      //else, object is statement object
      //----------------------------------------------------------------------------
      //if its a test statement build a test statement other wise its just a normal statement
      if (commands_[index][0] == '[' || commands_.at(index).compare(0, 4, "test") == 0)
      {
        left_command_ = new Test(commands_.at(index));
        index++;
      }
      else if ((commands_[index][0] == 'c') && (commands_[index][1] == 'd') && ((commands_[index].size() == 2) || (commands_[index][2] == ' '))) //added for cd assignment
      {
        left_command_ = new Cd(commands_.at(index));
        index++;
      }
      else //its a normal statement
      {
        left_command_ = new Statement(commands_.at(index));
        index++;
      }
      // leftCmd = new Statement(commands.at(index));
      // index++;

      //handles the single command case.
      if (index >= commands_.size())
        break;
    }
    //-----------------------END OF Statement---------------------------------------------------------------------

    /*******************************************Delimeter Cases**********************************************/
    //If the command at index is a delimeter check which one it is and add the tree

    //-----------------------------And Case---------------------------------------
    if ((index < commands_.size()) && (and_delimeter.c_str() == commands_.at(index))) //if it is an And delimeter
    {
      index++; //increment index to next delimeter

      //grab next string in index and stor it in  a statement
      if (left_parentheses.c_str() != commands_.at(index))
      {
        if (commands_[index][0] == '[' || commands_.at(index).compare(0, 4, "test") == 0)
        {
          right_command_ = new Test(commands_.at(index));
          left_command_ = new And(left_command_, right_command_);
        }
        else if ((commands_[index][0] == 'c') && (commands_[index][1] == 'd')) //added for cd assignment
        {
          right_command_ = new Cd(commands_.at(index));
          left_command_ = new And(left_command_, right_command_);
        }
        else //its a normal statement
        {
          right_command_ = new Statement(commands_.at(index));
          left_command_ = new And(left_command_, right_command_);
        }
        // rightCmd = new Statement(commands.at(index));
        // leftCmd = new And(leftCmd, rightCmd);
      }
      else if (left_parentheses.c_str() == commands_.at(index))
      {
        index = BuildParentheses(index);
        //add sub tree to regular tree
        left_command_ = new And(left_command_, right_command_);
        sub_command = ""; //reset sub_command after use -- may be useless
      }
    }
    //------------------------------End of And Case---------------------------------

    //--------------------------------Or Case---------------------------------------
    if ((index < commands_.size()) && (or_delimeter.c_str() == commands_.at(index)))
    {
      index++; //increment index to next delimeter
      //grab next string in index and stor it in  a statement
      if (left_parentheses.c_str() != commands_.at(index))
      {
        if (commands_[index][0] == '[' || commands_.at(index).compare(0, 4, "test") == 0)
        {
          right_command_ = new Test(commands_.at(index));
          left_command_ = new Or(left_command_, right_command_);
        }
        else if ((commands_[index][0] == 'c') && (commands_[index][1] == 'd')) //added for cd assignment
        {
          right_command_ = new Cd(commands_.at(index));
          left_command_ = new And(left_command_, right_command_);
        }
        else //its a normal statement
        {
          right_command_ = new Statement(commands_.at(index));
          left_command_ = new Or(left_command_, right_command_);
        }
        // rightCmd = new Statement(commands.at(index));
        // leftCmd = new Or(leftCmd, rightCmd);
      }

      //CHECKS FOR PARENTHESES
      else if (left_parentheses.c_str() == commands_.at(index))
      {
        index = BuildParentheses(index);
        //add sub tree to regular tree
        left_command_ = new Or(left_command_, right_command_);
        sub_command = ""; //reset sub_command after use -- may be useless
      }
    }
    //------------------------------End of Or Case-------------------------------

    //--------------------------------Semicolon Case---------------------------------------

    //trailing semicolon hack
    if ((index < commands_.size()) && (commands_.at(commands_.size() - 1) == semicolon_delimeter.c_str()))
      commands_.at(commands_.size() - 1) = "";

    if ((index < commands_.size()) && (semicolon_delimeter.c_str() == commands_.at(index)))
    {
      index++; //increment index to next delimeter
      //grab next string in index and stor it in  a statement
      if (left_parentheses.c_str() != commands_.at(index))
      {
        if (commands_[index][0] == '[' || commands_.at(index).compare(0, 4, "test") == 0)
        {
          right_command_ = new Test(commands_.at(index));
          left_command_ = new Semicolon(left_command_, right_command_);
        }
        else if ((commands_[index][0] == 'c') && (commands_[index][1] == 'd')) //added for cd assignment
        {
          right_command_ = new Cd(commands_.at(index));
          left_command_ = new And(left_command_, right_command_);
        }
        else //its a normal statement
        {
          right_command_ = new Statement(commands_.at(index));
          left_command_ = new Semicolon(left_command_, right_command_);
        }
        // rightCmd = new Statement(commands.at(index));
        // leftCmd = new Semicolon(leftCmd, rightCmd);
      }

      //CHECKS FOR PARENTHESES
      else if (left_parentheses.c_str() == commands_.at(index))
      {
        index = BuildParentheses(index);
        //add sub tree to regular tree
        left_command_ = new Semicolon(left_command_, right_command_);

        sub_command = ""; //reset sub_command after use -- may be useless
      }
    }
    //------------------------------End of Semicolon Case-------------------------------

    /*************************End of Delimeter Cases**********************************/

  } //end of for loop, commands vector is now empty
  //*********************End of Command Tree Builder************

  return left_command_; // return built tree to caller.
}

std::string Parser::Cleanse(string input) {
	input = RemoveComments(input);
	input = Format(input);

	return input;
}

// Remove comments in a string
// Example:
// Input: # this is a comment  Output: 
// Input: echo a # && echo b   Output: b
// Input: echo "#hello"        Output: #hello
std::string Parser::RemoveComments(const std::string &input) {

  std::string input_without_comments;

	unsigned int i = 0;

	for (i = 0; i < input.size(); ++i) {
		if (input.at(i) == '"') {
			i = input.find('"',i);
		} else if (input.at(i) == '#') {
			break;
		}
		input_without_comments = input.substr(0,i+1);
	}

	return input_without_comments;
}

// Formats input to add spaces between delimeters. This is useful when using
// boost's split command.
std::string Parser::Format(string input) {

	std::string formatted_input;

	// If the first thing inputs is nothing. Add a space
	if (input == "") {
		return " ";
	}

	//----------------------------------------------------------------------------

	// Inserts a space in front of, and behind a semicolon delimiter this way user 
	// can input with no spaces
	for (unsigned i = 0; i < input.size(); i++) {
		if (input.at(i) == ';') {

			// Inserts whitespace before ';'
			input.insert(i, " ");

			// Increment i by 2 to move past semicolon
			i += 2;

			// Check that we are not at the end of the string and add whitespace after
			// semicolon
			if (i < input.size()) {
				input.insert(i, " ");
				++i;
			}
			else {
				break;
			}
		}

		// Special case for both double && and double ||
		if (input.at(i) == '&' && input.at(i + 1) == '&') {
			input.insert(i, " ");
			input.insert(i + 3, " ");
			i += 4;
		}

		if (input.at(i) == '|' && input.at(i + 1) == '|') {
			input.insert(i, " ");
			input.insert(i + 3, " ");
			i += 4;
		}
	}

	//LEFT PARENTHESES -- GOOD
	//adds a space in front of, and behind a left parentheses delimiter
	for (unsigned i = 0; i < input.size(); i++) {
		if (input.at(i) == '(') {
			//if parentheses is at the beginning
			if (i == 0) {
				// Move to next index to later insert whitespace after '('
				i++;
				input.insert(i, " ");
				//
				//i++;
				continue;
			}

			//if parentheses is not at the beginning
			if (i > 0) {

				//If a there is no whitespace before '(' then inserts whitespace before '('
				if (input.at(i - 1) != ' ') {
					input.insert(i, " ");
					//increment i by 2 to move past left parentheses
					i = i + 2;
				}
				else {
					//move to next index to later insert whitespace after '('
					i++;
				}

				//Check that we are not at the end of the string and add whitespace after '('
				if (i <= input.size()) {
					input.insert(i, " ");
				}
			}
		}
	}

	//RIGHT PARENTHESES -- GOOD
	//adds a space infront of, and behind a right parentheses delimiter
	//this way user can input with no spaces
	for (unsigned i = 0; i < input.size(); i++) {
		if (input.at(i) == ')') {

			//If a there is no whitespace before ')' then inserts whitespace before ')'
			if (input.at(i - 1) != ' ') {
				input.insert(i, " ");
				//increment i by 2 to move past right parentheses
				i = i + 1;
			} else {
				//move to next index to later insert whitespace after ')'
				//	i++;
			}

			//Check that we are not at the end of the string and add whitespace after ')'
			if ((i + 1) < input.size()) {
				i++;
				input.insert(i, " ");
			}
		}
	}

	return input;
}

// Parses a string into distinct commands.
// i.e.
// Input: ls -a && echo "hello world" && true || pwd
// Output: [ls -a, &&, echo "hello world", &&, true, ||, pwd]
void Parser::ToVector(string user_input) {
	//
	string tmp, tmp2;
	size_t foundSemi, foundSemi2;
	size_t foundAnd, foundAnd2;
	size_t foundOr, foundOr2;
	//size_t foundCom, foundCom2;
	size_t foundRP, foundRP2;
	size_t foundLP, foundLP2;

	// Builds the vector by first parsing through user_input and deleting all 
	// spaces.
	boost::split(commands_, 
								user_input, boost::is_any_of(" "), 
								boost::token_compress_on);


  if (commands_.at(0) == "") {
    commands_.erase(commands_.begin());
  }

  // Go through the vector and creates commands by adding back in spaces, and 
  // grouping 2 statement commands IE:ls -a
  for (unsigned int i = 0; i < commands_.size() + 10; ++i) {
    for (unsigned int j = 0; j < commands_.size() - 1; ++j) {
      tmp        = commands_.at(j);
      foundSemi  = tmp.find(';');
      foundAnd   = tmp.find('&');
      foundOr    = tmp.find('|');
      foundRP    = tmp.find(')');
      foundLP    = tmp.find('(');

      tmp2       = commands_.at(j + 1);
      foundSemi2 = tmp2.find(';');
      foundAnd2  = tmp2.find('&');
      foundOr2   = tmp2.find('|');
      foundRP2   = tmp2.find(')');
      foundLP2   = tmp2.find('(');

      if (foundSemi2   != string::npos 
          || foundAnd2 != string::npos 
          || foundOr2  != string::npos 
          || foundRP2  != string::npos 
          || foundLP2  != string::npos) {
        continue;
      } else {
        if (commands_.size() == j) {
          continue;
        }
        if (foundSemi   != string::npos 
            || foundAnd != string::npos 
            || foundOr  != string::npos 
            || foundRP  != string::npos 
            || foundLP  != string::npos)
          continue;
        else
        {
          commands_.at(j) += " ";
          commands_.at(j) += commands_.at(j + 1);
          commands_.erase(commands_.begin() + (j + 1));
        }
      }
      if (foundSemi   != string::npos 
          || foundAnd != string::npos 
          || foundOr  != string::npos 
          || foundRP  != string::npos 
          || foundLP  != string::npos) {

        continue;
      }
    }
  }

  return;
}

/*****************************************************************************************************************************
     * build_parentheses
     * ------------------------------------------------------------
     * responsible for handling parentheses cases as well as nested parentheses.
     *
     ****************************************************************************************************************************/
unsigned int Parser::BuildParentheses(unsigned int index)
{
  // Keep track of parentheses count
  int lp_count = 0;
  int rp_count = 0;
  string sub_command = "";
  string left_parentheses = "(";
  string right_parentheses = ")";

  lp_count++; //increment left parentheses count
  index++;		//now, jump past left parentheses

  /*while (lp_count != rp_count)//run while left parentheses does not have a matching right parentheses
       {
           if (commands.at(index) == left_parentheses.c_str()) lp_count++;//if we find another left parenthese, increment 
       
           if (commands.at(index) == right_parentheses.c_str()) rp_count++;//if we find a right parenthese, increment 

          //build a substring until hitting the right parentheses
           sub_command.append(commands.at(index));
           sub_command.append(" ");
           index++;
           if ((lp_count != rp_count) && (index < commands.size()) && ( commands.at(index) == right_parentheses.c_str())) rp_count++;
       
       }
 
       if(index < commands.size() && (commands.at(index) == right_parentheses.c_str())) index++;//skip past right parentheses
       
       */

  while (lp_count != rp_count) //run while left parentheses does not have a matching right parentheses
  {
    if (commands_.at(index) == left_parentheses.c_str())
      lp_count++; //if we find another left parenthese, increment

    if (commands_.at(index) == right_parentheses.c_str())
      rp_count++; //if we find a right parenthese, increment

    //build a substring until hitting the right parentheses

    if (lp_count != rp_count)
    {
      sub_command.append(commands_.at(index));
      //sub_command.append(" ");
    }
    index++;

    /*if ((lp_count != rp_count) && ( commands.at(index) == right_parentheses.c_str()))
               {
                   rp_count++;
               }*/
  }

  if (index < commands_.size() && (commands_.at(index) == right_parentheses.c_str()))
  {
    index++; //skip past right parentheses
  }

  lp_count = 0; //reset sub_command after use
  rp_count = 0; //reset sub_command after use

  //recursive call parse -- takes care of nested parentheses
  Parser *sub_parser = new Parser();
  right_command_ = sub_parser->Parse(sub_command); //expect command to be returned then store in tree
  //add sub tree to regular tree

  sub_command = ""; //reset sub_command after use

  return index;
}
