#include<bits/stdc++.h>
using namespace std;


void abbr(string s,string ans,int count){
    if(s.length()==0){
        if(count==0){
            cout << ans << endl;
        }
        else{
            cout << ans+to_string(count) << endl;
        }
        return;
    }
    //if char agrees to come in ans
    if(count==0){
        abbr(s.substr(1),ans+s[0],count);
    }
    else{
        abbr(s.substr(1),ans+to_string(count)+s[0],0);
    }
    //if char dosnt agree to come in ans
    abbr(s.substr(1),ans,count+1);
}


int main(){
    string s;
    cin>>s;
    abbr(s,"",0);
}