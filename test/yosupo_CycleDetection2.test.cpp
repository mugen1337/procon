#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../template.hpp"

#include "../Graph2/CycleDetection.hpp"

signed main(){
    int n,m;cin>>n>>m;
    Graph g(n);
    map<pair<int,int>,int> id;
    rep(i,m){
        int u,v;cin>>u>>v;
        id[{u,v}]=i;
        g.add_directed_edge(u,v);
    }
    auto res=CycleDetection(g);
    if(res.empty()){
        cout<<-1<<endl;
        return 0;
    }
    int p=res[0];
    vector<int> ans;
    for(int i=1;i<(int)res.size();i++){
        ans.push_back(id[{p,res[i]}]);
        p=res[i];
    }
    ans.push_back(id[{p,res[0]}]);
    cout<<ans.size()<<"\n";
    for(auto e:ans) cout<<e<<"\n";
    return 0;
}
