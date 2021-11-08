#pragma once 

#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>

namespace shell_utilities {

std::string Username() {

  passwd *p;
  uid_t   uid;

  uid = geteuid();
  p   = getpwuid (uid);
  if (p) {
    return std::string(p->pw_name);
  }
  return "";
}

std::string Hostname() {
  char host[500];
  host[499] = '\0';
  gethostname(host, 499);

  return std::string(host);
}

std::string WorkingDir() {
  char* path = getenv("PWD");
  if (path != NULL) {

    std::string temp(path);
    std::string home = "/home/" + Username();
    temp.replace(0, home.size(), "~");
    return std::string(temp);
  }
  return "";
}

bool BalancedParenthesis(const std::string& user_input)
{
	int right_parenthesis = 0;
	int left_parenthesis  = 0;
	
	for (unsigned int i = 0; i < user_input.size(); i++) {
		if(user_input.at(i) == '(') ++left_parenthesis;
		if(user_input.at(i) == ')') ++right_parenthesis;
	}

	if (left_parenthesis == right_parenthesis) {
		return true;
	}	

	return false;
}
 
}