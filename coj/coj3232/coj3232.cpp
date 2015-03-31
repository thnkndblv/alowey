#include "iostream"
#include "string"
#include "utility"
#include "vector"
#include "algorithm"

using namespace std;

vector< pair< int, string> > a;

int main() {
  int n, sum = 0;
  bool ac = false;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int min;
    string v;

    cin >> min >> v;
    a.push_back( make_pair( min, v ) );
  }

  sort( a.begin(), a.end() );

  for (int i = 0; i < n; i++) {
    if (ac) break;

    if ( a[i].second == "AC" ) {
      ac = true;
      sum += a[i].first;
    } else {
      sum += 20;
    }
  }

  if (!ac) sum = 0;
  cout << sum << endl;

  return 0;
}
