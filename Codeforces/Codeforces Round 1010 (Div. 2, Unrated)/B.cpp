// Problem: B. Floor or Ceil
// Contest: Codeforces Round 1010 (Div. 2, Unrated)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2082/B
// Memory Limit: 512
// Time Limit: 1000
// Start: 29-09-2025 14:03:05 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = true;
const bool desync_stdio = false;

// int rec(int x, int n, int m, bool flag) {
//   if (n == 0 && m == 0) return x;
//   if (n == 0) return rec((x+1) / 2, n, m - 1, flag);
//   if (m == 0) return rec(x / 2, n - 1, m, flag);
//   if (flag) return max(rec(x / 2, n - 1, m, flag), rec((x+1) / 2, n, m - 1, flag));
//   return min(rec(x / 2, n - 1, m, flag), rec((x+1) / 2, n, m - 1, flag));
// }

auto solve(int tecs=-1)
{
  ll x, n, m; cin >> x >> n >> m;

  int mn = x, mx = x;

  int tn = n, tm = m;
  while (tm--) {
    if (mn <= 1) break;
    mn = ((mn + 1) >> 1);
  }

  while (tn--) {
    if (mn == 0) break;
    mn = (mn >> 1);
  }

  tn = n, tm = m;
  while (tn--) {
    if (mx == 0) break;
    mx = mx >> 1;
  }

  while (tm--) {
    if (mx <= 1) break;
    mx = (mx + 1) >> 1;
  }

  cout << mn << " " << mx << el;
}

void initialize()
{
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else {
    static_assert(is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool>,
      "solve() has to be bool or void");
  }
}

int main()
{
  if constexpr (desync_stdio) {
    Mob;
  }

  initialize();
  if constexpr (is_testcases) {
    int testcase;
    cin >> testcase;
    for (int tecs = 1; tecs <= testcase; tecs++) {
      call_solve(solve, tecs);
    }
  } else {
    call_solve(solve);
  }
}
