#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+4;
char s[maxn];
int nxt[maxn];
int main()
{
    while(~scanf("%s",s+1))
    {
        int len=strlen(s+1);
        int cur=0;
        int last=0;
        nxt[0]=0;
        for(int i=1;i<=len;i++)
        {
            char ch=s[i];
            if(ch=='[')
                cur=0;
            else if(ch==']')
                cur=last;
            else
            {
                nxt[i]=nxt[cur];
                nxt[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }
        }
        for(int i=nxt[0];i;i=nxt[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}