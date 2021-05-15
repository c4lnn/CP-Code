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

const int N=1e6+5;

int a[N];
int b[N];
int sum[N];
int f[N];
int ta;
int tb;


int main()
{
 
    int q;
    while(~scanf("%d",&q))
    {
        memset(f,0xc0,sizeof f);
        ta=0;
        tb=0;
        for(int i=1;i<=q;i++)
        {
            char opt;
            getchar();
            scanf("%c",&opt);   
            if(opt=='I')
            {
                int x;
                scanf("%d",&x);
                a[++ta]=x;
                sum[ta]=sum[ta-1]+x;
                f[ta]=max(f[ta-1],sum[ta]);
            }
            else if(opt=='D')
            {
                if(ta>0) f[ta--]=0xc0c0c0c0;
            }
            else if(opt=='L')
            {
                if(ta>0)
                {
                    b[++tb]=a[ta];
                    f[ta--]=0xc0c0c0c0;
                }
            }
            else if(opt=='R')
            {
                if(tb>0)
                {
                    a[++ta]=b[tb];
                    sum[ta]=b[tb]+sum[ta-1];
                    f[ta]=max(f[ta-1],sum[ta]);
                    tb--;
                }
            }
            else if(opt=='Q')
            {
                int k;
                scanf("%d",&k);
                printf("%d\n",f[k]);
            }
        }
    } 
    return 0;
}