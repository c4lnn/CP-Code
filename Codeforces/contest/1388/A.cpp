#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        if(n<=30) puts("NO");
        else {
            if(n==36||n==40||n==44) printf("YES\n6 10 15 %d\n",n-31);
            else printf("YES\n6 10 14 %d\n",n-30);
        }
    }
    return 0;
}