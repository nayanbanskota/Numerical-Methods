#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))

float simpson(float a, float b, float n){
    float h=(b-a)/n;
    float sum = f(a) + f(b);
    float sumD3 = 0;
    float sumND3 = 0;

    for(int i=1; i<=n-1; i++){
        float k = a+i*h;

        if(i%3==0){
            sumD3 += f(k);
        }
        else{
            sumND3 += f(k);
        }

    }
    return (sum+3*sumND3+2*sumD3)*(3*h/8);
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

 cout<< endl <<"Required value of integration is: "<<simpson(lower, upper, subInterval);

 return 0;
}
