#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000005;
int len1,len2;
char s[maxn];
char p[maxn];
int n[maxn];
void kmp()
{
    int i=0,j=-1;
    n[0]=-1;
    while(i<len2)
    {
        if(j==-1||p[i]==p[j])
        {
            i++;
            j++;
            n[i]=p[i]!=p[j]?j:n[j];
        }
        else
            j=n[j];
    }
}
void kmpsearch()
{
    kmp();
    int i=0,j=0;
    int ans=0;
    while(i<len1)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
            if(j==len2)
                ans++;
        }
        else
            j=n[j];
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",p,s);
        len1=strlen(s);
        len2=strlen(p);
        kmpsearch();
    }
    return 0;
}