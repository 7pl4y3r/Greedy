#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//Page 63
class Third {

public:

	void exe() {

		in.open("data3.txt");
		read();
		sortList();
		greedy();
		print();

	}
	
private:

	struct obj {

		int k;
		float g, p, f;
	};

	ifstream in;
	int n, gr[50], s[50], m;
	float G;
	obj v[100], aux;

	void read() {

		in >> n;
		in >> G;
		for (int i = 0; i < n; i++) {

			v[i].k = i;
			in >> v[i].g;
			in >> v[i].p;
			v[i].f = (float)v[i].p / v[i].g;
		}

		in.close();
	}

	void sortList() {

		for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if (v[i].f < v[j].f) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	}

	void greedy() {

		int j = -1;
		for(int i = 0; i < n && G != 0; i++)
			if (G > v[i].g) {

				j++;
				s[j] = v[i].k;
				gr[j] = v[i].g;
				G -= v[i].g;
			}
			else {

				j++;
				s[j] = v[i].k;
				gr[j] = G / v[i].g;
				G = 0;
			}

		m = j;
	}

	void print()
	{
		for (int i = 0; i < m; i++) {
			cout << "Obiectul " << v[s[i]].k << " cantitatea ";
			cout << gr[i] * v[s[i]].g << endl;
		}
	}

};