/*1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n. Don't change the signature of power function.
*/

#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n==0){
        return 1;
    }
    
    int smallAns = powerLogarithmic(x,n/2);
    int ans=smallAns*smallAns;
    if(n%2){
        return x*ans;
    }
    else{
        return ans;
    }
    
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}