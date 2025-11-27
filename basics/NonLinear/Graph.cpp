#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<algorithm>
#include<iomanip>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;   // <---- CHILDREN ARE NOW INSIDE THE NODE CLASS

    Node(int _val) : val(_val) {}
};

class WeightedNode {
public:
    int val;
    vector<pair<WeightedNode*, int>> children;   // <---- CHILDREN ARE NOW INSIDE THE NODE CLASS

    WeightedNode(int _val) : val(_val) {}
};


class Graph {
private:
    unordered_map<int, Node*> nodes;
    bool directed;

    // Cycle Detection (DFS)
    bool isCyclicDFS(Node* node, unordered_set<Node*>& visiting, unordered_set<Node*>& visited) {
        visiting.insert(node);

        for (Node* child : node->children) {
            if (visiting.count(child)) return true;       // back edge → cycle
            if (!visited.count(child))
                if (isCyclicDFS(child, visiting, visited)) return true;
        }

        visiting.erase(node);
        visited.insert(node);
        return false;
    }

public:
    Graph(bool directed = false) : directed(directed) {}

    Node* createNode(int val) {
        if (!nodes.count(val))
            nodes[val] = new Node(val);
        return nodes[val];
    }

    Node* getNode(int val) {
        return nodes.count(val) ? nodes[val] : nullptr;
    }

    void createEdge(int from, int to) {
        Node* u = getNode(from);
        Node* v = getNode(to);

        if (!u || !v) {
            cout << "Invalid edge (" << from << " -> " << to << ")\n";
            return;
        }

        // check if v is already a child of u
        if (find(u->children.begin(), u->children.end(), v) == u->children.end()) {
            u->children.push_back(v);
        }

        // undirected? add reverse, also only if not duplicate
        if (!directed) {
            if (find(v->children.begin(), v->children.end(), u) == v->children.end()) {
                v->children.push_back(u);
            }
        }
    }

    // BFS
    void bfs(int start) {
        Node* s = getNode(start);
        if (!s) { cout << "Invalid start\n"; return; }

        unordered_set<Node*> seen;
        queue<Node*> q;
        seen.insert(s);

        q.push(s);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            cout << curr->val << " ";

            for (Node* child : curr->children) {
                if (!seen.count(child)) {
                    seen.insert(child);
                    q.push(child);
                }
            }
        }

        cout << endl;
    }

    // DFS
    void dfs(int start) {
        Node* s = getNode(start);
        if (!s) { cout << "Invalid start\n"; return; }

        unordered_set<Node*> seen;
        stack<Node*> q;
        seen.insert(s);

        q.push(s);

        while (!q.empty()) {
            Node* curr = q.top(); q.pop();

            cout << curr->val << " ";

            for (Node* child : curr->children) {
                if (!seen.count(child)) {
                    seen.insert(child);
                    q.push(child);
                }
            }
        }

        cout << endl;
    }

    bool isCyclic() {
        unordered_set<Node*> visited, visiting;
        for (auto& [val, node] : nodes)
            if (!visited.count(node))
                if (isCyclicDFS(node, visiting, visited))
                    return true;
        return false;
    }

    // Display graph
    void display() {
        for (auto& [val, node] : nodes) {
            cout << val << ": ";
            for (Node* c : node->children)
                cout << c->val << " ";
            cout << "\n";
        }
    }
};


class WeightedGraph {
private:
    unordered_map<int, WeightedNode*> nodes;
    bool directed;

public:
    WeightedGraph(bool directed = false) : directed(directed) {}

    WeightedNode* createNode(int val) {
        if (!nodes.count(val))
            nodes[val] = new WeightedNode(val);
        return nodes[val];
    }

    WeightedNode* getNode(int val) {
        return nodes.count(val) ? nodes[val] : nullptr;
    }

    void createEdge(int from, int to, int weight) {
        WeightedNode* u = getNode(from);
        WeightedNode* v = getNode(to);

        if (!u || !v) {
            cout << "Invalid edge (" << from << " -> " << to << ")\n";
            return;
        }

        // check if v is already a child of u
        auto it = std::find_if(
            u->children.begin(),
            u->children.end(),
            [&](const pair<WeightedNode*, int> &p){
                return p.first == v;
            }
        );

        if (it == u->children.end()) {
            u->children.push_back({v, weight});
        }

        // undirected graph: check reverse direction too
        if (!directed) {
            auto it2 = std::find_if(
                v->children.begin(),
                v->children.end(),
                [&](const pair<WeightedNode*, int> &p){
                    return p.first == u;
                }
            );

            if (it2 == v->children.end()) {
                v->children.push_back({u, weight});
            }
        }
    }


