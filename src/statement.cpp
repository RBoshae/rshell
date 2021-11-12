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

	if (command_ == "exit") {
		exit (0);
	}
	
	// This is where syscalls come in 

	// Break up string by spaces and store them in an array of characters
	char* arg = new char[command_.length()];
	std::strcpy(arg, command_.c_str());

	char* tokenized_arg = std::strtok(arg, " ");
	char* array[1000];

	int i = 0;

	while (tokenized_arg != NULL) {
		array[i] = tokenized_arg;
		++i;
		tokenized_arg = std::strtok(NULL, " ");
	}
	array[i] = NULL;

	//********SYSTEMCALLS implementation*************
	pid_t child_pid;

	// Create child process
	child_pid = fork();
	int result = 0;

	if (child_pid == -1) {
		return false;
	}

	// Child process
	if (child_pid == 0) { 

		// This is done by the child process
		execvp(array[0], array);

		// If execvp returns, it must have failed
		std::cout << "Unknown command" << std::endl;
		exit(1); // Exit child process.
		return false;
	}	
	// Parent process
	else { 
		// Wait for the child to terminate.
		waitpid(child_pid, &result, 0);
		
		if (result != 0) {
			return false;
		} 
	}

	// Kill Child
	kill(child_pid, SIGKILL);

	delete arg;

	return true;
}
