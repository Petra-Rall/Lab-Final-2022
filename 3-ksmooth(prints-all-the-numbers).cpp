#include<iostream>
#include<vector>
using namespace std;

int main(){

    int k, x, count, count2, count3;
    cout << "Enter prime factor k: " << endl;
    cin >> k;

    vector<int> prime, rem, final;
    for(int i=k+1; i<100; i++){
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

    cout << endl;
    
    for(int i=1; i<=100; i++){
        count2=0;
        for(int num: prime){
            if(i%num==0){
                count2++;
            }
        }
        if(count2!=0){
            rem.push_back(i);
        }
   }

    for(int i=1; i<=100; i++){
        count3=0;
        for(int num: rem){
            if(i==num){
                count3++;
            }
        }
        if(count3==0){
            final.push_back(i);
        }
    }

    cout << "The k-smooth numbers are: " << endl;

    for(int num: final){
        cout << num << ",";
    }
 

    return 0;
}
