#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;;

ll x;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
void cal()
{
    ll a,b;
    for(ll i=(ll)sqrt(x);i;i--)
    {
        if(x%i==0)
        {
            a=i;
            b=x/i;
            if(gcd(a,b)==1)
                break;
        }
    }
    cout<<a<<" "<<b<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>x;
    cal();
    return 0;
}