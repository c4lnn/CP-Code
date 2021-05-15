#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000005;
int len;
char p[maxn];
int n[maxn];
void kmp()
{
	int i=0,j=-1;
	n[0]=-1;
	while(i<len)
	{
		if(j==-1||p[i]==p[j])
		{
			n[++i]=++j;	
		}
		else
			j=n[j];
	}

} 
void show(int i)
{
	if(n[i]!=0)
		show(n[i]);
	printf("%d ",i);
}
int main()
{
	while(~scanf("%s",p))
	{
		len=strlen(p);
		kmp();
		show(len);
		printf("\n");
	}
	return 0;
}