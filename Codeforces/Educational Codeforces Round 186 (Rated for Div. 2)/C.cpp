// Problem: C. Production of Snowmen
// Contest: Educational Codeforces Round 186 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2182/problem/C
// Memory Limit: 512
// Time Limit: 2000
// Start: 31-12-2025 00:32:19 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
  vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
  vector<int> c(n); for (int i=0; i<n; i++) cin >> c[i];

  ll res1 = 0, res2 = 0;
  for (int i=0; i<n; i++) {
    bool valid = true;
    for (int j=0; j<n; j++) {
      if (a[j] >= b[(j+i)%n]) valid = false;
    }
    if (valid) res1++;

    valid = true;
    for (int j=0; j<n; j++) {
      if (b[j] >= c[(j+i)%n]) valid = false;
    }
    if (valid) res2++;
  }

  return res1 * res2 * n;
}

// 5
// 1 4 2 3 5
// 6 4 5 7 6
// 7 5 8 10 10

// 2, 1

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
