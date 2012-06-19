#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<vector <int> > c;
vector<vector <int> > f;
vector<int> height;

int excess(int u) {
	int result = 0;
	for(int i = 0; i < c.size(); i++)
		result += f[i][u] + f[u][i];
}

inline bool canPush(int from, int to) {
	return (excess(from) > 0 && c[from][to] - f[from][to] > 0 && height[from] > height[to]);
}

inline void push(int from, int to) {
	f[from][to] = min(excess(from), c[from][to] - f[from][to]);
}

inline bool relabel(int u) {
	if(excess(u) <= 0) return false;
	int bestId = -1;
	int bestHeight = 999999;
	for(int v = 0; v < height.size(); v++) {
		if(v == u) continue;
		if(c[u][v] - f[u][v] > 0) {
			if(height[v] < bestHeight && height[v] > height[u]) {
				bestHeight = height[v];
				bestId = v;
			}
		}
	}
	if(bestId == -1) return false;
	height[u] = bestHeight+1;
	return true;
}

int main() {
	//read
	int crossings, bunkers, streets;

	bool done = false;
	while(!done) {
		done = true;
		for(int i = 0; i < height.size(); i++) {
			for(int j = 0; j < height.size(); i++) {
				if(i == j) continue;
				if(canPush(i, j)) {
					done = false;
					push(i, j);
				}
			}
		}
		if(done) {
			for(int i = 0; i < height.size(); i++) {
				if(relabel(i))
					done = false;
			}
		}
	}
	
	//calc result
	int result = 0;
	for(int i = 1; i < height.size(); i++)
		result += f[0][i];
	cout << result << endl;
}
