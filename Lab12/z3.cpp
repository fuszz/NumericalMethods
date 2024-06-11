#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


unsigned int lcg(unsigned int a, unsigned int c, unsigned int m, unsigned int x_n){
    return (a*x_n + c) % m;
}

int dec_to_bin(unsigned int n){
    int count=0;
    while(n){
        if(n%2==1)
        count++;
        n = n/2;
    }
    return count;
}

int main() {
    vector<unsigned int> randoms;
    unsigned int m = (unsigned int)pow(2, 32);
    unsigned int c = 1013904223;
    unsigned int a = 1664525;
    unsigned int elements = 20000;
    randoms.push_back(1);

    for(int i=0; i<elements; i++){
        randoms.push_back(lcg(a, c, m, randoms[randoms.size()-1]));
    }

    //for(int i=0; i<elements; i+=2){
    //    cout<<"<circle r=\"3\" cx=\"" << randoms[i]%1000 << "\" cy=\"" <<randoms[i+1]%1000 << "\" fill=\"red\" />" << endl;
    //}
    int jedynek = 0;
    string bity = "";
    int i=0;

    // while(bity.size()<20000){
    //     bity += dec_to_bin(randoms[i]);
    //     i++;
    // }
    int sum=0;
    for(int i=0; i<20000/32; i++){
        sum+=dec_to_bin(randoms[i]);
    }

    cout<<sum;
    return 0;
}
