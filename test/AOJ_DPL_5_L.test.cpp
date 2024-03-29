#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別しない
箱: 区別しない
入れ方: 箱ごと1個以上
*/

signed main(){
    int n,k;cin>>n>>k;
    if(n<k) cout<<0<<endl;
    else cout<<F.partition_function(n-k,k)<<endl;
    return 0;
}