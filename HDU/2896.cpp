#include<bits/stdc++.h>
using namespace std;
#define Set set<int>
int trie[1000000][128]={0};
int fail[10000000]={0};
int id[10000000]={0};
int t=0;
int ID=0;
int total=0;
void insert(char* word)
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        if(!trie[now][word[i]])    trie[now][word[i]]=++t;
        now=trie[now][word[i]];
    }    
    id[now]=++ID;
} 
int getFail()
{
    queue<int>q;
    for(int i=0;i<128;i++)
        if(trie[0][i])
        {
            fail[trie[0][i]]=0;
            q.push(trie[0][i]);
        }
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<128;i++)
        {
            if(trie[now][i]) 
            {
                fail[trie[now][i]]=trie[fail[now]][i];
                q.push(trie[now][i]);
            }
            else 
                trie[now][i]=trie[fail[now]][i];
        }
    }
}
Set query(char* str)
{
    int now=0;
    Set ans;
    for(int i=0;str[i];i++)
    {
        now=trie[now][str[i]];
        for(int j=now;j;j=fail[j])
            if(id[j])
                ans.insert(id[j]);
    }
    if(ans.size()) total++;
    return ans;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    char s1[201];
    while(n--)
    {
        scanf("%s",s1);
        insert(s1);
    }
    getFail();
    scanf("%d",&m);
    char s2[10001];
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s2);
        Set ans=query(s2);
        if(ans.size())
        {
            printf("web %d:",i);
            Set::iterator it;
            for(it=ans.begin();it!=ans.end();it++)
                printf(" %d",*it);
            printf("\n");
        }
    }
    printf("total: %d\n",total);
    return 0;
}