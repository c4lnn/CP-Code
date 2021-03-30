#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N=1e7+5;
 
char s[N];
ll nxt[N];
int len;
 
void getNext()
{
    int i=0;
    int j=-1;
    nxt[0]=-1;
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
        {
            i++,j++;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}
int main()
{
    int a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        scanf("%s",s);
        sscanf(s,"%*[^.].%s",s);
        len=strlen(s);
        reverse(s,s+len);
        getNext();
        ll ans=0xc0c0c0c0c0c0c0c0; 
        for(ll i=1;i<=len;i++) ans=max(ans,a*i-b*(i-nxt[i]));
        printf("%lld\n",ans);
    } 
    return 0;
}