#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  //write your code here
  
    if(sos>tar) return;//to stop uncessary rec calls
    
    if(idx==arr.size()){
        if(sos==tar){
            cout << set  <<"."<<endl;
        }
        return;
    }
    
    
    printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+", ",sos+arr[idx],tar);
    printTargetSumSubsets(arr,idx+1,set,sos,tar);
}


int main() {
    int n; cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int no; cin>>no;
        arr.push_back(no);
    }
    int target; cin>>target;
    
    printTargetSumSubsets(arr,0,"",0,target);
}