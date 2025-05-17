class Solution {
public:
class DisjointSet {
public:
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int intersect(const unordered_set<int>& a, const unordered_set<int>& b) {
    int count = 0;
    for (int num : a) {
        if (b.count(num)) count++;
    }
    return count;
}

int countComponents(vector<vector<int>>& properties, int k) {
    int n = properties.size();
    
    // Convert each row into a set for fast lookups
    vector<unordered_set<int>> sets(n);
    for (int i = 0; i < n; i++) {
        sets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
    }

    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Avoid redundant checks
            if (intersect(sets[i], sets[j]) >= k) {
                ds.unite(i, j);
            }
        }
    }
    unordered_set<int> components;
    for (int i = 0; i < n; i++) {
        components.insert(ds.find(i));
    }

    return components.size();
}


    int numberOfComponents(vector<vector<int>>& properties, int k) {
        return  countComponents(properties, k);
    }
};