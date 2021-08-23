//dfs without recursion
#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

void dfs(vector<list<int>> adj){
    stack<int> S;
    vector<bool> visited(adj.size());

    S.push(1);
    visited.at(1) = true;
    cout << 1 << endl;
    
    while (!S.empty()) 
    {
        if (!adj.at(S.top()).empty()) 
        {
            if (!visited.at(adj.at(S.top()).front())) 
            {
                int k = S.top();
                int tmp = adj.at(S.top()).front();
                visited.at(tmp) = true;
                S.push(tmp);
                cout << tmp << endl;
                adj.at(k).pop_front();
                continue;
            }
            else 
                adj.at(S.top()).pop_front();
        }
        else 
            S.pop();
    }
}

int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
