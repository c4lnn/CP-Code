#include<bits/stdc++.h>
using namespace std;
const double e=exp(1);
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<fixed<<setprecision(c)<<pow(a,e)/b<<endl;
    }
    return 0;
}