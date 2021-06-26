#include<bits/stdc++.h>
using namespace std;
char str[5001];
char s[10005];
int len[10005];
int Manacher(char s[])
{
    len[0]=0;
    int id=0,mx=0,sum=0;
    int lens=strlen(s);
    for(int i=1;i<lens;i++)
    {
        len[i]=i<mx?min(mx-i,len[2*id-i]):1;
        while(s[i-len[i]]==s[i+len[i]])len[i]++;
        if(i+len[i]>mx)id=i,mx=i+len[i],sum=max(sum,len[i]);
    }
    return sum-1;
}
int main()
{
    scanf("%s",str);
    s[0]='$';
    int i=0,t=1;
    int lenstr=strlen(str);
    while(t<=2*lenstr+1)s[t]=t%2?'#':str[i++],t++;
    int lens=strlen(s);
    char ss[10005];
    ss[0]='$';
    for(int i=1,m=lens/2+1,n=2;i<lens-1;i++)
        ss[i]=m<lens?s[m++]:s[n++];
    ss[strlen(s)-1]='#';
    int ans=max(Manacher(s),Manacher(ss));
    ans=ans>lens/2?lens/2:ans;
    printf("%d",ans);
    return 0;
}