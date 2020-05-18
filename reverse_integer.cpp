//Reverse an integer checking for the maximum and minimum for unsigned int

#include<iostream>
#include<climits>

using namespace std;

int reverseInteger(int x){
    long long res = 0;
    while(x){
        res = res*10 + x%10;
        x/=10;
    }
    return (res< INT_MIN || res>INT_MAX)? 0 : res;
}

int main(){
    int x = 321;
    int y = -123;
    int z = 210;
    cout<<reverseInteger(x)<<" "<<reverseInteger(y)<<" "<<reverseInteger(z)<<endl;
    return 0;
}