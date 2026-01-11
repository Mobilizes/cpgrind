// Problem: B - Count Subgrid
// Contest: AtCoder Beginner Contest 430
// Judge: AtCoder
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_b
// Memory Limit: 1024
// Time Limit: 2000
// Start: 16-11-2025 00:00:37 WIB

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
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  vector<string> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  map<vector<string>, bool> mp;
  for (int i=0; i<=n-m; i++) {
    for (int j=0; j<=n-m; j++) {
      vector<string> a(m);
      for (int x=0; x<m; x++) {
        string s = "";
        for (int y=0; y<m; y++) {
          s += arr[i+x][j+y];
        }
        a[x] = s;
      }
      mp[a] = true;
    }
  }

  return mp.size();
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
