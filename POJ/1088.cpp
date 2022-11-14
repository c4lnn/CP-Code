#include<iostream>
using namespace std;
int a[101][101];
int R,C;
int len[101][101]={0};
int s[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int l=0;
int find(int x,int y)
{
    int maxn;
    int tx,ty;
    int maxl=0;
    if(len[x][y])return len[x][y];
    for(int i=0;i<4;i++)
    {
        tx=x+s[i][0];
        ty=y+s[i][1];
        if(tx>=0&&ty>=0&&tx<R&&ty<C&&a[tx][ty]<a[x][y])
            maxl=max(maxl,find(tx,ty));
    }
    len[x][y]=maxl+1;
    return len[x][y];
}
int main()
{
    cin>>R>>C;
    int cap=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
        {
            cin>>a[i][j];
        }
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
        {
            if(!len[i][j])find(i,j);
            cap=max(cap,len[i][j]);
        }
    cout<<cap<<endl;
    return 0;
}