#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    string ans="";
    int len=s.length();
    for(int i=0;i<len;i++) ans=max(ans,s.substr(i,len-i));
    cout<<ans<<endl;
    return 0;
}