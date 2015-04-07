#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long int i64;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#		define lld I64d
#endif

int main()
{
	int tests , numbers;

	scanf("%d",&tests);

	while( tests-- )
	{
		i64 sum , ans = 0LL , tmp; 
		scanf("%d",&numbers);
		priority_queue < i64 , vector < i64 > , greater< i64 > > pq;
		for( int i = 0; i < numbers; i++ )
		{
			scanf("%lld",&sum);
			pq.push( sum );
		}
		while( !pq.empty() )
		{
			sum = pq.top();
			ans = max( ans , sum );
			pq.pop();
			if( pq.empty() ) break;
			tmp = pq.top();
			if( sum != tmp ) continue;
			pq.pop();
			pq.push( sum << 1 );
		}
		printf("%lld\n",ans);
	}

	return 0;
}