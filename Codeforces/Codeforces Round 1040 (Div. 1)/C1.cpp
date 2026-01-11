// Problem: C1. Interactive RBS (Easy Version)
// Contest: Codeforces Round 1040 (Div. 1)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2129/C1
// Memory Limit: 256
// Time Limit: 2000
// Start: 23-08-2025 12:29:27 WIB

#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
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

auto solve(int tecs=-1)
{
  int n;
  cin >> n;

  int res = 0;
  cout << "? " << n << " ";
  for (int i = 1; i <= n; i++) cout << i << " ";
  cout << el;
  cout.flush();

  cin >> res;
  if (res == 0) {
    int l=1, r=n;
    int m;
    while (l < r) {
      m = (l + r) / 2;
      cout << "? " << m << " ";
      for (int i=m; i>=1; i--) cout << i << " ";
      cout << el;
      cout.flush();

      cin >> res;
      if (res < 1) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    cout << "! ";
    for (int i=1; i<r; i++) cout << ')';
    for (int i=r; i<=n; i++) cout << '(';
    cout << el;
    cout.flush();

    return;
  }

  int l=1, r=n;
  int m;
  while (l < r) {
    m = (l+r)/2;
    cout << "? " << m << " ";
    for (int i=1; i<=m; i++) cout << i << " ";
    cout << el;
    cout.flush();

    cin >> res;
    if (res < 1) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  vector<int> left, right;
  for (int i=1; i<=n; i+=2) {
    if (i == n) {
      cout << "? 2 " << left.back() << " " << n << el;
      cout.flush();

      cin >> res;
      if (res == 1) right.push_back(n);
      else left.push_back(n);
      break;
    }

    int x = i, y = i + 1;

    printf("? 6 %d %d %d %d %d %d\n", r - 1, r, x, r, y, r);
    fflush(stdout);

    cin >> res;
    if (res == 6) {
      left.push_back(x);
      left.push_back(y);
    } else if (res == 3) {
      left.push_back(x);
      right.push_back(y);
    } else if (res == 2) {
      right.push_back(x);
      left.push_back(y);
    } else if (res == 1) {
      right.push_back(x);
      right.push_back(y);
    }
  }

  sort(left.begin(), left.end(), greater<int>());
  sort(right.begin(), right.end(), greater<int>());

  cout << "! ";
  while (!left.empty() && !right.empty()) {
    if (left.back() < right.back()) {
      cout << '(';
      left.pop_back();
    } else {
      cout << ')';
      right.pop_back();
    }
  }

  while (!left.empty()) {
    cout << '(';
    left.pop_back();
  }

  while (!right.empty()) {
    cout << ')';
    right.pop_back();
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
