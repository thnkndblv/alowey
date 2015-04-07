#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n , tmp, T , ans , m , f;

	scanf("%d",&T);
	while( T-- )
	{
		scanf("%d",&n);
		ans = f = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%d",&tmp);
			if( i == 0 ) m = tmp;
			if( m != tmp )
			{
				ans += 2 - f;
				f = 1;
			} else f = 0;
			m = tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}