#include <math.h>
#include "Systems.h"

void System::dehash0(long long int  &message){
  message--;
}

void System::dehash1(long long int  &message){
  message /= 2;
}

void System::dehash2(long long int  &message){
  message -= 45;
}

void System::dehash3(long long int  &message){
  message = sqrt(message);
}

void System::dehash4(long long int  &message){
  message++;
}

void System::decode(long long int  &message){
  while(!deHashes.empty()){
    (*this.*(deHashes.top()))(message);
    deHashes.pop();
  }
  set_message(message);
}
