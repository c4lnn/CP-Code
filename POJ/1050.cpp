#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

int s[105][105];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&s[i][j]);
            s[i][j]+=s[i-1][j];
        }
    int res=INT_MIN;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int last=0;
            for(int k=1;k<=n;k++)
            {
                last=max(last,0)+s[j][k]-s[i-1][k];
                res=max(res,last);
            }
        }
    printf("%d",res);
    return 0;
}