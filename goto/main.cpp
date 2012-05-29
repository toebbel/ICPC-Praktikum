#include <iostream>
#include <vector>

using namespace std;

struct label {
	vector<label> reachable; //use set instead
	bool visited;
};

void visit(label root);

vector<label> labels;
int hits;

int main() {
	unsigned int T;//#testcases
	cin >> T;
	for(unsigned int t = 0; t < T; t++) {
		int n, m, l; //#labels, #edged, #root-labels
		cin >> n >> m >> l;
		
		//create all labels and reset hits
		labels.clear();
		labels.resize(n);
		hits = 0;

		for(int i = 0; i < m; i++) { //read label-connections
			int x, y; //from x to y
			cin >> x >> y;
			labels[x - 1].reachable.push_back(labels[y - 1]); //labels are from 1..n
		}
		
		for(int i = 0; i < l; i++)  //read root labels
			visit(labels[i]);			

		cout << "Testcase #" << (t + 1) << ": " + hits << endl;
	}
}

void visit(label root) {
	if(root.visited) return;
	root.visited = true;
	hits++;
	for(int i = 0; i < root.reachable.size(); i++)
		visit(root.reachable[i]);
}
