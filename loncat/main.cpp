#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>

using namespace std;

struct cat {
	double angle;
	double distance;
	long height;
	long x, y;
};

double tresh = 0.00000001;

bool catCompare (const cat &a,const cat &b) {
	//if(abs(a.angle - b.angle) < tresh)
	if(a.angle == b.angle)
		return a.distance > b.distance;
	else
		return a.angle < b.angle; 
}

bool catCompare2 (const cat &a,const cat &b) {
//	if(a.x - b.x < tresh)
	if(a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x; 
}



int main() {
	//read cats
	vector<cat> cats;
	int N;
	while(cin >> N ) { //number of cats
	if(N == 0)
		break;
	for(int i = 0; i < N; i++) {
		double x, y, z;
		cin >> x >> y >> z;
		struct cat myCat;
		if (x != 0)
			myCat.angle = y / x;
		else
			if(y < 0)
				myCat.angle = INFINITY * -1;
			else
				myCat.angle = INFINITY;
		myCat.x = x;
		myCat.y = y;
		myCat.distance = sqrt(x * x + y * y);
		myCat.height = z;
		cats.push_back(myCat);
	}
	//sort the cats according to angle
	sort(cats.begin(), cats.end(), catCompare);
	for(unsigned int i = 0; i < N; i++)
		cout << "cat @ " << cats[i].angle << " dist " << cats[i].distance << endl;
	
	vector<cat> tooSmall;
	for(int i = 0; i < N ; i++) {
		int j = i+1;
		//while(j < N && abs(cats[j].angle - cats[i].angle) < tresh) {
		while(j < N && cats[j].angle == cats[i].angle) {		
			if(cats[i].height <= cats[j].height) {
				cout << "cat " << i << " @ " << cats[i].x << "|" << cats[i].y << "|" << cats[i].height << " is smaller than cat " << j << " @ " << cats[j].x << "|" << cats[j].y << "|" << cats[j].height << endl;
				tooSmall.push_back(cats[i]);
				break;
			}
			j++;
		}
	}

	if(tooSmall.size() == 0)
		cout << "I be keepin mah bukkits." << endl;
	else {
		cout << "Bukkit delivaries:" << endl;
		sort(tooSmall.begin(), tooSmall.end(), catCompare2);
		for(int i = 0; i < tooSmall.size(); i++) {
			cout << tooSmall[i].x << " " << tooSmall[i].y << endl;
		}
	}
	}
	
}
