// Problem: B. Buses
// Contest: 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2172/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: 18-11-2025 17:02:39 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, m, l, x, y; cin >> n >> m >> l >> x >> y;
  vector<pii> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i].F >> arr[i].S;
  sort(all(arr), [](auto a, auto b) {
    if (a.F == b.F) return a.S > b.S;
    return a.F < b.F;
  });

  for (int i=0; i<n; i++) {
    cout << arr[i].F << ' ' << arr[i].S << el;
  }
  cout << el;

  while (m--) {
    int x; cin >> x;
    int l=0, r=n-1;
    int idx=0;
    while (l <= r) {
      int m = (l+r)/2;
      if (arr[m].F <= x) {
        idx = m;
        l = m+1;
      } else {
        r = m-1;
      }
    }

    cout << arr[idx].F << ' ' << arr[idx].S << el;
  }
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
