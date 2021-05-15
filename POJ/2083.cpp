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
char a[1000][1000];
int Pow[]={1,3,9,27,81,243,729};

void work(int x,int i,int j)
{
	if(x==1){a[i][j]='X';return;}
	else 	
	{
		x--;
		work(x,i,j);
		work(x,i,j+Pow[x-1]*2);
		work(x,i+Pow[x-1],j+Pow[x-1]);
		work(x,i+2*Pow[x-1],j);
		work(x,i+2*Pow[x-1],j+2*Pow[x-1]);
	}
} 
int main()
{
	int n;
	while(~scanf("%d",&n)&&n!=-1)
	{
		work(n,1,1);
		for(int i=1;i<=Pow[n-1];i++) 
		{
			for(int j=1;j<=Pow[n-1];j++)
			{
			    if(a[i][j]=='X') cout<<a[i][j];
			    else cout<<" ";
		    }
			cout<<endl;
		}
		cout<<"-"<<endl;
	}		
    return 0;
}