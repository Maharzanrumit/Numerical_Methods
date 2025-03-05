//Simpsons 1/3 Rule
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float fun(int a){
	return exp(-a);
}

int main(){
		 float I,h,lwr,upr;
		
		cout<<"Enter the upper limit and lower limit :";
		cin>>upr>>lwr;
		
			h=(upr-lwr)/2;
			I=(h/3.0)*(fun(upr)+(4.0*fun(lwr+h))+fun(lwr));
		
		cout<<"The integration of given fx=exp(-x) is "<<setprecision(2)<<I;
		
		
	return 0;
}
