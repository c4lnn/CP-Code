#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

int T,n;
ll a,b;

pll work(int n,ll a)
{   
    if(n==0) return make_pair(0,0);
    ll cnt=1ll<<(2*n-2);
    ll len=1ll<<(n-1);
    pll pos=work(n-1,a%cnt);
    ll t=a/cnt;
    ll x=pos.first,y=pos.second;
    if(t==0) return make_pair(-y,-x);
    else if(t==1) return make_pair(x+len,y);
    else if(t==2) return make_pair(x+len,y-len);
    return make_pair(y+len-1,x-len*2+1);
}
int main()
{
	
    scanf("%d",&T);
    while(T--)
    {
  		scanf("%d%lld%lld",&n,&a,&b);
        pll posA=work(n,a-1);
        pll posB=work(n,b-1);
        ll tx=posA.first-posB.first;
        ll ty=posA.second-posB.second;
        printf("%.0f\n",sqrt(tx*tx+ty*ty)*10);
	} 
    return 0;
}