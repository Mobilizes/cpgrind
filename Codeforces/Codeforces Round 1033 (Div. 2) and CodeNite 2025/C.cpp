// Problem: C. Divine Tree
// Contest: Codeforces Round 1033 (Div. 2) and CodeNite 2025
// Judge: Codeforces
// URL: https://codeforces.com/contest/2120/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Wed 25 Jun 2025 02:41:07 PM WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define tcs() int testcase; cin >> testcase; for(int tecs=0; tecs<testcase; tecs++)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

void solve()
{
  ll n, m; cin >> n >> m;

  if (n == 1) {
    if (m == 1) {
      cout << "1\n1 2" << el;
      return;
    }

    cout << -1 << el;
    return;
  }

  if (m > n * (n - 1) / 2 || m < n - 1) {
    cout << -1 << el;
    return;
  }

  int cnt = n - 1;
  int l = 1, r = n+1;
  int i = 1;
  bool swtch = false;
  while (m > 2 * cnt) {

  }
}

int main()
{
  tcs() solve();
  // solve();
}

