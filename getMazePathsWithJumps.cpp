/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  //Write your code here
  if(sr==dr  && sc==dc){
      vector<string>base;
      base.push_back("");
      return base;
  }
  else if(sr>dr || sc>dc){
      vector<string>base;
      return base;
  }
  
  
  vector<string>ans;
  for(int i=1;i<=dc;i++){
      vector<string>smallans1 = get_maze_paths(sr,sc+i,dr,dc);
      for(int j=0;j<smallans1.size();j++){
          ans.push_back("h"+to_string(i)+smallans1[j]);
      }
  }
  for(int i=1;i<=dr;i++){
      vector<string>smallans1 = get_maze_paths(sr+i,sc,dr,dc);
      for(int j=0;j<smallans1.size();j++){
          ans.push_back("v"+to_string(i)+smallans1[j]);
      }
  }
  for(int i=1;i<=max(dr,dc);i++){
      vector<string>smallans1 = get_maze_paths(sr+i,sc+i,dr,dc);
      for(int j=0;j<smallans1.size();j++){
          ans.push_back("d"+to_string(i)+smallans1[j]);
      }
  }
  return ans;
  
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}