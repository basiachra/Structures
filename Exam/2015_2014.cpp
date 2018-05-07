//
// Created by Karolina on 03.05.2018.
//
//
//1.Drzewo BST jest opisane przez strukturę:
//
//struct BST {
//    BST *left, *right;
//    int value;
//};
//Proszę zaimplementować funkcję int countInterval(BST *T, int a, int b), która oblicza ile liczb z zadanego przedziału
//domkniętego [a,b] znajduje się w drzewie T.
//
//2.
//Dana jest struktura danych opisująca tab hasz, która przechowuje liczby
//typu int indeksowane napisami:
//
//struct HT{
//    string *key; //tab na klucze danych
//    int *data;//tab na dane
//    bool * free;//pole wolne czy zajęte
//    int size; //rozmiar tablicy
//};
//
//Tablica wykorzystuje funkcje haszująca int hash(string key, int size), która
//zwraca pozycję w tablicy na której powinny się znaleźć dane o kluczu key.
//Stosowane jest liniowe rozwiązywanie kolizji. Proszę zaimplementować funkcję
//double avarageAccess(HT * ht), która oblicza jaka jest średnia ilość pól w tablicy,
//które musi sprawdzić standardowy algorytm wyszukujący gdy poszukuje losowo wybranego
//klucza znajdującego się w tablicy ht.