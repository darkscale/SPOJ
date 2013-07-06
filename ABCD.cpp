#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int fill(char *a,char *b,int i,int n,int *count)
{
  if(i==n)
	{
		return 1;
	}
	char k='A';
	char p=a[2*i],q=a[2*i+1],r,s,t;
	if(p=='A' && q=='B' || q=='A' && p=='B')
		r='C',s='D';
	if(p=='A' && q=='C' || q=='A' && p=='C')
		r='B',s='D';
	if(p=='A' && q=='D' || q=='A' && p=='D')
		r='B',s='C';
	if(p=='B' && q=='C' || q=='B' && p=='C')
		r='A',s='D';
	if(p=='B' && q=='D' || q=='B' && p=='D')
		r='A',s='C';
	if(p=='C' && q=='D' || q=='C' && p=='D')
		r='A',s='B';
	if(i!=0 && r==b[2*i-1])
		swap(s,r);
	b[2*i]=r;
	b[2*i+1]=s;
	fill(a,b,i+1,n,count);
	return 0;
}
int main()
{
	int i,j,k,n;
	int count[4]={0};
	scanf("%d\n",&n);
	char c;
	char a[100005],b[100005];
	// vector<char> a;
	// vector<char> b;
	for(i=0;i<2*n;i++)
	{
		scanf("%c",&c);
		count[c-'A']++;
		a[i]=c;
		// a.push_back(c);
	}
	fill(a,b,0,n,count);
	for(i=0;i<2*n;i++)
		printf("%c",b[i]);
	printf("\n");
	return 0;
}
