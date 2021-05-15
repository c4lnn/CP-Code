#include<iostream>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

string g;

int f(string state) {
	int res=0;
	for(int i=0;i<9;i++) {
		if(state[i]!='x') {
			int t=state[i]-'1';
			res+=abs(i/3-t/3)+abs(i%3-t%3);
		}
	}
	return res;
}
void astar() {
	priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > >heap;
	map<string,bool>st;
	map<string,int>dist;
	map<string,pair<string,char> >pre;
	const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
	const char opt[]="udlr";
	const string end="12345678x";
	heap.push(make_pair(f(g),g));
	dist[g]=0;
	while(heap.size()) {
		string state=heap.top().second;
		heap.pop();
		if(state==end) break;
		if(st[state]) continue;
		st[state]=true;
		int step=dist[state];
		for(int i=0;i<9;i++)
			if(state[i]=='x') {
				int a=i/3,b=i%3;
				for(int j=0;j<4;j++)
					if(a+dx[j]>=0&&a+dx[j]<3&&b+dy[j]>=0&&b+dy[j]<3) {
						string t=state;
						swap(t[a*3+b],t[(a+dx[j])*3+(b+dy[j])]);
						if(!dist.count(t)||dist[t]>step+1)
						{
							dist[t]=step+1;
							pre[t]=make_pair(state,opt[j]);
							heap.push(make_pair(dist[t]+f(t),t));	
						}		
					}
				break;
			}
	}
	string res="";
	for(string i=end;pre.count(i);i=pre[i].first) {
		res+=pre[i].second;
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string seq="";
    for(int i=1;i<=9;i++) {
    	char c;
    	cin>>c;
    	g+=c;
    	if(c!='x') seq+=c;
	}
	int t=0; 
	for(int i=0;i<8;i++)
		for(int j=i+1;j<8;j++)
			if(seq[i]>seq[j])
				t++;
	if(t&1) cout<<"unsolvable"<<endl;
	else astar();
 	return 0;
}