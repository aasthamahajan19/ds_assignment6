/*
size_dll_cll.cpp
Two small implementations:
 - Size of Doubly Linked List from input
 - Size of Circular Linked List from input
Input format:
First line: m (size of DLL) then m integers
Next line: n (size of CLL) then n integers
Output: two lines with sizes
Compile: g++ size_dll_cll.cpp -o size_dll_cll
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m; if(!(cin>>m)) return 0;
    for(int i=0, x;i<m;i++) cin>>x;
    cout<<m<<"\n";
    int n; if(!(cin>>n)) return 0;
    for(int i=0, x;i<n;i++) cin>>x;
    cout<<n<<"\n";
    return 0;
}
