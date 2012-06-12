#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int tests;
int nodes;
int vertices;
int edges;
bool bla;
vector < vector<int> > graph;
vector <bool> visited;


int tiefensuche(int i) {
	nodes++;
	visited[i] = true;
	for(int m = 0; m < (int)graph[i].size(); ++m) {
		if (!visited[graph[i][m]])
			tiefensuche(graph[i][m]);
	}
}

int main() {
	
	cin >> tests;
	for(int j = 0; j < tests; ++j) {
		
		cin >> vertices >> edges;
		graph.clear();
		visited.clear();
		visited = vector<bool> (vertices, false);
		graph = vector < vector<int> > (vertices);
		nodes = 0;
		
		for(int i = 0; i < edges; ++i) {
			int tmp_a;
			int tmp_b;
			cin >> tmp_a >> tmp_b;
			--tmp_a;
			--tmp_b;
			graph[tmp_a].push_back(tmp_b);
			graph[tmp_b].push_back(tmp_a);
		}
		
		bla = true;
		for(int m = 0; m < (int)graph.size(); ++m) {
			if(graph[m].size()!=2) 
				bla = false;
		}

		if(bla) {
			tiefensuche(0);
		} 
		
		if(bla && nodes == vertices)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}
