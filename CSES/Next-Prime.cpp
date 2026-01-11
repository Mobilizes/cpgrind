// Problem: Next Prime
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3396
// Memory Limit: 512
// Time Limit: 1000
// Start: 12-11-2025 10:23:01 WIB

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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
  u64 result = 1;
  base %= mod;
  while (e) {
    if (e & 1) result = (u128)result * base % mod;
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
  u64 x = binpower(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1) return false;
  }
  return true;
}

bool miller_rabin(u64 n)
{
  if (n < 2) return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

auto solve(int tecs = -1)
{
  ll n; cin >> n;
  if (n == 1) return 2LL;
  n += n & 1 ? 2 : 1;
  while (!miller_rabin(n)) {
    n += 2;
  }

  return n;
}

void initialize() {}

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
