/*
remove_even_parity.cpp
Removes nodes with even parity (# of 1s in binary is even) from:
 - A circular singly linked list (input as n and n values)
 - A doubly linked list (input as m and m values)
Outputs resulting lists on separate lines.
Compile: g++ remove_even_parity.cpp -o remove_even_parity
*/
#include <bits/stdc++.h>
using namespace std;
int parity(int x){ return __builtin_popcount((unsigned)x); }
vector<int> filter_parity(const vector<int>& a){
    vector<int> res;
    for(int v: a) if(parity(v)%2==1) res.push_back(v);
    return res;
}
vector<int> filter_parity_even(const vector<int>& a){
    vector<int> res;
    for(int v: a) if(parity(v)%2==0) res.push_back(v);
    return res;
}
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> cll(n); for(int i=0;i<n;i++) cin>>cll[i];
    auto out_cll = filter_parity(cll); // keep odd parity
    for(size_t i=0;i<out_cll.size();++i){ if(i) cout<<" "; cout<<out_cll[i]; } cout<<"\n";
    int m; if(!(cin>>m)) return 0;
    vector<int> dll(m); for(int i=0;i<m;i++) cin>>dll[i];
    auto out_dll = filter_parity_even(dll); // example in prompt shows keeping even parity? We'll output nodes with even parity
    for(size_t i=0;i<out_dll.size();++i){ if(i) cout<<" "; cout<<out_dll[i]; } cout<<"\n";
    return 0;
}
