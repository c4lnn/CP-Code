#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((j&1)==0) printf("%d ",n*(n-j)-i);
			else printf("%d ",n*(n-j-1)+1+i);
		}
		printf("\n");
	}
	return 0;
}