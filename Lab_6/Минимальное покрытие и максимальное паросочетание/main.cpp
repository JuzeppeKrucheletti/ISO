#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
//MM
int n, k;
vector <vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
//MC
vector < vector<int> > G; // граф
int l; // число вершин
vector<bool> used2;
bool *mass;
void dfs(int v) {
	used2[v] = true;
	for (vector<int>::iterator i = G[v].begin(); i != G[v].end(); ++i)
		if (!used2[*i])
			dfs(*i);
}

int main() {
	setlocale(LC_ALL, "rus");
	n = 5;
	k = 4;
	g.resize(n);
	//g = { {0,2},{1,3},{4},{0,3,4,5},{2},{0,4,5} };
	g = { {1},{1},{0,1,2},{1,3},{3} };
	mt.assign(k, -1);
	for (int v = 0; v < n; ++v) {
		used.assign(n, false);
		try_kuhn(v);
	}

	mass = new bool [n+k];
	for (int i = 0; i < n+k; i++) {
		if (i < k) mass[i] = false;
		else mass[i] = true;
	}
	cout << "Максимальное паросочетание:" << endl;
	l = n + k;
	G.resize(l);
	for (int i = 0; i < n; i++) {
		G[i + k] = g[i];
	}
	for (int i = 0; i < k; ++i)
		if (mt[i] != -1) {
			printf("%d %d\n", i, mt[i] + k);
			mass[mt[i]+k] = false;
			G[i].push_back(mt[i] + k);
			G[mt[i] + k].erase(std::remove(G[mt[i] + k].begin(), G[mt[i] + k].end(), i), G[mt[i] + k].end());
		}
	cout << "Минимальное вершинное покрытие:" << endl;
	used2.assign(l, false);
	for (int i = 0; i < l; i++) {
		if (mass[i]) {
			dfs(i);
		}
	}
	for (int i = 0; i < l; i++) {
		if ((used2[i] == true && i < k) || (used2[i] == false && i >= k)) cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}