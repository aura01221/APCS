#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,ans;
    vector<int> h;
    h.clear();
    ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        h.push_back(0);
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        if(h[i]==0){
            if(i==0){
                ans = ans + h[i+1];
            }
            else if(i==n-1){
                ans = ans + h[i-1];
            }
            else{
                ans = ans + min(h[i-1],h[i+1]);
            }
        }
    }
    cout<<ans;
    return 0 ;
}