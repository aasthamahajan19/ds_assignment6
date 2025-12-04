/*
correct_random_pointer.cpp
This program demonstrates correcting one incorrect random pointer in a doubly linked list.
Input:
n
n integers (values)
n integers (random indices for each node, -1 means null). Exactly one entry is incorrect and should point to its expected node index:
We define "expected" as: node at index i should random-point to index (i+1)%n (for demonstration).
This program finds the node whose random pointer does not match expected and fixes it.
Output: the corrected random indices (space separated)
Compile: g++ correct_random_pointer.cpp -o correct_random_pointer
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> val(n);
    for(int i=0;i<n;i++) cin>>val[i];
    vector<int> rnd(n);
    for(int i=0;i<n;i++) cin>>rnd[i];
    for(int i=0;i<n;i++){
        int expected = (i+1)%n;
        if(rnd[i]!=expected){
            rnd[i]=expected;
            break;
        }
    }
    for(int i=0;i<n;i++){ if(i) cout<<" "; cout<<rnd[i]; } cout<<"\n";
    return 0;
}
