# rshell
CS100 Project, Assignment 3

Introduction: 
In this assignment we will emulate a shell terminal and call it rshell. When rshell is executed it will accept arguments from the user and execute the argument’s command(s). In order organize and accept multiple commands from the user we will build a Command class. The Command class is designed to be used as an interface. It will also interface with other classes, namely a Parse class, to differentiate multiple arguments and evaluate them properly. The Command class will be built with a Strategy pattern in mind, that is, we will utilize a common interface.

New Implementation:
Users can now utilize the test expression which will print a true or false value. Users can now use parentheses for precedence.

BUGS AND TODO LIST:


TODO:
	
	

Complete:
	Test class,
	semi colin,
	make file,
	Parentathesis precedence,
	Command class,
	Statement class,
	And class,
	Parser class,
	Or class,
	

Bug Report:
	Stable
	
Resolved Bugs:
	And class:
	execution returns an int to verify if we should run next child. If we have time we may want write a status function to do the same thing.
	With quotation marks the 
	no white space after the semi collen infinite loop initiated.
	if || with exit. Like ( echo goodbye || exit) exit should not terminate.
	Trailing semicolon will break the code.
	exits after first case was an unknown command.
	Precedence (echo a && (echo b || (echo c && echo d))) = unknown command