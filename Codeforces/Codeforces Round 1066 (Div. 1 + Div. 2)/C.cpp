// Problem: C. Meximum Array 2
// Contest: Codeforces Round 1066 (Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2157/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 23-11-2025 16:54:54 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, k, q; cin >> n >> k >> q;
  vector<int> arr(n, 0);
  vector<int> c(q), l(q), r(q);
  for (int i=0; i<q; i++) {
    cin >> c[i] >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<bool> mex(n, false);
  vector<bool> mn(n, false);
  for (int i=0; i<q; i++) {
    if (c[i] == 1) {
      for (int j=l[i]; j<=r[i]; j++) mn[j] = true;
    } else {
      for (int j=l[i]; j<=r[i]; j++) mex[j] = true;
    }
  }

  for (int i=0; i<n; i++) {
    if (mn[i] && mex[i]) arr[i] = k+1;
    else if (mn[i]) arr[i] = k;
    else if (mex[i]) {
      arr[i] = i % k;
    }
  }

  return arr;
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
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string> ||
                       is_same_v<ReturnValue, const char *>) {
    cout << f(tecs) << el;
  } else if constexpr (is_floating_point_v<ReturnValue>) {
    cout << fixed << setprecision(floating_precision) << f(tecs) << el;
  } else if constexpr (ranges::range<ReturnValue>) {
    for (auto i : f(tecs)) cout << i << ' ';
    cout << el;
  } else {
    f(tecs);
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
// if you see good syntax format, i used clang-format
