// Problem: A. Gellyfish and Flaming Peony
// Contest: Codeforces Round 1028 (Div. 1)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2115/A
// Memory Limit: 512
// Time Limit: 2000
// Start: Sat 28 Jun 2025 10:30:28 PM WIB

#include <bits/stdc++.h>
#include <functional>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / gcd(a, b)) * b)
#define tcs() int testcase; cin >> testcase; for(int tecs=0; tecs<testcase; tecs++)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

vector<int> divisors[5001];
int gcds[5001][5001];

void solve()
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  if (n == 1) {
    cout << 0 << el;
    return;
  }

  int tgcd = gcds[arr[0]][arr[1]];

  for (int i=2; i<n; i++) {
    tgcd = gcds[tgcd][arr[i]];
  }

  int rest = 0;
  for (int i=0; i<n; i++) if (arr[i] != tgcd) rest++;

  if (rest != n) {
    cout << rest << el;
    return;
  }

  int dist[5001];
  queue<int> q;

  for (int i=1; i<=5000; i++) dist[i] = 100000;

  for (int a : arr) {
    if (dist[a] == 100000) {
      dist[a] = 0;
      q.push(a);
    }
  }

  int res = 100000;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    if (a == tgcd) {
      res = dist[a];
      break;
    }

    for (int b : arr) {
      if (b == a) continue;
      int curr = gcds[a][b];
      if (dist[curr] > dist[a] + 1) {
        dist[curr] = dist[a] + 1;
        q.push(curr);
      }
    }
  }

  cout << res + n - 1 << el;
}

int main()
{
  for (int i=1; i<=5000; i++) {
    vector<int> v;
    for (int j=1; j<=sqrt(i); j++) {
      if (i % j != 0) continue;
      if (i / j != j) v.push_back(i / j);
      v.push_back(j);
    }
    divisors[i] = v;
  }

  for (int i=0; i<=5000; i++) {
    gcds[i][0] = i;
    gcds[0][i] = i;
    gcds[i][i] = i;
  }

  for (int x=1; x<=5000; x++) {
    for (int y=1; y<x; y++) {
      gcds[x][y] = gcds[y][x % y];
      gcds[y][x] = gcds[y][x % y];
    }
  }

  tcs() solve();
  // solve();
}

