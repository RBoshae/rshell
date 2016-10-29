#include <iostream>
#include <string>

using namespace std;

int main(){

	bool continue_shell = true;
	string user_input; 

	cout << "**********Welcome to rshell**********" << endl;

	while (continue_shell){

		//Prompt User
		cout << "$ ";
		getline(cin, user_input);//getline will allow us to record and print the string in one line.


		cout << user_input;
		cout <<endl;

	}
return 0;
}
