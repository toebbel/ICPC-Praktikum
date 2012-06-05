#include <vector>
#include <iostream>
#include <set>

using namepsace std;



struct city {
	city *father;
};

vector<city> cities;

struct line {
	city *a, *b;
	int cost;
};

city find(city node) {
	while(node.father != NULL)
		node = node.father;
	return node;
}

void shrink(city node) {
	city *root = &find(node);
	city tmp;
	while(node.father != NULL) {
		tmp = node.father;
		node.father = root;
		node = tmp;
	}
}

void unionNodes(city node1, city node2) {
	find(node1).father = &node2;
	shrink(node1);
}

void reset() {
	for(unsigned int i = 0; i < cities.size(); i++)
		cities[i].father = NULL;
}

int kruskal(vector<line> chosen) {
	int n = 0; //number of cities to connect
	set<city> connected;
	vector<line> lines; //filled with all lines, sorted by their weight

	int lineId = 0;
	while(connected.size() < n) {
		line currentLine = lines[lineId];
		city a = find(currLine.a);
		city b = find(currLine.b);
		if(a != b) {
			connected.insert(a);
			connected.insert(b);
			unionNodes(a, b);
			chosen.push_back(currentLine);
		}
	}

	int cost = 0;
	for(unsigned int i = 0; i < chosen.size(); i++)
		cost += chosen[i].cost;
	return cost;
}

int main() {
	//try all combinations of buys
}
