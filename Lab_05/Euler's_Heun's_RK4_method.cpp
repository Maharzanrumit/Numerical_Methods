#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float fun(float a, float b){
    float result1=0;
    result1=a+b;
    return result1;
}
void Rk4(float h,float x,float y,float xn){
     float m1,m2,m3,m4;
     int i=0;
    
    cout<<"\n\nRunge Kutta Method\n";
    while(x !=xn){
	        m1=fun(x,y);
	        m2=fun(x+(h/2),y+(m1*(h/2)));
	        m3=fun(x+(h/2),y+(m2*(h/2)));
	        m4=fun(x+h,y+(m3*(h/2)));
	        y=y+(m1+(2*m2)+(2*m3)+m4)*(h/6);
	        cout<<"Itr :"<<i++<<endl;
	        cout<<"y("<<x+h<<") : "<<setprecision(3)<<y;
	        cout<<endl;
	        x +=h;
    }
}

void Euler(float h, float x, float y,float xn){
	int i=1;
	cout<<"\n\nEulers Method\n";
	while(x !=xn){
		y=y+(h*fun(x,y));
		cout<<"Itr :"<<i++<<endl;
	        cout<<"y("<<x+h<<") : "<<setprecision(3)<<y;
	        cout<<endl;
		x+=h;
	}
}

void Heun(float h, float x, float y, float xn){
	float m1,m2 ;
	int i=0;
	cout<<"\n\nHeuns Method\n";
	while(x !=xn){
		m1=fun(x,y);
		m2=fun(x+h,y+(m1*h));
		y=y+((m1+m2)*(h/2.0));
		cout<<"Itr :"<<i++<<endl;
		cout<<"y("<<x+h<<") : "<<setprecision(3)<<y;
        cout<<endl;
		x+=h;
	}
}
int main() {
    float h,x,y,xn;
   
    cout<<"Enter the value for h :";
    cin>>h;
    cout<<"Initial value for x and y :";
    cin>>x>>y;
    cout<<"Final value for X : ";
    cin>>xn;
    
    Euler(h,x,y,xn);
    Heun(h,x,y,xn);
    Rk4(h,x,y,xn);
    
    return 0;
}
