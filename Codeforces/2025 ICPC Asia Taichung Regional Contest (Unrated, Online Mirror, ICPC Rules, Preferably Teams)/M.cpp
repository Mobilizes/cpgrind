// Problem: M. Maximum Distance To Port
// Contest: 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2172/M
// Memory Limit: 256
// Time Limit: 1000
// Start: 20-12-2025 01:00:11 WIB

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
  int n, m, k; cin >> n >> m >> k;
  vector<int> arr(n+1);
  for (int i=1; i<=n; i++) cin >> arr[i];
  vector<vector<int>> graph(n+1);
  for (int i=0; i<m; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> res(k+1, INT_MAX);
  vector<bool> vis(n+1, false);

  queue<pair<int, int>> q;
  q.push({1, 0});

  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    if (vis[f.first]) continue;
    vis[f.first] = true;
    res[arr[f.first]] = f.second;

    for (int i : graph[f.first]) {
      q.push({i, f.second+1});
    }
  }

  res.erase(res.begin());
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
