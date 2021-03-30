#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string dfs(string &s,int &u)
{
    u++;
    vector<string>seq;
    while(s[u]=='0') seq.push_back(dfs(s,u));
    u++;
    sort(seq.begin(),seq.end());
    string res="0";
    for(int i=0;i<seq.size();i++) res+=seq[i];
    res+='1';
    return res;
}
int main()
{
    int n;cin>>n;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        a='0'+a;
        b='0'+b;
        int ua=0,ub=0;
        if(dfs(a,ua)==dfs(b,ub)) cout<<"same"<<endl;
        else cout<<"different"<<endl;
    }
    return 0;
}