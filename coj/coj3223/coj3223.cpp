#include "stdio.h"

typedef long long Long;

int main() {
  int ntc;

  scanf("%d", &ntc);
  for (int i = 0; i < ntc; i++) {
    int n;
    scanf("%d", &n);

    Long ans = 0LL;
    for (int i = 1; i * i <= n; i++) if ( n % i == 0 ) {
      ans += i;
      if ( n != i*i ) ans += n / i;
    }
    
    printf("%lld\n", ans);
  }

  return 0;
}
