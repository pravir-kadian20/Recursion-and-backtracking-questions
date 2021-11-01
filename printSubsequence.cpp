/*1. You are given a string str.
2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.
*/

#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    
    if(ques==""){
        cout << ans << endl;
        return;
    }
    
    char c = ques[0];
    string smallstr = ques.substr(1);
    
    printSS(smallstr,ans+c);
    printSS(smallstr,ans);
    
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}