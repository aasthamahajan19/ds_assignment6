/*
matrix_to_4ptr_dll.cpp
Convert a 2D matrix to nodes with four pointers: next (right), prev (left), up, down.
We will print each node's neighbors by indices for demonstration.
Input:
r c
r*c integers (row-major)
Output:
For each cell i (0..r*c-1) print: val left_idx right_idx up_idx down_idx
(-1 if absent)
Compile: g++ matrix_to_4ptr_dll.cpp -o matrix_to_4ptr_dll
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c; if(!(cin>>r>>c)) return 0;
    vector<int> a(r*c);
    for(int i=0;i<r*c;i++) cin>>a[i];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int idx = i*c + j;
            int left = (j-1>=0)? idx-1 : -1;
            int right = (j+1<c)? idx+1 : -1;
            int up = (i-1>=0)? (i-1)*c + j : -1;
            int down = (i+1<r)? (i+1)*c + j : -1;
            cout<<a[idx]<<" "<<left<<" "<<right<<" "<<up<<" "<<down<<"\n";
        }
    }
    return 0;
}
