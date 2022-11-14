#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int n,p,h,m;
int l,r;
int a[10005];
int b[10005];
map<pair<int,int>,bool>v;

int main()
{
    scanf("%d%d%d%d",&n,&p,&h,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        if(v[make_pair(l,r)]) continue;
        b[l+1]--,b[r]++;
        v[make_pair(l,r)]=1;
    }
    for(int i=1;i<=n;i++) a[i]=a[i-1]+b[i],printf("%d\n",a[i]+h);
    return 0;
}