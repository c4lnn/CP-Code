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


int id;
int m[1000010];

int main()
{
    int t;
    for(int k=1;;k++)
    {
        scanf("%d",&t);
        if(t==0) break;
        printf("Scenario #%d\n",k);
        queue<int>q[1010];
        for(int i=1;i<=t;i++)
        {
            int x;
            scanf("%d",&x);
            while(x--) scanf("%d",&id),m[id]=i;
        }
        char opt[15];
        while(~scanf("%s",opt)&&opt[0]!='S')
        {
            if(opt[0]=='E')
            {
                scanf("%d",&id);
                int gp=m[id];
                if(q[gp].empty()) q[0].push(gp);
                q[gp].push(id);
            }
            else
            {
               int u=q[0].front();
               printf("%d\n",q[u].front());
               q[u].pop();
               if(q[u].empty()) q[0].pop();
            }
        }
        printf("\n");
    }
    return 0;
}