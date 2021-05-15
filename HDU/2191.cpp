#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        int p[m],h[m],c[m];
        for(int i=0;i<m;i++)cin>>p[i]>>h[i]>>c[i];
        int g[n+1]={0};
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=c[i];c[i]-=j,j<<=1)
                for(int k=n;k>=j*p[i];k--)
                    g[k]=max(g[k],g[k-j*p[i]]+j*h[i]);
            for(int j=n;j>=p[i]*c[i];j--)
                    g[j]=max(g[j],g[j-c[i]*p[i]]+c[i]*h[i]);
        }
        cout<<g[n]<<endl;
    }
    return 0;
}