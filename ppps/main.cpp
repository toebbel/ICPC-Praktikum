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
	//read the graph
	
	int result = 0;
	for(unsigned int i = 0; i < nodes.size() && result >= 0; i++) {
		if(nodes[i].visited) continue;
		colors[0] = colors[1] = 0;
		if(colorNode(i, 1))
			result += min(colors[0], colors[1]);
		else
			result = -1;
	}
}

bool colorNode(int root, int color) {
	nodes[root].color = color;
	nodes[root].visited = true;
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
