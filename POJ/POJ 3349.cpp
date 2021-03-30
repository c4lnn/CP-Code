#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e5+5;
const int mod=99991;
int n;
int cnt;
int snow[N][6];
int nxt[N],head[N];

int H(int *a)
{
    int sum=0,mul=1;
    for(int i=0;i<6;i++)
    {
        sum=(sum+a[i])%mod;
        mul=(ll)mul*a[i]%mod;
    }
    return (sum+mul)%mod;
}
bool eq(int *a,int *b)
{
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
        {
            int k;
            for(k=0;k<6;k++) if(a[(i+k)%6]!=b[(j+k)%6]) break;
            if(k==6) return true;
            for(k=0;k<6;k++) if(a[(i+k)%6]!=b[(j+6-k)%6]) break;
            if(k==6) return true;
        }
    return false;
}
bool insert(int *a)
{
    int val=H(a);
    for(int i=head[val];i;i=nxt[i]) if(eq(a,snow[i])==true) return 1;
    memcpy(snow[++cnt],a,sizeof(int)*6);
    nxt[cnt]=head[val];
    head[val]=cnt;
    return 0;
}
int main()
{
    scanf("%d",&n);
    int p[6];
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<6;j++) scanf("%d",&p[j]);
        if(insert(p)) flag=1;
    }
    if(flag) printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}