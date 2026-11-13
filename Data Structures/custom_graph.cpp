#include <list>

using namespace std;

class Graph {
public:
    int V;          // number of vertices
    list<int>* l;   // dynamic array of adjacency lists

    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1]; // 1-based indexing support
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
};
