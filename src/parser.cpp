/*
 * File: Parser.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 * 
 *
 */

#include "parser.h"

Parser::Parser()
{

}

Parser::~Parser()
{

}

void Parser::vectorize(string user_input)
{
	//
	string tmp, tmp2;
	size_t foundSemi, foundSemi2;
	size_t foundAnd, foundAnd2;
	size_t foundOr, foundOr2;
	//size_t foundCom, foundCom2;
	size_t foundRP, foundRP2;
	size_t foundLP, foundLP2;
	
	//cout << "Passed in user_input:" << "'" << user_input << "'" <<endl;
	
	//if the first thing inputs is nothing. Add a space
	if(user_input == "") user_input = " "; 
	
	//if the first thing typed is a comment delete everything
	if(user_input.at(0) == '#') 
	{
		user_input = " ";
	}
	//hunt down comments that arnt nested in quotes and DELETE YUM YUM YUM
	for(unsigned int i = 0; i < user_input.size(); i++)
	{
		//find and deal with comments
		if(user_input.at(i) == '#')
		{
			int quot_It = 0;
			//checks to see if its nested inside a quotation mark.
			if(user_input.at(i-1) == '"') continue;
			for(unsigned int j = 0; j < i; j++)
			{
				if(user_input.at(j) == '"') quot_It++;
			}
			if(quot_It % 2) continue;		//if its odd, then break. This means that it is nested in quotation marks Or nested quotes somewhere else
			else
				user_input.erase (i, string::npos);
		}
	}
	
	//------------------------------------------------------------------------------------------------------
	
	//adds a space infront of, and behind a semicolon delimiter
    //this way user can input with no spaces
	for (unsigned i = 0; i < user_input.size(); i++)
	{
			if(user_input.at(i) == ';') 
			{
				//inserts whitespace before ';'
				user_input.insert(i, " ");
				//increment i by 2 to move past semicolon
				i += 2;
				
				//Check that we are not at the end of the string and add whitespace after semicolon
				if(i < user_input.size())
				{
					user_input.insert(i, " ");
					i++;
				}
				else
				{
					break;
				}
			}
		//break were at the end
		//if(i == user_input.size()) break;
				//special case for both doble && and double ||
    	if(user_input.at(i) == '&' && user_input.at(i+1) == '&')
    	{
    		user_input.insert(i, " ");
    		user_input.insert(i + 3 ," ");
    		i+=4;
    	}
    	
    	if(user_input.at(i) == '|' && user_input.at(i+1) == '|')
    	{
    		user_input.insert(i, " ");
    		user_input.insert(i + 3," ");
    		i+=4;
    	}
	}
	
	//LEFT PARENTHESES -- GOOD
	//adds a space in front of, and behind a left parentheses delimiter
    //this way user can input with no spaces
	for (unsigned i = 0; i < user_input.size(); i++)
	{
			if (user_input.at(i) == '(') 
			{
				//if parentheses is at the beginning
				if( i == 0)
				{
					//move to next index to later insert whitespace after '('
					i++;
					user_input.insert(i, " ");
					//
					//i++;
					continue;
				}
				
				//if parentheses is not at the beginning
				if ( i > 0)
				{
					
					//If a there is no whitespace before '(' then inserts whitespace before '('
					if ( user_input.at(i - 1) != ' ')
					{	
						user_input.insert(i, " ");
						//increment i by 2 to move past left parentheses
						i = i + 2;
					}
					else
					{
						//move to next index to later insert whitespace after '('
						i++;
					}
					
					//Check that we are not at the end of the string and add whitespace after '('
					if(i <= user_input.size())
					{
						user_input.insert(i, " ");
						//i++;
					}
				}
				
				
			}
	}
	
	//RIGHT PARENTHESES -- GOOD
	//adds a space infront of, and behind a right parentheses delimiter
    //this way user can input with no spaces
	for (unsigned i = 0; i < user_input.size(); i++)
	{
		if (user_input.at(i) == ')') 
		{
				
			//If a there is no whitespace before ')' then inserts whitespace before ')'
			if ( user_input.at(i - 1) != ' ')
			{	
				user_input.insert(i, " ");
				//increment i by 2 to move past right parentheses
				i = i + 1;
			}
			else
			{
				//move to next index to later insert whitespace after ')'
			//	i++;
			}
		
			
			//Check that we are not at the end of the string and add whitespace after ')'
			if((i + 1) < user_input.size())
			{
				i++;
				user_input.insert(i, " ");
				
			}
		}
	}
	
    /*for (unsigned int k = 0; k < user_input.size(); k++)
    {
    	//adds a space infront of, and behind a single character delimiter
    	//this way user can input with no spaces
    	if((user_input.at(k) == ';') || (user_input.at(k) == '(') || (user_input.at(k) == ')'))
    	{
    		cout << "k is: " << k << endl;
    		user_input.insert(k, " ");
    		cout << "k is: " << k << endl;
    		k++;
    		k++;
    		
    		if (k >= user_input.size()) break;/////////////
    		
    		if ((k+2 < user_input.size()) && (k+1 < user_input.size()) && (user_input.at(k+1) != ' '))
    		{
    			cout << "k is: " << k << endl;
    			cout << "user_input.at(k) is '" << user_input.at(k) << "'" << endl;
    			cout << "Before white space added:";
    			cout << user_input << endl;
				user_input.insert((k), " ");
				cout << "After white space added:";
    			cout << user_input << endl;
			//	i++;
			//	i++;
				
    		}
    		
    		if (k >= user_input.size()) break;/////////////
    		//if (user_input.size() != (i))user_input.insert((i+1), " "); //code added by RB
    		
    		//cout << "i :" << i << endl;
    		//cout << "user_input.size() :" << user_input.size() << endl;
    		// if(user_input.size() == i + 2) // if the last character is a single char delim, then break no need to put a space at the very end.
    		// 	break;
    		// else
    		// {
    		// 	//put a space after the single delim
    		// 	user_input.insert(i + 2 ," ");
    		// 	i+=3;
    		// }
    	}
    	
    	//special case for both doble && and double ||
    	if(user_input.at(k) == '&' && user_input.at(k+1) == '&')
    	{
    		user_input.insert(k, " ");
    		user_input.insert(k + 3 ," ");
    		k+=4;
    	}
    	if (k >= user_input.size()) break;/////////////////////
    	
    	if(user_input.at(k) == '|' && user_input.at(k+1) == '|')
    	{
    		user_input.insert(k, " ");
    		user_input.insert(k + 3," ");
    		k+=4;
    	}
    }//end*/
    
    
    	//builds the vector by first parsing through user_input and deleting all spaces.
		for (unsigned int i = 0; i < user_input.size(); i++)
		{
			boost::split(commands, user_input, boost::is_any_of(" "), boost::token_compress_on);
		}
		if(commands.at(0) == "")
			commands.erase(commands.begin());
		//goes through the vector and creates commands by adding back in spaces, and grouping 2 statement commands IE:ls -a
		for (unsigned int i = 0; i < commands.size() + 10; i++)
		{
		    for(unsigned int j = 0; j < commands.size() - 1; j++)
		    {
			    tmp = commands.at(j);
			    tmp2 = commands.at(j + 1);
			    foundSemi = tmp.find(';');
			    foundAnd = tmp.find('&');
			    foundOr = tmp.find('|');
			    foundRP = tmp.find(')');
			    foundLP = tmp.find('(');
			    foundSemi2 = tmp2.find(';');
			    foundAnd2 = tmp2.find('&');
			    foundOr2 = tmp2.find('|');
			    foundRP2 = tmp2.find(')');
			    foundLP2 = tmp2.find('(');
			    //foundCom = tmp.find('#');
				if(foundSemi2 != string::npos || foundAnd2 != string::npos || foundOr2 != string::npos || foundRP2 != string::npos || foundLP2 != string::npos) continue;
				else
				{
					if (commands.size() == j) continue;
					if (foundSemi != string::npos || foundAnd != string::npos || foundOr != string::npos || foundRP != string::npos || foundLP != string::npos) continue;
					else
					{
						commands.at(j) += " ";
						commands.at(j) += commands.at(j + 1);
						commands.erase(commands.begin() + (j + 1));
					}
				}
				if (foundSemi != string::npos || foundAnd != string::npos || foundOr != string::npos || foundRP != string::npos || foundLP != string::npos) continue;
		    }
		}
		//cout << "'" << commands.at(commands.size() - 1) << " '" << endl;
		//if(commands.at(commands.size() - 1) == " ") commands.erase(commands.begin() + (commands.size() - 1));
		/*//print vector
		cout << "vectorized user_input" << endl;
		for (unsigned int i = 0; i < commands.size(); i++)
		{
			cout << commands.at(i) << endl;
		}
		cout << "end of vectorized user_input" << endl;*/
	return; //commands;

}



