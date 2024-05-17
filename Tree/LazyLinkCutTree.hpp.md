---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki1249_lct.test.cpp
    title: test/yuki1249_lct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/LazyLinkCutTree.hpp\"\ntemplate<typename Monoid,typename\
    \ OperatorMonoid=Monoid>\nstruct LazyLinkCutTree{\n\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    using G=function<Monoid(Monoid,OperatorMonoid)>;\n    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n\
    \    using Flip=function<Monoid(Monoid)>;\n\n    LazyLinkCutTree(int n,F f,G g,H\
    \ h,Monoid e,OperatorMonoid oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n\
    \        for(int i=0;i<n;i++) nodes.push_back(new Node(e,oe,i));\n    }\n\n  \
    \  LazyLinkCutTree(const vector<Monoid> &v,F f,G g,H h,Monoid e,OperatorMonoid\
    \ oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n       \
    \ for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],oe,i));\n   \
    \ }\n\n    // v \u3092 root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n\
    \        reverse(nodes[v]);\n    }\n\n    // link\n    void link(int ch,int par){\n\
    \        evert(ch);\n        expose(nodes[par]);\n        nodes[ch]->p=nodes[par];\n\
    \        nodes[par]->r=nodes[ch];\n        recalc(nodes[par]);\n    }\n\n    //\
    \ cut v-(v->p)\n    void cut(int v){\n        expose(nodes[v]);\n        nodes[v]->l->p=nullptr;\n\
    \        nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n    // check\
    \ u-v in E, cut u-v\n    void cut(int u,int v){\n        evert(u);\n        expose(nodes[v]);\n\
    \        assert(nodes[u]==nodes[v]->l);\n        nodes[v]->l->p=nullptr;\n   \
    \     nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n\n\n    Monoid query(int\
    \ u,int v){\n        evert(u);\n        expose(nodes[v]);\n\n        return nodes[v]->sum;\n\
    \    }\n\n    void update(int u,int v,OperatorMonoid x){\n        evert(u);\n\
    \        expose(nodes[v]);\n        propagate(nodes[v],x);\n        push(nodes[v]);\n\
    \    }\n    \n    int get_root(int v){\n        Node *cur=nodes[v];\n        expose(cur);\n\
    \        while(cur->l){\n            push(cur);\n            cur=cur->l;\n   \
    \     }\n        splay(cur);\n        return cur->idx;\n    }\n    \n    // not\
    \ connected -> return -1\n    int lca(int u,int v){\n        if(!is_connected(u,v))\
    \ return -1;\n        expose(nodes[u]);\n        return expose(nodes[v]);\n  \
    \  }\n\n    // faster than get_root(u)==get_root(v)\n    bool is_connected(int\
    \ u,int v){\n        if(u==v) return true;\n        expose(nodes[u]);\n      \
    \  expose(nodes[v]);\n        return bool(nodes[u]->p);\n    }\n\n    // \u672A\
    verify\n    int depth(int v){\n        expose(nodes[v]);\n        return size(nodes[v])-1;\n\
    \    }\n    // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\u305F\u3089path query\u3067\
    \u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int distance(int u,int v){\n\
    \        int p=lca(u,v);\n        if(p<0) return -1;\n        return depth(u)+depth(v)-depth(p)*2;\n\
    \    }\n    \nprivate:\n    struct Node{\n        Node *l,*r,*p;\n        Monoid\
    \ val,sum;\n        OperatorMonoid lazy;\n        int sz,idx;\n        bool rev;\n\
    \        bool is_root()const{\n            return (!p or (p->l!=(this) and p->r!=(this)));\n\
    \        }\n        Node(const Monoid &x,const OperatorMonoid &y,int idx)\n  \
    \          :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),lazy(y),sz(1),idx(idx),rev(false){}\n\
    \    };\n\n    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n\
    \    const OperatorMonoid oe;\n    const Flip flip;\n    vector<Node *> nodes;\n\
    \n    int expose(Node *t){\n        Node *pre=nullptr;\n        for(Node *cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            cur->r=pre;\n            recalc(cur);\n\
    \            pre=cur;\n        }\n        splay(t);\n        return pre->idx;\n\
    \    }\n    void rotr(Node *t){\n        auto *x=t->p,*y=x->p;\n        if((x->l=t->r))\
    \ t->r->p=x;\n        t->r=x,x->p=t;\n        recalc(x);\n        recalc(t);\n\
    \        if((t->p=y)){\n            if(y->l==x) y->l=t;\n            if(y->r==x)\
    \ y->r=t;\n            recalc(y);\n        }\n    }\n    void rotl(Node *t){\n\
    \        auto *x=t->p,*y=x->p;\n        if((x->r=t->l))t->l->p=x;\n        t->l=x,x->p=t;\n\
    \        recalc(x);\n        recalc(t);\n        if((t->p=y)){\n            if(y->l==x)\
    \ y->l=t;\n            if(y->r==x) y->r=t;\n            recalc(y);\n        }\n\
    \    }\n\n    int size(Node *t) const { return (t?t->sz:0); }\n\n    void recalc(Node\
    \ *t){\n        t->sum=t->val;\n        if(t->l) t->sum=f(t->l->sum,t->sum);\n\
    \        if(t->r) t->sum=f(t->sum,t->r->sum);\n    }\n\n    void propagate(Node\
    \ *t,OperatorMonoid x){\n        t->lazy=h(t->lazy,x);\n        t->val=g(t->val,x);\n\
    \        t->sum=g(t->sum,x);\n    }\n\n    void push(Node *t){\n        if(t->lazy!=oe){\n\
    \            if(t->l) propagate(t->l,t->lazy);\n            if(t->r) propagate(t->r,t->lazy);\n\
    \            t->lazy=oe;\n        }\n\n        if(t->rev){\n            if(t->l)\
    \ reverse(t->l);\n            if(t->r) reverse(t->r);\n            t->rev=false;\n\
    \        }\n    }\n\n    void reverse(Node *t){\n        swap(t->l,t->r);\n  \
    \      if(flip) t->sum=flip(t->sum);\n        t->rev^=true;\n    }\n    \n   \
    \ void splay(Node *cur){\n        push(cur);\n        while(!cur->is_root()){\n\
    \            Node *par=cur->p;\n            if(par->is_root()){// zig\n      \
    \          push(par);\n                push(cur);\n                if(par->l==cur)\
    \ rotr(cur);\n                else            rotl(cur);\n            }else{//\
    \ zig-zig, zig-zag\n                Node *parpar=par->p;\n                push(parpar);\n\
    \                push(par);\n                push(cur);\n                if(parpar->l==par){\n\
    \                    if(par->l==cur){rotr(par);rotr(cur);}\n                 \
    \   else           {rotl(cur);rotr(cur);}\n                }else{\n          \
    \          if(par->r==cur){rotl(par);rotl(cur);}\n                    else   \
    \        {rotr(cur);rotl(cur);}\n                }\n            }\n        }\n\
    \    }\n};\n"
  code: "template<typename Monoid,typename OperatorMonoid=Monoid>\nstruct LazyLinkCutTree{\n\
    \n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid,OperatorMonoid)>;\n\
    \    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n    using\
    \ Flip=function<Monoid(Monoid)>;\n\n    LazyLinkCutTree(int n,F f,G g,H h,Monoid\
    \ e,OperatorMonoid oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n\
    \        for(int i=0;i<n;i++) nodes.push_back(new Node(e,oe,i));\n    }\n\n  \
    \  LazyLinkCutTree(const vector<Monoid> &v,F f,G g,H h,Monoid e,OperatorMonoid\
    \ oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n       \
    \ for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],oe,i));\n   \
    \ }\n\n    // v \u3092 root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n\
    \        reverse(nodes[v]);\n    }\n\n    // link\n    void link(int ch,int par){\n\
    \        evert(ch);\n        expose(nodes[par]);\n        nodes[ch]->p=nodes[par];\n\
    \        nodes[par]->r=nodes[ch];\n        recalc(nodes[par]);\n    }\n\n    //\
    \ cut v-(v->p)\n    void cut(int v){\n        expose(nodes[v]);\n        nodes[v]->l->p=nullptr;\n\
    \        nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n    // check\
    \ u-v in E, cut u-v\n    void cut(int u,int v){\n        evert(u);\n        expose(nodes[v]);\n\
    \        assert(nodes[u]==nodes[v]->l);\n        nodes[v]->l->p=nullptr;\n   \
    \     nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n\n\n    Monoid query(int\
    \ u,int v){\n        evert(u);\n        expose(nodes[v]);\n\n        return nodes[v]->sum;\n\
    \    }\n\n    void update(int u,int v,OperatorMonoid x){\n        evert(u);\n\
    \        expose(nodes[v]);\n        propagate(nodes[v],x);\n        push(nodes[v]);\n\
    \    }\n    \n    int get_root(int v){\n        Node *cur=nodes[v];\n        expose(cur);\n\
    \        while(cur->l){\n            push(cur);\n            cur=cur->l;\n   \
    \     }\n        splay(cur);\n        return cur->idx;\n    }\n    \n    // not\
    \ connected -> return -1\n    int lca(int u,int v){\n        if(!is_connected(u,v))\
    \ return -1;\n        expose(nodes[u]);\n        return expose(nodes[v]);\n  \
    \  }\n\n    // faster than get_root(u)==get_root(v)\n    bool is_connected(int\
    \ u,int v){\n        if(u==v) return true;\n        expose(nodes[u]);\n      \
    \  expose(nodes[v]);\n        return bool(nodes[u]->p);\n    }\n\n    // \u672A\
    verify\n    int depth(int v){\n        expose(nodes[v]);\n        return size(nodes[v])-1;\n\
    \    }\n    // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\u305F\u3089path query\u3067\
    \u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int distance(int u,int v){\n\
    \        int p=lca(u,v);\n        if(p<0) return -1;\n        return depth(u)+depth(v)-depth(p)*2;\n\
    \    }\n    \nprivate:\n    struct Node{\n        Node *l,*r,*p;\n        Monoid\
    \ val,sum;\n        OperatorMonoid lazy;\n        int sz,idx;\n        bool rev;\n\
    \        bool is_root()const{\n            return (!p or (p->l!=(this) and p->r!=(this)));\n\
    \        }\n        Node(const Monoid &x,const OperatorMonoid &y,int idx)\n  \
    \          :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),lazy(y),sz(1),idx(idx),rev(false){}\n\
    \    };\n\n    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n\
    \    const OperatorMonoid oe;\n    const Flip flip;\n    vector<Node *> nodes;\n\
    \n    int expose(Node *t){\n        Node *pre=nullptr;\n        for(Node *cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            cur->r=pre;\n            recalc(cur);\n\
    \            pre=cur;\n        }\n        splay(t);\n        return pre->idx;\n\
    \    }\n    void rotr(Node *t){\n        auto *x=t->p,*y=x->p;\n        if((x->l=t->r))\
    \ t->r->p=x;\n        t->r=x,x->p=t;\n        recalc(x);\n        recalc(t);\n\
    \        if((t->p=y)){\n            if(y->l==x) y->l=t;\n            if(y->r==x)\
    \ y->r=t;\n            recalc(y);\n        }\n    }\n    void rotl(Node *t){\n\
    \        auto *x=t->p,*y=x->p;\n        if((x->r=t->l))t->l->p=x;\n        t->l=x,x->p=t;\n\
    \        recalc(x);\n        recalc(t);\n        if((t->p=y)){\n            if(y->l==x)\
    \ y->l=t;\n            if(y->r==x) y->r=t;\n            recalc(y);\n        }\n\
    \    }\n\n    int size(Node *t) const { return (t?t->sz:0); }\n\n    void recalc(Node\
    \ *t){\n        t->sum=t->val;\n        if(t->l) t->sum=f(t->l->sum,t->sum);\n\
    \        if(t->r) t->sum=f(t->sum,t->r->sum);\n    }\n\n    void propagate(Node\
    \ *t,OperatorMonoid x){\n        t->lazy=h(t->lazy,x);\n        t->val=g(t->val,x);\n\
    \        t->sum=g(t->sum,x);\n    }\n\n    void push(Node *t){\n        if(t->lazy!=oe){\n\
    \            if(t->l) propagate(t->l,t->lazy);\n            if(t->r) propagate(t->r,t->lazy);\n\
    \            t->lazy=oe;\n        }\n\n        if(t->rev){\n            if(t->l)\
    \ reverse(t->l);\n            if(t->r) reverse(t->r);\n            t->rev=false;\n\
    \        }\n    }\n\n    void reverse(Node *t){\n        swap(t->l,t->r);\n  \
    \      if(flip) t->sum=flip(t->sum);\n        t->rev^=true;\n    }\n    \n   \
    \ void splay(Node *cur){\n        push(cur);\n        while(!cur->is_root()){\n\
    \            Node *par=cur->p;\n            if(par->is_root()){// zig\n      \
    \          push(par);\n                push(cur);\n                if(par->l==cur)\
    \ rotr(cur);\n                else            rotl(cur);\n            }else{//\
    \ zig-zig, zig-zag\n                Node *parpar=par->p;\n                push(parpar);\n\
    \                push(par);\n                push(cur);\n                if(parpar->l==par){\n\
    \                    if(par->l==cur){rotr(par);rotr(cur);}\n                 \
    \   else           {rotl(cur);rotr(cur);}\n                }else{\n          \
    \          if(par->r==cur){rotl(par);rotl(cur);}\n                    else   \
    \        {rotr(cur);rotl(cur);}\n                }\n            }\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Tree/LazyLinkCutTree.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki1249_lct.test.cpp
documentation_of: Tree/LazyLinkCutTree.hpp
layout: document
redirect_from:
- /library/Tree/LazyLinkCutTree.hpp
- /library/Tree/LazyLinkCutTree.hpp.html
title: Tree/LazyLinkCutTree.hpp
---