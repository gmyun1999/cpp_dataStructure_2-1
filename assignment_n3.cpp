#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

struct Edge {
    int dst;
    int weight;
};
struct Node {
    int data;
    std::vector<Edge> adjList;
};

struct Graph {
    std::vector<Node> nodes;


    void addNode(int data) {
        nodes.push_back({data});
    }

    void addEdge(int from, int to, int w) {
        nodes[from].adjList.push_back({to, w});
    }

    void shortest_path(int start, int end) const {
        struct NodeInfo {
            int node;
            int dist;
        };
        struct NodeInfoCompare {
            bool operator()(const NodeInfo &a, const NodeInfo &b) {
                return a.dist > b.dist;
            }
        };
        std::priority_queue<NodeInfo, std::vector<NodeInfo>, NodeInfoCompare> open;
        std::vector<int> dist(nodes.size(), 1000000000);
        std::vector<bool> closed(nodes.size(), false);
        std::vector<int> parents(nodes.size(), -1);
        open.push({start, 0});
        dist[start] = 0.0;
        while (!open.empty()) {
            NodeInfo info = open.top();
            open.pop();
            if (closed[info.node]) continue;
            closed[info.node] = true;
            if (info.node == end)break;
            for (auto edge: nodes[info.node].adjList) {
                int dst = edge.dst;
                int weight = edge.weight;
                int new_weight = weight + dist[info.node];
                if (closed[dst])continue;
                if (parents[dst] != -1) {
                    if (dist[dst] < new_weight)continue;
                }
                open.push({dst, new_weight});
                parents[dst] = info.node;
                dist[dst] = dist[parents[dst]] + weight;
            }
        }
        //move back
        std::deque<int> path;
        int ptr = end;
        while (ptr != -1) {
            path.push_back(ptr);
            ptr = parents[ptr];
        };
        while (!path.empty()) {
            std::cout << path.back() + 1 << " ";
            path.pop_back();
        }
//        for (int i = 0; i < 8; i++) {
//            std::cout << i << "node's dist is :" << dist[i] << std::endl;
//        }
//        for (int i = 0; i < 8; i++) {
//            std::cout << i << "node's parent is: " << parents[i] << std::endl;
//        }

    }
};


int main() {
    Graph g;
    int start, end;
    std::cin >> start >> end;
    std::string filePath = "D:/cpp_practice/USA-road-d.NY.gr.txt";
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        std::string line;
        int edgesNum;
        if (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int vertexNum;
            if (iss >> vertexNum >> edgesNum) {
                int i = 0;
                while (i < vertexNum) {
                    g.addNode(i);
                    i += 1;
                }
            }
        }
        std::vector<int> buff;
        int i = 0;
        while (i < edgesNum) {
            if (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                char a;
                int from, to, weight;
                if (iss >> a >> from >> to >> weight) {
                    g.addEdge(from - 1, to - 1, weight);
                }
            }
            std::cout << "reading this file. just wait until: "<<733846-i << std::endl;
            i++;
        }
    }
    inputFile.close();
    g.shortest_path(start - 1, end - 1);

}










