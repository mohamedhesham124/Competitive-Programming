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
    ll n,m,k,cn=1; cin >> n >> m >> k;
    if(k>=n*m)
    {
        fll(i,0,n)
        {
            fll(j,0,m) cout << cn << " ",cn++;
            cout << nl;
        }
    }
    else
    {
        ll v[n][m]; bool ch=0;
        fll(i,0,n)
        {
            fll(j,0,m)
            {
                v[i][j]=cn;
                if(cn==k) cn=1;
                else cn++;
            }
        }
        fll(i,0,n)
        {
            fll(j,0,m)
            {
                if(i-1>0&&v[i-1][j]==v[i][j]) ch=1;
                if(i+1<n&&v[i+1][j]==v[i][j]) ch=1;
                if(j-1>0&&v[i][j-1]==v[i][j]) ch=1;
                if(j+1<m&&v[i][j+1]==v[i][j]) ch=1;
            }
        }
        if(!ch)
        {
            fll(i,0,n)
            {
                fll(j,0,m) cout << v[i][j] << " ";
                cout << nl;
            }
        }
        else
        {
            ll h=0;
            fll(i,0,n)
            {
                if(h==0)
                {
                    fll(j,0,m) cout << v[i][j] << " ";
                }
                else
                {
                    cout << v[i][m-1] << " "; 
                    fll(j,0,m-1) cout << v[i][j] << " ";
                }
                h^=1;
                cout << nl;
            }
        }
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