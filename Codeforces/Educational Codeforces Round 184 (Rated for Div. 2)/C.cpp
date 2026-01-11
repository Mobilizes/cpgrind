// Problem: C. Range Operation
// Contest: Educational Codeforces Round 184 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2169/problem/C
// Memory Limit: 512
// Time Limit: 2000
// Start: 21-11-2025 19:06:18 WIB

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
  int n; cin >> n;
  vector<ll> arr(n+1);
  for (int i=1; i<=n; i++) cin >> arr[i];

  ll sum = 0;
  ll mx = 0;
  int l = n+1;
  int rr = n;
  int r = n;
  for (int i=n; i>=1; i--) {
    if (sum == 0) r = i;
    sum += 2*i - arr[i];
    if (sum < 0) {
      sum = 0;
    } else if (sum > mx) {
      mx = sum;
      l = i;
      rr = r;
    }

    // cout << l << ' ' << r << ' ' << sum << el;
  }

  // cout << l << ' ' << rr << ' ' << mx << el;
  for (int i=1; i<=n; i++) {
    if (i >= l && i <= rr) arr[i] = l + rr;
    // cout << arr[i] << ' ';
  }
  // cout << "; ";

  return accumulate(all(arr), 0LL);

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
