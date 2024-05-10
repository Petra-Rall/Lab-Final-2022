#include<iostream>
#include<set>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;

int main(){

    int n, x, count=0, count2=0, largeprime=0;
    set<int> input, prime, comp;
    vector<int> v;
    do{
        cout << "Enter the number of inputs(has to be even and between 5 to 1000): " << endl;
        cin >> n;
    }while(n%2!=0 || n<5 || n>1000);

    cout << "Enter the numbers: " << endl;
    for(int i=1; i<=n; i++){
        cin >> x;
        input.insert(x);
    }

    for(int num: input){
        count=0;
        for(int i=2; i<=num/2; i++){
            if(num%i==0){
                count++;
                break;
            }
        }
        if(count==0){
            prime.insert(num);
        }
    }

    for(int num: input){
        count2=0;
        for(int num2: prime){
            if(num==num2){
                count2++;
                break;
            }
        }
        if(count2==0){
            comp.insert(num);
        }
    }
    cout << endl << "Prime Numbers: ";

    for(int num: prime){
        cout << num << ",";
        if(num>largeprime){
            largeprime=num;
        }
    }

    cout << endl<< "Composite Numbers: ";

    for(int num: comp){
        cout << num << ",";
        v.push_back(num);
    }

    //median composit method 1:
    auto mediancomp = comp.begin();
    advance(mediancomp, comp.size()/2);

    //median composite method 2:
    int mc=0;
    for(size_t s=0; s<v.size(); ++s){
        mc=((v[s]<mc && v[s+1]>mc) || (v[s]>mc && v[s+1]<mc))?mc:((mc<v[s] && v[s+1]>v[s]) || (mc>v[s] && v[s+1]<v[s]))?v[s]:v[s+1];
    }

    cout << endl << "Largest Prime Number: " << largeprime << endl;
    cout << "Median Composite Number(Method 1): " << *mediancomp << endl;
    cout << "Median Composite Number(Method 2): " << mc << endl;
    cout << "Absolute Difference: " << abs(largeprime - *mediancomp) << endl << endl;
    return 0;
}