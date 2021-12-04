#include<iostream>
#include<vector>
using namespace std;
int n,m;
int data[40005],boss[40005],siz[40005];
vector<int>ans;

int find(int x){
    if(boss[x] == x){
//        cout<<x<<endl;
        return x;
    }
    boss[x]=find(boss[x]);
//    cout'-'<<<<boss[x]<<<<endl;
    return a;
}
void merge(int a,int b){
    if(siz[a]<siz[b]){
        siz[b]+=siz[a];
        boss[a] = b;
    }
    else{
        siz[a]+=siz[b];
        boss[b] = a;
    }
//    for(int i=0;i<n;i++){
//        cout<<siz[i]<<' ';
//    }cout<<'\t';
//    for(int i=0;i<n;i++){
//        cout<<siz[n+i]<<' ';
//    }cout<<endl;
//    for(int i=0;i<n;i++){
//        cout<<boss[i]<<' ';
//    }cout<<'\t';
//    for(int i=0;i<n;i++){
//        cout<<boss[n+i]<<' ';
//    }cout<<endl<<endl;
}
void reset(){
    for(int i=0;i<2*n;i++){
        siz[i]=1; boss[i]=i;
    }
    for(int i=0;i<m;i++){
        int a=data[i*2],b=data[i*2+1];
        int fa=find(a),fb=find(b);
        int FA=find(a+n),FB=find(b+n);
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
        int fa = find(a)  ,fb=find(b);
        int FA = find(a+n),FB=find(b+n);//imaginary
//        cout<<"fa:"<<fa<<endl;
//        cout<<"fb:"<<fb<<endl;
//        cout<<"FA:"<<FA<<endl;
//        cout<<"FB:"<<FB<<endl;
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
            if(!ok){
//                cout<<"wrong1"<<endl;
                continue;
            }
            
            int fa = find(a)  ,fb = find(b);
            int FA = find(a+n),FB = find(b+n);//imaginary
            if(fa == fb || FA == FB){
//                cout<<"wrong2"<<endl;
//                cout<<"fa:"<<fa<<endl;
//                cout<<"fb:"<<fb<<endl;
//                cout<<"FA:"<<FA<<endl;
//                cout<<"FB:"<<FB<<endl;
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
    for(int i;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
/*
7 5
0 1 0 2 1 3 2 3 4 5
2 3
0 6 2 4 3 6
0 6 0 3 3 5
*/