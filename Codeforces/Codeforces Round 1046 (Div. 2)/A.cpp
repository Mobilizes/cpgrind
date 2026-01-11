// Problem: A. In the Dream
// Contest: Codeforces Round 1046 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2136/problem/A
// Memory Limit: 256
// Time Limit: 1000
// Start: 28-08-2025 21:38:43 WIB

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

auto solve(int tecs=-1)
{
  int a, b, c, d; cin >> a >> b >> c >> d;
  if (2 + min(a, b) * 2 < max(a, b)) {
    return false;
  }

  c -= a;
  d -= b;

  if (2 + min(c, d) * 2 < max(c, d)) {
    return false;
  }

  return true;
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
