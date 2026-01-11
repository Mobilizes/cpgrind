// Problem: B. Strange Machine
// Contest: Codeforces Round 1061 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2156/problem/B
// Memory Limit: 256
// Time Limit: 1500
// Start: 24-10-2025 21:39:50 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;

auto solve(int tecs = -1)
{
  int n, q; cin >> n >> q;
  string s; cin >> s;

  bool flag = true;
  for (int i=0; i<n; i++) {
    if (s[i] == 'B') flag = false;
  }

  for (int i=0; i<q; i++) {
    int a; cin >> a;
    if (flag) {
      cout << a << el;
      continue;
    }

    int cnt = 0;
    int idx = 0;
    while (a) {
      // cout << a << ' ';
      cnt++;
      if (s[idx] == 'A') a--;
      else a /= 2;

      idx++;
      if (idx == n) idx = 0;
    }

    cout << cnt << el;
  }
}

// clang-format off
void initialize()
{
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue>) {
    cout << f(tecs) << el;
  } else {
    static_assert(
      is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool> || is_integral_v<ReturnValue>,
      "solve() return type is not supported");
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
