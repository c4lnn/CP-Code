#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

const int N=1e5+5;

int n;
struct node
{
    int minn=INT_MAX;
    int maxn=-1;
}state[N];
int vis[N];
int cnt_max[N*10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        for(int j=0;j<l;j++)
        {
            int t;
            cin>>t;
            if(vis[i]==0)
            {
                if(t>state[i].minn) vis[i]=1;
                state[i].maxn=max(state[i].maxn,t);
                state[i].minn=min(state[i].minn,t);
            }

        }
        if(vis[i]==0) cnt_max[state[i].maxn]++;
    }
    for(int i=1;i<=1000000;i++) cnt_max[i]+=cnt_max[i-1];
    ll ans=(ll)n*n;
    for(int i=0;i<n;i++) if(vis[i]==0) ans-=cnt_max[state[i].minn];
    cout<<ans<<endl;
    return 0;
}