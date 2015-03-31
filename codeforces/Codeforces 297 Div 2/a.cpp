#include "iostream"
#include "string"

using namespace std;

string s;
int keyCounts[ 26 ];

int main() {
  int n, ans = 0;

  cin >> n;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    int keyFound = s[2 * i] - 'a';
    int keyNeeded = s[2*i + 1] - 'A';

    keyCounts[ keyFound ]++;
    if ( keyCounts[ keyNeeded ] > 0 ) {
      keyCounts[ keyNeeded ]--;
    } else {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
