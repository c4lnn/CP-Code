#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
bool st[N];
int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto c:b) st[c]=true;
    for(auto c:a) if(!st[c]) cout<<c;
    cout<<'\n';
    return 0;
}