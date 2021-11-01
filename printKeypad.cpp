/*1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map
    0 -> .;
   1 -> abc
   2 -> def
   3 -> ghi
   4 -> jkl
   5 -> mno
   6 -> pqrs
   7 -> tu
   8 -> vwx
   9 -> yz
3. Complete the body of printKPC function - without changing signature - to print the list of all words that could be produced by the keys in str.
*/
#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques==""){
        cout << asf << endl;
        return;
    }
    
    
    
    char c = ques[0];
    
    string roq = ques.substr(1);
    
    string str = codes[c-'0'];
    
    for(int i=0;i<str.length();i++){
        printKPC(roq,asf+str[i]);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}