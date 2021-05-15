#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>tb[26];
vector<string>ans;
void dfs(int x)
{
	while(!tb[x].empty())
	{
		 string ss=tb[x][0];
		 tb[x].erase(tb[x].begin());
		dfs(ss[ss.length()-1]-'a');
		ans.push_back(ss);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<26;i++)
			
				while(!tb[i].empty())
					tb[i].clear();
		ans.clear();
		int to[26]={0};
		int before[26]={0};
		int cnt_start=0;
		int cnt_end=0;
		int cnt=0;
		int start=26;
		int flag=0;
		string s[n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			start=min(start,s[i][0]-'a');
			before[s[i][0]-'a']++;
			to[s[i][s[i].length()-1]-'a']++;
		}
		sort(s,s+n);	
		for(int i=0;i<n;i++)
			tb[s[i][0]-'a'].push_back(s[i]);
		for(int i=0;i<26;i++)
		{
			if(before[i]==to[i]+1)
			{
				cnt_start++;
				start=i;
			}
			else if(to[i]==before[i]+1)
				cnt_end++;
			else if(before[i]!=to[i])
				cnt++;
		}
		if(cnt_start==1&&cnt_end==1&&cnt==2||cnt==0)
		{
		
			dfs(start);
			if(ans.size()==n)
				flag=1;
		}
		if(flag==1)
		{
			for(int i=ans.size()-1;i>0;i--)
				cout<<ans[i]<<".";
			cout<<ans[0]<<endl;
		}
		else
			printf("***\n");
	}
	return 0;
} 