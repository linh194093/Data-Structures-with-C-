#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    vector<int> temp;
    for (std::vector<int>::iterator it = a.begin() ; it != a.end(); ++it)
        if(*it %2 == 1 || *it %2 == -1) temp.push_back(*it);
    a = temp;

}


void sort_decrease(vector<int> &a) {
    sort(a.begin(), a.end(), [](int i, int j){ return i > j;});
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> v(a.size() + b.size());
    int first[a.size()];
    int i = 0; 
    int j = 0;
    for(; i < (int)a.size(); ++i){
        first[i] = a.at(a.size()-1-i);
    }

    int second[b.size()];
    for(; j < (int)b.size(); ++j){
        second[j] = b.at(b.size()-1-j);
    }
    std::merge(first, first + a.size(), second, second + b.size(), v.begin());
    sort_decrease(v);
    return v;

}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}