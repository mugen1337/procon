---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_CycleDetection.test.cpp
    title: test/yosupo_CycleDetection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/CycleDetection.hpp\"\nvector<int> CycleDetection(vector<vector<int>>\
    \ &g){\n    int n=(int)g.size();\n    vector<int> check(n,0),cyc,pre(n,-1);\n\n\
    \    function<bool(int)> dfs=[&](int cur){\n        check[cur]=1;\n        for(auto\
    \ &to:g[cur]){\n            if(check[to]==0){\n                pre[to]=cur;\n\
    \                if(dfs(to)) return true;\n            }else if(check[to]==1){//\
    \ detect\n                int v=cur;\n                while(v!=to){\n        \
    \            cyc.push_back(v);\n                    v=pre[v];\n              \
    \  }\n                cyc.push_back(v);\n                return true;\n      \
    \      }\n        }\n        check[cur]=2;\n        return false;\n    };\n\n\
    \    rep(i,n){\n        if(check[i]==0){\n            if(dfs(i)){\n          \
    \      reverse(begin(cyc),end(cyc));\n                return cyc;\n          \
    \  }\n        }\n    }\n    return {};\n}\n"
  code: "vector<int> CycleDetection(vector<vector<int>> &g){\n    int n=(int)g.size();\n\
    \    vector<int> check(n,0),cyc,pre(n,-1);\n\n    function<bool(int)> dfs=[&](int\
    \ cur){\n        check[cur]=1;\n        for(auto &to:g[cur]){\n            if(check[to]==0){\n\
    \                pre[to]=cur;\n                if(dfs(to)) return true;\n    \
    \        }else if(check[to]==1){// detect\n                int v=cur;\n      \
    \          while(v!=to){\n                    cyc.push_back(v);\n            \
    \        v=pre[v];\n                }\n                cyc.push_back(v);\n   \
    \             return true;\n            }\n        }\n        check[cur]=2;\n\
    \        return false;\n    };\n\n    rep(i,n){\n        if(check[i]==0){\n  \
    \          if(dfs(i)){\n                reverse(begin(cyc),end(cyc));\n      \
    \          return cyc;\n            }\n        }\n    }\n    return {};\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_CycleDetection.test.cpp
documentation_of: Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/Graph/CycleDetection.hpp
- /library/Graph/CycleDetection.hpp.html
title: Graph/CycleDetection.hpp
---