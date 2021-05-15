#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=22;
int n,m;
int R[N],H[N];
int minV[N],minS[N];
int res=INT_MAX;

void dfs(int depth,int s,int v)
{
    if(minV[depth]+v>n) return;
    if(minS[depth]+s>=res) return;
    if(2*(n-v)/R[depth+1]+s>res) return;
    if(depth==0)
    {
        if(v==n) res=min(res,s);
        return;
    }
    for(int i=min((int)sqrt(n-v),R[depth+1]-1);i>=depth;i--)//r
        for(int j=min((n-v)/(i*i),H[depth+1]-1);j>=depth;j--)//h
        {
            if(minS[depth-1]+2*i*j+s<res)
            {
                R[depth]=i,H[depth]=j;
                dfs(depth-1,depth==m?s+2*i*j+i*i:s+2*i*j,v+i*i*j);
            }
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    for(int i=1;i<=N;i++) minV[i]=minV[i-1]+i*i*i,minS[i]=minS[i-1]+2*i*i;
    cin>>n>>m;
    R[m+1]=H[m+1]=INT_MAX;
    dfs(m,0,0);
    cout<<res<<endl;
    return 0;
}