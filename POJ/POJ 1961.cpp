#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char p[1000001];
int  v[1000001];
int n;
void kmp()
{
    v[0]=-1;
    int i=0;
    int j=-1;
    while(i<n)
    {
        if(j==-1||p[i]==p[j])
        {
            i++;
            j++;
            v[i]=j;
        }
        else
            j=v[j];
    }
}
int main()
{
    int t=1;
	while(cin>>n&&n)
    {
        scanf("%s",p);
        kmp();
    	cout<<"Test case #"<<t++<<endl;
		for(int i=2;i<=n;i++)
			if(i%(i-v[i])==0&&i/(i-v[i])!=1)
				cout<<i<<" "<<i/(i-v[i])<<endl;
		cout<<endl;
	}
    return 0;
}