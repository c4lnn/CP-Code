#include<bits/stdc++.h>
using namespace std;
int trie[100005][12]={0};
int pos=0;
int flag;
struct ss
{
    char s[12];
    int len;
}s[10005];
void insert(char s[])
{
    int now=0;
    for(int i=0;s[i];i++)
    {
        int n=s[i]-'0';
        if(!s[i+1]&&trie[now][n])flag=1;
        if(!trie[now][n])trie[now][n]=++pos;
        now=trie[now][n];
    }
}
int cmp(ss a, ss b)
{
    return a.len>b.len;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        flag=0;
        memset(trie,0,sizeof trie);
        pos=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i].s);
            s[i].len=strlen(s[i].s);
        }
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)
            insert(s[i].s);
        if(!flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}