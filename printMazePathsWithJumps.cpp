/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of printMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
*/

#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        
        if(sr==dr && sc==dc){
            cout << psf << endl;
            return;
        }
        if(sr>dr || sc>dc) return;
        
        for(int i=1;i<=dc;i++){
            printMazePaths(sr,sc+i,dr,dc,psf+"h"+to_string(i));
        }
        
        for(int i=1;i<=dr;i++){
            printMazePaths(sr+i,sc,dr,dc,psf+"v"+to_string(i));
        }
        
        
        for(int i=1;i<=max(dr,dc);i++){
            printMazePaths(sr+i,sc+i,dr,dc,psf+"d"+to_string(i));
        }
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }