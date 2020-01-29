/*
	The Way This Will Work Systems Will Stage a Message with a target IP
	The Pipeline Will Then Invoke The Send Message Function, picking a random value to start
	Each time a hash is done, the pipeline will invoke the target system to add the corresponding
	dehash to push to a stack. When the System then decodes, it pops the hashes from the stack to try and
	decode the message.
*/

#include<iostream>
#include<stack>
using namespace std;

#ifndef SYSTEMS_H
#define SYSTEMS_H

class System{
	private:
		string IP;
		string trgt;
		int message;//will be changed to Template format once it works
		int beg; 	//where to begin decryption
		int rng;	//how many times to cycle
		typedef int(System::*FP)(int &);
		FP de_Hashes[5];
		stack<FP> deHashes;
		
	public:
		System(string name_address){ IP = name_address; }
		int readMessage(){return message;}
		void stage_message(){cin >> message; cin >> trgt};
		int decode();
		int dehash0(int &);
		int dehash1(int &);
		int dehash2(int &);
		int dehash3(int &);
		int dehash4(int &);
};

#endif