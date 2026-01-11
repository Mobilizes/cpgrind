// Problem: B. Even Modulo Pair
// Contest: Codeforces Global Round 30 (Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2164/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: 06-11-2025 21:40:01 WIB

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
  for (int i=0; i<n; i++) cin >> arr[i];

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (arr[j] % arr[i] % 2 == 0) {
        cout << arr[i] << " " << arr[j] << el;
        return;
      }
    }
  }

  cout << -1 << el;
  return;
}

// q < p, p mod q has to be even
// p & 1, then find q thats odd and p / q is odd
// if p = 13, q = 11, 9, 1
// p / q == 1 OK
// if p = 21, q = 19, 17, 15, 13, 11, 7, 3, 1
//
// p & 1 = find q > (p / 2) && q <= (p / 1) or q > (p / 4) && q <= (p / 3) or q > (p / 6) && q <= (p / 5) ...
//
// if p = 18, q = 16, 14, 12, 10, 9, 8, 7, 6, 4, 3, 2, 1

// clang-format off
void initialize()
{
}
// clang-format on

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
