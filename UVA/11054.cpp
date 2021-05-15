#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		int a;
		ll last=0;
		ll ans=0;
		while(n--)
		{
			cin>>a;
			ans+=abs(last);
			last+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}