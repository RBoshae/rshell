# rshell
CS100 Project, Assignment 2

Introduction: 
In this assignment we will emulate a shell terminal and call it rshell. When rshell is executed it will accept arguments from the user and execute the argument’s command(s). In order organize and accept multiple commands from the user we will build a Command class. The Command class is designed to be used as an interface. It will also interface with other classes, namely a Parse class, to differentiate multiple arguments and evaluate them properly. The Command class will be built with a Strategy pattern in mind, that is, we will utilize a common interface.


BUGS AND TODO LIST:


TODO:
	fix quotation marks
	add parentathesis
	comments
	test classs
	semi colin
	fix make file
	

Complete:
	Argument class,
	Statement class,
	And class,
	Parser,
	Or class,
	Container class (Possibly not needed),
	Ignore comment functionality

Bug Report:
	And class:
	execution returns an int to verify if we should run next child. If we have time we may want write a status function to do the same thing.
	With quotation marks the 
	no white space after the semi collen infinite loop initiated.
	if || with exit. Like ( echo goodbye || exit) exit should not terminate