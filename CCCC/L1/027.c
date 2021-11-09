#include <stdio.h>
char s[15];
int vis[10],b[10],cnt,f;
int main() {
    scanf("%s",s);
    for(int i=0;i<11;i++) vis[s[i]-'0']=1;
    printf("int[] arr = new int[]{");
    for(int i=9;i>=0;i--) if(vis[i]) {
        if(cnt) putchar(',');
        printf("%d",i);
        b[i]=cnt++;
    }
    printf("};\nint[] index = new int[]{");
    for(int i=0;i<11;i++) {
        if(f) putchar(',');
        else f=1;
        printf("%d",b[s[i]-'0']);
    }
    printf("};\n");
    return 0;
}