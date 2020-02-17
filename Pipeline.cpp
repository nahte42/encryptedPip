#include "Pipeline.h"
#include <functional>
#include <cstdlib>
#include <time.h>



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
	cout<<"Starting send message:\n";
	cout<<"Host is: "<<host<<endl;
	cout<<"Target is: "<<target<<endl;
	srand(time(NULL));
	int h;
	int t;
	for(int i = 0; i < systems.size(); i++){
		if(systems[i].get_sysName() == host)
			h = i;
		if(systems[i].get_sysName() == target)
			t = i;
	}
	cout<<"Found targets:\n";
	cout<<"Stage Message for sending\n";
	systems[h].stage_message();
	unsigned long long int message =  systems[h].readMessage();
	cout<<"Message before hashing: "<<message<<endl;
	int hsh;
	for(int i = 0; i < 10; i++){
		hsh = rand()%5;
		(*this.*hashes[hsh])(message);
		systems[t].push_hash(hsh);
	}
	cout<<"Hashed Message Is: "<<message<<endl;
	systems[t].decode(message);
	cout<<"Decoded Message: "<<systems[t].readMessage()<<endl;;
}

//Making Dinky "Hashes"
void Pipeline::hash0 (unsigned long long int & message){
	message++;
}

void Pipeline::hash1 (unsigned long long int & message){
	message*=2;

}
void Pipeline::hash2 (unsigned long long int & message){
	message += 45;

}

void Pipeline::hash3 (unsigned long long int & message){
	message *= 20;
}

void Pipeline::hash4 (unsigned long long int & message){
	message --;
}
