#include<cstdio>
#include<queue>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

int T,n,m; 
int a;

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d",&n,&m);
        printf("%d %d\n",i,(m+1)/2);
        priority_queue<int,vector<int>,greater<int> >q1;//(m+1)/2 ~ m 
        priority_queue<int>q2;//1 ~ (m+1)/2-1
        for(int j=1;j<=m;j++)       
        {
            scanf("%d",&a);
            if(q1.empty()||a>=q1.top()) q1.push(a);
            else q2.push(a);
            if(j&1)
            {
                if(q1.size()>q2.size()) while(q1.size()>q2.size()+1) q2.push(q1.top()),q1.pop();
                if(q2.size()>q1.size()) while(q2.size()>q1.size()) q1.push(q2.top()),q2.pop();
                printf("%d ",q1.top());
            }
            if(j%20==0&&j!=m) printf("\n"); 
        }   
        printf("\n");       
    }
    return 0;
}