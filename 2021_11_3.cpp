#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<long long> position,machine;
    long long diff[200005]={0};
    long long now=0,ans=0;
    int l,r,w,n,m,t;
    cin>>n>>m;
    while(m--){
        cin>>l>>r>>w;
        diff[l]+=w;
        diff[r+1]-=w;
    }
    for(int i=0;i<n;i++){
        cin>>t;
        position.push_back(t);
        now+=diff[i+1];
        machine.push_back(now);
    }
    sort(position.begin(),position.end());
    sort(machine.begin(),machine.end());
    for(int i=0;i<n;i++){
        ans+=position[i]*machine[n-i-1];
    }
    cout<<ans<<endl;
}