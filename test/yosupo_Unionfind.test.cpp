#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../template.hpp"

#include "../UnionFind/UnionFind.hpp"

signed main(){
    int n,q;cin>>n>>q;
    UnionFind uf(n);
    while(q--){
        int t,u,v;cin>>t>>u>>v;
        if(t) cout<<uf.sameroot(u,v)<<endl;
        else  uf.unite(u,v);
    }
    return 0;
}