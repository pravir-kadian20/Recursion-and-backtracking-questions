/*1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
Use sample input and output to take idea about output.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n) {
  //Write your code here
  if(n==0){
      vector<string>base;
      base.push_back("");
      return base;
  }
  else if(n<0){
      vector<string>base;
      return base;
  }
  
  
  vector<string>smallans1 = get_stair_paths(n-1);
  vector<string>smallans2 = get_stair_paths(n-2);
  vector<string>smallans3 = get_stair_paths(n-3);
  
  vector<string>ans;
  
  for(int i=0;i<smallans1.size();i++){
      ans.push_back("1"+smallans1[i]);
  }
  for(int i=0;i<smallans2.size();i++){
      ans.push_back("2"+smallans2[i]);
  }
  for(int i=0;i<smallans3.size();i++){
      ans.push_back("3"+smallans3[i]);
  }
  
  return ans;
  
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = get_stair_paths(n);
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