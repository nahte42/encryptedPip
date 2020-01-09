#include "Pipeline.h"
#include <functional>
#include <cstdlib>



Pipeline::Pipeline(){
	hashes[0] = &Pipeline::test;
	hashes[1] = &Pipeline::test;
	hashes[2] = &Pipeline::test;
	hashes[3] = &Pipeline::test;
	hashes[4] = &Pipeline::test;
	
	int g = 9;
	
	(this->*hashes[0])(g);
	
}


int Pipeline::test(int &n){
	cout<<"Test: "<<n<<endl;
	
	return 0;
}