# UNO_CardGame
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> 
using namespace std;

struct uno {
    string warna; // Red, Yellow, Green, Blue, Wild
    string angka; // 0-9, Skip, Reverse, Draw Two, Wild, Wild Draw Four
};

struct pemain {
    string namapemain;
    uno kartuditangan[100];
    int sisakartu;
    bool aktif;
};

uno kartuambil[108];
int sisakartuambil = 0;

uno kartuyangdibuang[108];
int jumlahkartubuang = 0;

pemain daftarpemain[10];
int totalpemain = 0;

void dekkartu() {
    string daftarwarna[] = {"Red", "Yellow", "Green", "Blue"};
    string daftarangka[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw Two"};
    
    sisakartuambil = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            // Kartu pertama
            kartuambil[sisakartuambil].warna = daftarwarna[i];
            kartuambil[sisakartuambil].angka = daftarangka[j];
            sisakartuambil++;

            // Kartu kedua (kecuali angka 0)
            if (j != 0) {
                kartuambil[sisakartuambil].warna = daftarwarna[i];
                kartuambil[sisakartuambil].angka = daftarangka[j];
                sisakartuambil++;
            }
        }
    }

    // Masukkan kartu Wild
    for (int i = 0; i < 4; i++) {
        kartuambil[sisakartuambil].warna = "Wild";
        kartuambil[sisakartuambil].angka = "Wild";
        sisakartuambil++;

        kartuambil[sisakartuambil].warna = "Wild";
        kartuambil[sisakartuambil].angka = "Wild Draw4";
        sisakartuambil++;
    }

    // Mengocok dek dengan fungsi swap standar
    for (int i = 0; i < sisakartuambil; i++) {
        int acak = rand() % sisakartuambil;
        uno temp = kartuambil[i];
        kartuambil[i] = kartuambil[acak];
        kartuambil[acak] = temp;
    }
}

// Mengambil kartu dari dek
uno ambilkartu() {
    // Jika dek habis, isi ulang dari tumpukan buang
    if (sisakartuambil == 0) {
        cout << "\n[SISTEM] Dek habis! Mengambil dari tumpukan buang.\n";
        uno kartuTeratas = kartuyangdibuang[jumlahkartubuang - 1];
        
        // Pindahkan semua kecuali yang teratas
        for (int i = 0; i < jumlahkartubuang - 1; i++) {
            kartuambil[i] = kartuyangdibuang[i];
        }
        sisakartuambil = jumlahkartubuang - 1;
        
        // Sisakan 1 di tumpukan buang
        kartuyangdibuang[0] = kartuTeratas;
        jumlahkartubuang = 1;

        // Kocok ulang dek baru
        for (int i = 0; i < sisakartuambil; i++) {
            int acak = rand() % sisakartuambil;
            uno temp = kartuambil[i];
            kartuambil[i] = kartuambil[acak];
            kartuambil[acak] = temp;
        }
    }

    sisakartuambil--;
    return kartuambil[sisakartuambil];
}
