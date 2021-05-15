#include<bits/stdc++.h>
using namespace std;
char virus[1002][55];
int trie[200000][26];
int fail[200000];
int id[200000];
int cnt[1002];
int t;
int ID;
char s[2000005];
void insert(char* word)
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        int n=word[i]-'A';
        if(!trie[now][n]) 
            trie[now][n]=++t;
        now=trie[now][n];
    }
    id[now]=++ID;
}
void getfail()
{
    queue<int>q;
    for(int i=0;i<26;i++)
    {    
        if(trie[0][i])
        {
            fail[trie[0][i]]=0;
            q.push(trie[0][i]);
        }
        else
            trie[0][i]=0; 
    }        
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<26;i++)
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
void query(char* word)
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        if(word[i]<'A'||word[i]>'Z')
            now=0;
        else
            now=trie[now][word[i]-'A'];
        for(int j=now;j;j=fail[j])
            if(id[j])
                cnt[id[j]]++;    
    }
}
void init()
{
    memset(trie,0,sizeof trie);
    memset(cnt,0,sizeof cnt);
    memset(id,0,sizeof id);
    t=0;
    ID=0;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",virus[i]);
            insert(virus[i]);
        }
        getfail();
        scanf("%s",s);
        query(s);
        for(int i=1;i<=n;i++)
            if(cnt[i])
                printf("%s: %d\n",virus[i],cnt[i]);
    }
    return 0;
}