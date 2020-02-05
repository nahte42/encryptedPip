#include <iostream>
#include <stack>
#include "Systems.h"
#include <vector>
using namespace std;

#ifndef PIPELINE_H
#define PIPELINE_H


class Pipeline{
		private:
			typedef void(Pipeline::*FP)(long long int &);
			FP hashes[5];
			vector<System> systems;

		public:
			Pipeline();
			void sendmessage(string host, string target);
			int decrypt();
			int test(int &n);
			void hash0 (long long int & message);
			void hash1 (long long int & message);
			void hash2 (long long int & message);
			void hash3 (long long int & message);
			void hash4 (long long int & message);
};

#endif
