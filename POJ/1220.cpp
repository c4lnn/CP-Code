#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;


int n;
int a,b;
char s[200];
int p[500];
int ans[200];

int get(char x)
{
    if(x>='0'&&x<='9') return x-'0';
    if(x>='A'&&x<='Z') return x-'A'+10;
    if(x>='a'&&x<='z') return x-'a'+36;
    return -1;
}
char put(int x)
{
    if(x>=0&&x<=9) return '0'+x;
    if(x>=10&&x<=35) return 'A'+x-10;
    if(x>=36&&x<=61) return 'a'+x-36;
    return '\0';
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++) p[i]=get(s[i]);
        int cnt=0;
        int t=strlen(s);
        while(t)
        {
            int len=t;
            t=0;
            int x=0;
            for(int i=0;i<len;i++)
            {
                x=x*a+p[i];
                if(x<b&&t==0) continue;
                p[t++]=x/b;
                x%=b;
            }
            ans[cnt++]=x;
        }
        for(int i=cnt-1;;i--) if(ans[i]!=0) break;
        printf("%d ",a);
        for(int i=0;s[i];i++) printf("%c",s[i]);
        printf("\n");
        printf("%d ",b);
        for(int i=cnt-1;i>=0;i--) printf("%c",put(ans[i]));
        printf("\n\n");
    }       
    return 0;
}  