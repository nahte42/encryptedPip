#include<iostream>
#include<string>

using namespace std;

int main(){

string my_string = "1234567890-asdfghjkl;'zxcvbnm,./'";
cout<<my_string[0]*4<<endl;
my_string[0] = (my_string[0]*4)%126+1;
my_string[1] = (my_string[1]*my_string[1])%126+1;
cout<<my_string<<endl;





  return 0;
}
