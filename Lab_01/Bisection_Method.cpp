#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    float fxu, fxl, xu=0, xl=1, xm, prexm, fxm, error=1;
    int itr=0;
    cout<<"Iteration  "<<"xl\t"<<"fxl\t"<<"xu\t"<<"fxu\t"<<"xm\t"<<"fxm\t"<<"Error\n";
    
    cout<<++itr<<"\t"<<xl<<"\t";
    fxl = exp(-xl) - xl;    
    cout<<setprecision(2)<<fxl<<"\t";
    
    cout<<xu<<"\t";    
    fxu = exp(-xu) - xu;
    cout<<fxu<<"\t\t";
    
    xm = (xu + xl) / 2;
    prexm = xm;
    cout<<xm<<"\t";
    
    fxm = exp(-xm) - xm;
    cout<<fxm<<"\n";

    // Use do-while loop to continue until error < 0.05
    do {            
        if (fxm > 0) {
            xu = xm;
            fxu = fxm;
        } else {
            xl = xm;
            fxl = fxm;
        }

        cout<<++itr<<"\t"<<xl<<"\t";
        fxl = exp(-xl) - xl;    
        cout<<setprecision(2)<<fxl<<"\t";
        
        cout<<xu<<"\t";    
        fxu = exp(-xu) - xu;
        cout<<setprecision(2)<<fxu<<"\t";
        
        xm = (xu + xl) / 2;
        cout<<setprecision(2)<<xm<<"\t";
        
        fxm = exp(-xm) - xm;
        cout<<setprecision(2)<<fxm<<"\t";
        
        error = abs((prexm - xm) / xm);
        prexm = xm;
        cout<<fixed<<setprecision(2)<<error<<endl;

        // Check if the error is less than 0.05
        if (error < 0.05) {
            cout<<"The root of the given equation is "<<xm<<endl;
            cout<<"The functional value at root ("<<xm<<") is "<<fxm<<endl;
            cout<<"The number of iterations is "<<itr<<endl;
            break;
        }
    } while (error >= 0.05); // Repeat until error is less than 0.05
    
    return 0;
}

