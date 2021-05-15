#include<bits/stdc++.h>
using namespace std;
int trie[1000001][26];
int fail[1000001];
int cnt[1000001];
char str[1000001];
int id=0;
void insert(char* word)
{
    int now=0;
    for(int i=0;word[i];i++)
    {
        int n=word[i]-'a';
        if(!trie[now][n]) trie[now][n]=++id;
        now=trie[now][n];
    }
    ++cnt[now];
}
void getfail()
{
    queue<int>q;
    for(int i=0;i<26;i++)
        if(trie[0][i])
        {
            fail[trie[0][i]]=0;
            q.push(trie[0][i]);
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
                trie[now][i] = trie[fail[now]][i];
        }
    }
}
int query(char* word)
{
    int ans=0;
    int now=0;
    for(int i=0;word[i];i++)
    {
        now=trie[now][word[i]-'a'];
        for(int j=now;j&&cnt[j]!=-1;j=fail[j])
        {
            ans+=cnt[j];
            cnt[j]=-1;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    char s[51];
    while(t--)
    {
        memset(trie,0,sizeof trie);
        memset(fail,0,sizeof fail);
        memset(cnt,0,sizeof cnt);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            insert(s);        
        }
        scanf("%s",str);
        getfail();
        cout<<query(str)<<endl;
    }
    return 0;
}