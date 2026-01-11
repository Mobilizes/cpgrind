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
  int n, m; cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> arr[i][j];

  int res = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<m-1; j++) {
      int cnt = arr[i][j] == '#';
      cnt += arr[i+1][j] == '#';
      cnt += arr[i][j+1] == '#';
      cnt += arr[i+1][j+1] == '#';

      if (cnt == 1) res++;
    }
  }

  int q; cin >> q;
  while (q--) {
    int r, c; cin >> r >> c;
    r--; c--;

    for (int i=r-1; i<=r; i++) {
      for (int j=c-1; j<=c; j++) {
        if (i == -1 || j == -1) continue;
        if (i + 1 >= n || j + 1 >= m) continue;
        int cnt1 = arr[i][j] == '#';
        cnt1 += arr[i+1][j] == '#';
        cnt1 += arr[i][j+1] == '#';
        cnt1 += arr[i+1][j+1] == '#';

        arr[r][c] = (arr[r][c] == '.' ? '#' : '.');

        int cnt2 = arr[i][j] == '#';
        cnt2 += arr[i+1][j] == '#';
        cnt2 += arr[i][j+1] == '#';
        cnt2 += arr[i+1][j+1] == '#';

        // cout << cnt1 << ' ' << cnt2 << el;

        if (cnt1 == 1 && cnt2 != 1) res--;
        else if (cnt1 != 1 && cnt2 == 1) res++;

        arr[r][c] = (arr[r][c] == '.' ? '#' : '.');
      }
    }

    arr[r][c] = (arr[r][c] == '.' ? '#' : '.');

    // cout << res << el;
    if (res == 0) cout << "RECTANGLES" << el;
    else cout << "NO" << el;
  }
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
  } else if constexpr (is_integral_v<ReturnValue>) {
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
