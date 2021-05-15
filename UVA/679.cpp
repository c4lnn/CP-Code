#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int m;
	cin>>m;
	int k,n;
	while(cin>>k>>n&&k!=-1)
	{
		int t=1;
		for(int i=0;i<k-1;i++)
		{
			if(n%2) t=2*t,n=(n+1)/2;
			else t=2*t+1,n=n/2;
		}
		cout<<t<<endl;
	}
	return 0;
}