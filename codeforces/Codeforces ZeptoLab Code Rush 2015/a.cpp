#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef long long int i64;

int main()
{
	string s;
	int n;
	cin >> n >> s;
	bool ans = false;
	for( int i = 0; i < n && !ans; i++ )
	{
		if( s[ i ] == '.' ) continue;
		for( int k = 1; k < n && !ans; k++ )
		{
			ans = true;
			for( int j = 1; j < 5 && ans; j++ )
			{
				int u = i + j * k;
				if( u >= n || s[ u ] == '.' )
				{
					ans = false;
				}
			}
		}
	}
	puts(ans?"yes":"no");
	return 0;
}