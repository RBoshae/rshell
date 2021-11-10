/*
 * File: or.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 11/10/2016
 *
 */

#include "or.h"

Or::Or()
:
left_command_(nullptr),
right_command_(nullptr) {
}

Or::Or(Command* left_command, Command* right_command) {
	left_command_  = left_command;
	right_command_ = right_command;
}

Or::~Or() {
	if (left_command_) {
		delete left_command_;
	}
	if (right_command_) {
		delete right_command_;
	}
}

bool Or::Execute() {	
	
	if (left_command_->Execute()) {
		return true; 
	}
	
	return (right_command_->Execute());
}
