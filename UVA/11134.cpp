#include<bits/stdc++.h>
using namespace std;
int j;
struct node
{
    int x;
    int y;
};
struct ret
{
    int id;
    node begin;
    node end;
};
int cmp1(ret a,ret b)
{
    return a.end.x<b.end.x||a.end.x==b.end.x&&a.begin.x<b.begin.x;
}
int cmp2(ret a,ret b)
{

        return a.end.y<b.end.y||a.end.y==b.end.y&&a.begin.y<b.begin.y;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        ret a[n+1];
        node ans[n+1];
        bool vis[n+1];
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            a[i].id=i;
            cin>>a[i].begin.x>>a[i].begin.y>>a[i].end.x>>a[i].end.y;
        }
        memset(vis,false,sizeof(vis));
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++)
        {
            for(j=a[i].begin.x;j<=a[i].end.x;j++)
                if(!vis[j])
                {
                    vis[j]=true;
                    ans[a[i].id].x=j;
                    break;
                }
            if(j>a[i].end.x)
            {
                flag=1;
                break;
            }
        }
        memset(vis,false,sizeof(vis));
        sort(a+1,a+1+n,cmp2);
        for(int i=1;i<=n;i++)
        {
            for(j=a[i].begin.y;j<=a[i].end.y;j++)
                if(!vis[j])
                {
                    vis[j]=true;
                    ans[a[i].id].y=j;
                    break;
                }
            if(j>a[i].end.y)
            {
                flag=1;
                break;
            }
        }
        if(flag) cout<<"IMPOSSIBLE\n";
        else for(int i=1;i<=n;i++) cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
    return 0;
}