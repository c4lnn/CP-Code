#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n;
int res[N];
bool st[N];

int dfs(int x) {
    if(st[x]) return res[x];
    int cnt=0;
    for(int i=11;i>=0;i--) if((x>>i)&1) cnt++;
    for(int i=11;i>=2;i--) if(((x>>(i-1))&1)&&(((x>>i)&1)^((x>>(i-2))&1))) cnt=min(cnt,dfs(x^(7<<(i-2))));
    st[x]=true;
    return res[x]=cnt;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int lim=(1<<12)-1;
    for(int i=0;i<=lim;i++) if(!st[i]) dfs(i);
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int t=0;
        for(int i=0;i<s.length();i++) if(s[i]=='o') t|=(1<<(11-i));
        cout<<res[t]<<endl;
    }
    return 0;
}