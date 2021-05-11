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

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int maxn=1006;
int n;
pii a[maxn];
struct bign
{
    int len;
    int num[4050];
    bign()
    {
        len=1;
        memset(num,0,sizeof num);
    }
};
bool operator < (bign a,bign b)
{
    if(a.len<b.len) return 1;
    else if(a.len>b.len) return 0;
    else for(int i=a.len;i>=1;i--)
    {
        if(a.num[i]<b.num[i]) return 1;
        else if(a.num[i]>b.num[i]) return 0;
    }
    return 0;
}
bign operator * (bign a,int b)
{
    bign res;
    int x=0;
    for(int i=1;i<=a.len;i++)
    {
        x+=a.num[i]*b;
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(x)
    {
        res.num[res.len++]=x%10;
        x/=10;
    }
    if(res.len>1) res.len--;
    return res;
}
bign operator / (bign a,int b)
{
    bign res,zero;
    int x;
    for(int i=a.len,t=0;i>=1;i--)
    {
        t=t*10+a.num[i];
        x=t/b;
        if(res.len!=1||x) res.num[res.len++]=x;
        t%=b;
    }
    res.len--;
    reverse(res.num+1,res.num+1+res.len);
    return res;
}
bign get(int x)
{
    bign res;
    for(int i=1;x;i++)
    {
        res.num[i]=x%10;
        x/=10;
        if(i>=2) res.len++;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second),a[i].first*=a[i].second;
    sort(a+1,a+1+n);
    bign ans,res,product=get(a[0].first/a[0].second);
    for(int i=1;i<=n;i++)
    {
        res=product/a[i].second;
        product=product*(a[i].first/a[i].second);
        if(ans<res) ans=res;
    }
    for(int i=ans.len;i>=1;i--) printf("%d",ans.num[i]);
    return 0;
}