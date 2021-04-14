#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	char c;
	vector<char>s;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		s.push_back(c);
	}
	if(s.size()!=1)
	{
		vector<char>::iterator it;
		for(it=s.begin();it<s.end(); ) 
		{
			if(*it==*(it+1))
			{
				s.erase(it);
				++cnt;
			}
			else
				it+=2;
		}
	} 
	if(s.size()%2)
	{
		cnt++;
		s.erase(s.end()-1);
	}	
	cout<<cnt<<endl;
	for(int i=0;i<s.size();i++)
		cout<<s[i];
	return 0;
}