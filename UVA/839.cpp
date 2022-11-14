#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))
#define lowbit(x) x&(-x)

typedef long long ll;
typedef pair<int,int>pii;


int f;
int judge()
{
    int wl,dl,wr,dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    if(!wl) wl=judge();
    if(!wr) wr=judge();
    if(wl*dl!=wr*dr)
    {
        f=0;
        return 0;
    }
    else return wl+wr;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        f=1;
        judge();
        if(f) printf("YES\n");
        else printf("NO\n");
        if(T) printf("\n");
    }
    return 0;
}