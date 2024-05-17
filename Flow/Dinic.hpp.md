---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2313.test.cpp
    title: test/AOJ_2313.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Flow/Dinic.hpp\"\ntemplate<typename T>\nstruct Dinic{\n\
    \    private:\n    vector<int> lv,iter;\n    // \u5897\u52A0\u9053\n    bool bfs(int\
    \ s,int t){\n        lv.assign(g.size(),-1);\n        queue<int> que;\n      \
    \  lv[s]=0;\n        que.push(s);\n        while(!que.empty() and lv[t]==-1){\n\
    \            int p=que.front();que.pop();\n            for(auto &e:g[p]){\n  \
    \              if(e.cap>0 and lv[e.to]==-1){\n                    lv[e.to]=lv[p]+1;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return lv[t]!=-1;\n    }\n    T dfs(int cur,int t,T flow){\n  \
    \      if(cur==t) return flow;\n        for(int &i=iter[cur];i<(int)g[cur].size();i++){\n\
    \            edge &e=g[cur][i];\n            if(e.cap>0 and lv[cur]<lv[e.to]){\n\
    \                T d=dfs(e.to,t,min(flow,e.cap));\n                if(d>0){\n\
    \                    e.cap-=d;\n                    g[e.to][e.rev].cap+=d;\n \
    \                   return d;\n                }\n            }\n        }\n \
    \       return 0;\n    }\n\n    public:\n    const T inf;\n    struct edge{\n\
    \        int to;\n        T cap;\n        int rev;\n        bool isrev;\n    \
    \    int idx;\n        edge(int to,T cap,int rev,bool isrev,int idx)\n       \
    \ :to(to),cap(cap),rev(rev),isrev(isrev),idx(idx){}\n        edge(){}\n    };\n\
    \    vector<vector<edge>> g;\n\n    Dinic(int V):inf(numeric_limits<T>::max()/2),g(V){}\n\
    \n    void add_edge(int from,int to,T cap,int idx=-1){\n        g[from].emplace_back(to,cap,(int)g[to].size(),false,idx);\n\
    \        g[to].emplace_back(from,0,(int)g[from].size()-1,true,idx);\n    }\n\n\
    \    T max_flow(int s,int t,T lim){\n        T ret=0;\n        while(lim>0 and\
    \ bfs(s,t)){\n            iter.assign(g.size(),0);\n            while(true){\n\
    \                T f=dfs(s,t,lim);\n                if(f==0) break;\n        \
    \        ret+=f;\n                lim-=f;\n            }\n        }\n        return\
    \ ret;\n    }\n    T max_flow(int s,int t){\n        return max_flow(s,t,inf);\n\
    \    }\n\n    // g[u][u_idx]\u3092\u5207\u308B\n    // idx>=0 \u306A\u3089index\u6307\
    \u5B9A\u3057\u3066\u5207\u308B\uFF0E\n    // idx<0  \u306A\u3089\u5168\u90E8\u5207\
    \u308B\n    T cut(int s,int t,int u,int v,int idx=-1){\n        T cr=0;\n    \
    \    for(auto &e:g[u])if(e.to==v and !e.isrev){\n            if(idx<0 or idx==e.idx){\n\
    \                cr+=g[v][e.rev].cap;\n                e.cap=0;\n            \
    \    g[v][e.rev].cap=0;\n            }\n        }\n        if(cr==0) return 0;\n\
    \        // \u8FC2\u56DE\u3057\u3066\u6D41\u3057\u306A\u304A\u3059\n        T\
    \ cap=cr-max_flow(u,v,cr);\n        // \u6D41\u305B\u306A\u304B\u3063\u305F\u5206\
    \u3092\u88DC\u6B63\u3059\u308B\n        if(u!=s and cap!=0) max_flow(u,s,cap);\n\
    \        if(v!=t and cap!=0) max_flow(t,v,cap);\n        return cap;\n    }\n\
    \    // u -> v\u306E\u5BB9\u91CF\u3092f\u3060\u3051\u5897\u3084\u3059\n    T add(int\
    \ s,int t,int u,int v,T f,int idx=-1){\n        add_edge(u,v,f,idx);\n       \
    \ return max_flow(s,t,f);\n    }\n};\n"
  code: "template<typename T>\nstruct Dinic{\n    private:\n    vector<int> lv,iter;\n\
    \    // \u5897\u52A0\u9053\n    bool bfs(int s,int t){\n        lv.assign(g.size(),-1);\n\
    \        queue<int> que;\n        lv[s]=0;\n        que.push(s);\n        while(!que.empty()\
    \ and lv[t]==-1){\n            int p=que.front();que.pop();\n            for(auto\
    \ &e:g[p]){\n                if(e.cap>0 and lv[e.to]==-1){\n                 \
    \   lv[e.to]=lv[p]+1;\n                    que.push(e.to);\n                }\n\
    \            }\n        }\n        return lv[t]!=-1;\n    }\n    T dfs(int cur,int\
    \ t,T flow){\n        if(cur==t) return flow;\n        for(int &i=iter[cur];i<(int)g[cur].size();i++){\n\
    \            edge &e=g[cur][i];\n            if(e.cap>0 and lv[cur]<lv[e.to]){\n\
    \                T d=dfs(e.to,t,min(flow,e.cap));\n                if(d>0){\n\
    \                    e.cap-=d;\n                    g[e.to][e.rev].cap+=d;\n \
    \                   return d;\n                }\n            }\n        }\n \
    \       return 0;\n    }\n\n    public:\n    const T inf;\n    struct edge{\n\
    \        int to;\n        T cap;\n        int rev;\n        bool isrev;\n    \
    \    int idx;\n        edge(int to,T cap,int rev,bool isrev,int idx)\n       \
    \ :to(to),cap(cap),rev(rev),isrev(isrev),idx(idx){}\n        edge(){}\n    };\n\
    \    vector<vector<edge>> g;\n\n    Dinic(int V):inf(numeric_limits<T>::max()/2),g(V){}\n\
    \n    void add_edge(int from,int to,T cap,int idx=-1){\n        g[from].emplace_back(to,cap,(int)g[to].size(),false,idx);\n\
    \        g[to].emplace_back(from,0,(int)g[from].size()-1,true,idx);\n    }\n\n\
    \    T max_flow(int s,int t,T lim){\n        T ret=0;\n        while(lim>0 and\
    \ bfs(s,t)){\n            iter.assign(g.size(),0);\n            while(true){\n\
    \                T f=dfs(s,t,lim);\n                if(f==0) break;\n        \
    \        ret+=f;\n                lim-=f;\n            }\n        }\n        return\
    \ ret;\n    }\n    T max_flow(int s,int t){\n        return max_flow(s,t,inf);\n\
    \    }\n\n    // g[u][u_idx]\u3092\u5207\u308B\n    // idx>=0 \u306A\u3089index\u6307\
    \u5B9A\u3057\u3066\u5207\u308B\uFF0E\n    // idx<0  \u306A\u3089\u5168\u90E8\u5207\
    \u308B\n    T cut(int s,int t,int u,int v,int idx=-1){\n        T cr=0;\n    \
    \    for(auto &e:g[u])if(e.to==v and !e.isrev){\n            if(idx<0 or idx==e.idx){\n\
    \                cr+=g[v][e.rev].cap;\n                e.cap=0;\n            \
    \    g[v][e.rev].cap=0;\n            }\n        }\n        if(cr==0) return 0;\n\
    \        // \u8FC2\u56DE\u3057\u3066\u6D41\u3057\u306A\u304A\u3059\n        T\
    \ cap=cr-max_flow(u,v,cr);\n        // \u6D41\u305B\u306A\u304B\u3063\u305F\u5206\
    \u3092\u88DC\u6B63\u3059\u308B\n        if(u!=s and cap!=0) max_flow(u,s,cap);\n\
    \        if(v!=t and cap!=0) max_flow(t,v,cap);\n        return cap;\n    }\n\
    \    // u -> v\u306E\u5BB9\u91CF\u3092f\u3060\u3051\u5897\u3084\u3059\n    T add(int\
    \ s,int t,int u,int v,T f,int idx=-1){\n        add_edge(u,v,f,idx);\n       \
    \ return max_flow(s,t,f);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Flow/Dinic.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_2313.test.cpp
documentation_of: Flow/Dinic.hpp
layout: document
redirect_from:
- /library/Flow/Dinic.hpp
- /library/Flow/Dinic.hpp.html
title: Flow/Dinic.hpp
---