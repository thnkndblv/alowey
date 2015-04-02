#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int Mx = 102;

int N , M , ans , b , in[ Mx ];
bool seen[ Mx ];
vector< vector< int > > G;

int dfs( int u )
{
    if( seen[ u ] ) return 0;
    seen[ u ] = true;
    
    int ret = 0 , cnt = 1 , son;
    for( int v = 0; v < G[u].size(); v++ )
    {
        if( seen[ G[u][v] ] ) continue;
        son = dfs( G[u][v] );
        if( son && son % 2 == 0 )
        {
            ans++;
            //printf("Cut edge between %d to %d\n",u+1,G[u][v]+1);
        }
        cnt += son;
    }
    //printf("%d has %d childs\n",u+1,cnt);
    return cnt;
}

int main()
{
    int u , v;
    b = scanf("%d %d",&N,&M);
    G.resize( N );
    for( int i = 1; i < N; i++ )
    {
        b = scanf("%d %d",&u,&v);
        u--; v--;
        G[ v ].push_back( u );
        G[ u ].push_back( v );
        in[ v ]++; in[ u ]++;
    }
    for( int i = 0; i < N; i++ )
    {
        if( in[ i ] == 1 )
        {
            //printf(" -- Starts in %d -- \n", i + 1 );
            dfs( i );
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}