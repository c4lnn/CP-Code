#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int a[maxn];
int b[maxn];
int n,neg,pos;
signed main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        b[i]=a[i]-a[i-1];
        if(i>1) {
            if(b[i]<0) neg-=b[i];
            else pos+=b[i];
        }
    }
    printf("%lld\n%lld",min(neg,pos)+abs(neg-pos),abs(neg-pos)+1);
    return 0;
}