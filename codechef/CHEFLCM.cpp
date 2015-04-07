#include <stdio.h>
#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#define MaxRoot 32700

using namespace std;

bitset < MaxRoot > is_prime;
vector< int > prime;

void sieve()
{
	is_prime.set();
	for( int p = 2; p < MaxRoot; p++ )
	{
		if( is_prime.test( p ) )
		{
			prime.push_back( p );
			for( int np = (p << 1); np < MaxRoot; np += p )
			{
				is_prime.reset( np );
			}
		}
	}
}

void factorize( int N , map <int,int> &f )
{
	for( int i = 0; i < prime.size() && N != 1; i++ )
	{
		int p = prime[ i ];
		while( N % p == 0 )
		{
			f[ p ]++;
			N /= p;
		}
	}
	if( N != 1 ) f[ N ]++;
}

int main()
{
	int cases , N , base , exponent , add , sum;
	long long int ans = 0;
	sieve();
	scanf("%d",&cases);
	while( cases-- )
	{
		scanf("%d",&N);
		map < int , int > factors;
		map < int , int > ::iterator it;
		ans = 1LL;
		factorize( N , factors );
		for( it = factors.begin(); it != factors.end(); it++ )
		{
			base = it->first;
			exponent = it->second;
			//printf("B %d  E %d\n",base,exponent );
			add = 1;
			sum = 1;
			while( exponent-- )
			{
				add *= base;
				sum += add;
				//printf("b %d  , s %d \n",add,sum);
			}
			ans *= sum;
		}
		cout << ans << endl;
	}
	return 0;
}