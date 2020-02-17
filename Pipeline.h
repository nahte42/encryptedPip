#include <iostream>
#include <stack>
#include "Systems.h"
#include <vector>
using namespace std;

#ifndef PIPELINE_H
#define PIPELINE_H


class Pipeline{
		private:
			typedef void(Pipeline::*FP)(unsigned long long int &);
			typedef void(Pipeline::*FP)(string &);
			FP hashes[5];
			vector<System> systems;

		public:
			Pipeline();
			void sendmessage(string host, string target);
			int decrypt();
			int test(int &n);
			void hash0 (unsigned long long int & message);
			void hash1 (unsigned long long int & message);
			void hash2 (unsigned long long int & message);
			void hash3 (unsigned long long int & message);
			void hash4 (unsigned long long int & message);
};

#endif
