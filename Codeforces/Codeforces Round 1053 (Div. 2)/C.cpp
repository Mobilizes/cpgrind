// Problem: C. Incremental Stay
// Contest: Codeforces Round 1053 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2151/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 11-10-2025 17:46:00 WIB

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

// clang-format off
auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<ll> arr(n*2);
  for (int i=0; i<n*2; i++) {
    cin >> arr[i];
  }

  vector<ll> prec1(n*2, 0);
  vector<ll> prec2(n*2, 0);
  for (int i=0; i<n*2; i++) {
    if (i > 0) {
      prec1[i] = prec1[i - 1];
      if (i + 1 < n * 2) prec2[i] = prec2[i - 1];
    }
    if (i & 1 && i + 1 < n * 2) prec2[i] += arr[i+1] - arr[i];
    else if (i + 1 < n * 2) prec1[i] += arr[i+1] - arr[i];
  }

  // for (int i=0; i<n*2; i++) {
  //   cout << prec1[i] << ' ';
  // }
  //
  // cout << el;
  // for (int i=0; i<n*2; i++) {
  //   cout << prec2[i] << ' ';
  // }
  //
  // cout << el;

  ll res = 0;
  for (int k=0; k<n; k++) {
    if (k > 0) {
      res += arr[n*2-1-(k-1)] - arr[k-1];
    }

    if (k & 1) {
      cout << (prec2[n*2-1-k] - prec2[k-1]) + res << ' ';
    } else {
      cout << (prec1[n*2-1-k] - (k > 0 ? prec1[k-1] : 0)) + res << ' ';
    }
  }
  cout << el;
}

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