Command* Parser::parse(string user_input)
{

   vectorize(user_input); 
    
    /**********************************************
     * Token Bank
     * --------------------------------------------
     * list of tokens/delimeters used to build tree
	 **********************************************/
    string and_delimeter = "&&";
    string or_delimeter = "||";
    string semicolon_delimeter = ";";
    string comment_delimeter = "#";
    string exiter = "exit";
    string test = "test";
    string blank = "";
    
    string left_parentheses = "(";
    string right_parentheses = ")";
   //***********End of Token Bank****************
    
    int lp_count = 0;
    int rp_count = 0;

    string token = "";
    string command = "";
    string sub_command = "";

   
   
	
	 /*****************************************************************************************************************************
     * Build Command Tree
     * ------------------------------------------------------------
     * Iterate through commands vector until it is empty. The loop
     * will contstruct a Command Tree based on the command or 
     * delimeter it receives.
     * 
	 ****************************************************************************************************************************/
   for(unsigned int index = 0; index < commands.size(); index++)
   {
		//Workaround - Getting an empty string at index 0 for some reason. We may need to investigate the vectorize function.
   		// if (index > commands.size()) break;
   		// if (blank.c_str() == commands.at(index)) index++;
   		// if (index >= commands.size()) break;
   		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   		
   		
   		//---------------------------------------------Parentheses Handler---------------------------------------------------
   		if (left_parentheses.c_str() == commands.at(index)) //If commands at index is a parentheses jump in
   			{
   				lp_count++; //increment left parentheses count
			   	index++;//now, jump past left parentheses
			   	
			   	while (lp_count != rp_count)//run while left parentheses does not have a matching right parentheses
			   	{
			   		if (commands.at(index) == left_parentheses.c_str()) lp_count++;//if we find another left parenthese, increment 
			   	
			   		if (commands.at(index) == right_parentheses.c_str()) rp_count++;//if we find a right parenthese, increment 
			
			  		//build a substring until hitting the right parentheses
			   	
			   		if (lp_count != rp_count)
			   		{
				   		sub_command.append(commands.at(index));
				   		//sub_command.append(" ");
			   		}
			   		index++;
			   		
			   		/*if ((lp_count != rp_count) && ( commands.at(index) == right_parentheses.c_str()))
		   			{
		   				rp_count++;
		   			}*/
			   	
			   	}
			 
			   	if(index < commands.size() && (commands.at(index) == right_parentheses.c_str())) 
			   	{
			   		index++;//skip past right parentheses
			   	}
			   	
			   	lp_count = 0; //reset sub_command after use
			   	rp_count = 0; //reset sub_command after use
			   	
			   	//recursive call parse -- takes care of nested parentheses
			   	Parser* sub_parser = new Parser();
			   
			   	leftCmd = sub_parser->parse(sub_command); //expect command to be returned then store in tree
			   	
			   	sub_command = ""; //reset sub_command after use

   			}
   			//-----------------------END OF Parentheses---------------------------------------------------
   		
		//first Statement Build
 		//---------------------------------------------Statement Handler---------------------------------------------------
   		//if commands at index is not a delimeter then it is a statement.
   		if ((index < commands.size()) && (and_delimeter.c_str() != commands.at(index)) 
   														  && (or_delimeter.c_str() != commands.at(index))
   														  && (semicolon_delimeter.c_str() != commands.at(index))
   														  && (blank.c_str() != commands.at(index))
   														  && (index < commands.size())
   														  && (left_parentheses.c_str() != commands.at(index)))
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
   			if(commands[index][0] == '[' || commands.at(index).compare(0,4,"test") == 0)
   			{
   				leftCmd = new Test(commands.at(index));
   				index++;
   			}
   			else if((commands[index][0] == 'c') && (commands[index][1] == 'd') && ((commands[index].size() == 2) || (commands[index][2] == ' ')))//added for cd assignment
   			{
   				leftCmd = new Cd(commands.at(index));
   				index++;
   			}
   			else //its a normal statement
   			{
	   			leftCmd = new Statement(commands.at(index));
	   			index++;
   			}
   			// leftCmd = new Statement(commands.at(index));
	   		// index++;
   			
   			//handles the single command case.
   			if(index >= commands.size()) break; 
   		}
   		//-----------------------END OF Statement---------------------------------------------------------------------
   		
   		
   		
   		
   		/*******************************************Delimeter Cases**********************************************/
   		//If the command at index is a delimeter check which one it is and add the tree 
   		
   		
   		
   		
   		//-----------------------------And Case---------------------------------------
   		if((index < commands.size()) && (and_delimeter.c_str() == commands.at(index)))//if it is an And delimeter
   		{
   			index ++;//increment index to next delimeter
   			
   			//grab next string in index and stor it in  a statement
   			if ( left_parentheses.c_str() != commands.at(index))
   			{
   				if(commands[index][0] == '[' || commands.at(index).compare(0,4,"test") == 0)
	   			{
	   				rightCmd = new Test(commands.at(index));
   					leftCmd = new And(leftCmd, rightCmd);
	   			}
	   			else if((commands[index][0] == 'c') && (commands[index][1] == 'd'))//added for cd assignment
	   			{
	   				rightCmd = new Cd(commands.at(index));
	   				leftCmd = new And(leftCmd, rightCmd);
	   			}
	   			else //its a normal statement
	   			{
		   			rightCmd = new Statement(commands.at(index));
   					leftCmd = new And(leftCmd, rightCmd);
	   			}
   				// rightCmd = new Statement(commands.at(index));
   				// leftCmd = new And(leftCmd, rightCmd);
   			}
   			else if (left_parentheses.c_str() == commands.at(index))
   			{
   				index = build_parentheses(index);
   				//add sub tree to regular tree
   				leftCmd = new And(leftCmd, rightCmd);
   				sub_command = ""; //reset sub_command after use -- may be useless
   				
   			}
   		}
   		//------------------------------End of And Case---------------------------------
   		
   		
   		//--------------------------------Or Case---------------------------------------
   		if((index < commands.size()) && (or_delimeter.c_str() == commands.at(index)))
   		{
   			index ++;//increment index to next delimeter
   			//grab next string in index and stor it in  a statement
   			if ( left_parentheses.c_str() != commands.at(index))
   			{
   				if(commands[index][0] == '[' || commands.at(index).compare(0,4,"test") == 0)
	   			{
	   				rightCmd = new Test(commands.at(index));
   					leftCmd = new Or(leftCmd, rightCmd);
	   			}
	   			else if((commands[index][0] == 'c') && (commands[index][1] == 'd'))//added for cd assignment
	   			{
	   				rightCmd = new Cd(commands.at(index));
	   				leftCmd = new And(leftCmd, rightCmd);
	   			}
	   			else //its a normal statement
	   			{
		   			rightCmd = new Statement(commands.at(index));
   					leftCmd = new Or(leftCmd, rightCmd);
	   			}
   				// rightCmd = new Statement(commands.at(index));
   				// leftCmd = new Or(leftCmd, rightCmd);
   			}
   			
   			//CHECKS FOR PARENTHESES
   			else if (left_parentheses.c_str() == commands.at(index))
   			{
   				index = build_parentheses(index);
   				//add sub tree to regular tree
   				leftCmd = new Or(leftCmd, rightCmd);
   				sub_command = ""; //reset sub_command after use -- may be useless
	
   			}
   		}
   		//------------------------------End of Or Case-------------------------------
   		
   		
   		
   		
   		//--------------------------------Semicolon Case---------------------------------------
   		
   		//trailing semicolon hack
   		if ((index < commands.size()) && (commands.at(commands.size() - 1) == semicolon_delimeter.c_str())) commands.at(commands.size() - 1) = ""; 
   			
   		if((index < commands.size()) && (semicolon_delimeter.c_str() == commands.at(index)))
   		{
   			index ++;//increment index to next delimeter
   			//grab next string in index and stor it in  a statement
   			if ( left_parentheses.c_str() != commands.at(index))
   			{
   				if(commands[index][0] == '[' || commands.at(index).compare(0,4,"test") == 0)
	   			{
	   				rightCmd = new Test(commands.at(index));
   					leftCmd = new Semicolon(leftCmd, rightCmd);
	   			}
	   			else if((commands[index][0] == 'c') && (commands[index][1] == 'd'))//added for cd assignment
	   			{
	   				rightCmd = new Cd(commands.at(index));
	   				leftCmd = new And(leftCmd, rightCmd);
	   			}
	   			else //its a normal statement
	   			{
		   			rightCmd = new Statement(commands.at(index));
   					leftCmd = new Semicolon(leftCmd, rightCmd);
	   			}
   				// rightCmd = new Statement(commands.at(index));
   				// leftCmd = new Semicolon(leftCmd, rightCmd);
   			}
   			
   			//CHECKS FOR PARENTHESES
   			else if (left_parentheses.c_str() == commands.at(index))
   			{
   				index = build_parentheses(index);
   				//add sub tree to regular tree
   				leftCmd = new Semicolon(leftCmd, rightCmd);
   				
   				sub_command = ""; //reset sub_command after use -- may be useless
   				
   			}
   		}
   		//------------------------------End of Semicolon Case-------------------------------
   		
   		/*************************End of Delimeter Cases**********************************/
   		
  
   }//end of for loop, commands vector is now empty
    //*********************End of Command Tree Builder************


    return leftCmd; // return built tree to caller.
}




