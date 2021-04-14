#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;;

int n;
ll a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        ll sum=0;
        ll dp=0;
        int dp_l,dp_r;
        ll maxn=INT_MIN;
        int maxn_l,maxn_r;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(dp<=0) dp=a[i],dp_l=dp_r=i;
            else dp+=a[i],dp_r=i;
            if(maxn<dp) maxn=dp,maxn_l=dp_l,maxn_r=dp_r;
        }
        //cout<<maxn_l<<" "<<maxn_r<<endl;
        if(sum>maxn||(sum==maxn&&maxn_l==1&&maxn_r==n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}