// Problem: C. Annoying Game
// Contest: Codeforces Round 1067 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2158/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 29-11-2025 23:03:22 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
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
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];

  vector<ll> mxb(n);
  mxb[0] = b[0];
  for (int i=1; i<n; i++) {
    mxb[i] = max(mxb[i-1], b[i]);
  }

  priority_queue<pll> pq;
  ll sum = -INT_MAX;
  ll curr = 0;
  int r=0;
  for (int i=0; i<n; i++) {
    curr = max(curr + a[i], a[i]);

    if (curr > sum) {
      sum = curr;
      r = i;
    }

    pq.push({sum, r});
  }

  if (k % 2 == 0) return sum;

  ll res = sum;
  while (!pq.empty()) {
    cout << res << " ";
    res = max(res, pq.top().first + b[pq.top().second]);
    pq.pop();
  }
  cout << "; ";

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
