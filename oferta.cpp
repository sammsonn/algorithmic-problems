#include <bits/stdc++.h>

using namespace std;

// functie care realizeaza interclasarea a 3 vectori sortati
void merge(double a[], double b[], double c[], double d[], int &k) {
    // lungimile celor 3 vectori
    int l1 = a[0], l2 = b[0], l3 = c[0];
    int c1 = 1, c2 = 1, c3 = 1;

    /* cel mai mic element disponibil din primul vector = "primul element", din
    al doilea = "al doilea element", din al treilea = "al treilea element" */

    /* cat timp nu am introdus deja k elemente in
    vectorul rezultat si mai exista un vector de parcurs */
    while (d[0] != k && (c1 <= l1 || c2 <= l2 || c3 <= l3)) {
        // daca am ajuns la capatul primului vector
        if (c1 == l1 + 1) {
            /* daca am ajuns la sfarsitul vectorului 3 sau daca n-am ajuns la
            sfarsitul vectorului 2 si elementul 2 este <= elementul 3 */
            if (c3 == l3 + 1 || (c2 <= l2 && b[c2] <= c[c3])) {
                // adaug al doilea element in vectorul rezultat
                d[(int)++d[0]] = b[c2++];
            } else {
                // altfel, adaug al treilea element
                d[(int)++d[0]] = c[c3++];
            }
        // altfel, daca am ajuns la capatul celui de-al doilea vector
        } else if (c2 == l2 + 1) {
            /* daca am ajuns la sfarsitul vectorului 3 sau daca n-am ajuns la
            sfarsitul vectorului 1 si elementul 1 este <= elementul 3 */
            if (c3 == l3 + 1 || (c1 <= l1 && a[c1] <= c[c3])) {
                // adaug primul element in vectorul rezultat
                d[(int)++d[0]] = a[c1++];
            } else {
                // altfel, adaug al treilea element
                d[(int)++d[0]] = c[c3++];
            }
        // altfel, daca am ajuns la capatul celui de-al treilea vector
        } else if (c3 == l3 + 1) {
            /* daca am ajuns la sfarsitul vectorului 2 sau daca n-am ajuns la
            sfarsitul vectorului 1 si elementul 1 este <= elementul 2 */
            if (c2 == l2 + 1 || (c1 <= l1 && a[c1] <= b[c2])) {
                // adaug primul element in vectorul rezultat
                d[(int)++d[0]] = a[c1++];
            } else {
                // altfel, adaug al doilea element
                d[(int)++d[0]] = b[c2++];
            }
        // altfel, daca nu am ajuns la capatul niciunui vector
        } else {
            // daca primul element este cel mai mic
            if (a[c1] <= b[c2] && a[c1] <= c[c3]) {
                // adaug primul element in vectorul rezultat
                d[(int)++d[0]] = a[c1++];
            } else if (b[c2] <= a[c1] && b[c2] <= c[c3]) {
                /* altfel, daca al doilea element este cel mai mic
                adaug al doilea element in vectorul rezultat */
                d[(int)++d[0]] = b[c2++];
            } else {
                // altfel, adaug al treilea element
                d[(int)++d[0]] = c[c3++];
            }
        }

        /* incrementez contoarele pentru cei 3 vectori cat este necesar,
        intrucat vectorul rezultat trebuie sa contina doar elemente distincte */
        while (c1 <= l1 && a[c1] == d[(int)d[0]]) {
            c1++;
        }
        while (c2 <= l2 && b[c2] == d[(int)d[0]]) {
            c2++;
        }
        while (c3 <= l3 && c[c3] == d[(int)d[0]]) {
            c3++;
        }
    }
}

// matricea de stocare a solutiilor partiale
double S[7082][4838];

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;
    fin >> n >> k;

    double prices[7082];

    // initializez matricea de solutii partiale
    S[0][0] = 1;
    S[0][1] = 0;

    // parcurg fiecare produs
    for (int i = 1; i <= n; i++) {
        fin >> prices[i];

        /* vectorii temporari pentru stocarea solutiilor partiale
        corespunzatoare celor 3 cazuri de grupare, pentru pozitia i */
        double S_temp1[k + 1];
        double S_temp2[k + 1];
        double S_temp3[k + 1];

        // lungimea solutiei partiale pentru pozitia i-1
        int l = S[i - 1][0];
        S_temp1[0] = l;

        /* calculez solutia partiala pentru cazul in care
        ultimul pachet nu este grupat cu niciunul din spate */
        for (int j = 1; j <= l; j++)
            S_temp1[j] = (S[i - 1][j] + prices[i]);

        /* daca avem cel putin 2 produse in total, consideram cazul
        in care ultimul pachet este grupat doar cu cel de dinainte */
        if (i >= 2) {
            // calculez costul pentru gruparea ultimelor 2 produse
            double cost2 = prices[i - 1] + prices[i]
            - min(prices[i], prices[i - 1]) / 2;

            // lungimea solutiei partiale pentru pozitia i-2
            l = S[i - 2][0];
            S_temp2[0] = l;

            /* consideram solutia partiala pentru pozitia i-2,
            adaugand costul pentru gruparea ultimelor 2 produse */
            for (int j = 1; j <= l; j++)
                S_temp2[j] = (S[i - 2][j] + cost2);
        }

        /* daca avem cel putin 3 produse in total, consideram cazul
        in care ultimul pachet este grupat cu cele 2 de dinainte */
        if (i >= 3) {
            // calculez costul grupari ultimelor 3 produse
            double cost3 =
                prices[i - 2] + prices[i - 1] + prices[i]
                - min(prices[i], min(prices[i - 1], prices[i - 2]));

            // lungimea solutiei partiale pentru pozitia i-3
            l = S[i - 3][0];
            S_temp3[0] = l;

            /* consideram solutia partiala pentru pozitia i-3,
            adaugand costul pentru gruparea ultimelor 3 produse */
            for (int j = 1; j <= l; j++)
                S_temp3[j] = (S[i - 3][j] + cost3);
        }

        /* interclasez solutiile partiale pentru
        cele 3 cazuri, pastrand doar primele k elemente distincte */
        merge(S_temp1, S_temp2, S_temp3, S[i], k);
    }

    // daca nu exista k preturi distincte, afisez -1
    if (S[n][0] < k) {
        fout << "-1\n";
    // altfel, afisez al k-lea cel mai bun pret unic
    } else {
        fout << fixed << setprecision(1) << S[n][k] << "\n";
    }

    return 0;
}
