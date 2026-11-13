#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;          // number of vertices
    list<int>* l;   // dynamic array of lists of int (neighbours)

    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1];
    }

    // Destructor to free heap memory
    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int max_ver = edges[0][0];
        for (int i = 0; i < edges.size(); i++) {
            if (max_ver < edges[i][0]) {
                max_ver = edges[i][0];
            }
            if (max_ver < edges[i][1]) {
                max_ver = edges[i][1];
            }
        }

        Graph G(max_ver);
        for (int i = 0; i < edges.size(); i++) {
            G.addEdge(edges[i][0], edges[i][1]);
        }

        int max_degree = G.l[1].size();
        int max_num = 1;

        for (int i = 1; i <= max_ver; i++) {
            if (G.l[i].size() > max_degree) {
                max_degree = G.l[i].size();
                max_num = i;
            }
        }

        return max_num;
    }
};
