#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int arr[21][21][21]; 
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			for(int k=0;k<21;k++)
			{
				if(!i||!j||!k)
					arr[i][j][k]=1;
				else 
					arr[i][j][k]=arr[i-1][j][k]+arr[i-1][j-1][k]+arr[i-1][j][k-1]-arr[i-1][j-1][k-1];
			}
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==-1&&b==-1&&c==-1)
			return 0;
		if(a<=0||b<=0||c<=0)
			printf("w(%d, %d, %d) = 1\n",a,b,c);
		else if(a>20||b>20||c>20)
			printf("w(%d, %d, %d) = %d\n",a,b,c,arr[20][20][20]);
		else
			printf("w(%d, %d, %d) = %d\n",a,b,c,arr[a][b][c]);
	}
	return 0;
}