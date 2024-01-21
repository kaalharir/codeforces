#include<bits/stdc++.h>
#define ll long long
#define mid (l+r>>1)
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
int N,fa[300005],lst[300005],dfn[300005],low[300005],nxt[300005],tot,col[300005];
vector<int>road[300005],son[300005];
struct SGT{
	int mx[1200005],tag[1200005];
	void build(int p,int l,int r){
		mx[p]=tag[p]=0;if(l==r)return;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void pp(int p){mx[p]=max(mx[ls],mx[rs]);}
	void pd(int p){mx[ls]+=tag[p],mx[rs]+=tag[p],tag[ls]+=tag[p],tag[rs]+=tag[p];tag[p]=0;}
	void add(int p,int l,int r,int a,int b){
		if(a<=l&&r<=b){++mx[p],++tag[p];return;}pd(p);
		if(a<=mid)add(ls,l,mid,a,b);if(b>mid)add(rs,mid+1,r,a,b);
		pp(p); 
	}
	int qry(int p,int l,int r,int a,int b){
        if(a<=l&&r<=b)return mx[p];pd(p);int res=0;
        if(a<=mid)res=max(res,qry(ls,l,mid,a,b));
        if(b>mid)res=max(res,qry(rs,mid+1,r,a,b));
        return res;
	}
}t;
void dfs1(int u){
	if(lst[col[u]])nxt[u]=lst[col[u]];else nxt[u]=0;dfn[u]=low[u]=++tot;
	int va=lst[col[u]];lst[col[u]]=u;if(nxt[u])son[nxt[u]].push_back(u);
	for(int v:road[u])dfs1(v),low[u]=low[v];
	lst[col[u]]=va;
}
ll ans;
void dfs2(int u){
	for(int v:road[u])dfs2(v);
    int lst=dfn[u];
    for(int v:son[u]){
    	if(dfn[v]>lst)t.add(1,1,N,lst,dfn[v]-1);
    	lst=low[v]+1;
	}
	if(lst<=low[u])t.add(1,1,N,lst,low[u]);
    int mx=1;
    for(int v:road[u]){
    	int now=t.qry(1,1,N,dfn[v],low[v]);
		ans=max(ans,1ll*mx*now);mx=max(mx,now);
	} ans=max(ans,1ll*mx);
}
void solve(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i)road[i].clear(),son[i].clear(),nxt[i]=dfn[i]=low[i]=0;tot=0;
	for(int i=2;i<=N;++i)scanf("%d",&fa[i]),road[fa[i]].push_back(i);
	for(int i=1;i<=N;++i)scanf("%d",&col[i]),lst[i]=0;
	t.build(1,1,N);dfs1(1);ans=0;dfs2(1);
	printf("%lld\n",ans);
}
int main() {
	int t;cin>>t;
	while(t--)solve();
	return 0;
}