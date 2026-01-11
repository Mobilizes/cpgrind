// Problem: E1. Submedians (Easy Version)
// Contest: Codeforces Round 1039 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2128/problem/E1
// Memory Limit: 512
// Time Limit: 3000
// Start: Wed 30 Jul 2025 09:07:44 AM WIB

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;

using namespace std;
using namespace __gnu_pbds;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define tcs() int testcase; cin >> testcase; for(int tecs=1; tecs<=testcase; tecs++)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

using oset = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int tecs = -1)
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  oset s;
  map<int, int> mp;
  for (int i = 0; i < k; i++) {
    s.insert({arr[i], mp[arr[i]]++});
  }

  int med = s.find_by_order(k / 2)->first, ansl = 0, ansr = k;
  if ((k & 1) && k != n) {
    for (int i = k; i <= n; i++) {
      int curr = s.find_by_order(k / 2)->first;
      if (curr > med) {
        med = curr;
        ansl = i - k;
        ansr = i - 1;
      }

      if (i == n) break;

      s.erase({arr[i - k], --mp[arr[i - k]]});
      s.insert({arr[i], mp[arr[i]]++});
    }

    k++;
    s.clear();
    mp.clear();
    oset s;
    for (int i = 0; i < k; i++) {
      s.insert({arr[i], mp[arr[i]]++});
    }

    for (int i = k; i <= n; i++) {
      int curr = s.find_by_order(k / 2)->first;
      if (curr > med) {
        med = curr;
        ansl = i - k;
        ansr = i - 1;
      }

      if (i == n) break;

      s.erase({arr[i - k], --mp[arr[i - k]]});
      s.insert({arr[i], mp[arr[i]]++});
    }
  } else {
    for (int i = k; i <= n; i++) {
      int curr = s.find_by_order(k / 2)->first;
      if (curr > med) {
        med = curr;
        ansl = i - k;
        ansr = i - 1;
      }

      if (i == n) break;

      s.erase({arr[i - k], --mp[arr[i - k]]});
      s.insert({arr[i], mp[arr[i]]++});
    }
  }

  std::cout << med << " " << ansl + 1 << " " << ansr + 1;
  cout << el;
}

int main()
{
  tcs() solve(tecs);
  // solve();
}