/*****************************************************************************************************************************
     * build_parentheses
     * ------------------------------------------------------------
     * responsible for handling parentheses cases as well as nested parentheses.
     *
	 ****************************************************************************************************************************/
unsigned int Parser::build_parentheses(unsigned int index)
{
	//keep track of parentheses count
	int lp_count = 0;
    int rp_count = 0;
    string sub_command = "";
    string left_parentheses = "(";
    string right_parentheses = ")";
    
   	lp_count++; //increment left parentheses count
   	index++;//now, jump past left parentheses
   	
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
   	
   	
   	
   	
   		while (lp_count != rp_count)//run while left parentheses does not have a matching right parentheses
	   	{
	   		if (commands.at(index) == left_parentheses.c_str()) lp_count++;//if we find another left parenthese, increment 
	   	
	   		if (commands.at(index) == right_parentheses.c_str()) rp_count++;//if we find a right parenthese, increment 
	
	  		//build a substring until hitting the right parentheses
	   	
	   		if (lp_count != rp_count)
	   		{
		   		sub_command.append(commands.at(index));
		   		//sub_command.append(" ");
	   		}
	   		index++;
	   		
	   		/*if ((lp_count != rp_count) && ( commands.at(index) == right_parentheses.c_str()))
   			{
   				rp_count++;
   			}*/
	   	
	   	}
	 
	   	if(index < commands.size() && (commands.at(index) == right_parentheses.c_str())) 
	   	{
	   		index++;//skip past right parentheses
	   	}
	   	
	   	lp_count = 0; //reset sub_command after use
	   	rp_count = 0; //reset sub_command after use
	   	
   	
   	//recursive call parse -- takes care of nested parentheses
   	Parser* sub_parser = new Parser();
    rightCmd = sub_parser->parse(sub_command); //expect command to be returned then store in tree
   	//add sub tree to regular tree
   	
   	sub_command = ""; //reset sub_command after use
    
    return index;
}

