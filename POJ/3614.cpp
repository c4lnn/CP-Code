#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof i)

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int maxn=2505;

int c,l;
set<int>s;
int cnt[maxn];
struct node
{
    int minSPF;
    int maxSPF;
    bool operator < (const node & a) const 
    {
        return maxSPF<a.maxSPF;
    }
}cow[maxn];
int main()
{
    scanf("%d%d",&c,&l);
    int a,b;
    for(int i=1;i<=c;i++) scanf("%d%d",&cow[i].minSPF,&cow[i].maxSPF);
    for(int i=1;i<=l;i++) scanf("%d%d",&a,&b),cnt[a]+=b,s.insert(a);
    sort(cow+1,cow+1+c);
    int res=0;
    for(int i=1;i<=c;i++) 
    {
        set<int>::iterator it=s.lower_bound(cow[i].minSPF);
        while(it!=s.end()&&*it<=cow[i].maxSPF)
        {
            if(cnt[*it]) {cnt[*it]--,res++;break;}
            else it++;
        }
    }
    printf("%d\n",res);
    return 0;
}