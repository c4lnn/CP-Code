#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<int>edge[205];
int in[205];
int ans[205];
int  main()
{
    int t;
    cin>>t;
    int n,m;
    int a,b;
    while(t--)
    {
        cin>>n>>m;
        int cnt=n;
        for(int i=0;i<=n;i++)
            edge[i].clear();
        memset(in,0,sizeof(in));
        memset(ans,0,sizeof(ans));
        priority_queue<int>pq;
        while(m--)
        {
            cin>>a>>b;
            edge[b].push_back(a);
            in[a]++;
        }
        for(int i=1;i<n+1;i++)
            if(in[i]==0)
                pq.push(i);
        while(!pq.empty())
        {
            int p=pq.top();
            pq.pop();
            ans[p]=cnt--;
            for(int i=0;i<edge[p].size();i++)
            {
                int y=edge[p][i];
                in[y]--;
                if(!in[y])
                    pq.push(y);
            }
        }
        if(cnt==0)
            for(int i=1;i<=n;i++)
            {
                cout<<ans[i];
                if(i==n)
                    cout<<endl;
                else
                    cout<<" ";
            }
        else
            cout<<-1<<endl;
    }
    return 0;
}