#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int trie[N*31][2];
int cnt;
void insert(int a)
{
    int pre=0;
    for(int i=30;i>=0;i--)
    {
        int now=(a>>i)&1;
        if(!trie[pre][now]) trie[pre][now]=++cnt;
        pre=trie[pre][now];
    }
}
int dfs(int pre,int t,int res)
{
    if(t==-1) return res;
    if(trie[pre][0]&&!trie[pre][1]) return dfs(trie[pre][0],t-1,res);
    else if(!trie[pre][0]&&trie[pre][1]) return dfs(trie[pre][1],t-1,res);
    return min(dfs(trie[pre][0],t-1,res+(1<<t)),dfs(trie[pre][1],t-1,res+(1<<t)));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        insert(a);
    }
    cout<<dfs(0,30,0)<<endl;
    return 0;
}