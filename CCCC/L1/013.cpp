#include <bits/stdc++.h>
using namespace std;
int fac[15];
int main() {
    int n;
    cin>>n;
    fac[0]=1;
    int res=0;
    for(int i=1;i<=n;i++) {
        fac[i]=fac[i-1]*i;
        res+=fac[i];
    }
    cout<<res<<'\n';
    return 0;
}