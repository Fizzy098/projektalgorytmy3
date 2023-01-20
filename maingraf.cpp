#include <iostream>
#include <iomanip>

using namespace std;
void petle(int wierzcholki, int **macierz){
    int i;
    for(i = 0; i < wierzcholki; i++){
                if(macierz[i][i] == 1){ //sprawdzamy czy wierzcholek z ktorego wychodzi krawedz i do ktorego to ten sam
                    cout << "Wierzcholek  " << i << "  posiada petle" << endl;
                }
            }
}

void krawedziedwukierunkowe(int wierzcholki, int **macierz){
    int i,j;
    for(i = 0; i < wierzcholki; i++){
        for(j = 0; j < wierzcholki; j++){
            if(macierz[i][j] == 1 && macierz[j][i] == 1 && i != j){ //sprawdzamy czy wierzcholki posiadaja krawedzie w obie strony, pomijamy "petle"
                cout << "Wierzcholek  " << i << "  posiadaja krawedz dwukierunkowa" << endl;
            }
        }
    }
}

void wierzcholekizolowany(int wierzcholki, int **macierz){
    int i,j,a;
    for(i = 0; i < wierzcholki; i++){
        a = 0;
        for(j = 0; j < wierzcholki; j++){
            if(macierz[i][j] == 0 && macierz[j][i] == 0){
                a++; //jesli wierzcholek posiada same zera w macierzy, jest wierzcholkiem izolowanym
            }
        }
        if(a == wierzcholki){
            cout << "Wierzcholek  " << i << "  jest wierzcholkiem izolowanym" << endl;
        }
    }
}

void sadziedzi(int wierzcholki, int **macierz){
    int i,j;
    for(i = 0; i < wierzcholki; i++){
        for(j = 0; j < wierzcholki; j++){
            if(macierz[i][j] == 1 && i != j){ //sprawdzamy do jakiego wierzholka wychodzi krawedz z sprawdzanego wierzcholka
                cout << "Sasiadem wierzcholka  " << i << "  jest wierzcholek  " << j << endl;
            }
        }
    }
}

void stopien(int wierzcholki, int **macierz){
    int i,j, a,b;
    for(i = 0; i < wierzcholki; i++){
        a = 0, b = 0;
        for(j = 0; j < wierzcholki; j++){ // zliczamy wszyskie krawedzie wchodzace i wychodzace z wierzcholka
            if(macierz[i][j] == 1 ){
                a++;
            }
            if(macierz[j][i] == 1){
                b++;
            }
        }
        cout << "Stopien wchodzacy wierzcholka " << i << " to:  " << b << endl;
        cout << "Stopien wychodzacy wierzcholka " << i << " to:  " << a << endl;
    }
}

void sasiedzikazdego(int wierzcholki, int **macierz){
    int i,j, a;
    for(i = 0; i < wierzcholki; i++){
        a = 0;
        for(j = 0; j < wierzcholki; j++){
            if(macierz[i][j] == 1 ){ //sprawdzamy jaki wierzcholek posiada same jedynki w macierzy
                a++;
            }
        }
        if(a == wierzcholki || a == wierzcholki-1){
            cout << "Wierzcholek " << i << " jest sasiadem kazdego wierzcholka" << endl;
        }
    }
}

int main( )
{
    int wierzcholki, krawedzie, **macierz;
    int a,b;
    //wprowadzanie ilosci wierzcholkow oraz krawedzi
    cout << "Podaj liczbe wierzcholkow:";
    cin >> wierzcholki;
    cout << "Podaj liczbe krawedzi:";
    cin >> krawedzie;
    //tworzenie tablicy wskaznikow
    macierz = new int *[wierzcholki];

    for(int i = 0; i < wierzcholki; i++){
        macierz[i] = new int [wierzcholki];
    }
    //tworzenie macierzy sasiedztwa wypelnionej na start zerami
    for(int i = 0; i < wierzcholki;i++){
        for(int j = 0; j< wierzcholki;j++){
            macierz[i][j] = 0;
        }
    }
    //wprowadzanie krawedzi
    for(int i = 0; i < krawedzie; i++){
        cout << "Podaj wierzcholek z ktorego wychodzi krawedz: ";
        cin >> a;
        cout << "Podaj wierzcholek do ktorego wchodzi krawedz: ";
        cin >> b;
        macierz[a][b] = 1;
    }
    //wywolanie funkcji
    petle(wierzcholki,macierz);
    krawedziedwukierunkowe(wierzcholki,macierz);
    wierzcholekizolowany(wierzcholki,macierz);
    sadziedzi(wierzcholki,macierz);
    stopien(wierzcholki,macierz);
    sasiedzikazdego(wierzcholki,macierz);

    //wypisanie macierzy
    for(int i =0; i < wierzcholki; i++){
        cout << setw ( 3 ) << i;
        for( int j = 0; j < wierzcholki; j++ ) cout << setw ( 3 ) << ( int ) macierz [ i ][ j ];
        cout << endl;
    }
    //zwolnienie pamieci
    for(int i = 0; i < wierzcholki; i++){
        delete [] macierz[i];
    }
    delete [] macierz;
    return 0;
}
