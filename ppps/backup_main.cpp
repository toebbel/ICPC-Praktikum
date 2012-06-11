#include <iostream>
#include <vector>

using namespace std;

struct intersection {
	vector<intersection> connected;
	int color;
	bool visited;	
};

int colors[2];
vector<intersection> inters;

bool colorNode(intersection &root, int color);

int main() {
	unsigned int m, n;//#streets, #intersections
	while(cin >> n >> m && m != 0 && n != 0) {
		inters.resize(n);
		for(unsigned int i = 0; i < m ; i++) {
			unsigned int a, b;
			cin >> a >> b;
			inters[a - 1].connected.push_back(inters[b - 1]);
			inters[b - 1].connected.push_back(inters[a - 1]);
		}
		
		int result = 0;
		for(unsigned int i = 0; i < n && result >= 0; i++) {
			if(inters[i].visited) continue;
			cout << "root@" << i << endl;
			colors[0] = colors[1] = 0;
			if(colorNode(inters[i], 1)) {
				result += min(colors[0], colors[1]);
				cout << "color1 " << colors[0] << " color2 " << colors[1] << endl;
			} else {
				result = -1;
				cout << "impossibruuuu" << endl;
			}
		}

		if(result == -1)
			cout << "Impossible" << endl;
		else 
			cout << result << endl;
	}
}

bool colorNode(intersection &root, int color) {
	root.color = color;
	colors[color]++;
	root.visited = true;
	for(unsigned int i = 0; i < root.connected.size(); i++) {
		if(root.connected[i].visited && root.connected[i].color == color)
			return false;
		if(!root.connected[i].visited)
			if(!colorNode((root.connected[i]), 1 - color))
				return false;
	}
	return true;
}
