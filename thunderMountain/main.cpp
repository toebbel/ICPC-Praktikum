#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <limits>
#include <stdio.h>

using namespace std;


struct city {
	unsigned int x, y;
	vector<city> connected;
	bool visited;
	double distance;
};

vector<city> cities;

double d[100][100];
bool adj[100][100]; 


int distSquared(int x1,int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double dist(double x1, double y1, double x2, double y2) {
	return sqrt(distSquared(x1, y1, x2, y2));
}


int main() {
	int N;
	cin >> N;
	for(unsigned int n = 0; n < N; n++) {
		unsigned int t;
		cin >> t;
		cities.resize(t);
		for(unsigned int i = 0; i < t; i++) {
			unsigned x, y;
			cin >> x >> y;
			cities[i].x = x;
			cities[i].y = y;
		}

		//build the street network
		for(unsigned int i = 0; i < t; i++) {
			for(unsigned int j = 0; j < t; j++) {
				if(distSquared(cities[i].x, cities[i].y, cities[j].x, cities[j].y) <= 100) {
					adj[i][j] = adj[j][i] = true;
					d[i][j] = dist(cities[i].x, cities[i].y, cities[j].x, cities[j].y); 
	//				cout << i << " and " << j << " are connected:" << d[i][j] << endl;
				} else {
					adj[i][j] = adj[j][i] = false;
					d[i][j] = d[j][i] = numeric_limits<double>::infinity();
				}
			}
		}
	
	/*	for(unsigned int i = 0; i < t; i++) {
			for(unsigned int j = 0; j < t; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}*/
		
		for(unsigned k = 0; k < t; k++) {
			for(unsigned int i = 0; i < t; i++)
				for(unsigned int j = 0; j < t; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
		
		double result = 0;
		for(unsigned int i = 0; i < t; i++) {
			for(unsigned int j = 0; j < t; j++) {
		//		cout << d[i][j] << " ";
				result = max(result, d[i][j]);
			}
		//	cout << endl;
		}
		
		
		printf("Case #%d:\n", n + 1);
		if(result == numeric_limits<double>::infinity())
			cout << "Send Kurdy" << endl << endl;
		else
			printf("%.4lf\n\n", result);
	}
}
