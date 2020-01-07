#include<iostream>

using namespace std;

#ifndef SYSTEMS_H
#define SYSTEMS_H

class Host{
	private:
		string IP;
		int message; //will be changed to Template format once it works
		
	public:
		Host(){ IP = "192.168.255.50"; message = 19192884;}
		int readMessage(){return message;}
		int decode();
	
};

class Target : public Host{
	private:
		string IP;
		int message; //will be changed to Template format once it works
	public:
		Target(){IP = "192.168.255.00"; message = 0;}
		int readMessage();
};

#endif