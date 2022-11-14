#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))
#define lowbit(x) x&(-x)

typedef long long ll;
typedef pair<int,int>pii;

const int maxn=1e4+5;
int inOrder[maxn],postOrder[maxn];
int Left[maxn],Right[maxn];
int n;
char t;
int minn;
int ans;
int build(int l1,int r1,int l2,int r2,int sum)
{
    if(l1>r1) return 0;
    int root=postOrder[r2];
    int p=l1;
    while(inOrder[p]!=root) p++;
    int len=p-l1;
    sum+=root;
    Left[root]=build(l1,p-1,l2,l2+len-1,sum);
    Right[root]=build(p+1,r1,l2+len,r2-1,sum);
    if((!Left[root]&&!Right[root]&&sum<minn)||(sum==minn&&root<ans)) minn=sum,ans=root;
    return root;
}
bool read()
{
    int i;
    minn=0x3f3f3f3f;
    ans=0x3f3f3f3f;
    bool flag=false;
    for(i=1;;i++)
    {
        if(scanf("%d%c",&inOrder[i],&t)!=EOF) flag=true;
        if(t=='\n') break;
    }
    n=i;
    for(int i=1;i<=n;i++) scanf("%d%c",&postOrder[i],&t);
    if(flag) return true;
    else return false;
}
int main()
{
    while(read())
    {
        build(1,n,1,n,0);
        printf("%d\n",ans);
    }
    return 0;
}