    // BFS
    void bfs(int start, int goal) {
        WeightedNode* s = getNode(start);
        if (!s) { cout << "Invalid start\n"; return; }

        unordered_set<WeightedNode*> seen;
        queue<pair<WeightedNode*, int>> q;
        seen.insert(s);

        q.push({s, 0});

        while (!q.empty()) {
            auto [node, cost] = q.front(); q.pop();
        
            cout << node->val << " ";

            if (node->val == goal) {
                cout << "\nGoal found with cost " << cost <<". \n";
                return;
            }

            for (auto [child, childCost] : node->children) {
                if (!seen.count(child)) {
                    seen.insert(child);
                    q.push({child, cost + childCost});
                }
            }
        }
        cout << "\nGoal not found\n";
    }

    // DFS
    void dfs(int start, int goal) {
        WeightedNode* s = getNode(start);
        if (!s) { cout << "Invalid start\n"; return; }

        unordered_set<WeightedNode*> seen;
        stack<pair<WeightedNode*, int>> q;
        seen.insert(s);

        q.push({s, 0});

        while (!q.empty()) {
            auto [node, cost] = q.top(); q.pop();
        
            cout << node->val << " ";

            if (node->val == goal) {
                cout << "\nGoal found with cost " << cost <<". \n";
                return;
            }

            for (auto [child, childCost] : node->children) {
                if (!seen.count(child)) {
                    seen.insert(child);
                    q.push({child, cost + childCost});
                }
            }
        }
        cout << "\nGoal not found\n";
    }

    // Cycle Detection (DFS)
    bool isCyclicDFS(WeightedNode* node, unordered_set<WeightedNode*>& visiting, unordered_set<WeightedNode*>& visited) {
        visiting.insert(node);

        for (auto [child, cost] : node->children) {
            if (visiting.count(child)) return true;       // back edge → cycle
            if (!visited.count(child))
                if (isCyclicDFS(child, visiting, visited)) return true;
        }

        visiting.erase(node);
        visited.insert(node);
        return false;
    }

    bool isCyclic() {
        unordered_set<WeightedNode*> visited, visiting;
        for (auto& [val, node] : nodes)
            if (!visited.count(node))
                if (isCyclicDFS(node, visiting, visited))
                    return true;
        return false;
    }

    // DFS Topological Sort
    void dfsTopo(WeightedNode* node, unordered_set<WeightedNode*>& visited, vector<int>& result) {
        visited.insert(node);

        for (auto [child, cost] : node->children) {
            if (!visited.count(child))
                dfsTopo(child, visited, result);
        }

        result.push_back(node->val);
    }

    vector<int> topoSortDFS() {
        if (directed && isCyclic()) {
            cout << "Graph has a cycle. Cannot topoSort.\n";
            return {};
        }

        vector<pair<int, WeightedNode*>> ordered(nodes.begin(), nodes.end());
        sort(ordered.begin(), ordered.end());

        unordered_set<WeightedNode*> visited;
        vector<int> result;

        for (auto& [v, node] : ordered)
            if (!visited.count(node))
                dfsTopo(node, visited, result);

        reverse(result.begin(), result.end());
        return result;
    }

