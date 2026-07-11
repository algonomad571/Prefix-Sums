#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int n;
vector<ll>a,pa,ppa,start,block,pblock;

vector<ll>pref(vector<ll>v){
    int m=v.size();
    vector<ll>res(m+1);

    for(int i=0;i<m;i++){
        res[i+1]=res[i]+v[i];
    }

    return res;
}

ll get(int l,int r1,int r2){
    if(r2<=r1) return 0;

    int cnt=r2-r1;
    ll rem=pa[l]*cnt;
    ll add=ppa[r2+1]-ppa[r1+1];

    return add-rem;
}

pair<int,int>conv(ll x){
    int id=upper_bound(start.begin(),start.end(),x)-start.begin()-1;
    return {id,(int)(x-start[id]+id)};
}

ll query(ll l,ll r){
    auto L=conv(l);
    auto R=conv(r);

    ll ans=pblock[R.first+1]-pblock[L.first];

    if(L.second!=L.first){
        ans-=get(L.first,L.first,L.second);
    }

    if(R.second!=n-1){
        ans-=get(R.first,R.second+1,n);
    }

    return ans;
}

void solve(){
    cin>>n;

    a.resize(n);

    for(int i=0;i<n;i++) cin>>a[i];

    pa=pref(a);
    ppa=pref(pa);

    start={0};

    for(int i=n;i>=1;i--){
        start.push_back(start.back()+i);
    }

    block.resize(n);

    for(int i=0;i<n;i++){
        block[i]=get(i,i,n);
    }

    pblock=pref(block);

    int q;
    cin>>q;

    while(q--){
        ll l,r;
        cin>>l>>r;

        cout<<query(l-1,r-1)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
