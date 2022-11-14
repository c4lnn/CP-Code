#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int r0,c0,r1,c1;
char t0;
const char* dirs="NESW";
const char* turns="FLR";
int dir_id(char c) { return strchr(dirs,c)-dirs; }
int turn_id(char c) { return strchr(turns,c)-turns; }
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int flag;
struct node{
    int x;
    int y;
    int dir;
    int pre_turn;
    node(int x=0,int y=0,int dir=0,int pre_turn=0):x(x),y(y),dir(dir),pre_turn(pre_turn){
    }
}pre[maxn][maxn][4][4];
node b1;
vector<node>ans;
int has_edge[maxn][maxn][4][3];
node walk(const node &u,int turn){
    int dir=u.dir;
    if(turn==1) dir=(dir+3)%4;
    else if(turn==2) dir=(dir+1)%4;
    return node(u.x+dx[dir],u.y+dy[dir],dir,u.dir);
}
int inside(int x,int y){
    if(x>=1&&y>=1&&x<10&&y<10)
        return 1;
    else
        return 0;
}
void print(node x){
    if(pre[x.x][x.y][x.dir][x.pre_turn].x==r0&&pre[x.x][x.y][x.dir][x.pre_turn].y==c0&&pre[x.x][x.y][x.dir][x.pre_turn].dir==b1.dir&&pre[x.x][x.y][x.dir][x.pre_turn].pre_turn==b1.pre_turn){
        ans.push_back(pre[x.x][x.y][x.dir][x.pre_turn]);
        ans.push_back(x);
        return;
    }
    else
        print(pre[x.x][x.y][x.dir][x.pre_turn]);
    ans.push_back(x);
}
void bfs(int x,int y){
    queue<node>p;
    p.push(b1);
    while(!p.empty()){
        node u=p.front();
        p.pop();
        if(u.x==r1&&u.y==c1){
            print(u);
            return;
        }
        for(int i=0;i<3;i++){
            node v=walk(u,i);
            if(has_edge[u.x][u.y][u.dir][i]&&inside(v.x,v.y)){
                pre[v.x][v.y][v.dir][v.pre_turn]=u;
                has_edge[u.x][u.y][u.dir][i]=0;
                p.push(v);
            }
        }
    }
    flag=1;
}
int main(){
    string name;
    while(cin>>name&&name!="END"){
        flag=0;
        cin>>r0>>c0>>t0>>r1>>c1;
        b1.x=r0+dx[dir_id(t0)];
        b1.y=c0+dy[dir_id(t0)];
        b1.dir=b1.pre_turn=dir_id(t0);
        memset(has_edge,0,sizeof(has_edge));
        if(ans.size())ans.clear();
        int x,y;
        cout<<name<<endl;
        while(cin>>x&&x){
            cin>>y;
            char s[10];
            while(cin>>s&&s[0]!='*'){
                int len=strlen(s);
                for(int i=1;i<len;i++)
                has_edge[x][y][dir_id(s[0])][turn_id(s[i])]=1;
            }
        }
        pre[b1.x][b1.y][b1.dir][b1.pre_turn]=node(r0,c0,b1.dir,b1.pre_turn);
        bfs(b1.x,b1.y);

        if(!flag){
            int t=1;
            for(int i=0;i<ans.size();i++,t++){
                if(t%10==1)cout<<" ";
                printf(" (%d,%d)",ans[i].x,ans[i].y);
                if(t%10==0)
                    cout<<endl;
            }
            if((t-1)%10!=0)
                cout<<endl;
        }
        else
            cout<<"  No Solution Possible"<<endl;
    }
    return 0;
}