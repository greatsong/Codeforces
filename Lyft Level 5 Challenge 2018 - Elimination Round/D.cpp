# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a / GCD(a, b) * b; }
ll INV(ll a, ll m) {
	ll m0 = m, y = 0, x = 1;
	if (m == 1)	return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += m0;
	return x;
}
pll EXGCD(ll a, ll b) {
	if (b == 0) return { 1,0 };
	auto t = EXGCD(b, a%b);
	return { t.second,t.first - t.second*(a / b) };
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()


int n;
ll a[504];
map<ll,int> M;
ll sq4(ll x){
  ll st = 1;
  ll en = 37700;
  while(st < en){
    ll mid = (st+en)>>1;
    ll calc = mid*mid*mid*mid;
    if(calc > x) en = mid-1;
    else if(calc == x) return mid;
    else st = mid+1;
  }
  if(st*st*st*st == x) return st;
  if(en*en*en*en == x) return en;
  return -1;
}
ll sq3(ll x){
  ll st = 1;
  ll en = 1259922;
  while(st < en){
    ll mid = (st+en)>>1;
    ll calc = mid*mid*mid;
    if(calc > x) en = mid-1;
    else if(calc == x) return mid;
    else st = mid+1;
  }
  if(st*st*st == x) return st;
  if(en*en*en == x) return en;
  return -1;
}
ll sq2(ll x){
  ll st = 1;
  ll en = 1414213563;
  while(st < en){
    ll mid = (st+en)>>1;
    ll calc = mid*mid;
    if(calc > x) en = mid-1;
    else if(calc == x) return mid;
    else st = mid+1;
  }
  if(st*st == x) return st;
  if(en*en == x) return en;
  return -1;
  
}
vl pq;
set<ll> plist;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
 // pf1l(sq2(9));
  sf1(n);
  rep(i,0,n){
    ll t;
    sf1(t);
    ll s4 = sq4(t);
    if(s4 != -1){
      plist.insert(s4);
      M[s4] += 4;
      continue;
    }    
    ll s3 = sq3(t);
    if(s3 != -1){
      plist.insert(s3);
      M[s3] += 3;
      continue;
    }
    ll s2 = sq2(t);
    if(s2 != -1){
      plist.insert(s2);
      M[s2] += 2;
      continue;
    }
    pq.pb(t);
  }
  for(int i = 0; i < sz(pq); i++){
    for(int j = i+1; j < sz(pq); j++){
      if(pq[i] == pq[j]) continue;
      ll g = GCD(pq[i], pq[j]);
      if(g == 1) continue;
      plist.insert(g);
      plist.insert(pq[i]/g);
      plist.insert(pq[j]/g);
    }
  }
  map<ll,int> left;
  for(int i = 0; i < sz(pq); i++){
    for(auto p : plist){
      if(pq[i] % p != 0) continue;
      M[p]++;
      M[pq[i]/p]++;
      pq[i] = -1;
      break;
    }
    if(pq[i] != -1) left[pq[i]]++;
  }
  ll tot = 1;
  ll mod = 998244353;
  for(auto e : left){
    tot = (tot*(e.Y+1)*(e.Y+1))%mod;
  }
  for(auto e : M){
    tot = (tot*(e.Y+1))%mod;
  }
  pf1l(tot);

}