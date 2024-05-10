#include<iostream>
using namespace std;

int* invert(int* x, int p, int n){

    for(int i=p-1; i<(p+n-1); i++){
        if(x[i]==1){
            x[i]=0;
        }
        else{
            x[i]=1;
        }
    }
    return x;
}


int main(){

    int r, p, n;
    cout << "Enter binary size:" << endl;
    cin >> r;
    int x[r];
    int* y;
    cout << "Enter bits: " << endl;
    for(int i=0; i<r; i++){
        cin >> x[i];
    }
    cout << "Enter position:" <<endl;
    cin >> p;

    cout << "Enter number of bits:" <<endl;
    cin >> n;

    y = invert(x,p,n);
    for(int i=0; i<r; i++){
    cout << y[i];
    }
    return 0;
}

    
