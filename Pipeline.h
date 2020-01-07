#include <iostream>
#include <stack>
#include "Systems.h"
using namespace std;

#ifndef PIPELINE_H
#define PIPELINE_H


class Pipeline{
		private:
			typedef int(Pipeline::*FP)(int );
			FP hashes[5]; 
			stack<FP> deHashes;
			Host system1;
			Target system2;	
		
		public:
			void sendmessage(Host, Target);
			int decrypt();
};

#endif