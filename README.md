# rshell

rshell is a command-line program that emulates a shell terminal. When executed,
rshell waits for input from the user. rshell was originally developed as an
assignment for CS100 Software Construction at
[UC Riverside](https://www.engr.ucr.edu/).

## Features

* Test class
* semi colin
* Makefile
* Parenthesis precedence
* Command class
* Statement class
* And class
* Parser class
* Or class

## Getting rshell up and Running on Your Machine

### Requirements

* Linux based operating system
* Boost Library, used in the Parser class.

Refer to [Boost's Getting Started](https://www.boost.org/doc/libs/1_73_0/more/getting_started/unix-variants.html) 
page for information on installing boost on your machine.

If you happen to use Ubuntu you can enter the following command in your 
terminal to obtain a copy of the boost library.

```bash
sudo apt-get install libboost-all-dev
```

### Install Instructions

Start by cloning the project to your local machine

```bash
git clone https://github.com/RBoshae/rshell.git
```

Navigate to rshell's top level directory and use ```make``` to build the it.

```bash
make
```

Assuming all went well, you are now ready to run rshell. The rshell executable
is located in the bin subdirectory. Navigate to the bin subdirectory to run the
program.

```bash
cd bin
./rshell
```

## Some Notes on the Code

A primary objective in creating rshell was implementing common design patterns
described in [Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns)
by The "Gang of Four".

Some patterns used in the code include the following

* Strategy Pattern
* Composite Pattern

### command.h

The command class serves as the user interface and is designed to organize and
accept multiple command inputs. The Command class will be built with a
Strategy pattern in mind,that is, we will utilize a common interface.

### parse.h

A Parse class was implemented to differentiate multiple arguments and evaluate
them properly.

## Running Tests

rshell comes with a ```test``` subdirectory which contains scripts for
executing tests. To run a test simply execute the test script. For example you
can test the multiple commands by entering the following

```bash
./multi_command.sh
```

## Known Issues

The latest commit to rshell is stable. Just keep in mind this project was
developed by a couple of college students, it likely has bugs.
Since then I've cleaned the project up a bit but that's about it.

## Resolved Issues

* Return Execution Result And.h
Execution returns an int to verify if we should run next child. If we have
time we may want write a status function to do the same thing.

* Resolved Infinite Loop Issue
no white space after a semi colon caused an infinite loop.

* Issue with exit command with and or if || with exit. Like
( echo goodbye || exit) exit should not terminate.

* Resolved issue with repeat trailing/repeating semicolons will break the code.
exits after first case was an unknown command.

* Fixed execution precedence
Precedence ```(echo a && (echo b || (echo c && echo d))) = unknown command```

## Authors

* [Rick Boshae](https://rboshae.github.io)
* [Sammy Macaluso](https://www.linkedin.com/in/sammy-macaluso/)
