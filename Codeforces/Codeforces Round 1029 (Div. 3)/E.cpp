// Problem: E. Lost[2]oul
// Contest: Codeforces Round 1029 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2117/E
// Memory Limit: 256
// Time Limit: 2000
//[2]tart:[2]un 29 Jun 2025 04:09:45 PM WIB

#include <bits/stdc++.h>

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
  int n; cin >> n;
  int a[n], b[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
  }

  unordered_map<int, array<ll, 3>> d1, d2;
  for (int i=1; i<=n; i++) {
    d1[i] = {INT_MAX, INT_MAX, INT_MAX};
    d2[i] = {INT_MAX, INT_MAX, INT_MAX};
  }

  for (int i=0; i<n; i++) {
    int ax = i & 1 ? b[i] : a[i];
    int bx = i & 1 ? a[i] : b[i];
    d1[ax] = {i+1, d1[ax][0], d1[ax][1]};
    d2[bx] = {i+1, d2[bx][0], d2[bx][1]};
  }

  // cout << "Tescs: " << tecs << el;
  // for (int i=1; i<=n; i++) {
  //   cout << i << ": " << d1[i][0] << ' ' << d1[i][2] << el;
  // }
  // cout << el;
  // for (int i=1; i<=n; i++) {
  //   cout << i << ": " << d2[i][0] << ' ' << d2[i][2] << el;
  // }
  // cout << el;

  ll res = 0;
  for (int i=1; i<=n; i++) {
    if (d1[i][0] != INT_MAX && d2[i][0] != INT_MAX) {
      res = max(res, min(d1[i][0], d2[i][0]));
    }

    if (d1[i][1] != INT_MAX && d1[i][0] > d1[i][1] + 1) {
      res = max(res, d1[i][1]);
    }

    if (d2[i][1] != INT_MAX && d2[i][0] > d2[i][1] + 1) {
      res = max(res, d2[i][1]);
    }

    if (d1[i][2] != INT_MAX && d1[i][0] > d1[i][2] + 1) {
      res = max(res, d1[i][2]);
    }

    if (d2[i][2] != INT_MAX && d2[i][0] > d2[i][2] + 1) {
      res = max(res, d2[i][2]);
    }
  }

  cout << res << el;
}

/*
 *
 * 2 4 5 2 3 1 2
 * 5 2 5 4 2 2 3
 *
 * 2 2 5 4 3 2 2
 * 5 4 5 2 2 1 3
 *
 */

int main()
{
  tcs() solve(tecs);
  // solve();
}

