#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	float xa=0,fxa,xb=-1,fxb,xc,fxc,error;
	int itr=0;
	cout<<"Iteration"<<" Xa\t"<<"f(Xa)\t"<<"Xb\t"<<"f(Xb)\t"<<"Xc\t"<<"f(Xc)\t"<<"Error\n";
	
	do{
		fxa = exp(-xa) - (2.0 * pow(xa, 2.0));
		fxb = exp(-xb) - (2.0 * pow(xb, 2.0));
		
		xc=xb-(((xb-xa)/(fxb-fxa))*fxb);
		fxc = exp(-xc) - (2.0 * pow(xc, 2.0));
		
		error=abs((xc-xb)/xc);
		
	cout<<"|"<<++itr<<"|\t|"<<fixed<<setprecision(2)<<xa<<"|\t|"<<fxa<<"|\t|"<<xb<<"|\t|"<<fxb<<"|\t|"<<xc<<"|\t|"<<fxc<<"|\t|"<<error<<"|\n";
	
	xa=xb;
	fxa=fxb;
	xb=xc;
	fxb=fxc;
	}
	
	while(error>0.05);
	
		cout<<"Root of the given equation is \t"<<fixed<<setprecision(2)<<xc<<endl;
		cout<<"functional value at root("<<xc<<")is  "<<fxc<<endl;
		cout<<"Required number of iteration is  "<<itr<<endl;
		
	return 0;
}
