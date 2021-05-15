#include<bits/stdc++.h>
using namespace std; 
vector<int>edge[30010],ans;
int in[30010];
priority_queue<int>pq; 
int  main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    int a,b;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            in[i]=0;
        }
        ans.clear();
        while (!pq.empty()) pq.pop();        
        while(m--)
        {
            scanf("%d%d",&a,&b);
            edge[b].push_back(a);
            in[a]++;
        }
        for(int i=1;i<=n;i++)
            if(in[i]==0)
                pq.push(i);
        while(!pq.empty())
        {
            int p=pq.top();
            pq.pop();
            ans.push_back(p);
            for(int i=0;i<edge[p].size();i++)
            {
                int y=edge[p][i];
                in[y]--;
                if(!in[y])
                    pq.push(y);
            }        
        }                
        for(int i=ans.size()-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            if(i==0)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}