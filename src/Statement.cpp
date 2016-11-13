/*
* File: Statement.h
* ------------------
*
* Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/07/16.
*
*/


#include "Statement.h"



Statement::Statement()
{
}


Statement::~Statement()
{
}

Statement::Statement(std::string passed_in_command)
{
	this->single_command = passed_in_command;
	return;
}

bool Statement::execute()
{
	/*********************************************************************************
	 * RShell Exit Handlers
	 * ------------------------------------------------------------------------------
	 * If Statement object is an exit command it will exit here.
	 * version without space is the normal case
	 * We would expect exit to have a space at the end if it was nested in a parentheses.
	 * Possible Revisions would be to trim the value of exit when it is passed in.
     *********************************************************************************/
	std::string exiter = "exit";
	std::string exiter_with_space = "exit ";
	if ((single_command.c_str() == exiter) || (single_command.c_str() == exiter_with_space)) exit (0);
	
	//****************************End of RShell Exit Handlers**************************
	
	
	
	
	
	//This is where syscalls stuff will come in 

	//Break up string by spaces and store them in an array of characters

	arg = new char[single_command.length() + 1];
	std::strcpy(arg, single_command.c_str());

	//arg now contains a c-string copy of statement

	char * tokenized_arg = std::strtok(arg, " ");
	char * array[100];

	int i = 0;
	int status;
	char comment[] = "#";

	while ((tokenized_arg != 0) && (std::strcmp(comment, tokenized_arg) != 0))
	{
		array[i++] = tokenized_arg;
		tokenized_arg = std::strtok(NULL, " ");
	}
	array[i] = NULL;

	//********SYSTEMCALLS implementation*************
	pid_t child_pid;
	//int child_status;

	//create child process
	child_pid = fork();

	if (child_pid == -1)
	{
		success = false;
		return false;
	}

	if (child_pid == 0) {//This is the child process

						 //This is done by the child process
		execvp(array[0], array);

		//If execvp returns, it must have failed
		std::cout << "Unknown command" << std::endl;
		success = false;
		return false;
	}
	else { //This is the parent process
		   //This is run by the parent. Wait for the child to terminate.
		waitpid(child_pid, &status, 0);//wait for the child process to return
	}

	//Kill Child
	kill(child_pid, SIGKILL);

	success = true;
	return true;

}