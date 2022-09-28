#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x*x-2*x-5

void main(){
	float x1,x2,x0,f1,f2,f0,e;
	int n,i;
	printf("Guess the value of x1: ");
	scanf("%f",&x1);
	printf("Guess the value of x2: ");
	scanf("%f",&x2);
	printf("Enter tolerable error: ");
	scanf("%f",&e);
	printf("Enter maximum number of iteration allowed: ");
	scanf("%d",&n);
	
	f1= f(x1);
	f2= f(x2);
	
	if (f1 * f2 > 0.0){
		printf("Root lies between %f and %f",x1,x2);
	}
	else{
		printf("Root doesn't lies between %f and %f",x1,x2);
	}
	
	printf("\nStep\t\tx1\t\tx2\tx0\t\tf(x0)");
	
	while(fabs(f2)>e){
		for(i=0; i<n ;i++){
			x0 = (x1+x2)/2;
			f0 = f(x0);
		
			printf("%d\t\t%f\t%f\t%f\t%f\n",i,x1,x2,x0,f0);
		
			if( f0 * f2 < 0){
			   	x1 = x0;
			   	f1 = f0;
			}
			else{
				x1 = x0;
				f1 = f0;
			}
		}
	}
}
