#include<bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define N	    100001
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
using ll = long long;
bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
}
void solve() {
	ll n, num;
	cin >> n;
	vii arr(n);
	rep(i ,0, n) {
		cin >> num;
		arr[i].x = num;
		arr[i].y = i;
	}
	sort(all(arr), sortinrev);
	
	vi ans(n);
	ll cnt = 0, tt = 0;
	rep(i ,0, n) {
		ans[i] = arr[i].y + 1;
		cnt += (arr[i].x * tt + 1);
		tt++;
	}
	cout << cnt << endl;
	rep(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;

}
int main () {
	ll q;
	//cin >> q;
	q = 1;
	while(q--) {
		solve();
	}
	return 0;
}