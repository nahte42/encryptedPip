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
		unsigned long long int message;//will be changed to Template format once it works
		unsigned long long int beg; 	//where to begin decryption
		unsigned long long int rng;	//how many times to cycle
		typedef void(System::*FP)(unsigned long long int &);
		typedef void(System::*FP_S)(string &);
		FP de_Hashes[5];
		FP_S de_String[5];
		stack<FP> deHashes;

	public:
		System(string name_address){ 	IP = name_address; de_Hashes[0] = &System::dehash0;
																	de_Hashes[1] = &System::dehash1; de_Hashes[2] = &System::dehash2;
																	de_Hashes[3] = &System::dehash3; de_Hashes[4] = &System::dehash4;}
		void set_message(unsigned long long int msg) {message = msg;}
		unsigned long long int readMessage(){return message;}
		void stage_message(){cin >> message; cin >> trgt;}
		string get_sysName(){return IP;}
		void push_hash(int hash){deHashes.push(de_Hashes[hash]);}
		void decode(unsigned long long int &);
		void dehash0(unsigned long long int &);
		void dehash1(unsigned long long int &);
		void dehash2(unsigned long long int &);
		void dehash3(unsigned long long int &);
		void dehash4(unsigned long long int &);
};

#endif
