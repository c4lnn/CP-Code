#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000001];
int b[2000001]={0};
int main()
{
    int n,m;
    cin>>n>>a[1]>>m;
    for(int i=2;i<=n;i++)
        a[i]=(a[i-1]+7*i)%m;
    int ans=a[1];
    for(int i=1;i<=n;i++)
        for(int j=i;i*j<=n;j++)
        {
            if(i!=j)
                b[i*j]+=a[i]+a[j];
            else
                b[i*j]+=a[i];
        }
    for(int i=2;i<=n;i++)
        ans^=b[i];
    cout<<ans;
    return 0;
}