#!/bin/sh
#tests commands with ;, &&, ||

#example tests
ls -a; echo hello; mkdir testing
ls -a; echo hello && mkdir testing || echo world; git status
#test default connectors
echo hello && echo world
mkdir testing || mkdir fail
ls; ls -a
#test double connectors
echo hello && && echo world
mkdir testing || || mkdir fail
ls; ; ls -a
#test long inputs
echo hello && echo world && echo how && echo do && echo you && echo do
mkdir testing || mkdir fail || mkdir this || mkdir that
echo hello; echo world; echo how; echo do; echo you; echo do
