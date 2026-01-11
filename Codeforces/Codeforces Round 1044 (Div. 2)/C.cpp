// Problem: C. The Nether
// Contest: Codeforces Round 1044 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2133/problem/C
// Memory Limit: 256
// Time Limit: 3000
// Start: 24-08-2025 22:11:56 WIB

#include <bits/stdc++.h>
#include <iostream>

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

// 1 = 3
// 2 = 1
// 3 = 3
// 4 = 2
// 5 = 4

auto solve(int tecs=-1)
{
  int n; cin >> n;
  vector<pii> arr;

  int res;
  for (int i=1; i<=n; i++) {
    cout << "? " << i << " " << n << " ";
    for (int j = 1; j <= n; j++) cout << j << " ";
    cout << el;
    cout.flush();

    cin >> res;
    arr.push_back({res, i});
  }

  sort(arr.begin(), arr.end(), greater<pii>());

  vector<int> ord;
  for (int i=0; i<n-1; i++) {
    if (arr[i].first != arr[i + 1].first) {
      ord.push_back(arr[i].second);
      break;
    }
  }

  if (ord.empty()) {
    cout << "! 1 1" << el;
    cout.flush();

    return;
  }

  int curr = arr[0].first - 1;
  int i;
  for (i = 0; i < n; i++) {
    if (curr < arr[i].first) continue;
    if (curr == 1) break;

    cout << "? " << ord.front() << " " << ord.size() + n - i << " ";
    for (int j : ord) cout << j << " ";
    for (int j=i; j < n; j++) {
      cout << arr[j].second << " ";
    }
    cout << el;
    cout.flush();

    cin >> res;
    if (res < arr[0].first) {
      ord.push_back(arr[i - 1].second);
      curr--;
    }
  }

  for (i=n-1; i>=0; i--) if (arr[i-1].first != 1) break;

  for (; i < n; i++) {
    cout << "? " << ord.front() << " " << ord.size() + 1 << " ";
    for (int j : ord) cout << j << " ";
    cout << arr[i].second << el;
    cout.flush();

    cin >> res;
    if (res == arr[0].first) {
      ord.push_back(arr[i].second);
      break;
    }
  }

  cout << "! " << ord.size() << " ";
  for (int i : ord) {
    cout << i << " ";
  }
  cout << el;
  cout.flush();
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
