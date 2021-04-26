#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;cin>>x;
    int m=x%10;
    x/=10;
    m=(x%10)*10+m;
    x/=10;
    if(x>=1000) return printf("%d-%02d\n",x,m),0;
    if(x<22) cout<<20;
    else cout<<19;
    printf("%02d-%02d\n",x,m);
    return 0;
}