#include<iostream>
#include<vector>
using namespace std;

int kSmooth(int x, int k){

    int count, count2=0;

    vector<int> prime;
    for(int i=k+1; i<x; i++){
        count = 0;
        for(int j=2; j<=i/2; j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==0){
            prime.push_back(i);
        }
    }

    for(int num: prime){
        if(x%num==0){
            count2++;
        }
    }


    if(count2==0){
        return 1;
    }
    else{
        return 0;
    }



}

    int main(){

    cout << "If k-smooth:1" << endl;
    cout << "If not k-smooth:0" << endl << endl;

    int x, k;
    cout << "Enter prime factor k: " << endl;
    cin >> k;
    cout << "Enter number: " << endl;
    cin >> x;

    cout << endl << "Result:" << kSmooth(x, k) << endl;

    return 0;
}
