*PA - Tema 1
*Samson Alexandru-Valentin
*322CC

-Problema 1:
    Solutia aleasa utilizeaza o abordare de cautare binara pentru a gasi 
    valoarea maxima a puterii. Intervalul de cautare este setat initial intre 
    0 si valoarea maxima a alimentarii pentru toate serverele. In fiecare pas 
    al cautarii binare, se calculeaza puterea minima pe care o poate genera un 
    server la alimentarea curenta si se actualizeaza puterea maxima daca este 
    necesar. In functie de rezultat, se ajusteaza intervalul de cautare.
    Complexitatea temporala a solutiei este O(n * log m), unde n este numarul 
    de servere si m este valoarea maxima a pragurilor de alimentare. Acest 
    lucru se datoreaza faptului ca pentru fiecare pas al cautarii binare, se 
    parcurge lista de servere pentru a calcula puterea minima.
    Complexitatea spatiala este O(n), unde n este numarul de servere. Acest 
    lucru se datoreaza faptului ca se stocheaza puterea si alimentarea pentru 
    fiecare server in vectorii p si c.

-Problema 2:
    Solutia aleasa utilizeaza o abordare matematica. Pentru fiecare grup de 
    dreptunghiuri, se calculeaza numarul de moduri in care se pot colora 
    dreptunghiurile in functie de tipul dreptunghiurilor din grupul anterior 
    si de numarul de dreptunghiuri din grupul curent. Numarul de moduri este 
    calculat folosind o functie de exponentiere rapida, care calculeaza base ^ 
    exponent % mod in timp logaritmic.
    Complexitatea temporala a solutiei este O(K log N), unde K este numarul de 
    grupuri si N este numarul maxim de zone intr-un grup. Acest lucru se 
    datoreaza faptului ca pentru fiecare grup, se calculeaza numarul de moduri 
    in care se pot colora dreptunghiurile folosind functia de exponentiere 
    rapida, care are o complexitate temporala de O(log N).
    Complexitatea spatiala este O(1), deoarece nu se utilizeaza structuri de 
    date suplimentare care depind de dimensiunea inputului.

-Problema 3:
    Solutia aleasa utilizeaza o abordare greedy. Se parcurg vectorii A si B 
    simultan, iar pentru fiecare pozitie se verifica daca elementele sunt 
    egale. Daca sunt, se trece la urmatoarele elemente si se actualizeaza 
    lungimea maxima. Daca nu sunt, se construieste o suma cu elementele 
    urmatoare pentru elementul curent pana cand suma este egala cu suma din 
    celalalt vector.
    Complexitatea temporala a solutiei este O(n + m), unde n si m sunt 
    lungimile vectorilor A si B. Acest lucru se datoreaza faptului ca fiecare 
    element din fiecare vector este parcurs o singura data.
    Complexitatea spatiala este O(n + m), deoarece se utilizeaza doi vectori 
    pentru a stoca elementele.

-Problema 4:
    Solutia aleasa utilizeaza o abordare de programare dinamica. Se parcurg 
    toate literele din alfabet si pentru fiecare litera se calculeaza 
    diferenta dintre frecventa acesteia si frecventa celorlalte litere in 
    fiecare cuvant. Aceste diferente sunt stocate intr-un vector de perechi, 
    impreuna cu lungimea cuvantului corespunzator. Vectorul este sortat 
    descrescator dupa diferenta si se calculeaza suma maxima a lungimilor 
    cuvintelor cu conditia ca suma diferentelor sa fie strict pozitiva.
    Complexitatea temporala a solutiei este O(n * l), unde n este numarul
    de cuvinte si l este suma lungimilor cuvintelor din lista. Acest lucru se
    datoreaza faptului ca pentru fiecare litera se parcurg toate cuvintele si 
    se calculeaza suma maxima a lungimilor cuvintelor.
    Complexitatea spatiala este O(n * l), deoarece se utilizeaza o matrice 
    pentru aflarea sumei maxime a lungimilor cuvintelor ce respecta conditia.

-Problema 5:
    Solutia aleasa utilizeaza o abordare de programare dinamica. Se calculeaza 
    solutiile partiale pentru fiecare pozitie, considerand cele 3 cazuri 
    posibile de grupare a produselor (fara grupare, grupare cu produsul 
    anterior, grupare cu cele 2 produse anterioare). Solutiile partiale sunt 
    stocate in matricea S, unde S[i][j] reprezinta al j-lea cel mai bun pret 
    unic obtinut considerand primele i produse.
    Functia merge este folosita pentru a interclasa solutiile partiale obtinute 
    pentru cele 3 cazuri de grupare, pastrand doar primele k elemente 
    distincte. Aceasta functioneaza similar cu algoritmul de interclasare din 
    Merge Sort, dar cu 3 vectori in loc de 2.
    Complexitatea temporala a acestui algoritm este O(n * k), unde n este 
    numarul de produse si k este numarul de preturi distincte cautate. Acest 
    lucru se datoreaza faptului ca pentru fiecare produs se calculeaza o 
    solutie partiala care implica parcurgerea a cel mult k elemente.
    Complexitatea spatiala este de asemenea O(n * k), deoarece se stocheaza o 
    matrice de solutii partiale cu n linii si k coloane.