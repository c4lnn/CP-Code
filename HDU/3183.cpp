#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e3+5;
char s[N];
int a[N];
int st[N][50];
int m;
int len;
queue<int>q;

int Min(int x,int y)
{
    return a[x]<=a[y]?x:y;
}
void build()
{
    for(int i=1;i<=len;i++) st[i][0]=i;
    int k=log(len)/log(2);
    for(int j=1;j<=k;j++)
        for(int i=1;i+(1<<j)-1<=len;i++)
            st[i][j]=Min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int search(int l,int r)
{
    int k=log(r-l+1)/log(2);
    return Min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
    while(~scanf("%s%d",s,&m)){
        len=strlen(s);
        m=len-m;
        for(int i=0;i<len;i++) a[i+1]=s[i]-'0';
        build();
        int pos=1;
        for(int i=1;i<=m;i++){
            pos=search(pos,len-m+i);
            q.push(a[pos]);
            pos++;
        }
        while(!q.empty()&&!q.front()) q.pop();
        if(q.empty()) printf("0");
        else while(!q.empty()) printf("%d",q.front()),q.pop();
        printf("\n");
    }
    return 0;
}