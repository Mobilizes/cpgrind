// Problem: C. Two Colors
// Contest: Educational Codeforces Round 176 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2075/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 25-11-2025 16:28:05 WIB

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
  int n, m; cin >> n >> m;
  vector<ll> arr(m);
  for (int i=0; i<m; i++) cin >> arr[i];

  sort(all(arr));

  ll sum = 0;
  for (ll i=1; i<=n; i++) {
    ll j = n - i;
    ll l = m - (lower_bound(all(arr), i) - arr.begin());
    ll r = m - (lower_bound(all(arr), j) - arr.begin());
    sum += l * r - min(l, r);
  }

  return sum;
}

// 14
// 5 11 15
// 5 15
// 5 9
// 4 10
// 3 11
// 2 12
// 1 13
//
// 12
// 5 8 9
//
// 12
// 5 8
// 5 7
// 4 8
// 2*2 = 4
//
// 12
// 5 9
// 5 7
// 4 8
// 3 9
// 3*2 = 6
//
// 12
// 8 9
// 3 9
// 4 8
// 5 7
// 6 6
// 7 5
// 8 4
// 6*2 = 12
//
// 12
// 5 10 12
//
// 5 10
// 5 7
// 4 8
// 3 9
// 2 10
// 4*2 = 8
// 
// 5 12
// 5 7
// 4 8
// 3 9
// 2 10
// 1 11
// 5*2 = 10
//
// 10 12
// 10 2
// 9 3
// 8 4
// 7 5
// 6 6
// 5 7
// 4 8
// 3 9
// 2 10
// 1 11
// 10*2 = 20

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
