#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool edges[27][27];

struct city {
	bool seen;
	int id;
	vector<city> adj;
};

queue<city> q;
vector<city> cities;
int visit(city root);

int main() {
	unsigned int m, n;
	while(cin >> m >> n && m != 0 && n != 0) {

		cities.clear();
		cities.resize(n);

		for(unsigned int i = 0; i < n; i++) {
			cities[i].id = i;
			q.push(cities[i]);
		}

		for(unsigned int i = 0; i < m; i++) {
			unsigned int a, b;
			cin >> a >> b;
			edges[a][b] = true;
			edges[b][a] = true;
			cities[a].adj.push_back(cities[b]);
			cities[b].adj.push_back(cities[a]);
		}

		int tmp, max;
		while(q.size() > 0) {
			city root = q.front();
			q.pop();
			if(root.seen) continue;

			cout << "root: " << root.id << endl;
			tmp = visit(root);
			if(tmp > max)
				max = tmp;
		}
		cout << max << endl;
	}
}

int visit(city root) {
	cout << "visit " << root.id << endl;
	root.seen = true;
	int localMax = 0;
	for(unsigned int i = 0; i < root.adj.size(); i++) {
		if(edges[root.id][root.adj[i].id]) {
			edges[root.id][root.adj[i].id] = false;
			edges[root.adj[i].id][root.id] = false;
			int tmp = visit(root.adj[i]);
			if(tmp > localMax)
				localMax = tmp;
			edges[root.id][root.adj[i].id] = true;
			edges[root.adj[i].id][root.id] = true;
		}
	}
	if(localMax = 0) return 0;
	return localMax + 1;
}