    // Kahn's Algorithm
    vector<int> kahn() {
        if (directed && isCyclic()) {
            cout << "Graph has a cycle. Cannot topoSort.\n";
            return {};
        }

        vector<pair<int, WeightedNode*>> ordered(nodes.begin(), nodes.end());
        sort(ordered.begin(), ordered.end());

        int N = ordered.size();
        unordered_map<int,int> idx;
        vector<WeightedNode*> indexToNode(N);

        for (int i = 0; i < N; i++) {
            idx[ordered[i].first] = i;
            indexToNode[i] = ordered[i].second;
        }

        vector<int> indeg(N, 0);
        for (int i = 0; i < N; i++) {
            WeightedNode* u = indexToNode[i];
            for (auto [v, cost] : u->children)
                indeg[idx[v->val]]++;
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> result;
        while (!q.empty()) {
            int ui = q.front(); q.pop();
            WeightedNode* u = indexToNode[ui];

            result.push_back(u->val);

            for (auto [v, cost] : u->children) {
                int vi = idx[v->val];
                indeg[vi]--;
                if (indeg[vi] == 0)
                    q.push(vi);
            }
        }

        if (result.size() != N) {
            cout << "Cycle detected. Kahn failed.\n";
            return {};
        }

        return result;
    }

    int getMaxVertex() {
        vector<pair<int, WeightedNode*>> ordered(nodes.begin(), nodes.end());
        sort(ordered.begin(), ordered.end());

        int maxV = -1;

        for (auto [weight, node] : ordered) {
            maxV = max(maxV, node->val);
        }

        return maxV;
    }

    vector<int> shortestPath() {
        vector<int> topo = kahn();   // topological order
        if (topo.empty()) {
            cout << "Graph is not a DAG. Cannot find shortest path.\n";
            return {};
        }

        int source = topo[0];
        int maxV = getMaxVertex();   // should return largest vertex value

        vector<int> dist(maxV + 1, INT_MAX);
        dist[source] = 0;

        for (int u : topo) {
            WeightedNode* node = getNode(u);

            if (dist[u] == INT_MAX) continue; // unreachable node

            for (auto [child, w] : node->children) {
                int v = child->val;

                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        cout << "Found path from source: " << source << "\n";
        return dist;
    }

    struct Compare {
        bool operator()(const pair<int, WeightedNode*> a, const pair<int, WeightedNode*> b) const {
            return a.first > b.first; // min heap
        }
    };

    vector<pair<int, WeightedNode*>> dijkstra(int source) {
        WeightedNode* sNode = getNode(source);

        if (!sNode) {
            cout << "Invalid starting postion.\n";
            return {};
        }

        int maxV = getMaxVertex();

        vector<pair<int, WeightedNode*>> dist(maxV + 1, {INT_MAX, nullptr}); // distance from root, parent 

        priority_queue<
            pair<int, WeightedNode*>,
            vector<pair<int, WeightedNode*>>,
            Compare
        > pq; // distance of V from root, V

        dist[sNode->val] = {0, nullptr}; // starting node distance = 0

        pq.push({0, sNode});
        vector<bool> seen(maxV + 1, false);  // seen map

        while (!pq.empty()) {
            auto [curDist, node] = pq.top(); pq.pop();

            // Skip if we've already finalized this node
            if (seen[node->val]) continue;      
            seen[node->val] = true;            

            for (auto [child, cost] : node->children) { // update the distance of all its children
                if (seen[child->val]) continue; 
                
                int newCost = curDist + cost; // calculate the new cost

                if (newCost < dist[child->val].first) { // if the new cost is smaller than existing, then update the cost
                    dist[child->val] = {newCost, node};
                    pq.push({newCost, child});
                }
            }   
        }

        return dist;
    }

        void printDijkstraTable(const vector<pair<int, WeightedNode*>>& result, int source) {
        cout << left                     // left-align all columns
            << setw(8)  << "Node"
            << setw(20) << "Distance from Root"
            << setw(12) << "Parent"
            << "\n";

        // Separator line
        cout << string(60, '-') << "\n";

        for (int v = 0; v < result.size(); ++v) {
            auto [dist, parent] = result[v];

            cout << left
                << setw(8)  << v;

            if (dist == INT_MAX) {
                cout << setw(20) << "Unreachable";
            } else if (v == source) {
                cout << setw(20) << 0 << " (Source)";
            } else {
                cout << setw(20) << dist;
            }

            if (parent == nullptr) {
                if (v == source) {
                    cout << "Root";
                } else {
                    cout << "-";  // unreachable or no parent
                }
            } else {
                cout << parent->val;
            }

            cout << "\n";
        }
    }

    // Display graph
    void display() {
        for (auto& [val, node] : nodes) {
            cout << val << ": ";
            for (auto [c, cost] : node->children)
                cout << "( "<< c->val << ", " << cost << " ), ";
            cout << "\n";
        }
    }
};

int main() {
    WeightedGraph g;

    for (int i = 0; i <= 11; i++) g.createNode(i);

    // Layer 0 → Layer 1
    g.createEdge(0, 3, 4);
    g.createEdge(0, 4, 6);
    g.createEdge(1, 4, 3);
    g.createEdge(1, 5, 5);
    g.createEdge(2, 3, 2);
    g.createEdge(2, 5, 7);

    // Layer 1 → Layer 2
    g.createEdge(3, 6, 5);
    g.createEdge(3, 7, 8);
    g.createEdge(4, 6, 4);
    g.createEdge(4, 7, 2);
    g.createEdge(5, 6, 6);
    g.createEdge(5, 8, 3);

    // Layer 2 → Layer 3
    g.createEdge(6, 8, 5);
    g.createEdge(6, 9, 7);
    g.createEdge(7, 9, 2);
    g.createEdge(7, 10, 4);
    g.createEdge(8, 10, 3);
    g.createEdge(8, 11, 6);

    // Cross-layer connections
    g.createEdge(0, 5, 2);
    g.createEdge(1, 3, 4);
    g.createEdge(2, 4, 1);

    g.display();

    cout << "BFS: "; g.bfs(1, 3);
    cout << "IsCyclic: " << (g.isCyclic() ? "Yes" : "No") << "\n";

    cout << "Kahn: ";
    for (int x : g.kahn()) cout << x << " ";
    cout << "\n";

    cout << "Shortest Path: ";
    for (int x : g.shortestPath()) cout << x << " ";
    cout << "\n";

    cout << "Dijsktra: \n";
    vector<pair<int, WeightedNode*>> path = g.dijkstra(10);

    g.printDijkstraTable(path, 10);

}
