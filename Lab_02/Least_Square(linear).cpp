#include<iostream>
using namespace std;

int main(){
	int x[10],y[10],i,n,xy[10],sqrx[10];
	float a,b,sumx=0,sumy,sum_sqrx,sumxy;

	
	cout<<"Enter the number of elements in the array :";
	cin>>n;
	
	for(i=0;i<n;i++){
		cout<<"x["<<i<<"] :";
		cin>>x[i];
		cout<<"y["<<i<<"] :";
		cin>>y[i];
	}
	cout<<"x\t"<<"y\t"<<"x^2\t"<<"x*y\n";
	for(i=0;i<n;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<x[i]*x[i]<<"\t"<<x[i]*y[i]<<endl;
	}
	for(i=0;i<n;i++){
		sumx+=x[i];
		sumy+=y[i];
		sum_sqrx+=x[i]*x[i];
		sumxy+=x[i]*y[i];	
	}
	cout<<"Ex:"<<sumx<<"\t"<<"Ey:"<<sumy<<"\t"<<"Ex^2:"<<sum_sqrx<<"\t"<<"Exy:"<<sumxy<<"\t"<<endl;
	
	b=((n*sumxy)-(sumx*sumy))/((n*sum_sqrx)-(sumx*sumx));
	a=(sumy/n)-(b*sumx/n);
	
	cout<<"The linear eqn is : y ="<<a<<" + "<<b<<"x";
	return 0;
}
