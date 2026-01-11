// Problem: Counting Coprime Pairs
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2417
// Memory Limit: 512
// Time Limit: 1000
// Start: 02-11-2025 11:47:04 WIB

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

const int mx = 1000000;
vector<int> lpf;
vector<int> mobius;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n);
  vector<int> cnt(mx+1, 0);
  for (int i=0; i<n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  ll res = 0;
  for (int i=1; i<=mx; i++) {
    if (!mobius[i]) continue;

    ll d = 0;
    for (int j=i; j<=mx; j+=i) d += cnt[j];

    res += (d*(d-1)/2) * mobius[i];
  }

  return res;
}

// clang-format off
void initialize()
{
  lpf.assign(mx+1, 0);
  mobius.assign(mx+1, 0);

  for (int i=2; i<=mx; i++) {
    if (lpf[i]) continue;
    for (int j=i; j<=mx; j+=i) {
      if (!lpf[j]) lpf[j] = i;
    }
  }

  for (int i=1; i<=mx; i++) {
    if (i == 1) {
      mobius[i] = 1;
      continue;
    }

    if (lpf[i/lpf[i]] == lpf[i]) mobius[i] = 0;
    else mobius[i] = -1 * mobius[i/lpf[i]];
  }
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
