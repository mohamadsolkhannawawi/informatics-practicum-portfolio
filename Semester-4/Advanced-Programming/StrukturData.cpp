#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    cout << "Array ke-1: " << array[0] << endl;
    cout << "Array ke-2: " << array[1] << endl;
    cout << "Array ke-3: " << array[2] << endl;
    cout << "Array ke-4: " << array[3] << endl;
    cout << "Array ke-5: " << array[4] << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    vector<int> v2 = {4, 5, 6};
    cout << v2[0] << endl;
    cout << v2[1] << endl;
    cout << v2[2] << endl;

    vector<int> a(8); // Size 8, inisiialisasi 0
    vector<int> b(8,3); // Size 8, inisialisasi 3
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }

    for(auto x : v){
        cout<< x << endl;
    }

    cout << "Mencoba fungsi back dan pop_back" << endl;
    vector<int> pop = {2,4,2,5,1};
    cout << pop.back() << endl;//1
    pop.pop_back();
    cout << pop.back() << endl;//5

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    random_shuffle(v.begin(),v.end());
    cout << *v.begin() << "\n";

    vector<int> TestLowerUpperBound = {2,3,3,5,7,8,8,8};
    auto Lower = lower_bound(v.begin(),v.end(),5);
    auto Upper = upper_bound(v.begin(),v.end(),5);
    cout << &Lower <<" --- "<<&Upper<<"\n";//57

    
    return 0;
}