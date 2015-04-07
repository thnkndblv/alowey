#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

double lg;
i64 ans , K , D;

i64 f( i64 x )
{
	double m = lg * (double)( x );
	return ( (i64)(ceil( m ))  >= D );
}

int main()
{
	while( cin >> K >> D )
	{
		lg = log10( (double)( K ) );
		ans = (1LL << 40) - 1LL;
		for( int i = 39; i >= 0; i-- )
		{
			ans ^= f( ans ^ (1LL << i) ) << i;
		}
		cout << ans << endl;
	}
	return 0;
}