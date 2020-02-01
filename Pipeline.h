#include <iostream>
#include <stack>
#include "Systems.h"
#include <vector>
using namespace std;

#ifndef PIPELINE_H
#define PIPELINE_H


class Pipeline{
		private:
			typedef void(Pipeline::*FP)(int &);
			FP hashes[5]; 
			vector<System> systems;
		
		public:
			Pipeline();
			void sendmessage(string host, string target);
			int decrypt();
			int test(int &n);
			void hash0 (int& message);
			void hash1 (int& message);
			void hash2 (int& message);
			void hash3 (int& message);
			void hash4 (int& message);
};

#endif