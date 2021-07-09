#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        long long n;
        scanf("%lld",&n);
        if(n==1||n==24) printf("Fake news!\n");
        else printf("Nobody knows it better than me!\n");
    }
    return 0;
}