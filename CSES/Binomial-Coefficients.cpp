// Problem: Binomial Coefficients
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1079
// Memory Limit: 512
// Time Limit: 1000
// Start: 16-11-2025 18:03:02 WIB

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

ll mod = 1000000007;
const ll mx_n = 1000000;

ll fact[mx_n+1];
ll inv[mx_n+1];

auto solve(int tecs = -1)
{
  ll a, b; cin >> a >> b;

  return (fact[a] * inv[b] % mod) * inv[a - b] % mod;
}

// ll inv(ll a) {
//   return a <= 1 ? a : mod - (ll)(mod/a) * inv(mod % a) % mod;
// }

ll power(ll x, ll y, ll m) {
    ll res = 1;
    x %= m;
    while(y) {
        if(y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y = y >> 1;
    }
    return res;
}

void initialize()
{
  fact[0] = 1;
  for (int i=1; i<=mx_n; i++) {
    fact[i] = fact[i-1] * i % mod;
  }

  inv[mx_n] = power(fact[mx_n], mod - 2, mod);
  for(int i = mx_n; i >= 1; i--) {
      inv[i - 1] = (inv[i] * i) % mod;
  }
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
