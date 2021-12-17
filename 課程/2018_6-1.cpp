#include <iostream>
using namespace std;
   
int main() {
    int n;
    while (cin >> n){
        char letter[16];
        letter[5] = 'A';
        letter[7] = 'B';
        letter[2] = 'C';
        letter[13] = 'D';
        letter[8] = 'E';
        letter[12] = 'F';
        for (int i=0; i<n; i++){
            int x = 0, tmp;
            for (int j=0; j<4; j++){
                cin >> tmp;
                x = 2 * x + tmp;
            }
            cout << letter[x];
        }
        cout <<endl;
    }
    return 0;
}