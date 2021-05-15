#include<iostream>
#include<cstring>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

int n;
int a[12]={0,1};
int vis[105];
int ans;

bool dfs(int cur,int end)
{
    if(cur==end+1)
    {
        if(a[end]==n) return true;
        else return false;
    }
    for(int i=cur-1;i>=1;i--)
        for(int j=cur-1;j>=i;j--)
        {
            if(a[i]+a[j]>a[cur-1]&&!vis[a[i]+a[j]])
            {
                a[cur]=a[i]+a[j];
                vis[a[cur]]=1;
                if(dfs(cur+1,end)) return true;
                vis[a[cur]]=0;
            }
        }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    while(cin>>n&&n)
    {
        for(int i=1;i<=10;i++)
        {
            memset(vis,0,sizeof vis);  
            if(dfs(2,i)){ans=i;break;}
        }
        for(int i=1;i<=ans;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}