/*1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
13 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.
*/
#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // write your code here
    if(str.length()==0){
        cout << asf << endl;
        return;
    }
    else if(str.length()==1){
        if(str[0]=='0'){
            return;
        }
        else{
            
            char c = str[0];
            char code = char((c-'0')+'a'-1);
            asf = asf+code;
            cout << asf << endl;
            return;
        }
    }
    else{
        char c = str[0];
        string smallstr1 = str.substr(1);
        
        if(c=='0'){
            return;
        }
        else{
            char code = char((c-'0')+'a'-1);
            printEncoding(smallstr1,asf+code);
        }
        string s = str.substr(0,2);
        
        string smallstr2 = str.substr(2);
        
        int toint = stoi(s);
        if(toint<=26){
            char code = char(toint+'a'-1);
            printEncoding(smallstr2,asf+code);
        }
    }
    
    
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}