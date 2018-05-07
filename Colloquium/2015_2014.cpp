//
// Created by Karolina on 03.05.2018.
//

//1. Pewna firma przechowuje duzo iczb pierwszych w postaci binarnej jako stringi ”10101...”.
//Zaimplementuj strukture danych Set do przechowywania tych danych. Napisz funkcje:
//Set createSet( string A[], int n ), która tworzy Set z n-elementowej tablicy stringów
//        oraz bool contains( Set a, string s ), która sprawdza czy dana liczba jest w Secie.
//Oszacuj złozonosc czasowa i pamieciowa powyzszych funkcji.

//tworzymy Set, która za pomocą getHash zamienia stringi na liczby, przechowując je w ten sposób w tablicy rozproszonej
#include<iostream>
#include <cmath>

using namespace std;

enum Status { freeToGo, taken };

struct Data {
    int value;
};

struct Set {
    Data ** data;
    Status * status;
    int size;
};
int frombinaryto10(int n){
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
int getHash(Data * data){
    data->value;
}
void view(Set *HT){
    //wyswietlenie HashTable
    for (int i = 0; i < HT->size; i++)
    {
        if (HT->data[i] != NULL)
        {
            cout << HT->data[i]->value <<endl;
        }
    }
}
int findindex(Set * HT, Data * data, bool sokl)//so keep looking
{
    Status status;
    int x = getHash(data);
    //int index = x % HT->size;
    int i = 0;
    while (HT->size > i)
    {
        if (HT->data[x] == data && HT->status[x] == taken) return x;
        if (HT->status[x] == freeToGo) return x;

        x = (x + 1) % HT->size;
        i++;
    }
    return -1;
}
//dodawanie adresowanie otwarte
void insert(Set * HT, Data * data)
{
    //ustalanie indeksu
    int index = findindex(HT, data, false); //dodawanie gdy status == keep looking lub free więc sokl == true
    if (index == -1) return;


    HT->status[index] = taken;
    HT->data[index] = data;
}

void createinsertData(Set *HT, string A[], int n){

    for(int i=0;i<n;i++){
        Data *data =new Data;
        data->value=frombinaryto10(stoi(A[i]));////czemu mi się tu wykrzacza
        insert(HT,data);
    }
}



Set createSet(string A[], int n){
    Set * HT = new Set;
    HT->size = n;
    HT->data = new Data *[HT->size];

    //ustawianie wszystkich pól na NULL
    for (int i = 0; i < HT->size; i++) {
        HT->data[i] = NULL;
        HT->status[i] = freeToGo;
    }
    createinsertData(HT,A,n);
    view(HT);
}


//szukanie adresowanie otwarte
bool contains( Set *a, string s )  // w temacie zadania jest bez
{
    Data *data= new Data;
    data->value=frombinaryto10(stoi(s));

    int index = findindex(a, data, true);
    if (index == -1) return false;

    if (a->status[index] == taken && a->data[index] == data) return true;

    return false;
}

//n operacji insert => O(1) * n => O(n)
// wyszukiwanie elementu O(1)
//Pamięciowa => O(n)


int main()
{
    int n = 5;
    string A[n]={"1", "111","1111","1000","100"};
    createSet(A,n);

    cout << frombinaryto10(stoi(A[1])) << endl;

    //if (find(HT, data4)) cout << "got it!!" << endl;
    //else cout << "couldn't find it ;c" << endl;

    return 0;
}
