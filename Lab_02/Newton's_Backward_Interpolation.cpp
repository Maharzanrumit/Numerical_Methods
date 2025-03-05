#include<iostream>
using namespace std;

int main(){
	float xarr[4]={1,2,3,4};
	float fx[4]={2,2.5,5.6,5.9},x=2.73,dx[4],d2x[4],d3x[4],s,h,y,dfxn,d2fxn,d3fxn;
	
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
	
		for(int i=3;i>2;i--){
			s=(x-xarr[i])/(xarr[i]-xarr[i-1]);
		}

	for(int i=0;i<4;i++){
		cout<<xarr[i]<<"\t"<<fx[i]<<"\t"<<dx[i]<<"\t"<<d2x[i]<<"\t"<<d3x[i]<<endl;	
	}	
	cout<<"s:"<<s<<endl;
	
	cout<<"Enter from the table:\n";
	cout<<"dfx(n):";
	cin>>dfxn;
	cout<<"d2fx(n):";
	cin>>d2fxn;
	cout<<"d3fx(n):";
	cin>>d3fxn;
	
	
	for(int i=3;i>2;i--){
		y=fx[i]	+(s*dfxn)+(((s*(s+1))/2)*d2fxn) + (((s*(s+1)*(s+2))/6)*d3fxn) ;
			}
	cout<<"The value when x:"<<x<<" is "<<y;
	return 0;
	}
  
