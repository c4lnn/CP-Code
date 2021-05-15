#include<bits/stdc++.h>
using namespace std;
typedef set<int> Set;
map<Set,int>IDcache;
vector<Set>Setcache;
int ID(Set x)
{
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		stack<int>s;
		cin>>n;
		string str;
		for(int i=0;i<n;i++)
		{
			cin>>str;	
			if(str[0]=='D') s.push(s.top());
			else if(str[0]=='P') s.push(ID(Set()));
			else
			{
				Set x1=Setcache[s.top()];s.pop();
				Set x2=Setcache[s.top()];s.pop();
				Set x;
				if(str[0]=='U') set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
				else if(str[0]=='I') set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
				else if(str[0]=='A') x=x2,x.insert(ID(x1));
				s.push(ID(x));
			} 
			cout<<Setcache[s.top()].size()<<endl;
		}
		cout<<"***\n";
	}
	return 0;
}