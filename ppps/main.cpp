#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool colorNode(int root, int color);

struct node {
	vector<int> connected;
	int color;
	bool visited;
};

vector<node> nodes;
int colors[2];

int main() {
	int streets, inters;
	while(cin >> inters >> streets) {
		nodes.clear();
		nodes.resize(inters);
		for(int i = 0; i < streets; i++) {
			int a, b;
			cin >> a >> b;
			nodes[a - 1].connected.push_back(b - 1);
			nodes[b - 1].connected.push_back(a - 1);
		}

		int result = 0;
		for(unsigned int i = 0; i < nodes.size(); i++) {
			if(nodes[i].visited) continue;
			colors[0] = colors[1] = 0;
			if(colorNode(i, 1))
				result += min(colors[0], colors[1]);
			else {
				result = -1;
				break;
			}
		}

		if(result == -1)
			cout << "Impossible" << endl;
		else
			cout << result << endl;
	}
}

bool colorNode(int root, int color) {
	nodes[root].color = color;
	nodes[root].visited = true;
	colors[color]++;
	for(unsigned int i = 0; i < nodes[root].connected.size(); i++) {
		node *other = &nodes[nodes[root].connected[i]];
		if(other->color == color && other->visited)
			return false;
		if(!other->visited)
			if(!colorNode(nodes[root].connected[i], 1 - color))
				return false;
	}
	return true;
}
