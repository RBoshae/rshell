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
		std::cout << "Unkown command" << std::endl;
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
