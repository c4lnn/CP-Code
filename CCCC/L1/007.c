#include <stdio.h>
#include <string.h>
char a[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char s[1005];
int main() {
    scanf("%s",s);
    int len=strlen(s),i=0;
    for(;i<len;i++) {
        if(s[i]=='-') printf("fu");
        else printf("%s",a[s[i]-'0']);
        printf("%c",i==len-1?'\n':' ');
    }
    return 0;
}