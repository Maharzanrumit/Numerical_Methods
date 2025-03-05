#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	float xarr[4]={1,2,3,4};
	float fx[4]={2,2.5,5.6,5.9},x=2.73,dx[4],d2x[4],d3x[4],s,h,y;
	
	cout<<"x\t"<<"f(x)\t"<<"dx\t"<<"d2x\t"<<"d3x\n";
	
		for(int i=0;i<3;i++){
		dx[i]=0;
		d2x[i]=0;
		d3x[i]=0;
		}
	
	for(int i=0;i<3;i++){
		dx[i]=fx[i+1]-fx[i];
	}
	
	for(int i=0;i<2;i++){
		d2x[i]=dx[i+1]-dx[i];
	}
	
	for(int i=0;i<1;i++){
		d3x[i]=d2x[i+1]-d2x[i];
	}
	
		
			s=(x-xarr[0])/(xarr[1]-xarr[0]);

	for(int i=0;i<4;i++){
		cout<<xarr[i]<<"\t"<<fx[i]<<"\t"<<dx[i]<<"\t"<<d2x[i]<<"\t"<<d3x[i]<<endl;	
	}	
	cout<<"s:"<<s<<endl;
	
	for(int i=0;i<1;i++){
		y=fx[i]	+(s*dx[i])+(((s*(s-1))/2)*d2x[i]) + (((s*(s-1)*(s-2))/6)*d3x[i]) ;
			}
	cout<<"The value when x:"<<x<<" is "<<setprecision(2)<<y;
	return 0;
	}
