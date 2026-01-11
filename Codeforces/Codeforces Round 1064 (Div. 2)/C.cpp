// Problem: C. Cyclic Merging
// Contest: Codeforces Round 1064 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2166/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 16-11-2025 22:34:21 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;


auto solve(int tecs = -1)
{
  int n; cin >> n;

  vector<int> arr(n);
  map<int, vector<int>> mp;
  for (int i=0; i<n; i++) {
    cin >> arr[i];
    mp[arr[i]].push_back(i);
  }

}

// 7
// 5 2 3 1 4 5 3, 0
// 5 2 3 4 5 3, 3 +3
// 5 3 4 5 3, 6 +3
// 5 4 5 3, 10 +4
// 5 4 5, 15 +5
// 5 5, 20 +5
// 5, 25 +5

// 7
// 1 1 4 5 1 4 1, 0
// 1 4 5 1 4 1, 1
// 4 5 1 4 1, 2
// 4 5 1 4, 6
// 4 5 4, 10
// 4 5, 14
// 5, 19

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
