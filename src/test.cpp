/*
* File: Test.h
* ------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/12/16.
*
*/


#include "test.h"

Test::Test() {
}


Test::~Test() {
}

Test::Test(std::string command) {
	this->single_command = command;
	return;
}

bool Test::Execute()
{
    struct stat sb;
    string default_flag = "-e ";
    
    //trim the test delimeter(s) from from the single_command string.
    if((single_command.at(0) == '[') && (single_command.at(1) == ' ')  && (single_command.at(single_command.size() - 2) == ' ') && (single_command.at(single_command.size() - 1) == ']'))
    {
      single_command = single_command.substr(2, single_command.size() - 2);// 1 changed to 2 in first parameter
      if(single_command[0] != '-')
      {
        single_command = default_flag.append(single_command);
      }
    }
    
    else if(single_command.compare(0,4,"test") == 0)
    {
        single_command = single_command.substr(5, single_command.size() - 1);
        if(single_command[0] != '-')
        {
          single_command = default_flag.append(single_command);
        }
        
    }
    
    else
    {
      cout << "Error with test input, please check syntax" << endl;
      return -1;
    }
    //cout << "single_command = " << single_command << endl;
    
    //Break up string by spaces and store them in an array of characters
    
    arg = new char[single_command.length() + 1];
    strcpy(arg, single_command.c_str());
    
    //arg now contains a c-string copy of statement
      //Tokenizer from Statement.cpp
    char* tokenized_arg = strtok(arg, " ");
    char* array[100];
    
    int i = 0;
    
    while (tokenized_arg != 0)
    {
    	array[i++] = tokenized_arg;
    	tokenized_arg = std::strtok(NULL, " ");
    }
    array[i] = NULL;
    
    
    // int j = 0;
    // 	while(array[j] != NULL)
    // 	{
    // 	  cout << array[j] << endl;
    // 	  j++;
    // 	}
    	
    // cout << "array[0][0] = " << array[0][0] << endl;
    // cout << "array[0][1] = " << array[0][1] << endl;
    
    // if (stat(array[1], &sb) == -1)
    // {
    //     //perror("stat");
    //     exit(EXIT_FAILURE);
    //     cout << "(False)" << endl;
    //     return 1;
    // }
    // cout << "-e case" << endl;
    
  
    //-e checks if the file/directory exists
    //probabaly going to need an if
    // if (trimmed) stat(array[1] , &sb);
    // else stat(array[0], &sb);
    
    stat(array[1] , &sb);
    
    if(array[0][1] == 'e' && array[0][0] == '-')
    {
      if(S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode))
      {
          cout << "(TRUE)" << endl;
          return 0;
      }
      else 
      {
          cout << "(FALSE)" << endl;
          return 1;
      }
      
    }
    //-d checks if the file/directory exists and is a directory
    else if(array[0][1] == 'd' && array[0][0] == '-')
    {
      if(S_ISDIR(sb.st_mode))
      {
          cout << "(TRUE)" << endl;
          return 0;
      }
      else 
      {
          cout << "(FALSE)" << endl;
          return 1;
      }
     
    }
    
    //-f checks if the file/directory exists and is a regular file
    else if(array[0][1] == 'f' && array[0][0] == '-')
    {
      if(S_ISREG(sb.st_mode))
      {
          cout << "(TRUE)" << endl;
          return 0;
      }
      else 
      {
          cout << "(FALSE)" << endl;
          return 1;
      }
    }
    
    else
    {
      cout << "Unknown flag" <<endl;
      return 1;
    }
    
    cout << "Error with test" << endl; 
   return 1;
}
