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

const int N=2e5+5;

int n;
pii a[N];
int top=-1;
int flag;
int res=1;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1,j=i;i<=n;i=j)
    {
        int minn=a[i].second;
        while(a[i].first==a[j].first) j++;
        int maxn=a[j-1].second;
        if(top==-1) top=minn;
        else
        {
            if(flag==0)
            {
                if(maxn>top) top=maxn,flag=1;
                else top=minn;
            }
            else
            {
                if(minn>top) top=maxn;
                else res++,top=minn,flag=0;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}