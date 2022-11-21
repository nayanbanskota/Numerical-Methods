#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))
float simpson(float a, float b){
    float h=(b-a)/2;
    float sum =f(a)+4*f((a+b)/2)+f(b);
    return (sum*h)/3;

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
 

 cout<< endl <<"Required value of integration is: "<<simpson(lower, upper);

 return 0;
}
