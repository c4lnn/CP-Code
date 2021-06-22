#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        ll r,b,k;
        cin>>r>>b>>k;
        if(r>b) swap(r,b);
        if(gcd(b,r)+(k-1)*r>=b) cout<<"OBEY"<<endl;
        else cout<<"REBEL"<<endl;
    }
    return 0;
}