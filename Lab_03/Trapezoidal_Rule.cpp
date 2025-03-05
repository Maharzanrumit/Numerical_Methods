//Write a program to calculate integration using Trapezoidal rule. 

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float fun(float a){
	
	return exp(-a);
}

int main(){
		float I, lwr,upr;
		
		cout<<"Enter the upper limit and lower limit :";
		cin>>upr>>lwr;
		I=((upr-lwr)/2.0)*(fun(upr)+fun(lwr));
		
		cout<<"The integration of given fx=exp(-x) is "<<setprecision(2)<<I;
		
		
	return 0;
}
