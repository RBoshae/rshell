/*
 * File: And.cpp
 * -------------------------
 *
 * Created by Rick Boshae, Sammy Macaluso, and Christopher Sultzbaugh on 
 * 10/29/16.
 *
 */

#include "and.h"

And::And() :
left_command_(nullptr),
right_command_(nullptr) {

}

And::And(Command* left_command, Command* right_command) {
	left_command_  = left_command;
	right_command_ = right_command;
}

And::~And() {
	if (left_command_ != nullptr) {
		delete left_command_;
	}

	if (right_command_ != nullptr) {
		delete right_command_;
	}
}

bool And::Execute() {
	// Always execute left_command_
	if (left_command_->Execute()) {
		return right_command_->Execute();
	}
	return false;
}
