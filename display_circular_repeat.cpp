/*
display_circular_repeat.cpp
Given a circular linked list, display nodes and repeat head value at the end.
Example:
Input: 20 -> 100 -> 40 -> 80 -> 60 (circular)
Output: 20 100 40 80 60 20
This program reads n followed by n integers and prints the required output.
Compile: g++ display_circular_repeat.cpp -o display_circular_repeat
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==0) return 0;
    for(int x: a) cout<<x<<" ";
    cout<<a[0]<<"\n";
    return 0;
}
