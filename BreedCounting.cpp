#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    vector<int>pref1(n+1,0);
    vector<int>pref2(n+1,0);
    vector<int>pref3(n+1,0);

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;

        pref1[i]=pref1[i-1];
        pref2[i]=pref2[i-1];
        pref3[i]=pref3[i-1];

        if(x==1){
            pref1[i]++;
        }
        else if(x==2){
            pref2[i]++;
        }
        else{
            pref3[i]++;
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        int breed1=pref1[b]-pref1[a-1];
        int breed2=pref2[b]-pref2[a-1];
        int breed3=pref3[b]-pref3[a-1];

        cout<<breed1<<" "<<breed2<<" "<<breed3<<endl;
    }

    return 0;
}