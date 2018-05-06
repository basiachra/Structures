//
// Created by Karolina on 03.05.2018.
//

//1. Dane sa struktury danych opisujace SkipListe:
//struct SLNode f
//int value; // wartosc przechowywana w wezle
//int level; // poziom wezła
//SLNode** next; // level-elementowa tablica wskazników na nastepniki
//g;
//struct SkipList f
//SLNode* first; // wartownik przedni (pole value ma wartosc -1)
//SLNode* last; // wartownik tylny (pole value ma wartosc +1)
//g;
//const int MAX LEVEL = ... ; // maksymalny poziom wezłów
//Prosze zaimplementowac funkcje SkipList merge( SkipList A, SkipList B ), która scala
//dwie otrzymane SkipListy (w efekcie powstaje nowa SkipLista składajaca sie z dokładnie tych
//        samych wezłów co poprzednie; nie nalezy zmieniac poziomów wezłów). Wezły wartowników maja
//        poziom MAX LEVEL. Funkcja powinna działac mozliwie jak najszybciej. Prosze oszacowac
//złozonosc czasowa.


//2. Prosze opisac (bez implementacji) algorytm, który otrzymuje na wejsciu pewne drzewo BST T
//i tworzy nowe drzewo BST T0, które spełnia nastepujace warunki: (a) T0 zawiera dokładnie te
//same wartosci co T, oraz (b) drzewo T0 jest drzewem czerwono-czarnym (w zwiazku z tym
//        powinno zawierac kolory wezłów).
//druga grupa: AVL

//3. W ramach obchodów miedzynarodowego swieta cyklistów organizatorzy przewidzieli górska
//        wycieczke rowerowa. Bedzie sie ona odbywac po bardzo waskiej sciezce, na której rowery moga
//        jechac tylko jeden za drugim. W ramach zapewnienia bezpieczenstwa kazdy rowerzysta bedzie
//        miał numer identyfikacyjny oraz małe urzadzenie, przez które bedzie mógł przekazac
//        identyfikator rowerzysty przed nim (lub -1 jesli nie widzi przed soba nikogo). Nalezy napisac
//funkcje, która na wejsciu otrzymuje informacje wysłane przez rowerzystów i oblicza rozmiar
//        najmniejszej grupy (organizatorzy obawiaja sie, ze na małe grupy mogłyby napadac dzikie
//zwierzeta). Dane sa nastepujace struktury danych:
//struct Cyclist f
//int id, n id; // identyfikator rowerzysty oraz tego, którego widzi
//g;
//Funkcja powinna miec prototyp int smallestGroup( Cyclist cyclist[], int n ), gdzie
//cyclist to tablica n rowerzystów. Funkcja powinna byc mozliwie jak najszybsza. Mozna załozyc,
//        ze identyfikatory rowerzystów to liczby z zakresu 0 do 108 (osiem cyfr napisanych w dwóch
//        rzedach na koszulce rowerzysty) i ze pamiec nie jest ograniczona. Rowerzystów jest jednak duzo
//mniej niz identyfikatorów (nie bez powodu boja sie dzikich zwierzat). Nalezy zaimplementowac
//wszystkie potrzebne struktury danych.


#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int ID_MAX = 1000;
const int CYCLIST_COUNT = 10;

typedef struct Cyclist {
    int id, n_id;           //identyfiktor rowerzysty oraz tego, ktorego widzi
} Cyclist;

typedef struct Group {
    int first_id;           //identyfikator pierwszej osoby, potem jest identyfikatorem osoby, dla ktorej szukamy osoby, ktora go widzi
    int size;               //rozmiar grupy
} Group;


Cyclist *generate_data() {
    srand(time(NULL));
    bool *B = (bool *) calloc(sizeof(bool), CYCLIST_COUNT);
    Cyclist *C = (Cyclist *) calloc(sizeof(Cyclist), CYCLIST_COUNT);

    for (int i = 0; i < CYCLIST_COUNT; ++i) {
        C[i].id = rand() % ID_MAX;
    }

    C[0].n_id = -1;
    for (int i = 1; i < CYCLIST_COUNT; ++i) {

        if (rand() % 4 == 0)
            C[i].n_id = -1;
        else {
            int x = rand() % CYCLIST_COUNT;
            while (B[x]) {                          //lata na sytuacje, w ktorej dwaj rowerzysci maja przed soba ta sama osobe
                x = rand() % CYCLIST_COUNT;         //jada gesiego => sytuacja niemozliwa
            }

            C[i].n_id = C[x].id;
            B[x] = true;
        }
    }

    return C;
}


int smallest_group(Cyclist *cyclist, int n) {
    Group*G = (Group*)calloc(sizeof(Group),n);

    bool*B = (bool*)calloc(sizeof(bool),n);

    int max_group_size = 0;
    int group_count = 0;
    int j = 0;

    for (int i = 0; i < CYCLIST_COUNT; ++i) {

        if (cyclist[i].n_id == -1){             //znalezienie pierwszych osob w grupie
            G[j].first_id = cyclist[i].id;      //ustawienie
            G[j].size++;

            B[i] = true;                            //ustawienie ze przewtorzono
            group_count++;
            j++;
        }
    }

    for (int i = 0; i < CYCLIST_COUNT; ++i) {
        if (!B[i]) {
            for (int j = 0; j < group_count; ++j) {
                if (cyclist[i].n_id ==  G[j].first_id){
                    G[j].size++;
                    G[j].first_id = cyclist[i].id;
                    B[i] = true;
                    i = -1;
                    break;
                }
            }
        }
    }


    for (int i = 0; i < group_count; ++i) {
        if (G[i].size > max_group_size)
            max_group_size = G[i].size;
    }

    return max_group_size;
}

int main(){
    //smallest_group(generate_data(),100);

    Cyclist*c = generate_data();
    for (int i = 0; i < CYCLIST_COUNT; ++i) {
        cout << c[i].id << " ";
    }
        cout << endl;

    for (int i = 0; i < CYCLIST_COUNT; ++i) {
        cout <<c[i].n_id << " ";
    }
    cout << endl;

    cout << smallest_group(c,CYCLIST_COUNT);

}
