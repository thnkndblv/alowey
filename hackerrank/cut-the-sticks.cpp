#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map < int , int > frecuency;
map < int , int > :: iterator it;
int N , number , op;

int main()
{   
    op = scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        op = scanf("%d",&number);
        frecuency[ number ]++;
    }
    for(it = frecuency.begin(); it != frecuency.end(); it++ )
    {
        printf("%d\n", N);
        N -= it->second;
    }
    return 0;
}