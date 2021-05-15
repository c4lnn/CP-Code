#include<bits/stdc++.h>
using namespace std;
int stu[500];
int P,N;
int a[500][500];   
int used[500];
int find(int x)
{
    for(int i=1;i<=N;i++)
    {
        if(a[x][i]&&!used[i])
        {
            used[i]=1;
            if(!stu[i]||find(stu[i]))
            {
                
                stu[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m,i;
    cin>>n;
    while(n--)
    {
        int v[500];
        memset(stu,0,sizeof(stu));
        memset(a,0,sizeof(a));
        cin>>P>>N;
        for(i=1;i<=P;i++)
        {
            cin>>v[i];
            for(int j=1;j<=v[i];j++)
            {
                cin>>m;
                a[i][m]=1;
            }    
        }
        for(i=1;i<=P;i++)
        {
            memset(used,0,sizeof(used));   
            if(!find(i))
            {
                cout<<"NO"<<endl;
                break;
            }
        }
        if(i>P)
            cout<<"YES"<<endl;
    }
    return 0;
}