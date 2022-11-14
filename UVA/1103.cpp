#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m[200][50];
int a[200][200];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int h,w;
int ans;
char ch[6]={'W','A','K','J','S','D'};
void dfs(int x,int y)
{
    if(x<0||y<0||x>=h||y>=w||a[x][y])return;
    a[x][y]=2;
    for(int i=0;i<4;i++)
        dfs(x+dir[i][0],y+dir[i][1]);
}
int find(int x,int y)
{
    a[x][y]=3;
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx>=0&&ty>=0&&tx<h&&ty<w&&a[tx][ty]==1)
            find(tx,ty);
        else if(tx>=0&&ty>=0&&tx<h&&ty<w&&a[tx][ty]==0)
        {
            dfs(tx,ty);
            ans++;
        }
    }
    return ans;
}
int main()
{
    int sum=0;
    char c;
    while(~scanf("%d%d",&h,&w)&&h&&w)
    {
        memset(m,0,sizeof(0));
        memset(a,0,sizeof(0));
        multiset<char>put;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                cin>>c;
                if(c>='0'&&c<='9')m[i][j]=c-'0';
                else if(c>='a'&&c<='f')m[i][j]=c-'a'+10;
            }

        for(int i=0;i<h;i++)
        {
            int t=0;
            for(int j=0;j<w;j++)
            {
                int p=m[i][j];
                for(int k=3;k>=0;k--)
                {
                    a[i][t+k]=p&1;
                    p>>=1;
                }
                t+=4;
            }
        }
        w*=4;
        for(int i=0;i<w;i++)
        {
            if(!a[0][i])
                dfs(0,i);
            if(!a[h-1][i])
                dfs(h-1,i);
        }
        for(int i=0;i<h;i++)
        {
            if(!a[i][0])
                dfs(i,0);
            if(!a[i][w-1])
                dfs(i,w-1);
        }
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(a[i][j]==1)
                {
                    ans=0;
                    int p=find(i,j);
                    put.insert(ch[p]);
                }
        printf("Case %d: ",++sum);
        multiset<char>::iterator it;
        for(it=put.begin();it!=put.end();it++)
            printf("%c",*it);
        cout<<endl;
    }
    return 0;
}