#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float fun(float,float,float);

int main(){
	float fx,x=0,dfx,nxtx,error;
	int itr=0;
	
	cout<<"Iteration\t"<<"Xn\t\t"<<"f(Xn)\t"<<"df(Xn)\t"<<"Xn+1\t"<<"Error\n";
	do{
		
		fx = exp(-x) - (2.0 * pow(x, 2.0));
		dfx=-exp(-x)-(4*x);
		nxtx=x-(fx/dfx);
		error=abs((nxtx-x)/nxtx);
	
		cout<<"|"<<++itr<<"|\t\t|"<<fixed<<setprecision(2)<<x<<"|\t\t|"<<fx<<"|\t|"<<dfx<<"|\t|"<<nxtx<<"|\t|"<<error<<"|\n";
		
		x=nxtx;
	}
	while(error>0.05);
	
	cout<<"Root of the given equation is \t"<<fixed<<setprecision(2)<<nxtx<<endl;
	cout<<"functional value at root("<<x<<")is  "<<fx<<endl;
	cout<<"Required number of iteration is  "<<itr<<endl;
	
	return 0;
}
