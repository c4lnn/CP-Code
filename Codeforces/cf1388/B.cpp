#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        int t=(n+3)/4;
        for(int i=1;i<=n;i++) {
            if(i<=n-t) printf("9");
            else printf("8");
        }
        puts("");
    }
    return 0;
}