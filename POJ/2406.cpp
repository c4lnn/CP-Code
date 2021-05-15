#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int n[maxn];
void kmp()
{
	int i=0,j=-1;
	n[0]=-1;
	int len=strlen(s);
	while(i<len)
	{
		if(j==-1||s[i]==s[j])
		{
			n[++i]=++j;
		}
		else
			j=n[j];
	}
	if(len%(len-n[len])==0)
		printf("%d\n",len/(len-n[len]));
	else
		printf("1\n");
}
int main()
{
	while(~scanf("%s",s)&&s[0]!='.')
		kmp();
	return 0;
}