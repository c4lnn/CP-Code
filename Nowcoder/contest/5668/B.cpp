#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m;
char s[N];
int main() {
    scanf("%s%d",s,&m);
    n=strlen(s);
    int l=0;
    for(int i=1;i<=m;i++) {
        char opt[2];
        int x;
        scanf("%s%d",opt,&x);
        if(opt[0]=='A') printf("%c\n",s[(l+x-1)%n]);
        else if(opt[0]=='M') l=(l+n+x)%n;
    }
    return 0;
}