#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))

float trap(float a, float b){
    float temp = (f(a)+f(b))/2;
    float res=(b-a)*temp;
    return res;
}

using namespace std;
int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;

 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;

 cout<< endl<<"Required value of integration is: "<<trap(lower, upper)<<endl;

 return 0;
}
