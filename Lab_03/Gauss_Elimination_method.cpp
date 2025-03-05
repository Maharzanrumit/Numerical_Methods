//Write a program to find a solution of linear algebraic equations using Gauss elimination method. 
#include<iostream>
#include<cmath>
using namespace std;

double det(double a1, double a2,double a3,double b1,double b2,double b3,double c1,double c2,double c3){
	
 return (a1 * ((b2 * c3) - (b3 * c2))) - 
           (b1 * ((a2 * c3) - (a3 * c2))) + 
           (c1 * ((a2 * b3) - (a3 * b2)));
}
int main(){
	double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
	double dx,dy,dz,d,x,y,z;
	cout<<"Enter the coeff fo x :";
	cin>>a1>>a2>>a3;
	cout<<"Enter the coeff of y";
	cin>>b1>>b2>>b3;
	cout<<"Enter the coeff of z";
	cin>>c1>>c2>>c3;
	cout<<"Enter the constant";
	cin>>d1>>d2>>d3;
	
	d=det(a1,a2,a3,b1,b2,b3,c1,c2,c3);
	dx=det(d1,d2,d3,b1,b2,b3,c1,c2,c3);
	dy=det(a1,a2,a3,d1,d2,d3,c1,c2,c3);
	dz=det(a1,a2,a3,c1,c2,c3,d1,d2,d3);
	
	x=dx/d;
	y=dy/d;
	z=dz/d;
	
	cout<<"The Solution is x:"<<x<<" y :"<<y<<" z : "<<z;
	return 0;
}
