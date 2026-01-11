// Problem: D. Chicken Jockey
// Contest: Codeforces Round 1044 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2133/problem/D#
// Memory Limit: 256
// Time Limit: 2000
// Start: 25-08-2025 11:27:55 WIB

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = true;
const bool desync_stdio = false;

int n;
vector<int> arr;
vector<int> onestart;
vector<int> oneend;

ll prop(int l, int r, vector<int> & arr) {
  for (int i=1; i<=n; i++) cout << arr[i] << " ";
  cout << "|";
  cout << l << " " << r << el;
  if (l == r) return arr[l];

  int idx = 0;
  int mx = INT_MIN;
  for (int i=l; i<=r-1; i++) {
    int curr = -arr[i];
    if (arr[i+1] > i - l + 1) {
      curr += i - l + 1;
    } else {
      curr += arr[i+1];
      if (i+2 <= r && oneend[i+2] != -1) {
        curr += oneend[i+2] - (i+2) + 1;
        if (oneend[i+2] + 1 <= r) curr++;
      } else if (i+2 <= r) {
        curr++;
      }
    }

    cout << curr << " ";
    if (curr >= mx) {
      mx = curr;
      idx = i;
    }
  }
  cout << el;


  int lr = max(idx - 1, l);
  int rl = min(idx + 1, r);

  ll res = arr[idx];
  arr[idx] = 0;

  if (arr[rl] > idx - l + 1) {
  // cout << arr[1] << "/" << l << "." << r << "\\";
  // cout << idx - l + 1 << ".-.";
    arr[rl] -= idx - l + 1;
  } else {
    arr[rl] = 0;
    rl = min(rl + 1, r);
    if (idx+2 <= r && oneend[idx+2] != -1) {
      rl = r;
      for (int i=idx+2; i<=r; i++) {
        if (arr[i] != 1) {
          rl = i;
          arr[rl]--;
          break;
        }

        arr[i] = 0;
        oneend[i] = -1;
      }
    } else if (idx+2 <= r) {
      arr[idx+2]--;
    }
  }

  return res + prop(rl, r, arr) + prop(l, lr, arr);
}

auto solve(int tecs=-1)
{
  cin >> n;

  arr.clear(); arr.resize(n+1, 0);
  onestart.clear(); onestart.resize(n+1, -1);
  oneend.clear(); oneend.resize(n+1, -1);

  for (int i=1; i<=n; i++) cin >> arr[i];

  onestart.front() = arr.front() == 1 ? 1 : -1;
  for (int i=2; i<=n; i++) {
    if (arr[i] == 1) {
      onestart[i] = onestart[i - 1] == -1 ? i : onestart[i - 1];
    }
  }

  oneend.back() = arr.back() == 1 ? n : -1;
  for (int i=n-1; i>=1; i--) {
    if (arr[i] == 1) {
      oneend[i] = oneend[i + 1] == -1 ? i : oneend[i + 1];
    }
  }

  ll res = prop(1, n, arr);
  cout << res << el;
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
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else {
    static_assert(is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool>,
      "solve() has to be bool or void");
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
