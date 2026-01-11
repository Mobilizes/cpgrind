// Problem: Sum of Four Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1642
// Memory Limit: 512
// Time Limit: 1000
// Start: 03-12-2025 07:45:03 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, x; cin >> n >> x;
  vector<int> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  vector<vector<int>> raw;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      raw.push_back({arr[i] + arr[j], i+1, j+1});
    }
  }

  sort(all(raw));
  int m = raw.size();

  vector<pii> idxs;
  vector<int> sum;
  for (int i=0; i<m; i++) {
      sum.push_back(raw[i][0]);
      idxs.push_back({raw[i][1], raw[i][2]});
  }

  map<int, bool> mp;

  // for (int i=0; i<sum.size(); i++) {
  //   cout << i << " " << sum[i] << ' ' << idxs[i].first << ' ' << idxs[i].second << el;
  // }

  for (int i=0; i<m; i++) {
    if (mp[sum[i]]) continue;
    mp[sum[i]] = true;
    int a = idxs[i].first, b = idxs[i].second;

    int j = upper_bound(all(sum), x-sum[i]-1) - sum.begin();
    for (; sum[j] == x-sum[i]; j++) {
      int c = idxs[j].first, d = idxs[j].second;
      if (c == a || d == a || c == b || d == b) continue;
      // cout << arr[a-1] << ' ' << arr[b-1] << ' ' << arr[c-1] << ' ' << arr[d-1] << el;
      cout << a << " " << b << " " << c << " " << d << el;
      return;
    }
  }

  cout << "IMPOSSIBLE" << el;
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
