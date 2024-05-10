#include<iostream>
#include<fstream>
#include<map>
#include<iomanip>
using namespace std;

int main(){

    string st;
    float day, temp, hum, rain;
    int district;
    map<int, float> tempMap, humMap, rainMap;
    map<int, float> countMap;

    ifstream infile("4-data.txt");
    if(!infile.is_open()){
        cout << "Error while opening data.txt" << endl;
    }
    else{
        while(infile >> district >> day >> temp >> hum >> rain ){
            if(tempMap.find(district)==tempMap.end()){
                tempMap.insert({district, temp});
            }
            else{
                tempMap[district]+=temp;

            }

            if(humMap.find(district)==humMap.end()){
                humMap.insert({district, hum});
            }
            else{
                humMap[district]+=hum;
            }

            if(rainMap.find(district)==rainMap.end()){
                rainMap.insert({district, rain});
            }
            else{
                rainMap[district]+=rain;
            }
            countMap[district]++;
        }
    }
    infile.close();

    for(auto it=tempMap.begin(); it!=tempMap.end(); ++it){
            (*it).second/=countMap[(*it).first];
    }
    
    for(auto it=humMap.begin(); it!=humMap.end(); ++it){
        (*it).second/=countMap[(*it).first];
    }

    for(auto it=rainMap.begin(); it!=rainMap.end(); ++it){
        (*it).second/=countMap[(*it).first];
    }

    
    ofstream outfile1("4-temperature.txt");
    if(!outfile1.is_open()){
        cout << "Error while opening data.txt" << endl;
    }
    else{
        outfile1 << "District" << "\t" << "Average Temperature(degree Celsius)" << endl;
        for(auto it=tempMap.begin(); it!=tempMap.end(); ++it){
            outfile1 << (*it).first << "\t\t\t\t\t\t" << (*it).second << fixed << setprecision(2) << endl;
        }
    }
    outfile1.close();

    ofstream outfile2("4-humidity.txt");
    if(!outfile2.is_open()){
        cout << "Error while opening data.txt" << endl;
    }
    else{
        outfile2 << "District" << "\t" << "Average Humidity(%)" << endl;
        for(auto it=humMap.begin(); it!=humMap.end(); ++it){
            outfile2 << (*it).first << "\t\t\t\t" << (*it).second << fixed << setprecision(2) << endl;
        }
    }
    outfile2.close();

    ofstream outfile3("4-rain.txt");
    if(!outfile3.is_open()){
        cout << "Error while opening data.txt" << endl;
    }
    else{
        outfile3 << "District" << "\t" << "Average rain(cm)" << endl;
        for(auto it=rainMap.begin(); it!=rainMap.end(); ++it){
            outfile3 << (*it).first << "\t\t\t\t" << (*it).second << fixed << setprecision(2) << endl;
        }
    }
    outfile3.close();

    return 0;
}