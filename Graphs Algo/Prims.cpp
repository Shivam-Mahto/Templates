#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

vector<int> key;
vector<bool> selected;
vector<int> mst;

void prims(int n, vector<pair<int, int>> adj[]) {


	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	
	q.push({0, 0});
	key[0] = 0;
	mst[0] = -1;

	for(int i=0; i<n-1; i++) {

		int node = q.top().second;
		q.pop();

		while(selected[node]) {
			node = q.top().second;
			q.pop();
		}
		
		selected[node] = true;

		for(auto x: adj[node]) {
			int curr = x.first;
			int wt = x.second;
			if((selected[curr] == false) && wt < key[curr]) {
				mst[curr] = node;
				key[curr] = wt;
				q.push({key[curr], curr});
			}
		}
	}


	cout<<"The MST is"<<endl;
	for(int i=1; i<n; i++) {	
		cout<<mst[i]<<" - "<<i<<nline;
	}

}
void solve() {
	
	int n, e;
	cin>>n>>e;

	mst = vector<int> (n, -1);
	selected = vector<bool> (n+1, false);
	key = vector<int> (n, INT_MAX);

	vector<pair<int, int>> adj[n];
	for(int i=0; i<e; i++) {
		int a, b, wt;
		cin>>a>>b>>wt;
		adj[a].pb({b, wt});
		adj[b].pb({a, wt});
	}

	prims(n, adj);
} 

int main() {
	
	int t = 1;
	while(t--) {

		solve();
	}
	return 0;
}

/*
INTPUT	
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
7 1 11
7 8 7
2 8 2
8 6 6
2 5 4
3 5 14
*/