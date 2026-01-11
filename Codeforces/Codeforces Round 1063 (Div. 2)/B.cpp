// Problem: B. Siga ta Kymata
// Contest: Codeforces Round 1063 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2163/problem/B
// Memory Limit: 256
// Time Limit: 1500
// Start: 10-11-2025 22:29:26 WIB

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

  string s; cin >> s;
  if (s[0] == '1' || s[n-1] == '1') {
    cout << -1 << el;
    return;
  }

  vector<pii> mnl(n), mxl(n);
  vector<pii> mnr(n), mxr(n);
  mnl[0] = {n+1, -1};
  mxl[0] = {0, -1};
  for (int i=1; i<n; i++) {
    if (arr[i-1] < mnl[i-1].F) mnl[i] = {arr[i-1], i-1};
    else mnl[i] = mnl[i-1];
    if (arr[i-1] > mxl[i-1].F) mxl[i] = {arr[i-1], i-1};
    else mxl[i] = mxl[i-1];
  }

  mnr[n-1] = {n+1, -1};
  mxr[n-1] = {0, -1};
  for (int i=n-2; i>=0; i--) {
    if (arr[i+1] < mnr[i+1].F) mnr[i] = {arr[i+1], i+1};
    else mnr[i] = mnr[i+1];
    if (arr[i-1] > mxr[i-1].F) mxr[i] = {arr[i-1], i-1};
    else mxr[i] = mxr[i-1];
  }

  string t = "";
  for (int i=0; i<n; i++) t[i] = '0';

  for (int _=0; _<5; _++) {
    for (int i=1; i<n-1; i++) {
      if (s[i] == '0') continue;
      if (t[i] == '1') continue;
      if (arr[i] > mnl[i].F && arr[i] > mnr[i].F) continue;
      if (arr[i] < mxl[i].F && arr[i] < mxr[i].F) continue;
    }
  }
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
