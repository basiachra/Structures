////
//// Created by Karolina on 03.05.2018.
////
//
//1. Prosze zaimplementowac funkcje wstawiajaca zadana liczbe do SkipListy przechowujacej dane
//        typu int. Prosze zadeklarowac wszystkie potrzebne struktury danych i krótko (2-3 zdania) opisac
//        zaimplementowany algorytm.

//2. Prosze opisac jak zmodyfikowac drzewa czerwono-czarne (przechowujace elementy typu int) tak,
//by operacja int sum(T, x, y) obliczajaca sume elementów z drzewa o wartosciach
//        z przedziału [x, y] działała w czasie O(log n) (gdzie n to rozmiar drzewa T). Pozostałe operacje
//na powstałym drzewie powinny miec złozonosc taka sama jak w standardowym drzewie
//czerwono-czarnym. (Podpowiedz: Warto w kazdym wezle drzewa przechowywac pewna dodatkowa
//        informacje, która upraszcza wykonanie operacji sum i która mozna łatwo aktualizowac).

//3. Kapitan pewnego statku zastanawia sie, czy moze wpłynac do portu mimo tego, ze nastapił
//odpływ. Do dyspozycji ma mape zatoki w postaci tablicy:
//int n = ...
//int m = ...
//int A[m][n];
//gdzie wartosc A[y][x] to głebokosc zatoki na pozycji (x, y). Jesli jest ona wieksza niz pewna
//wartosc int T to statek moze sie tam znalezc. Poczatkowo statek jest na pozycji (0, 0) a port
//znajduje sie na pozycji (n − 1,m − 1). Z danej pozycji statek moze przepłynac bezposrednio
//        jedynie na pozycje bezposrednio obok (to znaczy, na pozycje, której dokładnie jedna ze
// współrzednych rózni sie o jeden). Prosze napisac funkcje rozwiazujaca problem kapitana.