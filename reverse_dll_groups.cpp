/*
reverse_dll_groups.cpp
Reverse every group of k nodes in a doubly linked list.
Input:
n k
n integers
Output: resulting list
Compile: g++ reverse_dll_groups.cpp -o reverse_dll_groups
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; if(!(cin>>n>>k)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i+=k){
        int l=i, r=min(n-1,i+k-1);
        while(l<r){ swap(a[l],a[r]); l++; r--; }
    }
    for(int i=0;i<n;i++){ if(i) cout<<" "; cout<<a[i]; } cout<<"\n";
    return 0;
}
