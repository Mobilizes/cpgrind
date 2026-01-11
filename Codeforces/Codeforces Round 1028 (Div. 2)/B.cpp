// Problem: B. Gellyfish and Baby's Breath
// Contest: Codeforces Round 1028 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2116/B
// Memory Limit: 256
// Time Limit: 1000
// Start: Fri 13 Jun 2025 02:15:22 PM WIB

#include <bits/stdc++.h>
#include <iomanip>

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
#define MODULO 998244353

ll power(long long x, unsigned int y, int p)
{
  ll res = 1;  // Initialize result

  x = x % p;  // Update x if it is more than or
              // equal to p

  if (x == 0) return 0;  // In case x is divisible by p;

  while (y > 0) {
    // If y is odd, multiply x with result
    if (y & 1) res = (res * x) % p;

    // y must be even now
    y = y >> 1;  // y = y/2
    x = (x * x) % p;
  }
  return res;
}

void solve()
{
  int n; cin >> n;
  vector<ll> p(n), q(n);

  for (int i=0; i<n; i++) {
    cin >> p[i];
  }

  for (int i=0; i<n; i++) {
    cin >> q[i];
  }

  vector<ll> mx_p(n, 0);
  vector<ll> mx_q(n, 0);
  for (int i=1; i<n; i++) {
    if (p[mx_p[i-1]] <= p[i]) mx_p[i] = i;
    else mx_p[i] = mx_p[i-1];

    if (q[mx_q[i-1]] <= q[i]) mx_q[i] = i;
    else mx_q[i] = mx_q[i-1];
  }

  vector<pair<ll, ll>> mx(n, {0, 0});  // p_i_max, q_i_max
  for (int i=0; i<n; i++) {
    if (p[mx_p[i]] < q[mx_q[i]]) {
      mx[i] = {i - mx_q[i], mx_q[i]};
    } else if (p[mx_p[i]] > q[mx_q[i]]) {
      mx[i] = {mx_p[i], i - mx_p[i]};
    } else {
      if (p[i - mx_q[i]] < q[i - mx_p[i]]) {
        mx[i] = {mx_p[i], i - mx_p[i]};
      } else {
        mx[i] = {i - mx_q[i], mx_q[i]};
      }
    }
  }

  for (int i=0; i<n; i++) {
    ll res1 = power(2, p[mx[i].first], MODULO);
    ll res2 = power(2, q[mx[i].second], MODULO);
    cout << (res1 + res2) % MODULO << ' ';
  }

  cout << el;
}

int main()
{
  tcs() solve();
  // solve();
}

