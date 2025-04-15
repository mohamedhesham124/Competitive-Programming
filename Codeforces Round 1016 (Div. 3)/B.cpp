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
    ll n,cn=0,cx=0; string s; cin >> s;
    fll(i,0,sz(s))
    {
        if(s[i]!='0')
        {
            cx=0;
            fll(j,0,i)
            {
                if(s[j]=='0') cx++;
            }
        }
        if(cx+1>cn) cn=cx+1;
    }
    cout << sz(s)-cn << nl;
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