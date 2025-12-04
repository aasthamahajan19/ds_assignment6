/*
is_circular_check.cpp
Simple check whether a linked list (given as values ending with -1) is circular.
Because we cannot build a truly circular input from textual stdin easily,
this program demonstrates a simple pointer-traversal detection (Floyd's cycle-finding)
on an explicitly constructed list where user may specify next indices.
To keep things simple for automated testing, we ask:
n (number of nodes)
then n values
then n integers specifying next index for each node (-1 for null, or 0..n-1 for circular links)
Output: True if circular, False otherwise
Compile: g++ is_circular_check.cpp -o is_circular_check
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{ int val; int next; Node(int v=0,int n=-1):val(v),next(n){} };
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<Node> a(n);
    for(int i=0;i<n;i++) cin>>a[i].val;
    for(int i=0;i<n;i++) cin>>a[i].next; // -1 or 0..n-1
    int slow = 0, fast = 0;
    if(n==0){ cout<<"False\n"; return 0; }
    auto advance = [&](int idx)->int{ if(idx<0 || idx>=n) return -1; return a[idx].next; };
    slow = advance(0);
    fast = advance(advance(0));
    while(slow!=-1 && fast!=-1 && slow!=fast){
        slow = advance(slow);
        fast = advance(advance(fast));
    }
    cout<<((slow!=-1 && fast!=-1 && slow==fast)?"True\n":"False\n");
    return 0;
}
