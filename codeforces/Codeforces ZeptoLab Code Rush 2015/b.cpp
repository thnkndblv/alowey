#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef long long int i64;

int tr[ 100005 ] , N;
i64 ans;

int dfs( int r )
{
	int izq , der;
	izq = ( r << 1 ) + 1;
	der = ( r << 1 ) + 2;
	if( izq > N ) return 0;
	int iz = dfs( izq );
	int de = dfs( der );
	ans += (i64)abs( (iz + tr[izq]) - (de + tr[der]) );
	return max( iz + tr[izq] , de + tr[der] );
}

int main()
{
	scanf("%d",&N);
	N = (1 << (N+1)) - 2;
	for( int i  = 1; i <= N ; i++ )
	{
		scanf("%d",&tr[i]);
	}
	dfs( 0 );
	cout << ans << endl;
	return 0;
}