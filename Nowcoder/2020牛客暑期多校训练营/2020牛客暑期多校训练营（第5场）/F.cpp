#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
long long mx,a[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++) {
        printf("+");
        long long len=a[i]*50/mx;
        if(a[i]*50%mx>0) len++;
        for(int j=1;j<=len;j++) printf("-");
        printf("+\n|");
        for(int j=1;j<=len;j++) {
            if(a[i]==mx&&j==len) printf("*");
            else printf(" ");
        }
        printf("|%lld\n",a[i]);
        printf("+");
        for(int j=1;j<=len;j++) printf("-");
        printf("+\n");
    }
    return 0;
}