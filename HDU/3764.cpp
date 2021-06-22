#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,a[N];
int main() {
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        bool f=false;
        for(int i=2;i<=n;i++) if(a[i]-a[i-1]>200) {f=true;break;}
        if(1422-a[n]>100) f=true;
        if(f) puts("IMPOSSIBLE");
        else puts("POSSIBLE");
    }
    return 0;
}