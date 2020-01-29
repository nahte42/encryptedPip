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