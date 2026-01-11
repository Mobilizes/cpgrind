// Problem: System of Linear Equations
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3154
// Memory Limit: 512
// Time Limit: 1000
// Start: 18-11-2025 22:51:42 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  m++;
  vector<vector<double>> arr(n, vector<double>(m));
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> arr[i][j];
    }
  }

  int i=0, j=0;
  while (i < n && j < m-1) {
    // cout << i << ' ' << j << el;
    double mx = 0;
    int idx = 0;
    for (int k=i; k<n; k++) {
      if (abs(arr[k][j]) > mx) {
        mx = abs(arr[k][j]);
        idx = k;
      }
    }
    double v = arr[idx][j];
    if (arr[idx][j] == 0) j++;
    else {
      swap(arr[i], arr[idx]);
      for (int k=i+1; k<n; k++) {
        double mult = arr[k][j] / arr[i][j];
        arr[k][j] = 0;
        for (int l=j+1; l<m; l++) {
          arr[k][l] -= arr[i][l] * mult;
        }
      }
      i++; j++;
    }
  }

  for (int j=0; j<m-1; j++) {
    double mx = 0;
    int idx = 0;
    for (int i=0; i<n; i++) {
      if (abs(arr[i][j]) > mx) {
        mx = abs(arr[i][j]);
        idx = i;
      }
    }
    double v = arr[idx][j];
    for (int k=0; k<m; k++) {
      arr[idx][k] /= v;
    }
  }

  for (int j=0; j<m-1; j++) {
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << el;
  }
}

void initialize()
{
  cout << fixed << setprecision(floating_precision);
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
