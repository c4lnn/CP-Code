#include<bits/stdc++.h>
using namespace std;
char ans[]="ABCDEFGHJKLMNOPQRSTUVWXYZabcdefghjklmnopqrstuvwxyz";
int main() {
	int n;
	while(~scanf("%d",&n)) {
		printf("2 %d %d\n",n,n);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				printf("%c",ans[i]);
			puts("");
		}
		puts("");
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				printf("%c",ans[j]);
			puts("");
		}
	} 
	return 0;
}