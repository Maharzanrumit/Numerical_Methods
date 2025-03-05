//Write a program to evaluate integration of a function using Gauss integration algorithm.
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

float fun(float a){
	return exp(a);
}

int main(){
	float lwr,upr,I;
	int choice;
	string ch="y";
	
	
	
	while(ch=="y"){
	
		cout<<"1.For n=2\n";
		cout<<"2.For n=3\n";
		cout<<"Enter the choice:";
		cin>>choice;
		
		while(choice==1){
			float w1,w2,x1,x2;
			w1=1.0;
			w2=1.0;
			x1=-1.0/sqrt(3.0);
			x2=1.0/sqrt(3.0);
			
			I=(w1*fun(x1))+(w2*fun(x2));
			cout<<"The intergated value  for exp(x) with upr :1 lwr :-1 is "<<setprecision(3)<<I;
			break;
		}
			
		while(choice==2){
			float w1,w2,w3,x1,x2,x3;
			w1=5.0/9.0;
			w2=8.0/9.0;
			w3=5.0/9.0;
			x1=-sqrt(3.0/5.0);
			x2=0.0;
			x3=sqrt(3.0/5.0);
			
			I=(w1*fun(x1))+(w2*fun(x2)+(w3*fun(x3)));
			cout<<"The intergated value  for exp(x) with upr :1 lwr :-1"<<" is "<<setprecision(3)<<I;
			break;
		}
		
		cout<<"\nWant to continue (y/n) :";
		cin>>ch;
	}
	return 0;
}
