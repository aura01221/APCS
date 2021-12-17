#include<iostream>
#include<vector>
using namespace std;

int n,m;
int data[40005],boss[40005],siz[40005];
vector<int> ans;

int find(int x){
    if(boss[x] == x)
        return x;
    boss[x] = find(boss[x]);
    return boss[x];
}
int merge(int a,int b){
    if(siz[a]<siz[b]){
        siz[b]+=siz[a];
        boss[a] = b;
    }
    else{
        siz[a]+=siz[b];
        boss[b] = a;
    }
}
void reset(){
    for(int i=0;i<2*n;i++){
        siz[i]=1; boss[i]=i;
    }
    for(int i=0;i<m;i++){
        int a = data[2*i];
        int b = data[2*i+1];
        int fa = find(a);
        int fb = find(b);
        int FA = find(a+n);
        int FB = find(b+n);
        merge(fa,FB);
        merge(FA,fb);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<2*n;i++){
        siz[i] = 1;
        boss[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        data[2*i] = a;
        data[2*i+1] = b;
        int fa = find(a);
        int fb = find(b);
        int FA = find(a+n);
        int FB = find(b+n);
        // cout<<"fa:"<<fa<<endl;
        // cout<<"fb:"<<fb<<endl;
        // cout<<"FA:"<<FA<<endl;
        // cout<<"FB:"<<FB<<endl;
        merge(fa,FB);
        merge(FA,fb);
    }
    int p,k;
    cin>>p>>k;
    for(int i=0;i<p;i++){
        bool ok = 1;
        for(int j=0;j<k;j++){
            int a,b;
            cin>>a>>b;
            if(!ok) continue;
            int fa = find(a);
            int fb = find(b);
            int FA = find(a+n);
            int FB = find(b+n);
            if(fa == fb || FA == FB){
                ok = 0;
                continue;
            }
            merge(fa,FB);
            merge(FA,fb);
        }
        if(!ok){
            ans.push_back(i+1);
            reset();
        }
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<siz[i]<<' ';
        // }cout<<'\t';
        // for(int i=0;i<n;i++){
        //     cout<<siz[n+i]<<' ';
        // }cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<boss[i]<<' ';
        // }cout<<'\t';
        // for(int i=0;i<n;i++){
        //     cout<<boss[n+i]<<' ';
        // }cout<<endl<<endl;
}