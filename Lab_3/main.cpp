#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
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
ifstream fin;
ofstream fout;
int main() {
	setlocale(LC_ALL, "ru");
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
	fin >> n;
	fin >> k;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		set <int> s;
		int el;
		for (int j = 0; j < k; j++) {
		
			fin >> el;
			el -= 1;
			s.insert(el);
		}
		g[i].assign(s.begin(),s.end());
	}

    fin.close();
   
		mt.assign(k, -1);
	for (int v = 0; v < n; ++v) {
		used.assign(n, false);
		try_kuhn(v);
	}

	fout.open("output.txt");
	if (!fout.is_open())
	{
		cout << "Не удалось открыть файл output.txt" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; j++) {
			if (mt[j] == i) fout << j + 1 << " ";

		}
	fout.close();
}