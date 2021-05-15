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

char c;
int p;
int q[16];
int get(int x)
{
	int res=(1<<(x+4)%16)+(1<<(x+8)%16)+(1<<(x+12)%16)+(1<<(x+16)%16);
	if(x%4==0) res+=(1<<x+1)+(1<<x+2)+(1<<x+3);
	else if(x%4==1) res+=(1<<x+1)+(1<<x+2)+(1<<x-1);
	else if(x%4==2)	res+=(1<<x+1)+(1<<x-2)+(1<<x-1);
	else if(x%4==3)	res+=(1<<x-3)+(1<<x-2)+(1<<x-1);
	return res;
}
int main()
{
	for(int i=0;i<16;i++) q[i]=get(i);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			cin>>c;
			if(c=='+') p|=1<<((i-1)*4+j-1);
		}
	pii res;
	res.first=0x3f3f3f3f;
	for(int i=0;i<1<<16;i++)
	{
		int t=p;
		int cnt=0;
		for(int j=0;j<16;j++) if(i>>j&1) t^=q[j],cnt++;
		if(t==0) if(cnt<res.first) res.first=cnt,res.second=i;	
	}
	cout<<res.first<<endl;
	for(int i=0;i<16;i++) if(res.second>>i&1) cout<<i/4+1<<" "<<i%4+1<<endl; 
    return 0;
}