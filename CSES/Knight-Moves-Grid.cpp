// Problem: Knight Moves Grid
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3217
// Memory Limit: 512
// Time Limit: 1000
// Start: 06-12-2025 15:27:32 WIB

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

vector<int> diri = {1, 1, 2, 2, -1, -1, -2, -2};
vector<int> dirj = {2, -2, 1, -1, 2, -2, 1, -1};

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<vector<int>> arr(n, vector<int>(n, -1));
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  queue<vector<int>> q;
  q.push({0, 0, 0});

  while (!q.empty()) {
    auto t = q.front();
    int i = t[0], j = t[1], v = t[2];
    q.pop();

    if (i < 0 || i >= n || j < 0 || j >= n) continue;
    if (vis[i][j]) continue;
    vis[i][j] = true;
    arr[i][j] = v;

    for (int k=0; k<8; k++) {
      q.push({i+diri[k], j+dirj[k], v+1});
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) cout << arr[i][j] << ' ';
    cout << el;
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
