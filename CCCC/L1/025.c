#include <stdio.h>
#include <string.h>
char s[3000];
int a,b,pos;
int main() {
    gets(s);
    int len=strlen(s),i;
    for(int i=0;i<len;i++) if(s[i]==' ') {pos=i;break;}
    for(i=0;i<pos;i++) {
        if(s[i]>='0'&&s[i]<='9') a=a*10+s[i]-'0';
        else {a=0;break;}
    }
    for(i=pos+1;i<len;i++) {
        if(s[i]>='0'&&s[i]<='9') b=b*10+s[i]-'0';
        else {b=0;break;}
    }
    if(a>1000) a=0;
    if(b>1000) b=0;
    if(a==0) putchar('?');
    else printf("%d",a);
    printf(" + ");
    if(b==0) putchar('?');
    else printf("%d",b);
    printf(" = ");
    if(a&&b) printf("%d",a+b);
    else putchar('?');
    putchar('\n');
    return 0;
}