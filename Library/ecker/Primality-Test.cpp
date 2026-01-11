// Problem: Primality Test
// Contest: unknown_contest
// Judge: Library Checker
// URL: https://judge.yosupo.jp/problem/primality_test
// Memory Limit: 1024
// Time Limit: 5000
// Start: 13-11-2025 02:37:17 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define lcm(a, b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

using i128 = __int128;

ll power(ll x, ll y, ll m) {
    ll res = 1;
    x %= m;
    while(y) {
        if(y & 1) {
            res = (res * x) % m;
        }
        x = (i128)x * x % m;
        y = y >> 1;
    }
    return res;
}

bool checkcomposite(ll n, ll a, ll d, ll s) {
  ll x = power(a, d, n);
  if (x == 1 || x == n-1) return false;
  for (int i=1; i<s; i++) {
    x = (i128)x * x % n;
    if (x == n-1) return false;
  }
  return true;
}

bool millerrabin(ll n) {
  if (n < 4) return n >= 2;

  vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

  ll s = 0;
  ll d = n-1;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }

  for (ll a : primes) {
    if (n == a) return true;
    if (checkcomposite(n, a, d, s)) return false;
  }
  return true;
}

auto solve(int tecs = -1)
{
  ll n; cin >> n;
  if (millerrabin(n)) cout << "Yes" << el;
  else cout << "No" << el;
}

void initialize() {}

int main()
{
  if constexpr (desync_stdio) {
    Mob;
  }

  initialize();
  if (is_testcases) {
    int testcase;
    cin >> testcase;
    for (int tecs = 1; tecs <= testcase; tecs++) {
      solve(tecs);
    }
  } else {
    solve();
  }
}
// if you see good syntax format, i used clang-format
