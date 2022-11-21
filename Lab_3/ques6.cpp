#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))

float simpson(float a, float b){
    float h=(b-a)/3;
    float sum = f(a) + f(b);

    for(int i=1; i<=3-1; i++){
        float k = a+i*h;
        sum+=3*f(k);
    }
    return sum*(3*h/8);
}


using namespace std;
int main()
{
 float lower, upper;

 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;

 cout<< endl <<"Required value of integration is: "<<simpson(lower, upper);

 return 0;
}
