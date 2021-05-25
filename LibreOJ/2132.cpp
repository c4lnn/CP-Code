#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef pair<ll,int> pli;
int main()
{
   // freopen("in.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    priority_queue<pli,vector<pli>,greater<pli> >q;
    for(int i=1;i<=n;i++)
    {
        ll val;
        scanf("%lld",&val);
        q.push({val,0});
    }
    int a=n;
    while((a-1)%(k-1)) q.push({0,0}),a++;
    ll res=0;
    while(q.size()>1)
    {
        ll t=0;
        int depth=0;
        for(int j=1;j<=k;j++)
        {
            t+=q.top().first;
            depth=max(depth,q.top().second);
            q.pop();
        }
        res+=t;
        q.push({t,depth+1});
    }
    printf("%lld\n%d",res,q.top().second);
    return 0;
}