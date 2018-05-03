//
// Created by Karolina on 03.05.2018.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//2.Dana jest struktura HT, która opisuje tablicę haszującą rozmiaru size, przechowywującą liczby nieujemne:
//
//struct HT {
//    int* table;
//    int size;
//};
//Tablica korzysta z funkcji haszującej int hash(int x) i liniowego rozwiązywania konfliktów (ujemne wartości w tablicy table oznaczają wolne pola).
//
//Doskonałością takiej tablicy nazywamy liczbę elementów x takich, że pozycja x w tablicy to hash(x) % size (a więc x jest na "swojej" pozycji).
//
//Proszę napisać funkcję void enlarge(HT* ht), która powiększa tablicę dwukrotnie i wpisuje elementy w takiej kolejności, by doskonałość powstałej
//        tablicy była największa. Funkcja powinna być możliwie najszybsza.


//3. Dany jest ciag klocków (k1, ..., kn). Klocek ki zaczyna sie na pozycji ai i ciagnie sie do pozycji bi
//        (wszystkie pozycje to liczby naturalne) oraz ma wysokosc 1. Klocki układane sa po kolei. Jesli
//        klocek nachodzi na którys z poprzednich, to jest przymocowywany na szczycie poprzedzajacego
//klocka. Na przykład dla klocków o pozycjach (1,3), (2,5), (0,3), (8,9), (4,6) powstaje konstrukcja
//o wysokosci trzech klocków (vide rysunek). Prosze podac mozliwie jak najszybszy algorytm,
//        który oblicza wysokosc powstałej konstrukcji (bez implementacji) oraz oszacowac jego złozonosc
//obliczeniowa.
//0 1 2 3 4 5 6 7 8 9 10 x
//        k1
//k2
//        k3
//k4
//        k5
//Rysunek 1: Przykład konstrukcji.