// Problem: C - Truck Driver
// Contest: AtCoder Beginner Contest 430
// Judge: AtCoder
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_c
// Memory Limit: 1024
// Time Limit: 2000
// Start: 16-11-2025 00:07:11 WIB

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
  int n, A, B; cin >> n >> A >> B;
  string s; cin >> s;

  int res = 0;
  int l=0, r=0;
  int a=s[0] == 'a', b=s[0] == 'b';
  while (l <= r) {
    // cout << l+1 << ' ' << r+1 << ' ' << a << ' ' << b << ' ';
    if (a >= A && b < B) {
      res++;
      // cout << "yes";
    }
    // cout << el;
    if (b >= B && l + 1 <= r) {
      if (s[l] == 'a') a--;
      else b--;
      l++;
    } else if (r + 1 < n) {
      if (s[r + 1] == 'b' && b + 1 == B && l + 1 <= r) {
        if (s[l] == 'a') a--;
        else b--;
        l++;
      } else {
        r++;
        if (s[r] == 'a') a++;
        else b++;
      }
    } else {
      if (s[l] == 'a') a--;
      else b--;
      l++;
    }
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
