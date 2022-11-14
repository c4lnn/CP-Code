#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int point[500000];
int pre[500000]={0};
int t=0;
struct trie
{
    trie* next[26];
    int id;
    trie()
    {
        for(int i=0;i<26;i++)
            next[i]=NULL;
        id=0;
    }
}root;
int insert(char word[])
{
    trie *p=&root;
    for(int i=0;word[i];i++)
    {
        int n=word[i]-'a';
        if(!p->next[n])p->next[n]=new trie;
        p=p->next[n];
    }
    if(p->id==0)p->id=++t;
    return p->id;
}
int find(int x)
{
    int r=x;
    while(r!=pre[r])r=pre[r];
    int i=x,j;
    while(pre[i]!=r)j=pre[i],pre[i]=r,i=j;
    return r;
}
void union_set(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
        pre[x]=y;
}
int main()
{
    char s1[12],s2[12];
    int flag=0;
    int cnt=0;
    while(~scanf("%s%s",s1,s2))
    {
        int a=insert(s1);
        int b=insert(s2);
        point[a]++;
        point[b]++;
        if(!pre[a])pre[a]=a;
        if(!pre[b])pre[b]=b;
        union_set(a,b);
    }
    for(int i=1;i<=t;i++)
        if(point[i]%2==1)
            cnt++;
    for(int i=1;i<=t;i++)
        if(find(i)!=find(1))
            flag=1;
    if((cnt==2||!cnt)&&!flag)
        cout<<"Possible";
    else
        cout<<"Impossible";
    return 0;
}