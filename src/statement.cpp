/*
 * File: Statement.h
 * ------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 
 * 11/07/16.
 *
 */
#include "statement.h"

Statement::Statement() {
}


Statement::~Statement() {
}

Statement::Statement(std::string command) {
	command_ = command;
}

bool Statement::Execute() {
	/*****************************************************************************
	 * RShell Exit Handlers
	 * ---------------------------------------------------------------------------
	 * If Statement object is an exit command it will exit here.
	 * version without space is the normal case
	 * We would expect exit to have a space at the end if it was nested in a 
	 * parentheses.
	 * Possible Revisions would be to trim the value of exit when it is passed in.
     **************************************************************************/
	std::string exiter            = "exit";
	std::string exiter_with_space = "exit ";
	if (command_.c_str() == exiter 
	    || (command_.c_str() == exiter_with_space)) exit (0);
	
	//****************************End of RShell Exit Handlers*********************
	
	//This is where syscalls come in 

	//Break up string by spaces and store them in an array of characters
	arg = new char[command_.length() + 1];
	std::strcpy(arg, command_.c_str());

	//arg now contains a c-string copy of statement

	char * tokenized_arg = std::strtok(arg, " ");
	char * array[1000];

	int i = 0;
	int status;

	while (tokenized_arg != 0) {
		array[i++] = tokenized_arg;
		tokenized_arg = std::strtok(NULL, " ");
	}
	array[i] = NULL;

	//********SYSTEMCALLS implementation*************
	pid_t child_pid;

	//create child process
	child_pid = fork();

	if (child_pid == -1) {
		return false;
	}

	if (child_pid == 0) { // This is the child process

						 //This is done by the child process
		execvp(array[0], array);

		//If execvp returns, it must have failed
		std::cout << "Unknown command" << std::endl;
		exit(0);//exit child process.
		return false;
	}	else { // This is the parent process
		       // This is run by the parent. Wait for the child to terminate.
		waitpid(child_pid, &status, 0); // wait for the child process to return
		
		if (status != 0) return false;
	}

	// Kill Child
	kill(child_pid, SIGKILL);

	return true;
}
