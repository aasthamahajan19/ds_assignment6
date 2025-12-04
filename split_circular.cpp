/*
split_circular.cpp
Split a circular linked list into two halves.
Input: n followed by n integers (forming circular list)
Output: first half then second half (each printed as linear list)
If odd, first list gets one extra element.
Compile: g++ split_circular.cpp -o split_circular
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==0) return 0;
    int mid = (n+1)/2;
    for(int i=0;i<mid;i++){
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<"\n";
    for(int i=mid;i<n;i++){
        if(i!=mid) cout<<" ";
        cout<<a[i];
    }
    cout<<"\n";
    return 0;
}
