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
  vector<int> arr(n);
  vector<string> res(n, string(m, '0'));

  for (int i=0; i<n; i++) cin >> arr[i];

  bool flag = true;
  vector<int> mx(n, 0);
  for (int i=0; i<n; i++) {
    if (arr[i] == m/2+1) {
      flag = false;
      mx[i] = m/2+1;
      if (i-1>=0 && (mx[i-1] == 0 || mx[i-1] == m/2)) {
        mx[i-1] = m/2;
      }
      if (i+1<n) {
        mx[i+1] = m/2;
      }
    }
  }

  if (m % 2 == 0 || flag) {
    for (int i=0; i<n; i++) {
      int cnt = arr[i];
      for (int j=i&1; j<m; j+=2) {
        if (cnt == 0) break;
        cnt--;
        res[i][j] = '1';
      }

      if (cnt > 0) {
        cout << -1 << el;
        return;
      }
    }
  } else {
    for (int i=0; i<n; i++) {
      if (mx[i] == 0) continue;
      int cnt = arr[i];
      for (int j=m-1-(mx[i]==m/2); j>=0; j-=2) {
        if (cnt == 0) break;
        if ((i-1>=0 && res[i-1][j] == '1') || (i+1<n && res[i+1][j] == '1') || (j+1<m && res[i][j+1] == '1')) continue;
        cnt--;
        res[i][j] = '1';
      }

      if (cnt > 0) {
        cout << -1 << el;
        return;
      }
    }

    vector<string> a(m-1);
    for (int i=0; i<m-1; i++) {
      for (int j=0; j<m; j++) {
        if (j-1>=0 && a[i][j-1] == '1') a[i] += '0';
        else if (i-1>=0 && a[i-1][j] == '1') a[i] += '0';
        else if (i == j) {
          a[i] += '0'; j++;
          a[i] += '0';
        }
        else a[i] += '1';
      }

      // cout << a[i] << el;
    }
    // cout << el;

    int lsti = -1;
    for (int k=0; k<n; k++) {
      if (mx[k] != m/2+1) continue;
      int gap = k - lsti - 3;
      if (gap % 2 == 0) {
        int l=0;
        for (int i=lsti+2; i<k-1; i++) {
          if (l == m-1) l = m-3;
          int cnt = arr[i];
          for (int j=m-1; j>=0; j--) {
            if (cnt == 0) break;
            if (i != k-2 && a[l][j] == '1') {
              cnt--;
              res[i][j] = '1';
            } else if (i == k-2) {
              if ((i-1>=0 && res[i-1][j] == '1') || (i+1<n && res[i+1][j] == '1') || (j-1>=0 && res[i][j-1] == '1') || (j+1<m && res[i][j+1] == '1')) continue;
              cnt--;
              res[i][j] = '1';
            }
          }

          if (cnt > 0) {
            // for (int i=0; i<n; i++) {
            //   cout << res[i] << el; 
            // }
            // cout << i << ' ' << cnt << el;
            cout << -1 << el;
            return;
          }
          l++;
        }
      } else {
        for (int i=lsti+2; i<k-1; i++) {
          int cnt = arr[i];
          for (int j=(i-lsti+2)&1; j<m; j+=2) {
            if (cnt == 0) break;
            cnt--;
            res[i][j] = '1';
          }

          if (cnt > 0) {
            cout << -1 << el;
            return;
          }
        }
      }
      lsti = k;
    }

    for (int i=lsti+2; i<n; i++) {
      int cnt = arr[i];
      for (int j=0; j<m; j++) {
        if (cnt == 0) break;
        if ((i-1>=0 && res[i-1][j] == '1') || (i+1<n && res[i+1][j] == '1') || (j-1>=0 && res[i][j-1] == '1') || (j+1<m && res[i][j+1] == '1')) continue;
        cnt--;
        res[i][j] = '1';
      }

      if (cnt > 0) {
        cout << -1 << el;
        return;
      }
    }
  }

  for (int i=0; i<n; i++) {
    cout << res[i] << el; 
  }
}

  /*
   * 1010101
   * 0101010
   * 0010101
   * 1001010
   * 0100101
   * 1010010
   * 0101001
   * 1010010
   * 0101001
   * 1010010
   * 0101001
   * 
   * 0101010
   * 1010101
   * if gap / 2 is even, just continue
   * if gap / 2 is odd && gap / 2 <= 3, keep doing the pattern, and greedily fill the last row
   * if gap / 2 is odd && gap / 2 > 3, after ,just copy the previous 2 row in the last 2 rows, then greedily fill the last row
  */

  /*
   * 1010101
   * 0101010
   * 0010101
   * 1000000
   * 0101010
   * 1010101
  */

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
