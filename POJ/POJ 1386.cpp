#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sum;
int tb[26][26];
void dfs(int x)
{
	for(int i=0;i<26;i++)
		if(tb[x][i])
		{
			tb[x][i]--;
			sum--;
			dfs(i);
		}
}
int main()
{
     int t;
     char s[1005];
     int n;
     scanf("%d",&t);
     while(t--)
     {
     	scanf("%d",&n);;
     	int to[26]={0};
     	int before[26]={0};
     	memset(tb,0,sizeof(tb));
     	sum=n;
		int flag=0;
     	int start=26;
		int cnt=0;
     	int cnt_end=0;
     	int cnt_start=0;
		for(int i=0;i<n;i++)
     	{ 
     		scanf("%s",s);
     		start=min(start,s[0]-'a'); 
			to[s[0]-'a']++;
			before[s[strlen(s)-1]-'a']++;
			tb[s[0]-'a'][s[strlen(s)-1]-'a']++;	
		}
		for(int i=0;i<26;i++)
		{
			if(to[i]==before[i]+1)
			{
				cnt_start++;
				start=i;
				cnt++;
			}
			else if(to[i]==before[i]-1)
			{
				cnt_end++;
				cnt++;
			}
			else if(to[i]!=before[i])
				cnt++;
		}
		if(cnt==2&&cnt_start==1&&cnt_end==1||cnt==0)
		{
			dfs(start);
			if(sum==0)
				flag=1;
		}
		if(flag==0)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");
	 }
    return 0;
}