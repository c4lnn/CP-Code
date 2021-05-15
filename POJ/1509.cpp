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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ull,ull> pull;
//head
const int N=1e6+5;

char s[N];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++) s[len+i]=s[i];
        int i=0,j=1;
        while(i<len&&j<len)
        {
            int k=0;
            for(;k<len;k++) if(s[i+k]!=s[j+k]) break;
            if(k==len) break;
            if(s[i+k]>s[j+k])
            {
                i=i+k+1;
                if(i==j) i++;
            }
            else if(s[j+k]>s[i+k])
            {
                j=j+k+1;
                if(i==j) j++;
            }
        }
        printf("%d\n",min(i,j)+1);
    }
    return 0;
}