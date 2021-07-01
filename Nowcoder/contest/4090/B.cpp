#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

bool st[2];
int res;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++) {
        int t=s[i]-'0';
        if(st[t^1]) res++,st[t^1]=false;
        else st[t]=true;
    }
    cout<<res<<endl;
    return 0;
}