#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define INF 1e9
#define MAX_NODE 20001

vector<pair<int, int>>graph[MAX_NODE];
int dist[MAX_NODE];

void dijkstra(int start) {
	priority_queue<pair<int, int>>PQ;
	PQ.push(make_pair(0, start));
	dist[start] = 0;

	while (!PQ.empty()) {
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {
	int v, e, k;
	int u, vv, w;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		cin >> u >> vv >> w;
		graph[u].push_back(make_pair(vv, w));
	}
	fill(dist, dist + MAX_NODE, INF);

	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i]<<"\n";
	}
}