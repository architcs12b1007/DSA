#include <iostream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    set<int> numbers;
    set<int> children;
};

bool isSubset(set<int>& a, set<int>& b) {
    return includes(a.begin(), a.end(), b.begin(), b.end());
}


int main() {
    int n;
    cin >> n;
    cin.ignore(); // Consume newline after N
    
    vector<Node> nodes(n);
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        
        int num;
        while (iss >> num) {
            nodes[i].numbers.insert(num);
        }
    }

    for (int i = 0; i < n; ++i) {
        for(int j=i+1;j<n;j++){
            if(nodes[i].numbers.size()<nodes[j].numbers.size()){
                bool isProperSubset=isSubset(nodes[j].numbers,nodes[i].numbers);
                if(isProperSubset)
                nodes[j].children.insert(i);

            }else if((nodes[i].numbers.size()>nodes[j].numbers.size())){
                bool isProperSubset=isSubset(nodes[i].numbers,nodes[j].numbers);
                if(isProperSubset)
                nodes[i].children.insert(j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nodes[i].children.size() >0) {
            for (int child : nodes[i].children) {
                set<int> intersection;

                set_intersection(nodes[i].children.begin(), nodes[i].children.end(), nodes[child].children.begin(), nodes[child].children.end(),inserter(intersection, intersection.begin()));
                
                for (int num : intersection) {
                    nodes[i].children.erase(num);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nodes[i].children.empty()) {
            cout << -1;
        } else {
            for (int child : nodes[i].children) {
                cout << child << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
