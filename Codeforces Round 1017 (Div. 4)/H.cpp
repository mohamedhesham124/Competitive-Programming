// بسم الله الرحمن الرحيم

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define Hesham ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#define ordered_set tree<ll,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define fllm(i,a,b) for(long long i=a;i>=b;i--)
#define f(b,a) cout << fixed << setprecision(b) << a << endl;
#define rall(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define sub_mod(a,b,m) ((((a)%m)-((b)%m)+m)%m)
#define add_mod(a,b,m) ((((a)%m)+((b)%m))%m)
#define mult_mod(a,b,m) ((((a)%m)*((b)%m))%m)
#define pi 3.14159265358979323846
#define all(x) x.begin(),x.end()
#define ull unsigned long long
#define ld long double
#define ll long long
#define sz(s) s.size()
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define F first
#define S second
#define nl '\n'

using namespace std;
//using namespace __gnu_pbds;

vector<ll>divisors(ll n)
{
    vector<ll>c;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c.push_back(i);
            if(n/i!=i) c.push_back(n/i);
        }
    }
    return c;
}

void solve()
{
    ll n,q; cin >> n >> q; vector<ll>v(n); map<ll,vector<ll>>mp;
    fll(i,0,n) 
    {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    while(q--)
    {
        ll l,r,k,cn=0; cin >> k >> l >> r; l--,r--; 
        while(l<=r)
        {
            ll h=r;
            for(auto &i:divs[k])
            {
                if(sz(mp[i])>0)
                {
                    auto x=lower_bound(all(mp[i]),l)-mp[i].begin();
                    if(x<sz(mp[i])&&mp[i][x]<=r) h=min(h,mp[i][x]);
                }
            }
            cn+=(h-l)*k;
            while(k%v[h]==0) k/=v[h];
            if(k==1)
            {
                cn+=(r-h+1);
                break;
            }
            cn+=k,l=h+1;
        }
        cout << cn << nl;
    }
}

int main()
{
    Hesham;
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    ll t=1;
    fll(i,2,100001)
    {
        vector<ll>d=divisors(i);
        fll(j,0,sz(d)) divs[i].push_back(d[j]);
    }
    cin >> t;
    while(t--) solve();

  return 0;
}