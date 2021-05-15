#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;

int n;
int t,m,p;
queue<pii> q;//长度，时间
set<pii> s;//起始地址，长度
priority_queue<pii,vpii,greater<pii> > heap;//释放时间，起始地址
int cnt;//等待个数
int ans;//结束时间

bool work(int t,int m,int p)
{
    int start=0;
    for(set<pii>::iterator it=s.begin();it!=s.end();it++)
    {
        pii x=*it;
        if(x.first-start>=m){s.insert({start,m}),heap.push({t+p,start});return true;}
        start=x.first+x.second;
    }

    return false;
}
void release(int t)
{
    while(!heap.empty()&&heap.top().first<=t)
    {
        int f=heap.top().first;
        ans=f;
        while(!heap.empty()&&heap.top().first==f)
        {
            set<pii>::iterator it=s.lower_bound({heap.top().second,0});
            s.erase(it);
            heap.pop();    
        }
        while(!q.empty())
        {
            if(work(f,q.front().first,q.front().second)==false) break;
            else q.pop();
        }
    }   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>n;
    s.insert({n,0});
    while(cin>>t>>m>>p&&(t||m||p))
    {
        release(t);
        if(work(t,m,p)==false) q.push({m,p}),cnt++;
    }
    release(1e9+5);
    cout<<ans<<endl;
    cout<<cnt<<endl;
    return 0;
}