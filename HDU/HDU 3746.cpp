#include<bits/stdc++.h>
using namespace std;
char s[100005];
int n[100005];
void kmp()
{
    n[0]=-1;
    int i=1,j=0;
    int len=strlen(s);
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
            n[++i]=++j;
        else
            j=n[j];
    }
    if(len!=len-j&&len%(len-j)==0)
        printf("0\n");
    else
        printf("%d\n",len-j-j%(len-j));
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        kmp();
    }
    return 0;
}