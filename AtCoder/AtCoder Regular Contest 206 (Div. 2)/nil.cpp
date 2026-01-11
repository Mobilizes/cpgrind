// Problem: A - Range Replace
// Contest: AtCoder Regular Contest 206 (Div. 2)
// Judge: AtCoder
// URL: https://atcoder.jp/contests/arc206/tasks/arc206_a
// Memory Limit: 1024
// Time Limit: 2000
// Start: 29-09-2025 09:00:32 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;

auto solve(int tecs = -1)
{
  int n;
  cin >> n;
  vector<int> arr(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll res = 1;
  map<int, pii> mp;
  for (int i = n - 1; i >= 0; i--) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      res += n - i - mp[arr[i]].first - 1;
    }
    mp[arr[i]].first++;
  }

  cout << res << el;
}

void initialize() {}

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
