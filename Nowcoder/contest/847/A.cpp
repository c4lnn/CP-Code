#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5000;
int main()
{
    char s[maxn];
    cin>>s;
    ll sum[maxn]={0};
    ll ans=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(!i&&s[i]=='Q')
            sum[i]=1;
        else if(i)
            sum[i]=s[i]=='Q'?sum[i-1]+1:sum[i-1];
    }
    for(int i=2;i<len-2;i++)
        if(s[i]=='A')
            ans+=sum[i-2]*(sum[len-1]-sum[i+1]);
    cout<<ans;
    return 0;
}