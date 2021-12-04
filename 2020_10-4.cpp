#include <iostream>
#include <vector>

using namespace std;

int b[100005];
vector<int> p(200005);
vector<int> p2(200005);
long long int ans;

void mergeSort(int left, int right)
{
    //相等
    if (left == right)
        return;

    //取中點
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    vector<int> Lvector;
    vector<int> Rvector;
    int Lindex = left, Rindex = mid + 1;

    while (Lindex <= mid && Rindex <= right)
    {
        if (p[Lindex] < p[Rindex])
        {
            Lvector.push_back(p[Lindex]);
            Rvector.push_back(p2[Lindex]);
            Lindex++;
        }
        else
        {
            ans += (Lindex - left) * p2[Rindex];
            Lvector.push_back(p[Rindex]);
            Rvector.push_back(p2[Rindex]);
            Rindex++;
        }
    }
    while (Lindex <= mid)
    {
        Lvector.push_back(p[Lindex]);
        Rvector.push_back(p2[Lindex]);
        Lindex++;
    }
    while (Rindex <= right)
    {
        ans += (Lindex - left) * p2[Rindex];
        Lvector.push_back(p[Rindex]);
        Rvector.push_back(p2[Rindex]);
        Rindex++;
    }
    for (int i = 0; i < Lvector.size(); i++)
    {
        p[left + i] = Lvector[i];
        p2[left + i] = Rvector[i];
    }
}

int main()
{
    int n, loc;
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> loc;
        //b[]為0代表第一次出現，
        if (b[loc])
        {
            p[i] = loc;
            p2[i] = 1;
        }
        else
        {
            b[loc] = 1;
            p[i] = loc;
            p2[i] = -1;
        }
    }
    mergeSort(1, n * 2);
    cout << ans << endl;
    return 0;
}