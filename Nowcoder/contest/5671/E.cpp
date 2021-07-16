#include<bits/stdc++.h>
using namespace std;
int n,k,tot;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) tot+=i;
    if(tot%n!=k) puts("-1");
    else if(n&1) {
        printf("%d ",n);
        for(int i=1,j=n-1;i<j;i++,j--) printf("%d %d ",i,j);
        puts("");
    }
    else {
        printf("%d %d ",n,k);
        for(int i=1,j=n-1;;) {
            if(i==k) i++;
            if(j==k) j--;
            if(i>=j) break;
            printf("%d %d ",i++,j--);
        }
        puts("");
    }
    return 0;
}