// Problem: C. Sums on Segments
// Contest: Educational Codeforces Round 173 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2043/C
// Memory Limit: 256
// Time Limit: 1000
// Start: 25-10-2025 14:03:17 WIB

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
  int n;
  cin >> n;
  vector<ll> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }

  ll l1 = 0, r1 = 0;
  ll l2 = INT_MAX, r2 = INT_MIN;

  ll mnr = INT_MAX, mnl = 0;
  ll mxr = INT_MIN, mxl = 0;
  for (int i = 1; i <= n; i++) {
    ll curr = arr[i] - arr[i - 1];
    if (curr != 1 && curr != -1) {
      mnr = mnl;
      mxr = mxl;
      mnl = arr[i];
      mxl = arr[i];
    }

    l1 = min(l1, arr[i] - mxl);
    r1 = max(r1, arr[i] - mnl);
    l2 = min(l2, arr[i] - mxr);
    r2 = max(r2, arr[i] - mnr);

    mnl = min(mnl, arr[i]);
    mxl = max(mxl, arr[i]);

    // cout << arr[i] << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << mnl << ' ' << mxl << ' ' << mnr << ' ' << mxr << el;
  }

  vector<int> res;
  if (l2 > r1) {
    for (int i = l1; i <= r1; i++) res.push_back(i);
    for (int i = l2; i <= r2; i++) res.push_back(i);
  } else if (r2 < l1) {
    for (int i = l2; i <= r2; i++) res.push_back(i);
    for (int i = l1; i <= r1; i++) res.push_back(i);
  } else {
    for (int i=min(l1,l2); i<=max(r1,r2); i++) res.push_back(i);
  }

  cout << res.size() << el;
  for (int i : res) cout << i << ' ';
  cout << el;
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
