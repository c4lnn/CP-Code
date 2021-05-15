#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	int a;
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		int b1=0;
		int b2=0;
		while(n--)
		{
			scanf("%d",&a);
			if(a%3==0) ans++;
			else if(a%3==1) b1++;
			else if(a%3==2) b2++;
		}
		if(b1<b2) ans+=b1,b2-=b1,ans+=b2/3;
		else ans+=b2,b1-=b2,ans+=b1/3;
		printf("%d\n",ans);
	}
	return 0;
}