#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5]= {2,4,6,8,10};
    vector<int>v(10);
    set<int>s;
    s.insert(7);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(9);
    merge(arr, arr+5, s.begin(), s.end(), v.begin());
    cout << "Merged : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
    return 0;
}
