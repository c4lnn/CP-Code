#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const int N=1e3+5;
int a[N][N*2];
int p[N*2];
struct node
{
    int val;
    int i;
    int j;
    bool flag;
    node(int val,int i,int j,bool flag):val(val),i(i),j(j),flag(flag){}
    bool operator > (const node &a) const{return val>a.val;}
};
int main()
{
    int T;scanf("%d",&T);
    int n,m;
    while(T--)
    {
        scanf("%d%d" ,&m,&n);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=m;i++) sort(a[i]+1,a[i]+1+n);
        for(int j=2;j<=m;j++)
        {
            priority_queue<node,vector<node>,greater<node> >q;
            q.push(node(a[1][1]+a[j][1],1,1,false));
            for(int i=1;i<=n;i++)
            {
                p[i]=q.top().val;
                int ni=q.top().i,nj=q.top().j;
                bool flag=q.top().flag;
                q.pop();
                q.push(node(a[1][ni]+a[j][nj+1],ni,nj+1,true));
                if(flag==false) q.push(node(a[1][ni+1]+a[j][nj],ni+1,nj,false));
            }
            for(int i=1;i<=n;i++) a[1][i]=p[i];
        }
        for(int i=1;i<=n;i++) printf("%d ",a[1][i]);
        printf("\n");
    }
    return 0;
}