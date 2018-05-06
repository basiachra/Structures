//
// Created by Karolina on 03.05.2018.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//I termin

//[2pkt.] Zadanie 2. Dana jest SkipLista przechowująca liczby z przedziału (0,1). Proszę opisać (bez
//  implementacji) algorytm, który z takiej SkipListy usuwa wszystkie liczby z zadanego przedziału (x, y)
//        (gdzie 0 < x < y < 1). Proszę oszacować złożoność obliczeniową zaproponowanego algorytmu jako funkcję
//liczby n elementów w SkipLiście (przed operacją usuwania) oraz liczby d elementów, które zostaną
//        usunięte. Proszę uzasadnić przedstawione oszacowanie złożoności. Algorytm powinien być możliwie jak
//        najszybszy. Ocenie podlega poprawność i efektywność algorytmu (1pkt) oraz poprawność oszacowania
//        złożoności czasowej (1pkt).

//Złożoność O(logn + d)
//Wyszukuje wartość x i zapamiętuję poprzednika, wyszukuje następnika y i przepinam i usuwam za pomocą remove 

//[2pkt.] Zadanie 4. Dany jest graf G = (V, E), którego wierzchołki reprezentują punkty nawigacyjne nad
//        Bajtocją, a krawędzie reprezentują korytarze powietrzne między tymi punktami. Każdy korytarz
//powietrzny ei ∈ E powiązany jest z optymalnym pułapem przelotu pi ∈ N (wyrażonym w metrach).
//Przepisy dopuszczają przelot danym korytarzem jeśli pułap samolotu różni się od optymalnego najwyżej o
//t metrów. Proszę zaproponować algorytm (bez implementacji), który sprawdza czy istnieje możliwość
//        przelotu z zadanego punktu x ∈ V do zadanego punktu y ∈ V w taki sposób, żeby samolot nigdy nie
//        zmieniał pułapu. Algorytm powinien być poprawny i możliwie jak najszybszy. Proszę oszacować jego
//        złożoność czasową.

//III termin
//Rozważmy tablice haszujące z adresowaniem otwartym i liniowym rozwiazywaniem konfliktów. Zakładamy że
//sprawdzenie czy dany ele należy do takiej tablicy zajmuje czas stały. Mamy dane dwie tablice A,B obie
//majace n pół i przechowujace k elementów (k<=n) Przy standardowej implementacji sprawdzenie, czy takie
//        tablice zawierają dokładnie takie same elementy zajmuje czas O(n). Proszę zaproponować rozszerzenie
//tej struktury danych tak aby nie pogorszyła się złożoność operacji wstawiania, usuwania i sprawdzania
//przynależnosci elementów ale by dało się sprawdzać czy dwie tablice mają dokładnie takie same elem w
//czasie O(k), Proszę opisać alg porównywania tablic.
