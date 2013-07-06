#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int i,j,k,n,h,w,x,y,test=0;
	char a[55][55],s[55];
	bool valid[55][55],flag=false;
	vector< vector< pair< int,int > > > v(30);
	while(1)
	{
		scanf("%d %d\n",&h,&w);
		if(h==0 && w==0)
			break;
		for(i=0;i<30;i++)
			v[i].clear();
		for(i=0;i<h;i++)
		{
			scanf("%s",s);
			for(j=0;j<w;j++)
			{
				valid[i][j]=false;
				a[i][j]=s[j];
				v[s[j]-65].push_back(make_pair(i,j));
			}
		}
		for(i=0;i<26;i++)
		{
			if(v[i].size())
			{
				if(i==0)
				{
					for(j=0;j<v[i].size();j++)
						valid[v[i][j].first][v[i][j].second]=true;
				}
				else
				{
					flag=false;
					for(j=0;j<v[i].size();j++)
					{
						x=v[i][j].first;
						y=v[i][j].second;
						if(x>0 && y>0 && a[x-1][y-1]==i+64 && valid[x-1][y-1])
							valid[x][y]=true;
						else if(x>0 && a[x-1][y]==i+64 && valid[x-1][y])
							valid[x][y]=true;
						else if(x>0 && y<w-1 && a[x-1][y+1]==i+64 && valid[x-1][y+1])
							valid[x][y]=true;
						else if(y<w-1 && a[x][y+1]==i+64 && valid[x][y+1])
							valid[x][y]=true;
						else if(x<h-1 && y<w-1 && a[x+1][y+1]==i+64 && valid[x+1][y+1])
							valid[x][y]=true;
						else if(x<h-1 && a[x+1][y]==i+64 && valid[x+1][y])
							valid[x][y]=true;
						else if(x<h-1 && y>0 && a[x+1][y-1]==i+64 && valid[x+1][y-1])
							valid[x][y]=true;
						else if(y>0 && a[x][y-1]==i+64 && valid[x][y-1])
							valid[x][y]=true;
						if(valid[x][y])
							flag=true;
					}
					if(!flag)
						break;
				}
			}
			else
				break;
		}
		printf("Case %d: %d\n",++test,i );
	}
	return 0;
}
