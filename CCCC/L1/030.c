#include <stdio.h>
#include <string.h>
int o,l1,r1,l2,r2,rk1[55],rk2[55];
char s[105],a[55][105],b[55][105];
int main() {
    int n;scanf("%d",&n);
    l1=l2=1;
    for(int i=0;i<n;i++) {
        scanf("%d%s",&o,s);
        if(o==0) strcpy(a[++r1],s),rk1[r1]=i;
        else strcpy(b[++r2],s),rk2[r2]=i;
    }
    while(l1<=r1) {
        if(rk1[l1]<rk2[l2]) printf("%s %s\n",a[l1++],b[r2--]);
        else printf("%s %s\n",b[l2++],a[r1--]);
    }
    return 0;
}