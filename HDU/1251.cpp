#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int trie[maxn][27]={0};
int num[maxn]={0};
int pos=1; 
void insert(char word[])
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        int n=word[i]-'a';
        if(!trie[now][n])
            trie[now][n]=pos++;
        now=trie[now][n];
        num[now]++;
    }
}
int query(char word[])
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        int n=word[i]-'a';
        if(!trie[now][n])
            return 0;
        now=trie[now][n];
    }
    return num[now];
}
int main()
{
    char s[11];
    while(gets(s)&&s[0]!=0)
        insert(s);
    while(~scanf("%s",s))
        printf("%d\n",query(s));
    return 0;
}