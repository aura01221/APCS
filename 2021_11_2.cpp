#include<iostream>
using namespace std;
int main(){
    int m,n,hh,r,c,t,chk,cnt=0,maxVal=0;
    int tree[100][100]={0},h[100][100]={0},v[100][100]={0};//horizon vertical
    bool ok;
    cin>>m>>n>>hh;
    while(hh--){
        cin>>r>>c>>t;
        if(t){
            //pull
            tree[r][c]=0;
            //下
            for(int i = r + 1; i < m; i++){
                if(!v[i][c]) break;
                v[i][c]--;
            }//上
            for(int i = r - 1; i >= 0; i--){
                if(!v[i][c]) break;
                v[i][c]--;
            }//右
            for(int i = c + 1; i < n; i++){
                if(!h[r][i]) break;
                h[r][i]--;
            }//左
            for(int i = c - 1; i >= 0; i--){
                if(!h[r][i]) break;
                h[r][i]--;
            }
        }
        else{
            //add
            tree[r][c] =1;
            h[r][c] = 0;
            v[r][c] = 0;
            //下
            ok=0;
            for(int i=r+1;i<m;i++){
                if(tree[i][c]){
                    ok=1;
                }
            }
            if(ok){
                for(int j=r+1;j<m;j++){
                    if(tree[j][c] || v[j][c])break;
                    v[j][c]++;
                }
            }
            //上
            ok=0;
            for(int i=r-1;i>=0;i--){
                if(tree[i][c]){
                    ok=1;
                }
            }
            if(ok){
                for(int j=r-1;j>=0;j--){
                    if(tree[j][c] || v[j][c])break;
                    v[j][c]++;
                }
            }
            //右
            ok=0;
            for(int i=c+1;i<n;i++){
                if(tree[r][i]){
                    ok=1;
                }
            }
            if(ok){
                for(int j=c+1;j<n;j++){
                    if(tree[r][j] || h[r][j])break;
                    h[r][j]++;
                }
            }
            //左
            ok=0;
            for(int i=c-1;i>=0;i--){
                if(tree[r][i]){
                    ok=1;
                }
            }
            if(ok){
                for(int j=c-1;j>=0;j--){
                    if(tree[r][j] || h[r][j])break;
                    h[r][j]++;
                }
            }
        }
        cnt=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(tree[j][i]||v[j][i]||h[j][i])cnt++;
            }
        }
        maxVal = max(maxVal,cnt);
    }
    cout<<maxVal<<endl<<cnt<<endl;
}