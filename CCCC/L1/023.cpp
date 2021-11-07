#include <stdio.h>
char s[10005];
int main() {
    scanf("%s",s);
    int i,g=0,p=0,l=0,t=0;
    for(i=0;s[i];i++) {
        if(s[i]=='G'||s[i]=='g') ++g;
        if(s[i]=='P'||s[i]=='p') ++p;
        if(s[i]=='L'||s[i]=='l') ++l;
        if(s[i]=='T'||s[i]=='t') ++t;
    }
    int mx=g;
    if(p>mx) mx=p;
    if(l>mx) mx=l;
    if(t>mx) mx=t;
    for(i=1;i<=mx;i++) {
        if(g) putchar('G'),--g;
        if(p) putchar('P'),--p;
        if(l) putchar('L'),--l;
        if(t) putchar('T'),--t;
    }
    putchar('\n');
    return 0;
}