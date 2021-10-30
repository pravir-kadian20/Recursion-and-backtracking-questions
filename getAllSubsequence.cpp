/*1. You are given a string str.
2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
Use sample input and output to take idea about subsequences.
*/
#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.length()==0){
        vector<string>baseans;
        baseans.push_back("");
        return baseans;
    }
    
    vector<string>smallans = gss(s.substr(1));
    
    vector<string>ans;
    for(int i=0;i<smallans.size();i++){

        ans.push_back(smallans[i]+"");
    }
    for(int i=0;i<smallans.size();i++){
        string st = s[0]+smallans[i];
       
        ans.push_back(st);
    }
    return ans;
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}