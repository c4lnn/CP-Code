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
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e5+5;

int n;
int h[N],s[N],l[N],r[N];

void get(int *bound)
{
    int top=0;
    h[0]=-1;
    for(int i=1;i<=n;i++)
    {
        while(h[s[top]]>=h[i]) top--;
        bound[i]=s[top];
        s[++top]=i;
    }

}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        get(l);
        reverse(h+1,h+1+n);
        get(r);
        ll res=0;
        for(int i=1,j=n;i<=n;i++,j--) res=max(res,h[i]*(n+1-r[i]-l[j]-1ll));
        printf("%lld\n",res);
    }
    return 0;
}