/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are required to find the maximum of input. 
4. For the purpose complete the body of maxOfArray function. Don't change the signature.
*/
#include <bits/stdc++.h>
using namespace std;

int maxi(int arr[], int idx, int n){
    // write your code here
    if(idx==n-1){
        return arr[idx];
    }
    return max(arr[idx],maxi(arr,idx+1,n));
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = maxi(arr, 0, n);
    cout << p << endl;
}
