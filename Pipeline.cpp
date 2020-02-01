#include "Pipeline.h"
#include <functional>
#include <cstdlib>



Pipeline::Pipeline(){
	hashes[0] = &Pipeline::hash0;
	hashes[1] = &Pipeline::hash1;
	hashes[2] = &Pipeline::hash2;
	hashes[3] = &Pipeline::hash3;
	hashes[4] = &Pipeline::hash4;
		
	System system1("192.168");
	System system2("192.167");
	
	systems.push_back(system1);
	systems.push_back(system2);
}

//Send Message:
void Pipeline::sendmessage(string host, string target){
	
	
}

//Making Dinky "Hashes"
void hash0 (int& message){
	message++;
}

void hash1 (int& message){
	message*=2;
	
}
void hash2 (int& message){
	message += 45;
	
}

void hash3 (int& message){
	message += message / 2;
}

void hash4 (int& message){
	message --;
}