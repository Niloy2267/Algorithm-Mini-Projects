#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

typedef pair<int, int> iPair;

void dijkstra(int source, int vertices, vector<vector<iPair>>& adj) {

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(vertices, INF);

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "\nShortest Distance from City " << source << ":\n";

    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF)
            cout << "To City " << i << " -> Unreachable\n";
        else
            cout << "To City " << i << " -> " << dist[i] << " km\n";
    }
}

int main() {

    int vertices = 5;

    vector<vector<iPair>> adj(vertices);

    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source_city = 0;

    dijkstra(source_city, vertices, adj);

    return 0;
}
