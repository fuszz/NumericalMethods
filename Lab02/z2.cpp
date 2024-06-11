#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double norma_euklidesowa(vector<double> v1, vector<double> v2){
    double suma=0;
    for(int i=0; i<v1.size(); i++){
        suma += pow((v1[i]-v2[i]), 2);
    }
    return sqrt(suma);
}

double norma_maksymalna(vector<double> v1, vector<double> v2){
    double maks=0;
    for(int i=0; i<v1.size(); i++){
        if (maks<abs(v1[i]-v2[i])){
            maks=abs(v1[i]-v2[i]);
        }}
    return maks;
}

double norma_manhattan(vector<double> v1, vector<double> v2){
    double suma=0;
    for(int i=0; i<v1.size(); i++){
        suma+=abs(v1[i]-v2[i]);
    }
    return suma;
}

double norma_rzeka(vector<double> v1, vector<double> v2){
    if (v1.size()>2){
        return -1;
    }
    
    if(v1[1]==v2[1]){
        return norma_euklidesowa(v1, v2);
    }
    
    else{
        vector<double> c1 = {v1[0], 0};
        vector<double> c2 = {v2[0], 0};
        return norma_euklidesowa(v1, c1) + norma_euklidesowa(c1, c2) + norma_euklidesowa (c2, v2);
    }
}

double norma_kolejowa(vector<double> v1, vector<double> v2){
    double epsilon = 0.00002;
    if(abs(v1[0]*v2[1] - v1[1]*v2[0]) < epsilon) {
        return norma_euklidesowa(v1, v2);
    }
    else{
        vector<double> poczatek = {0,0};
        return norma_euklidesowa(v1, poczatek) + norma_euklidesowa(poczatek, v2);
    }
}

int main(){
    vector<double> v1 = {1, 1};
    vector<double> v2 = {3, 2};

    cout<<"Norma euklidesowa "<<norma_euklidesowa(v1, v2)<<endl;
    cout<<"Norma maksymalna: "<<norma_maksymalna(v1, v2)<<endl;
    cout<<"Norma Manhattan "<<norma_manhattan(v1, v2)<<endl;
    cout<<"Norma rzeka "<<norma_rzeka(v1, v2)<<endl;
    cout<<"Norma kolejowa "<<norma_kolejowa(v1, v2)<<endl;
    return 0;
}

