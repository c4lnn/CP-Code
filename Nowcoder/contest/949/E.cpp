#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)
typedef pair<int,int>pii;
int n;
int m[51][51];
set<int>s;
int dir[2][2]={{1,0},{0,1}};
void dfs(int x,int y,int sum)
{
    if(x==n&&y==n){s.insert(sum);return;}
    for(int i=0;i<2;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx<=n&&ty<=n) dfs(tx,ty,sum+m[tx][ty]);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&m[i][j]);
    dfs(1,1,m[1][1]);
    printf("%d",s.size());
    return 0;
}