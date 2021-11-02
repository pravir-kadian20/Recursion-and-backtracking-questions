/*1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.
*/
#include<iostream>

#include<vector>

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, string asf,vector<vector<bool>> visited) {
//write your code here
    
    if(sr>=maze.size() || sc>=maze[0].size()|| sr<0 || sc<0 || visited[sr][sc]==true || maze[sr][sc]==1){
        return;
    }
    
    if(sr==maze.size()-1 && sc==maze[0].size()-1){
        cout << asf << endl;
        return;
    }
    
    
    
    visited[sr][sc]=true;
    floodfill(maze,sr-1,sc,asf+"t",visited);
    floodfill(maze,sr,sc-1,asf+"l",visited);
    floodfill(maze,sr+1,sc,asf+"d",visited);
    floodfill(maze,sr,sc+1,asf+"r",visited);
    visited[sr][sc]=false;
    
    
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
    
    
  
  vector<vector<bool>>visited(n,vector<bool>(m));
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          visited[i][j]=false;
      }
  }
  floodfill(arr, 0, 0, "",visited);
}