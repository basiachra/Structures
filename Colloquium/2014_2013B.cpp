//
// Created by Karolina on 03.05.2018.
//
//
//B
//1. Prosze zaimplementowac funkcje usuwajaca zadana liczbe ze SkipListy przechowujacej dane
//typu int. Prosze zadeklarowac wszystkie potrzebne struktury danych i krótko (2-3 zdania) opisac
//        zaimplementowany algorytm.

//2. Prosze opisac jak zmodyfikowac drzewa AVL (przechowujace elementy typu int) tak, by
//        operacja int findRandom(T) zwracajaca losowo wybrany element z drzewa T działała w czasie
//O(log n). Funkcja findRandom powinna zwracac kazdy element z drzewa z takim samym
//        prawdopodobienstwem. Do dyspozycji maja Panstwo funkcje int random( int k ), która
//zwraca liczbe ze zbioru f0, ..., k − 1g zgodnie z rozkładem jednostajnym. Pozostałe operacje na
//        powstałym drzewie powinny miec złozonosc taka sama jak w standardowym drzewie AVL.
//(Podpowiedz: Warto w kazdym wezle drzewa przechowywac pewna dodatkowa informacje, która
//upraszcza wykonanie operacji findRandom i która mozna łatwo aktualizowac).

//3. Dana jest tablica:
//int n = ...
//int m = ...
//bool A[m][n];
//Gracz poczatkowo znajduje sie na (zadanej) pozycji (x, y), dla której zachodzi A[y][x] == true.
//Z danej pozycji wolno bezposrednio przejsc jedynie na pozycje, której dokładnie jedna
//        współrzedna rózni sie o 1, oraz której wartosc w tablicy A wynosi true. Prosze napisac program
//        obliczajacy do ilu róznych pozycji moze dojsc gracz startujac z zadanej pozycji (x, y).