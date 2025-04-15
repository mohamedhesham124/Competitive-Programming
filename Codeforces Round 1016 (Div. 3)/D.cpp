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
map<ll,pair<ll,ll>>mp; map<pair<ll,ll>,ll>mk;

pair<ll,ll>find1(ll n,ll d)
{
    if(n==1) return mp[d];
    ll h=1<<(n-1);
    ll hn=h*h;
    if(d<=hn)
    {
        auto p=find1(n-1,d);
        return {p.F,p.S};
    }
    else if(d<=2*hn)
    {
        auto p=find1(n-1,d-hn);
        return {p.F+h,p.S+h};
    }
    else if(d<=3*hn)
    {
        auto p=find1(n-1,d-2*hn);
        return {p.F+h,p.S};
    }
    else
    {
        auto p=find1(n-1,d-3*hn);
        return {p.F,p.S+h};
    }
}
 
ll find2(ll n,ll x,ll y)
{
    if(n==1) return mk[{x,y}];
    ll h=1<<(n-1);
    if(x<=h&&y<=h) return find2(n-1,x,y);
    else if(x>h&&y>h) return h*h+find2(n-1,x-h,y-h);
    else if(x>h&&y<=h) return 2*h*h+find2(n-1,x-h,y);
    else return 3*h*h+find2(n-1,x,y-h);
}
 
void solve()
{
    ll n,q,cn=0; cin >> n >> q; string s;
    while(q--)
    {
        ll x,y; cin >> s;
        if(s=="->")
        {
            cin >> x >> y;
            cout << find2(n,x,y) << nl;
        }
        else
        {
            cin >> x;
            pair<ll,ll>a=find1(n,x);
            cout << a.F << " " << a.S << nl;
        }
    }
}
 
int main()
{
    Hesham;
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    ll t=1;
    fll(i,1,5)
    {
        if(i==1) mp[i]={1,1};
        else if(i==2) mp[i]={2,2};
        else if(i==3) mp[i]={2,1};
        else mp[i]={1,2};
    }
    mk[{1,1}]=1,mk[{2,2}]=2,mk[{2,1}]=3,mk[{1,2}]=4;
    cin >> t;
    while(t--) solve();
 
  return 0;
}