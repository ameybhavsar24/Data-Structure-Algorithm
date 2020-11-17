#include <iostream>
#include <vector>

using namespace std;

class DSU {
	int n;
	vector< int > parent;
	vector< int > size;
	public:
	int nCC;
	DSU (int len) {
		n = len;
		init();
		nCC = n;
	}
	void init () {
		size.assign(n, 1);
		parent.resize(n);
		for (int i=0; i<n; i++) {
			parent[i] = i;
		}
	}
	int find_set (int v) {
		if (v == parent[v]) return v;
		return parent[v] = find_set(parent[v]);
	}
	void union_sets (int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] < size[b]) swap(a,b);
			parent[b] = a;
			size[a] += size[b];
			--nCC;
		}
	}
};

int main() {
	
}
