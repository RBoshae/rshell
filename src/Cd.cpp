/*
* File: Cd.cpp
* ------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/28/16.
*
*/


#include "Cd.h"



Cd::Cd()
{
}


Cd::~Cd()
{
}

Cd::Cd(std::string passed_in_command)
{
	this->single_command = passed_in_command;
	return;
}

int Cd::execute()
{
    //cout << "CD is working" << endl;
    //cout << "contents of single_command: " << single_command << endl;
    int ret;
    int i = 0;
		
		//delete rogue space at the end of string
		if(single_command.at(single_command.size() - 1) == ' ')
		  single_command.erase((single_command.size() - 1), 1);
    
    //part a) cd <PATH> will change the current working directory to <PATH>
    if (single_command.size() > 2 && single_command.at(3) != '-') 
    {
      //cout << "cd has a path" << endl;
      single_command = single_command.substr(3, single_command.size() - 1);
      if(single_command.at(0) != '/')
        single_command.insert(0, "/");
      
  		arg = new char[single_command.length() + 1];
  		strcpy(arg, single_command.c_str());
  		
  		//arg now contains a c-string copy of statement
  		  //Tokenizer from Statement.cpp
  		char* array[1000];
  		
  		while (arg != 0)
  		{
  			array[i++] = arg;
  			arg = std::strtok(NULL, " ");
  		}
  		array[i] = NULL;
  		
		  
		  
		  char* pPath;
		  char* lastPath;
		  size_t found;
		  //string tmp;
		  
      pPath = getenv("PWD");
      lastPath = pPath;
      // cout << "pPath is: "<< pPath << endl;

      //for some reason this function delete the lastPath if you start it off as a char*
      //so i had to start it as a string above, then set the lastPathChar = to the string converted to a char.str
      string tmp =pPath;
      string tmp2 =array[0];
      tmp += tmp2;
      
      pPath = const_cast<char*>(tmp.c_str());
      //strcat(pPath, array[0]);
   
      
      // cout << "Made it here" << endl;
      // cout << "pPath is: "<< pPath << endl;

	  	ret = chdir(pPath);
	  	cout << ret << endl;
	  	if(ret < 0)
	  	{
	  	  return 1; //error 
	  	}
	  	//if the .. is entered need to delete up until the last backslash'/' twice.
	  	//because its a back
	  	tmp = pPath;
	  	//cout << "contents of temp '" << tmp << "'" << endl;
	  	if(tmp.at(tmp.size() - 1) == '.' && tmp.at(tmp.size()-2) == '/')
	  	{
	  	  //cout << "test passed" << endl;
	  	  return 0;
	  	}
	  	if(tmp.at(tmp.size() - 1) == '.' && tmp.at(tmp.size()-2) == '.')
	  	{
	  	  for(int i = 0; i < 2; i++)
	  	  {
	  	  found = tmp.find_last_of("/");
	  	  tmp = tmp.substr(0, found);
	  	  pPath = const_cast<char*>(tmp.c_str());
	  	  }
	  	}
      
		  //this is where is gets converted to a char
      //lastPathChar = const_cast<char*>(lastPath.c_str());
      if(-1 == setenv("OLDPWD",lastPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }
      //cout << "here?" << endl;
      
      if(-1 == setenv("PWD",pPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }

    }
    
    //part b) cd (alone) will change the current working directory to the user's home directory
    else if (single_command.size() == 2) {
      //cout << "cd alone" << endl;
      char* pPath; //represents future path
      char* lastPath;
      lastPath = getenv("PWD");
      pPath = getenv("HOME");
      
      ret = chdir(pPath);
	  	if(ret < 0)
	  	   return 1; //error
		  //cout << "The value is: " << ret << endl;
      
      if(-1 == setenv("OLDPWD",lastPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }
      
      //cout << "The home pPath is "<< pPath << endl;
      if(-1 == setenv("PWD",pPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }

    }
    
    //part c) will change the current working directory to the previous working directory //cd -a
    else if (single_command.size() <= 5 && single_command.at(3) == '-') 
    {
      //cout << "cd back to pwd" << endl;
      char* pPath;
      char* lastPath;
      pPath = getenv("OLDPWD");
      lastPath = getenv("PWD");

      ret = chdir(pPath);
	  	if(ret < 0)
	  	   return 1; //error
		  //cout << "The value is: " << ret << endl;
      
      if(-1 == setenv("OLDPWD",lastPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }
      
      if(-1 == setenv("PWD",pPath,1))           //since the overwrite parameter is non-zero it replaces environment 
      {
  				perror("setenv");                     //of $PWD with the value of ppath which is defined by the environment
  				cout << "ERROR IN SETENV" << endl;
      }
    
    }
    
    else 
    {
      cout << "Unkown command" << endl;
      return 1;
    }

/*    cd_history.push_back("hellloooooo");
    cd_history.push_back("2");
    cout << cd_history.back() << endl;*/
    
    
    
    
    
    return 0;
}
