// Problem: C. A Good Problem
// Contest: Codeforces Round 1035 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2119/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Mon 14 Jul 2025 12:10:49 PM WIB

#include <bits/stdc++.h>
#include <climits>
#include <cmath>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define tcs() int testcase; cin >> testcase; for(int tecs=1; tecs<=testcase; tecs++)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

void solve(int tecs=-1)
{
  ll n, l, r, k; cin >> n >> l >> r >> k;

  ll res = 1LL << (64 - __builtin_clzll(l));

  if (n == 2 || res > r) {
    cout << -1 << el;
    return;
  }

  if (n & 1 && k <= n - 2) {
    cout << l << el;
    return;
  }

  cout << res << el;
}

int main()
{
  tcs() solve(tecs);
  // solve();
}
