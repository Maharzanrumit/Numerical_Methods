/*non-linear y=a*x^b */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int i,n;
	float x[10],y[10],a,b,sum_lnx=0,sum_lny,sum_lnxlny,sum_sqr_lnx;

	
	cout<<"Enter the number of elements in the array :";
	cin>>n;
	
	for(i=0;i<n;i++){
		cout<<"x["<<i<<"] :";
		cin>>x[i];
		cout<<"y["<<i<<"] :";
		cin>>y[i];
	}
	cout<<"x\t"<<"y\t"<<"ln(x)\t"<<"ln(y)\t"<<"ln(x)*ln(y)\t"<<"(ln(x))^2\n";
	for(i=0;i<n;i++){
		cout<<fixed<<setprecision(3)<<x[i]<<"\t"<<y[i]<<"\t"<<log(x[i])<<"\t"<<log(y[i])<<"\t"<<log(x[i])*log(y[i])<<"\t\t"<<pow(log(x[i]),2)<<endl;
	}
	for(i=0;i<n;i++){
		sum_lnx+=log(x[i]);
		sum_lny+=log(y[i]);
		sum_lnxlny+=log(x[i])*log(y[i]);
		sum_sqr_lnx+=pow(log(x[i]),2);
	}
	cout<<"\t\tElnx:"<<sum_lnx<<"\t"<<"Elny:"<<sum_lny<<"\t"<<"Elnx*lny:"<<sum_lnxlny<<"\t"<<"E(lnx)^2:"<<sum_sqr_lnx<<"\t"<<endl;
	
	b=((n*sum_lnxlny)-(sum_lnx*sum_lny))/((n*sum_sqr_lnx)-(sum_lnx*sum_lnx));
	a=exp((sum_lny/n)-(b*sum_lnx/n));
	
	cout<<"The linear eqn is : y ="<<a<<"*x^"<<b;
	return 0;
}
