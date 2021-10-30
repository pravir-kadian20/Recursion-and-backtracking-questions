
/*1. You are given a positive number n. 
2. You are required to print the counting from n to 1 and back to n again.
3. You are required to not use any loops. Complete the body of pdi function to achieve it. Don't change the signature of the function.
*/


#include<iostream>
using namespace std;

void printIncDec(int n){
    // write your code here
    if(n==0) return;
    
    cout << n << endl;
    printIncDec(n-1);
    cout << n << endl;
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}
