#include<bits/stdc++.h>
using namespace std;
char a[21][21];
int v[21][21];
int w,h;
int cnt;
void dfs(int x,int y)
{
    if(x<0||y<0||x>=h||y>=w||a[x][y]=='#'||v[x][y])
        return;    
    else
    {
        v[x][y]=++cnt;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }

}
int main()
{
    int m,n;
    while(cin>>w>>h&&w&&h)
    {
        memset(v,0,sizeof(v));
        cnt=0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='@')
                {
                    m=i;
                    n=j;
                }
            }
        dfs(m,n);
        cout<<cnt<<endl;
    }
    return 0;
} 