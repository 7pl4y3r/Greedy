#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Second {

public:

	void exe() {

		in.open("data2.txt");
		in >> n;
		for (int i = 1; i <= n; i++) {
			in >> v[i].t;
			in >> v[i].d;
		}

		quickSort(1, n);
		greedy();

	}

private:

	ifstream in;

	struct Data {
		int t;
		int d;
	};

	int n, a[10];
	Data v[10];

	void quickSort(int l, int r) {

		if (l < r) {

			int piv = l;
			int i = l;
			int j = r;
			Data temp;

			while(v[i].t + v[i].d < v[piv].t + v[piv].d)
				i++;

			while (v[j].t + v[j].d > v[piv].t + v[piv].d)
				j--;

			if (i < j) {
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}

			temp = v[piv];
			v[piv] = v[j];
			v[j] = temp;

			quickSort(l, j - 1);
			quickSort(j + 1, r);
		}
	}

	void greedy() {

		int l = 1;
		a[l] = 1;
		for (int i = 2; i <= n; i++)
			if (v[i].d >= v[a[i]].t + v[a[i]].d)
				a[++l] = i;

		print(l);
	}

	void print(int l) {

		for (int i = 1; i <= l; i++)
			if(a[i] != 0)
			cout << v[a[i]].t << ' ' << v[a[i]].d + v[a[i]].t << endl;
	}
};