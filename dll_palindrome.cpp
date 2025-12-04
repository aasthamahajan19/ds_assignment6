/*
dll_palindrome.cpp
Check if a doubly linked list of characters is palindrome.
Input: n followed by n characters (space separated or continuous letters)
Output: True or False
Compile: g++ dll_palindrome.cpp -o dll_palindrome
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<char> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0, r=n-1;
    bool ok=true;
    while(l<r){
        if(v[l]!=v[r]){ ok=false; break; }
        l++; r--;
    }
    cout<<(ok?"True\n":"False\n");
    return 0;
}
