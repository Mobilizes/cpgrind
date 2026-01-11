// Problem: Prime Multiples
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2185
// Memory Limit: 512
// Time Limit: 1000
// Start: 28-10-2025 13:38:44 WIB
 
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
 
const bool is_testcases = false;
const bool desync_stdio = false;
 
auto solve(int tecs = -1)
{
  ll n, k; cin >> n >> k;
  vector<ll> arr(k);
  for (int i=0; i<k; i++) cin >> arr[i];
 
  vector<pll> mults;
  for (int i=0; i<(1<<k); i++) {
    ll curr = 1;
    int cnt = 0;
    bool flag = false;
    for (int j=0; j<k; j++) {
      if (i & (1 << j)) {
        if (double(curr) * double(arr[j]) > 1e18) {
          flag = true;
          break;
        }
        curr *= arr[j];
        cnt++;
      }
    }
    if (flag) continue;
    if (cnt > 1) mults.push_back({curr, cnt});
  }
 
  ll res = 0;
  for (int i=0; i<k; i++) {
    res += n / arr[i];
    // if (i >= mults.size()) continue;
    // if (mults[i].S & 1) res += n / mults[i].F;
    // else res -= n / mults[i].F;
  }

  for (int i=0; i<mults.size(); i++) {
    if (mults[i].S & 1) res += n / mults[i].F;
    else res -= n / mults[i].F;
  }
 
  return res;
}
 
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
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string>) {
    cout << f(tecs) << el;
  } else {
    static_assert(
      is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool> || is_integral_v<ReturnValue>,
      "solve() return type is not supported");
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
