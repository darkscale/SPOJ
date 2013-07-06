#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
  int i,j,t,n,k;
	vector<int> prices;
	vector<int> minimun_price;
	scanf("%d",&t);
	while(t>0)
	{
		prices.clear();
		minimun_price.clear();
		scanf("%d %d",&n,&k);
		for (i = 0; i < k; ++i)
		{
			scanf("%d",&j);
			prices.push_back(j);
		}
		minimun_price.push_back(0);
		minimun_price.push_back(prices[0]);
		int min;
		for(i=2;i<=k;i++)
		{
			min=prices[i-1];
			for(j=1;j<i;j++)
			{
				if(minimun_price[i-j]!=-1 && minimun_price[j]!=-1 )
				{
					if((minimun_price[i-j]+minimun_price[j]<min) || min==-1)
					{
						min=minimun_price[i-j]+minimun_price[j];
					}
				}
			}
			minimun_price.push_back(min);
		}
		printf("%d\n",minimun_price[k]);
		t--;
	}
	return 0;
}
