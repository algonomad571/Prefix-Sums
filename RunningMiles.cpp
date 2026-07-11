#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<long long> b(n+1);
        for(int i=1; i<=n; i++)cin>>b[i];
        
        vector<long long>pref_max(n+1);
        vector<long long>suff_max(n+2);
        
        const long long NEG = -(1LL<<60);

        pref_max[0] = NEG;
        suff_max[n+1] = NEG;
        
        long long ans=0;
        
        for(int i=1; i<=n; i++){
            pref_max[i]=max(b[i]+i,pref_max[i-1]);
        }
        
        for(int i=n; i>=1; i--){
            suff_max[i]=max(b[i]-i,suff_max[i+1]);
        }
        
        for(int j=2; j<=n-1; j++){
            long long k=pref_max[j-1]+b[j]+suff_max[j+1];
            ans=max(k,ans);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
