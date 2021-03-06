template<typename Monoid>
struct LinkCutTree{

    using F=function<Monoid(Monoid,Monoid)>;
    using G=function<Monoid(Monoid)>;

    LinkCutTree(int n,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){
        for(int i=0;i<n;i++) nodes.push_back(new Node(e,i));
    }

    LinkCutTree(const vector<Monoid> &v,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){
        for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],i));
    }

    // v を root に
    void evert(int v){
        expose(nodes[v]);
        reverse(nodes[v]);
    }

    // link
    void link(int ch,int par){
        evert(ch);
        expose(nodes[par]);
        nodes[ch]->p=nodes[par];
        nodes[par]->r=nodes[ch];
        recalc(nodes[par]);
    }

    // cut v-(v->p)
    void cut(int v){
        expose(nodes[v]);
        nodes[v]->l->p=nullptr;
        nodes[v]->l=nullptr;
        recalc(nodes[v]);
    }
    // check u-v in E, cut u-v
    void cut(int u,int v){
        evert(u);
        expose(nodes[v]);
        assert(nodes[u]==nodes[v]->l);
        nodes[v]->l->p=nullptr;
        nodes[v]->l=nullptr;
        recalc(nodes[v]);
    }

    // path query u-v
    // evert(u), expose(v)のあと，splay(v)されているので
    // vをrootとする二分木にpath(u,v)の頂点のみが全て含まれる状態に
    // -> sumを返すだけでよい
    Monoid query(int u,int v){
        evert(u);
        expose(nodes[v]);
        return nodes[v]->sum;
    }

    Monoid get(int v){ return nodes[v]->val; }

    void update(int v,const Monoid &x){
        expose(nodes[v]);
        nodes[v]->val=x;
        recalc(nodes[v]);
    }
    
    int get_root(int v){
        Node *cur=nodes[v];
        expose(cur);
        while(cur->l){
            push(cur);
            cur=cur->l;
        }
        splay(cur);
        return cur->idx;
    }
    
    // not connected -> return -1
    int lca(int u,int v){
        if(!is_connected(u,v)) return -1;
        expose(nodes[u]);
        return expose(nodes[v]);
    }

    // faster than get_root(u)==get_root(v)
    bool is_connected(int u,int v){
        if(u==v) return true;
        expose(nodes[u]);
        expose(nodes[v]);
        return bool(nodes[u]->p);
    }

    // 未verify
    int depth(int v){
        expose(nodes[v]);
        return size(nodes[v])-1;
    }
    // 未verify
    // ヤバかったらpath queryで各頂点1をのせろ
    int distance(int u,int v){
        int p=lca(u,v);
        if(p<0) return -1;
        return depth(u)+depth(v)-depth(p)*2;
    }
    
private:
    struct Node{
        Node *l,*r,*p;
        Monoid val,sum;
        int sz,idx;
        bool rev;
        bool is_root()const{
            return (!p or (p->l!=(this) and p->r!=(this)));
        }
        Node(const Monoid &x,int idx)
            :l(nullptr),r(nullptr),p(nullptr),
            val(x),sum(x),sz(1),idx(idx),rev(false){}
    };

    const F f;
    const Monoid e;
    const G flip;
    vector<Node *> nodes;

    int expose(Node *t){
        Node *pre=nullptr;
        for(Node *cur=t;cur;cur=cur->p){
            splay(cur);
            cur->r=pre;
            recalc(cur);
            pre=cur;
        }
        splay(t);
        return pre->idx;
    }
    // tを1個下へ
    void rotr(Node *t){
        // ((A) - lch - (B)) - t - (C) 
        Node *lch=t->l;// lch->top
        t->l=lch->r;
        if(lch->r) lch->r->p=t;// B
        lch->p=t->p;
        if(t->p){
            if(t->p->l==t) t->p->l=lch;
            if(t->p->r==t) t->p->r=lch;
        }
        lch->r=t;
        t->p=lch;
        recalc(t);
        recalc(lch);
    }
    void rotl(Node *t){
        // (C) - t - ((B) - rch - (A) )
        Node *rch=t->r;// lch->top
        t->r=rch->l;
        if(rch->l) rch->l->p=t;// B
        rch->p=t->p;
        if(t->p){
            if(t->p->l==t) t->p->l=rch;
            if(t->p->r==t) t->p->r=rch;
        }
        rch->l=t;
        t->p=rch;
        recalc(t);
        recalc(rch);
    }

    int size(Node *t) const { return (t?t->sz:0); }

    void recalc(Node *t){
        if(!t) return ;
        t->sz=size(t->l)+1+size(t->r);
        t->sum=t->val;
        if(t->l) t->sum=f(t->l->sum,t->sum);
        if(t->r) t->sum=f(t->sum,t->r->sum);
    }

    void push(Node *t){
        if(t->rev){
            if(t->l) reverse(t->l);
            if(t->r) reverse(t->r);
            t->rev=false;
        }
    }

    void reverse(Node *t){
        swap(t->l,t->r);
        if(flip) t->sum=flip(t->sum);
        t->rev^=true;
    }
    
    void splay(Node *cur){
        push(cur);
        while(!cur->is_root()){
            Node *par=cur->p;
            if(par->is_root()){// zig
                push(par);
                push(cur);
                if(par->l==cur) rotr(par);
                else            rotl(par);
            }else{// zig-zig, zig-zag
                Node *parpar=par->p;
                push(parpar);
                push(par);
                push(cur);
                if(cur==par->l){
                    if(par==parpar->l){
                        rotr(parpar);
                        rotr(par);
                    }else{
                        rotr(par);
                        rotl(parpar);
                    }
                }else{
                    if(par==parpar->l){
                        rotl(par);
                        rotr(parpar);
                    }else{
                        rotl(parpar);
                        rotl(par);
                    }
                }
            }
        }
    }
};
