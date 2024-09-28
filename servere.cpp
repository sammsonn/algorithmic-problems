#include <bits/stdc++.h>

using namespace std;

// functie care calculeaza cea mai mica putere pentru alimentarea curenta
double compute_power(int n, vector<int> &p, vector<int> &c,
double current, double &threshold_of_min_power) {
	double min_power = 1e9;

	// parcurg fiecare server
	for (int i = 0; i < n; i++) {
		// calculez puterea de calcul a serverului pentru alimentarea curenta
		double power = p[i] - abs(c[i] - current);

		if (power < min_power) {
			min_power = power;
			// salvez limita de alimentare pentru serverul cu puterea minima
			threshold_of_min_power = c[i];
		}
	}

	return min_power;
}

int main() {
	ifstream fin("servere.in");
	ofstream fout("servere.out");

	int n;
	fin >> n;

	vector<int> p(n), c(n);
	for (int i = 0; i < n; i++) {
		fin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		fin >> c[i];
	}

	// setez capetele intervalului de alimentare in care voi cauta
	double low = 0, high = *max_element(c.begin(), c.end());
    double threshold_of_min_power, max_power = -INT_MAX, error;

	// setez eroarea in functie de numarul de servere
	if (n > 10) {
		error = 1.0 / n;
	} else {
		error = 1e-9;
	}

	/* caut binar valoarea maxima a puterii cat timp diferenta dintre capetele
	alimentarii este mai mare decat eroarea setata */ 
	while (high - low > error) {
		double mid = (high + low) / 2;
		// calculez puterea cea mai mica pentru alimentarea curenta
		double power = compute_power(n, p, c, mid, threshold_of_min_power);

		max_power = max(max_power, power);

		/* daca limita de alimentare pentru serverul cu puterea minima pentru
		alimentarea curenta este mai mica decat alimentarea curenta */ 
		if (threshold_of_min_power < mid) {
			// scad limita superioara a intervalului de cautare
			high = mid - error;
		} else {
			// altfel, cresc limita inferioara a intervalului de cautare
			low = mid + error;
		}
	}

	fout << fixed << setprecision(1) << max_power << "\n";

	return 0;
}
