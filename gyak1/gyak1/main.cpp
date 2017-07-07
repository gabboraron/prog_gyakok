//1. gyakorlat
//Feladat: adott n darab egész szám, válogassuk ki a k-val oszthatókat.
//Bemenet:
//   1. mód: billentyűzet (előbb a darabszám, utána a számok)
//   2. mód: billentyűzet  (amíg egy "nem szám"-ot ütünk)
//   3. mód: fájlból (előbb a darabszám, utána a számok)
//   4. mód: fájlból (fájl végéig)
//Kimenet: az eredmény is egy tömbbe kerüljön.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void beolvasf1(vector<int>&); //fájlból, darabszám szerint
void beolvasf2(vector<int>&); //fájlból fájlvégéig
void beolvasb1(vector<int>&);   //billentyűzetről darabszám szerint
void beolvasb2(vector<int>&);   //billentyűzetről, amíg egy "nem szám" érkezik
void kiir(const vector<int>&);
int menu();
int read_int(const string &msg);


int main()
{
    char c;
    vector<int> x; //Bemenõ adatok tömbje
    vector<int> y; //Kimenet tömb
    do{            //Itt kezdődik az újrafuttatás ciklusa
// Beolvasások
        x.clear();
        int mod=menu();
        switch (mod){
        case 1:
            beolvasb1(x);
            break;
        case 2:
            beolvasb2(x);
            break;
        case 3:
            beolvasf1(x);
            break;
        default:
            beolvasf2(x);
        }
        cout<<"A beolvasott adatok:"<<endl;
        kiir(x);
        cout<<endl;
// k beolvasása k <> 0!


// Kiválogatás


// Újra futtatás
        do{
            cout<<"Ujra(i/n):";
            cin>>c;
            c=tolower(c);
        }while(!(c=='i' || c=='n'));
    }while(c=='i');
    return 0;
}

//Billentyűzetről olvasunk darabszám szerint
void beolvasb1(vector<int>& a){

    return;
}

//Billentyűzetről, amíg egy "nem szám" bemenetet nem adunk
void beolvasb2(vector<int>& a){

    return;
}

//Fájl első adata a fájlban lévő egész számok száma, utána jönnek a számok
void beolvasf1(vector<int>& a){

    return;
}

//Fájl végéig olvas.
void beolvasf2(vector<int>& a){

    return;
}

void kiir(const vector<int>& a){
    for(unsigned i=0;i<a.size();i++) cout<<a[i]<<"  ";
    cout<<endl;
    return;
}


int menu(){
    int v;
    do{
        cout<<"\nMilyen modon olvassuk be az adatokat:\n";
        cout<<"1. Billentyuzetrol darabszam szerint\n";
        cout<<"2. Billentyuzetrol, amig szoveget nem adunk szam helyett\n";
        cout<<"3. Fajlbol, fajl elso adata a darabszam\n";
        cout<<"4. Fajlbol, fajl vegeig\n";
        v=read_int("valassz:");
    }while(v<1 || v>4);
    return v;
}

int read_int(const string &msg)
{
    int n;
    bool hiba;
    do{
        cout << msg;
        cin >> n;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0;
        if(hiba) cout << "Hibas input: Egesz szamot varok!\n";
    }while(hiba);

    return n;
}

