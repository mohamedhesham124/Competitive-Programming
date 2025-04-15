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

void solve()
{
    ll n,cn=0,cz=0,ch=0; cin >> n; deque<ll>a;
    fll(i,0,n)
    {
        ll s; cin >> s;
        if(s==3)
        {
            ll k; cin >> k;
            if(!ch) a.push_back(k);
            else a.push_front(k);
            cn+=k*sz(a),cz+=k;
        }
        else if(s==1)
        {
            ll h;
            if(!ch)
            {
                h=a.back();
                a.push_front(h),a.pop_back();
            }
            else
            {
                h=a.front();
                a.push_back(h),a.pop_front();
            }
            cn+=cz,cn-=h*sz(a);
        }
        else
        {
            cn=(sz(a)+1)*cz-cn;
            ch^=1;
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
    cin >> t;
    while(t--) solve();

  return 0;
}