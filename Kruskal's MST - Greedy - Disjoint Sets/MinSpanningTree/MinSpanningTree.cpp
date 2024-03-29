#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct elem {
	int parent;
	int rank;
	elem(int p, int r) {
		parent = p;  rank = r;
	}
};
struct edge {
	int a, b, w;
	edge(int aa, int bb, int ww) {
		a = aa; b = bb; w = ww;
	}
	
};
bool compare(edge e1, edge e2) {
	return e1.w < e2.w;
}
class DisJointSet {
	vector<elem> v;
	int sum = 0;
	
	int FindParent(int idx) {
		while (true) {
			if (v[idx].parent == idx) {
				return v[idx].parent;
			}
			idx = v[idx].parent;
		}
	}
	vector<int> firstTime;

public:
	void init() {

		for (int i = 0; i < 100; i++) {
			//parent of each disjoint set will be the same as its child till it's in another set
			// 1 is the rank means it has no one in its set except itself
			v.push_back(elem(i, 1));
			//firstime means no one uses me, the same as rank == 1
		}
	}
	void uni(edge e) {
		if (FindParent(e.a) != FindParent(e.b)) {
			
			int toBeReplaced,newValue;

			cout << "("<<e.a << "," << e.b << ")"<<endl;;
			if (v[e.a].rank >= v[e.b].rank) {
				toBeReplaced = v[e.b].parent;
				newValue = e.a;
				v[e.b].parent = e.a;
				v[e.a].rank++;
				sum += e.w;
			}
			else {
				toBeReplaced = v[e.a].parent;
				newValue = e.b;
				v[e.a].parent = e.b;
				v[e.b].rank++;
				sum += e.w;
			}
			for (int i = 0; i < v.size(); i++) {
				if (v[i].parent == toBeReplaced) {
					v[i].parent = newValue;
				}
			}
		  }
	}
	int getSum() {
		return sum;
	}
};
int main()
{

	vector<edge> edges;
	DisJointSet d;
	d.init();
/*	edges.push_back(edge(0, 1, 8));
	edges.push_back(edge(1, 3, 4));
	edges.push_back(edge(3, 2, 1));
	edges.push_back(edge(2, 0, 3));
	edges.push_back(edge(0, 3, 5));
*/
	edges.push_back(edge(0,1,10));
	edges.push_back(edge(0,2,6));
	edges.push_back(edge(0,3,5));
	edges.push_back(edge(1,3,15));
	edges.push_back(edge(2,3,4));

	/*
	edges.push_back(edge(1, 4, 1));
	edges.push_back(edge(0, 2, 2));
	edges.push_back(edge(2, 4, 3));
	edges.push_back(edge(0, 1, 4));
	edges.push_back(edge(0, 4, 5));
	edges.push_back(edge(3,5,6));
	edges.push_back(edge(1,2,7));
	edges.push_back(edge(4,5,8));
	edges.push_back(edge(2,5,9));
	edges.push_back(edge(0, 3, 10));
	edges.push_back(edge(3,4,11));
	*/
	sort(edges.begin(), edges.end(), compare);

	/*
	//printing the edges after sorting them by weight.
	for (auto it = edges.begin(); it != edges.end(); it++) {
		cout << (*it).a << "," << (*it).b << "," << (*it).w<< endl;
	}*/
	
	cout << "The edges in the minimum spanning tree are\n";
	for (auto it = edges.begin(); it != edges.end(); it++) {
		d.uni(*it);
	}
	cout <<"Total MST cost is "<< d.getSum()<<endl;
	system("pause");
}
