// Problem: E. Two Arrays and Sum of Functions
// Contest: Codeforces Round 560 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/1165/problem/E
// Memory Limit: 256
// Time Limit: 2000
// Start: 15-11-2025 16:24:25 WIB

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
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];

  vector<pll> tmp(n);
  for (int i=0; i<n; i++) {
    tmp[i].F = a[i];
    tmp[i].S = i;
  }

  sort(all(tmp));
  sort(all(b), greater<ll>());

  vector<ll> newb(n);
  for (int i=0; i<n; i++) {
    newb[tmp[i].S] = b[i];
  }

  b = newb;

  // for (int i=0; i<n; i++) cout << b[i] << ' ';
  // cout << el;

  vector<ll> arr(n);
  for (int i=0; i<n; i++) arr[i] = a[i] * b[i];

  vector<ll> mult(n);
  for (ll i=0; i<n; i++) {
    mult[i] = (n-i) * (i+1);
  }

  // sort(all(mult), greater<int>());
  // for (int i=0; i<n; i++) cout << mult[i] << ' ';
  // cout << el;

  ll res = 0;
  for (int i=0; i<n; i++) {
    res += (arr[i] * mult[i]) % 998244353LL;
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
