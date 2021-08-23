#include<iostream>
#include<set>
using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> c;
    for (int i : a) c.insert(i);
    for (int i : b) c.insert(i);
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;
    set<T> d;
    int temp;
    for (int i : a) c.insert(i);
    for (int i : b){
        temp = c.size();
        c.insert(i);
        if (temp == (int)c.size()) d.insert(i);
    }
    return d;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main(){
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);
        
    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);
}