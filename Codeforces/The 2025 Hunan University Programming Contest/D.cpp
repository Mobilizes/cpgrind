// Problem: D. Keine's Prefix Sum
// Contest: The 2025 Hunan University Programming Contest
// Judge: Codeforces
// URL: https://codeforces.com/gym/105981/problem/D
// Memory Limit: 512
// Time Limit: 2000
// Start: 27-11-2025 14:43:04 WIB

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
  int n; cin >> n;
  vector<int> arr(n+1);
  for (int i=1; i<=n; i++) cin >> arr[i];

  vector<int> pref(2*n+1);
  for (int i=1; i<=2*n; i++) pref[i] = pref[i-1] + arr[(i-1) % n + 1];

  for (int i=1; i<=n; i++) {
    for (int j=i; j<i+n; j++) {
      cout << pref[j] - pref[i-1] << ' ';
    }
    cout << el;
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
