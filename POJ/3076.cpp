#include<iostream>
#include<cstring>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

const int N=16;

int cnt;
char str[N][N+1];
int state[N][N];
int ones[1<<N],mp[1<<N];
int bustr[N*N+1][N][N],bustate[N*N+1][N][N],bustate2[N*N+1][N][N];

int lowbit(int x)
{
    return x&-x;
}
void init()
{
    cnt=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            state[i][j]=(1<<N)-1;
}
void draw(int x,int y,int c)
{
    str[x][y]='A'+c;
    for(int i=0;i<N;i++)
    {
        state[x][i]&=~(1<<c);
        state[i][y]&=~(1<<c);
    }
    int a=x/4*4,b=y/4*4;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            state[a+i][b+j]&=~(1<<c);
    state[x][y]=1<<c;
}
bool dfs(int cnt)
{
    if(!cnt) return true;
    int temp=cnt;
    memcpy(bustr[temp],str,sizeof str);
    memcpy(bustate[temp],state,sizeof state);
    for(int i=0;i<N;i++)//blank
        for(int j=0;j<N;j++)
            if(str[i][j]=='-')
            {
                int s=state[i][j];
                if(state[i][j]==0)
                {
                    memcpy(str,bustr[temp],sizeof str);
                    memcpy(state,bustate[temp],sizeof state);
                    return false;
                }
                else if(ones[s]==1)
                {
                    draw(i,j,mp[s]);
                    cnt--;
                }
            }
    for(int i=0;i<N;i++)//row
    {
        int sor=0;
        int sand=(1<<N)-1;
        int drawn=0;
        for(int j=0;j<N;j++)
        {
            int s=state[i][j];
            sand&=~(sor&s);//qu diao bu wei yi ke tian
            sor|=s;//ke tian bing ji
            if(str[i][j]!='-') drawn|=s;//yi tian
        }
        if(sor!=(1<<N)-1)
        {
            memcpy(str,bustr[temp],sizeof str);
            memcpy(state,bustate[temp],sizeof state);
            return false;
        }
        for(int j=sand;j;j-=lowbit(j))
        {
            int t=lowbit(j);
            if(!(drawn&t))
                for(int k=0;k<N;k++)
                    if(state[i][k]&t)
                    {
                        draw(i,k,mp[t]);
                        cnt--;
                        break;
                    }
        }
    }
    for(int j=0;j<N;j++)//col
    {
        int sor=0;
        int sand=(1<<N)-1;
        int drawn=0;
        for(int i=0;i<N;i++)
        {
            int s=state[i][j];
            sand&=~(sor&s);
            sor|=s;
            if(str[i][j]!='-') drawn|=s;
        }
        if(sor!=(1<<N)-1)
        {
            memcpy(str,bustr[temp],sizeof str);
            memcpy(state,bustate[temp],sizeof state);
            return false;
        }
        for(int i=sand;i;i-=lowbit(i))
        {
            int t=lowbit(i);
            if(!(drawn&t))
                for(int k=0;k<N;k++)
                    if(state[k][j]&t)
                    {
                        draw(k,j,mp[t]);
                        cnt--;
                        break;
                    }
        }
    }
    for(int n=0;n<N;n++)//16
    {
        int sor=0;
        int sand=(1<<N)-1;
        int drawn=0;
        int x=n/4*4,y=n%4*4;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                int s=state[x+i][y+j];
                sand&=~(sor&s);
                sor|=s;
                if(str[x+i][y+j]!='-') drawn|=s;
            }
        if(sor!=(1<<N)-1)
        {
            memcpy(str,bustr[temp],sizeof str);
            memcpy(state,bustate[temp],sizeof state);
            return false;
        }
        for(int k=sand;k;k-=lowbit(k))
        {
            int t=lowbit(k);
            if(!(drawn&t))
                for(int i=0;i<4;i++)
                    for(int j=0;j<4;j++)
                        if(state[x+i][y+j]&t)
                        {
                            draw(x+i,y+j,mp[t]);
                            cnt--;
                        }
        }
    }
    if(!cnt) return true;
    int minn=100,x,y;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(str[i][j]=='-')
                if(ones[state[i][j]]<minn)
                {
                    minn=ones[state[i][j]];
                    x=i,y=j;
                }
    memcpy(bustate2[cnt],state,sizeof state);
    for(int i=state[x][y];i;i-=lowbit(i))
    {
        memcpy(state,bustate2[cnt],sizeof state);
        draw(x,y,mp[lowbit(i)]);
        if(dfs(cnt-1)) return true;
    }
    memcpy(state,bustate2[temp],sizeof state);
    memcpy(str,bustr[temp],sizeof str);
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    for(int i=0;i<N;i++) mp[1<<i]=i;
    for(int i=0;i<1<<N;i++) for(int j=i;j;j-=lowbit(j)) ones[i]++;
    while(cin>>str[0])
    {
        init();
        for(int i=1;i<N;i++) cin>>str[i];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                if(str[i][j]!='-') draw(i,j,str[i][j]-'A');
                else cnt++;
            }
        dfs(cnt);
        for(int i=0;i<N;i++) cout<<str[i]<<endl;
        cout<<endl;
    }
    return 0;
}