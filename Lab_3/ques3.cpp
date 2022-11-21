#include<iostream>
#include<math.h>
#define f(x) 1/(1+pow(x,2))

float trap(float a, float b, float n){
    float sum=0;
    float h = (b-a)/n;
    float integ = f(a)+f(b);
    for(int i=1; i<=n-1; i++){
        float steps = a+i*h;
        sum += 2*f(steps);
    }
    integ = (integ+sum)*(h/2);
    return integ;
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
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 cout<< endl<<"Required value of integration is: "<< integration<<endl<<trap(lower, upper, subInterval);

 return 0;
}
