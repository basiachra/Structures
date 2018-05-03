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
