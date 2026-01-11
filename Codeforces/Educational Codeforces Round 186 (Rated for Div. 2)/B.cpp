// Problem: B. New Year Cake
// Contest: Educational Codeforces Round 186 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2182/problem/B
// Memory Limit: 512
// Time Limit: 2000
// Start: 31-12-2025 00:27:31 WIB

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
  int a, b; cin >> a >> b;
  int res = 0;
  int cnt = 1;
  int ta = a, tb = b;
  bool flaga = true;
  for (int i=1;; i++) {
    if (flaga) {
      if (ta < cnt) break;
      ta -= cnt;
    } else {
      if (tb < cnt) break;
      tb -= cnt;
    }
    flaga = !flaga;
    res = max(res, i);
    cnt *= 2;
  }

  cnt = 1;
  ta = a, tb = b;
  flaga = false;
  for (int i=1;; i++) {
    if (flaga) {
      if (ta < cnt) break;
      ta -= cnt;
    } else {
      if (tb < cnt) break;
      tb -= cnt;
    }
    flaga = !flaga;
    res = max(res, i);
    cnt *= 2;
  }

  return res;
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

