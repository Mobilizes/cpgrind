// Problem: E. Adjacent XOR
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/E
// Memory Limit: 256
// Time Limit: 2000
// Start: Fri 15 Aug 2025 02:34:18 PM KST

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

const bool is_testcases = true;

auto solve(int tecs=-1)
{
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  if (a.back() != b.back()) {
    return false;
  }

  for (int i = 0; i < n - 1; i++) {
    if (a[i] == b[i]) continue;
    if ((a[i] ^ a[i + 1]) == b[i]) continue;
    if ((a[i] ^ b[i + 1]) == b[i]) continue;

    return false;
  }

  return true;
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  if (is_testcases) {
    using ret = invoke_result_t<decltype(f), int>;
    if constexpr (is_same_v<ret, bool>) {
      cout << (f(tecs) ? "YES" : "NO") << el;
    } else if constexpr (is_same_v<ret, void>) {
      f(tecs);
    } else {
      static_assert(is_same_v<ret, void> || is_same_v<ret, bool>, "solve() has to be bool or void");
    }
  }
}

int main()
{
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
