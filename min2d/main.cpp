#include <iostream>

using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	cin >> m;

	unsigned int arr[n + 1][m + 1];


	//read the array, calc the sum
	unsigned int tmp = 0;
	for(int i = 1; i <= n ; i++) {		
		for(int j = 1; j <= m; j++) {
			cin >> tmp;			
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + tmp;
		}
	}


	int xmin, ymin, xmax, ymax;
	while(cin >> xmin >> ymin >> xmax >> ymax) {
		int area1 = arr[xmax][ymax];
		int area2 = arr[xmin - 1][ymin - 1];
		int area3 = arr[xmin - 1][ymax];
		int area4 = arr[xmax][ymin - 1];

		cout << "area1 " << area1 << ", area2 " << area2 << ", area3 " << area3 << ", area4 " << area4 << endl;
		cout << area1 + area2 - area3 -area4 << endl;
	}
}
