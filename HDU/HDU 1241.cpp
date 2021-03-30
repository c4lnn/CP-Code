#include<bits/stdc++.h>
using namespace std;
int m,n;
char a[105][105];
void dfs(int x,int y)
{
    if(x<0||y<0||x>=m||y>=n||a[x][y]!='@')
        return;
    else if(a[x][y]=='@')
    {
        a[x][y]='*';
        dfs(x-1,y-1);
        dfs(x-1,y);
        dfs(x-1,y+1);
        dfs(x,y-1);
        dfs(x,y+1);
        dfs(x+1,y-1);
        dfs(x+1,y);
        dfs(x+1,y+1);
    }
}
int main()
{
    int s;
    while(cin>>m>>n&&m&&n)
    {
        s=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];    
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]=='@')
                {
                    dfs(i,j);
                    s++; 
                }
        cout<<s<<endl;
    }
    return 0;
} 