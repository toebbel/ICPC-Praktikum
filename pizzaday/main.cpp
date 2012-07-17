#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<double> capers;
vector<double> peppercorns;

int main() {
	//read angles of objects into vectory	

	while(true) {
	int numCapers, numPepper;
	cin >> numCapers >> numPepper;
	if(numCapers == -1 &&  numPepper == -1)
		break;
	peppercorns.clear();
	capers.clear();
	float x, y;
	for(int i = 0; i < numCapers; i++) {
		cin >> x >> y;
		capers.push_back(cos(x/y));
	}
	for(int i = 0; i < numPepper; i++) {
		cin >> x >> y;
		peppercorns.push_back(cos(x/y));
	}

	//sort according to angle
	sort(capers.begin(), capers.end());
	sort(peppercorns.begin(), peppercorns.end());

	int capersHalf = capers.size() / 2;
	int pepperHalf = peppercorns.size() / 2;
	
	double diff = abs(capers[capersHalf] - peppercorns[pepperHalf]);
	bool result = diff < abs(capers[capersHalf] - capers[capersHalf + 1]) ||
			diff < abs(peppercorns[pepperHalf] - peppercorns[pepperHalf]);
	
	if(result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	}
}
