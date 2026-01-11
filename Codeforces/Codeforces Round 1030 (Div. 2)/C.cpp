// Problem: C. Make It Beautiful
// Contest: Codeforces Round 1030 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2118/C
// Memory Limit: 512
// Time Limit: 2000
// Start: Mon 23 Jun 2025 06:53:18 PM WIB

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

ll next_power2(ll v)
{
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;

  return v;
}

void solve()
{
  int n, k; cin >> n >> k;
  vector<ll> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];


}

int main()
{
  tcs() solve();
  // solve();
}

