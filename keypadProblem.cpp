/*1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map :
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
3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


string keypad[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};


vector<string> getKPC(string s) {
  //Write your code here
  if(s.length()==0){
      vector<string>base;
      base.push_back("");
      return base;
  }
  char c = s[0];
  vector<string>smallans = getKPC(s.substr(1));
  vector<string>ans;
  
  for(int i=0;i<keypad[c-'0'].length();i++){
      char ch = keypad[c-'0'][i];
      for(int j=0;j<smallans.size();j++){
          ans.push_back(ch+smallans[j]);
      }
  }
  
  return ans;
  
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}