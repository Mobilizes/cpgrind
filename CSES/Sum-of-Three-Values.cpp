// Problem: Sum of Three Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1641
// Memory Limit: 512
// Time Limit: 1000
// Start: 17-11-2025 03:12:08 WIB

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
  int n, k; cin >> n >> k;
  vector<pii> arr(n);
  for (int i=0; i<n; i++) {
    cin >> arr[i].F;
    arr[i].S = i+1;
  }

  sort(all(arr));

  // for (int i=0; i<n; i++) cout << arr[i] << ' ';
  // cout << el;

  for (int i=0; i<n-2; i++) {
    int target = k - arr[i].F;
    int l=i+1, r=n-1;
    while (l < r) {
      int curr = arr[l].F + arr[r].F;
      if (curr == target) {
        cout << arr[i].S << ' ' << arr[l].S << ' ' << arr[r].S << el;
        return;
      } else if (curr < target) {
        l++;
      } else {
        r--;
      }
    }
  }

  cout << "IMPOSSIBLE" << el;
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
