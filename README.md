# 🃏 UNO_CardGame

## *Console-Based UNO Card Game*

**EST. 2026** — *Bring People Together, One Card at a Time*

---

![Language](https://img.shields.io/badge/LANGUAGE-C%2B%2B-blue) ![Status](https://img.shields.io/badge/STATUS-DEVELOPMENT-orange)
![Version](https://img.shields.io/badge/VERSION-1.0.0-cyan) ![Team](https://img.shields.io/badge/TEAM-KELOMPOK_8-red)

> "Mainkan game kartu legendaris UNO langsung dari terminal komputer kamu — kocok kartu, atur strategi, dan jangan lupa teriak UNO sebelum kartu terakhirmu habis!"

---

## 📌 Daftar Isi

* [Tentang Project](#tentang-project)
* [Fitur Unggulan](#fitur-unggulan)
* [Alur Sistem](#alur-sistem)
* [Struktur Menu](#struktur-menu)
* [Cara Menjalankan](#cara-menjalankan)
* [Tim Pengembang](#tim-pengembang)

---

## 🎮 Tentang Project

**UNO_CardGame** adalah permainan kartu UNO berbasis *command-line interface* (CLI) yang dibangun menggunakan bahasa C++. Proyek ini dibuat oleh **Kelompok 8** untuk mensimulasikan keseruan bermain kartu UNO secara digital dengan pembagian deck, pengocokan kartu otomatis (*shuffling*), dan giliran antar pemain yang terstruktur.

---

## ✨ Fitur Unggulan

* **Modul Dek & Shuffle:** Pengocokan kartu secara acak yang adil menggunakan algoritma pemrograman (terdapat di file `Shuffle Dek.cpp`).
* **Multiplayer System:** Mendukung giliran bermain untuk beberapa pemain sekaligus.
* **Aturan UNO Otentik:** Sistem membaca warna kartu (Red, Yellow, Green, Blue, Wild) dan angka/efek kartu (0-9, Skip, Reverse, Draw Two, Wild, Wild Draw Four).

---

## 🛠️ Cara Menjalankan

1. Clone repository ini ke komputer kamu.
2. Pastikan kamu memiliki compiler C++ (seperti `g++`).
3. Compile program utama dengan perintah:
```bash
   g++ "Shuffle Dek.cpp" -o UnoGame

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

struct uno
{
    string warna;
    string angka;
};

struct pemain
{
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

// ==========================================
// FUNGSI BANTUAN UNTUK GRAFIS KARTU ASCII
// ==========================================
string getWarnaKode(string w)
{
    if (w == "Red")
        return "\033[1;31m";
    if (w == "Green")
        return "\033[1;32m";
    if (w == "Yellow")
        return "\033[1;33m";
    if (w == "Blue")
        return "\033[1;34m";
    if (w == "Wild")
        return "\033[1;35m";
    return "\033[0m";
}

// Data bentuk angka (Lebar pasti 11 karakter)
void isiASCII(string n, string ascii[])
{
    if (n == "0")
    {
        ascii[0] = "  #######  ";
        ascii[1] = " ##     ## ";
        ascii[2] = " ##     ## ";
        ascii[3] = " ##     ## ";
        ascii[4] = " ##     ## ";
        ascii[5] = " ##     ## ";
        ascii[6] = "  #######  ";
    }
    else if (n == "1")
    {
        ascii[0] = "     ##    ";
        ascii[1] = "    ###    ";
        ascii[2] = "   ####    ";
        ascii[3] = "     ##    ";
        ascii[4] = "     ##    ";
        ascii[5] = "     ##    ";
        ascii[6] = "   ######  ";
    }
    else if (n == "2")
    {
        ascii[0] = "  #######  ";
        ascii[1] = "        ## ";
        ascii[2] = "        ## ";
        ascii[3] = "  #######  ";
        ascii[4] = "  ##       ";
        ascii[5] = "  ##       ";
        ascii[6] = "  #######  ";
    }
    else if (n == "3")
    {
        ascii[0] = "  #######  ";
        ascii[1] = "        ## ";
        ascii[2] = "        ## ";
        ascii[3] = "  #######  ";
        ascii[4] = "        ## ";
        ascii[5] = "        ## ";
        ascii[6] = "  #######  ";
    }
    else if (n == "4")
    {
        ascii[0] = "  ##   ##  ";
        ascii[1] = "  ##   ##  ";
        ascii[2] = "  ##   ##  ";
        ascii[3] = "  #######  ";
        ascii[4] = "       ##  ";
        ascii[5] = "       ##  ";
        ascii[6] = "       ##  ";
    }
    else if (n == "5")
    {
        ascii[0] = "  #######  ";
        ascii[1] = "  ##       ";
        ascii[2] = "  ##       ";
        ascii[3] = "  #######  ";
        ascii[4] = "        ## ";
        ascii[5] = "        ## ";
        ascii[6] = "  #######  ";
    }
    else if (n == "6")
    {
        ascii[0] = "  #######  ";
        ascii[1] = "  ##       ";
        ascii[2] = "  ##       ";
        ascii[3] = "  #######  ";
        ascii[4] = "  ##   ##  ";
        ascii[5] = "  ##   ##  ";
        ascii[6] = "  #######  ";
    }
    else if (n == "7")
    {
        ascii[0] = "###########";
        ascii[1] = "         ##";
        ascii[2] = "        ## ";
        ascii[3] = "       ##  ";
        ascii[4] = "      ##   ";
        ascii[5] = "     ##    ";
        ascii[6] = "    ##     ";
    }
    else if (n == "8")
    {
        ascii[0] = "   #####   ";
        ascii[1] = "  ##   ##  ";
        ascii[2] = "  ##   ##  ";
        ascii[3] = "   #####   ";
        ascii[4] = "  ##   ##  ";
        ascii[5] = "  ##   ##  ";
        ascii[6] = "   #####   ";
    }
    else if (n == "9")
    {
        ascii[0] = "  #######  ";
        ascii[1] = " ##     ## ";
        ascii[2] = " ##     ## ";
        ascii[3] = "  #######  ";
        ascii[4] = "        ## ";
        ascii[5] = "        ## ";
        ascii[6] = "  #######  ";
    }
    else if (n == "Skip")
    {
        // REVISI: Tampilan Skip baru menyerupai lingkaran/kotak yang dicoret diagonal
        ascii[0] = "  #######  ";
        ascii[1] = " ##    /## ";
        ascii[2] = " ##   / ## ";
        ascii[3] = " ##  /  ## ";
        ascii[4] = " ## /   ## ";
        ascii[5] = " ##/    ## ";
        ascii[6] = "  #######  ";
    }
    else if (n == "Reverse")
    {
        ascii[0] = " #######   ";
        ascii[1] = " ##    ##  ";
        ascii[2] = " ##    ##  ";
        ascii[3] = " #######   ";
        ascii[4] = " ##  ##    ";
        ascii[5] = " ##   ##   ";
        ascii[6] = " ##    ##  ";
    }
    else if (n == "Draw Two")
    {
        ascii[0] = "           ";
        ascii[1] = "  #   #### ";
        ascii[2] = " ###     # ";
        ascii[3] = "  #   #### ";
        ascii[4] = "      #    ";
        ascii[5] = "      #### ";
        ascii[6] = "           ";
    }
    else if (n == "Wild Draw4")
    {
        ascii[0] = "           ";
        ascii[1] = "  #   #  # ";
        ascii[2] = " ###  #  # ";
        ascii[3] = "  #   #### ";
        ascii[4] = "         # ";
        ascii[5] = "         # ";
        ascii[6] = "           ";
    }
    else if (n == "Wild")
    {
        ascii[0] = " #       # ";
        ascii[1] = " #       # ";
        ascii[2] = " #   #   # ";
        ascii[3] = " #  ###  # ";
        ascii[4] = " # ## ## # ";
        ascii[5] = " ###   ### ";
        ascii[6] = " #       # ";
    }
    else
    {
        for (int i = 0; i < 7; i++)
            ascii[i] = "           ";
    }
}

// Menampilkan kartu di meja
void cetakKartuMeja(string w, string n)
{
    string kode = getWarnaKode(w);
    string ascii[7];
    isiASCII(n, ascii);

    cout << "++=============++\n";
    cout << "||             ||\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "|| " << kode << ascii[i] << "\033[0m ||\n";
    }
    cout << "||             ||\n";
    cout << "++=============++\n";
}

// ==========================================
// GAME LOGIC BAWAAN
// ==========================================
void dekkartu()
{
    string daftarwarna[] = {"Red", "Yellow", "Green", "Blue"};
    string daftarangka[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw Two"};

    sisakartuambil = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            kartuambil[sisakartuambil].warna = daftarwarna[i];
            kartuambil[sisakartuambil].angka = daftarangka[j];
            sisakartuambil++;

            if (j != 0)
            {
                kartuambil[sisakartuambil].warna = daftarwarna[i];
                kartuambil[sisakartuambil].angka = daftarangka[j];
                sisakartuambil++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        kartuambil[sisakartuambil].warna = "Wild";
        kartuambil[sisakartuambil].angka = "Wild";
        sisakartuambil++;

        kartuambil[sisakartuambil].warna = "Wild";
        kartuambil[sisakartuambil].angka = "Wild Draw4";
        sisakartuambil++;
    }

    for (int i = 0; i < sisakartuambil; i++)
    {
        int acak = rand() % sisakartuambil;
        uno temp = kartuambil[i];
        kartuambil[i] = kartuambil[acak];
        kartuambil[acak] = temp;
    }
}

uno ambilkartu()
{
    if (sisakartuambil == 0)
    {
        cout << "\n[SISTEM] Dek habis! Mengambil dari tumpukan buang.\n";
        uno kartuTeratas = kartuyangdibuang[jumlahkartubuang - 1];

        for (int i = 0; i < jumlahkartubuang - 1; i++)
        {
            kartuambil[i] = kartuyangdibuang[i];
        }
        sisakartuambil = jumlahkartubuang - 1;

        kartuyangdibuang[0] = kartuTeratas;
        jumlahkartubuang = 1;

        for (int i = 0; i < sisakartuambil; i++)
        {
            int acak = rand() % sisakartuambil;
            uno temp = kartuambil[i];
            kartuambil[i] = kartuambil[acak];
            kartuambil[acak] = temp;
        }
    }
    sisakartuambil--;
    return kartuambil[sisakartuambil];
}

// Menampilkan kartu di tangan (MENGGUNAKAN POINTER PEMAIN)
void ditangan(pemain *p)
{
    cout << "Kartu di tangan Anda:\n";
    int sisa = p->sisakartu;
    int maxPerBaris = 5;

    for (int start = 0; start < sisa; start += maxPerBaris)
    {
        int end = min(start + maxPerBaris, sisa);

        // 1. Bagian Penomoran Kartu
        for (int i = start; i < end; i++)
        {
            if (i + 1 < 10)
                cout << "  " << i + 1 << ".              ";
            else
                cout << " " << i + 1 << ".              ";
        }
        cout << "\n";

        // 2. Garis Atas
        for (int i = start; i < end; i++)
        {
            cout << "++=============++  ";
        }
        cout << "\n";

        // 3. Margin Kosong Atas
        for (int i = start; i < end; i++)
        {
            cout << "||             ||  ";
        }
        cout << "\n";

        // 4. Body Kartu (Tengah)
        for (int baris = 0; baris < 7; baris++)
        {
            for (int i = start; i < end; i++)
            {
                string w = p->kartuditangan[i].warna;
                string n = p->kartuditangan[i].angka;
                string kode = getWarnaKode(w);
                string ascii[7];
                isiASCII(n, ascii);

                cout << "|| " << kode << ascii[baris] << "\033[0m ||  ";
            }
            cout << "\n";
        }

        // 5. Margin Kosong Bawah
        for (int i = start; i < end; i++)
        {
            cout << "||             ||  ";
        }
        cout << "\n";

        // 6. Garis Bawah
        for (int i = start; i < end; i++)
        {
            cout << "++=============++  ";
        }
        cout << "\n\n";
    }

    cout << sisa + 1 << ". [ AMBIL KARTU BARU DARI DEK ]\n";
}

// Menghapus kartu dari tangan array (MENGGUNAKAN POINTER PEMAIN)
void hapuskartu(pemain *p, int indeksKartu)
{
    for (int i = indeksKartu; i < p->sisakartu - 1; i++)
    {
        p->kartuditangan[i] = p->kartuditangan[i + 1];
    }
    p->sisakartu--;
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    srand(time(0));

    cout << "\033[1;36m";
    cout << "=========================================\n";
    cout << "        SELAMAT DATANG DI GAME UNO C++     \n";
    cout << "=========================================\n";
    cout << "\033[0m";

    cout << "Masukkan jumlah pemain (2-10): ";
    cin >> totalpemain;

    while (totalpemain < 2 || totalpemain > 10 || cin.fail())
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Tidak valid. Masukkan lagi (2-10): ";
        cin >> totalpemain;
    }

    for (int i = 0; i < totalpemain; i++)
    {
        cout << "Masukkan nama Pemain " << i + 1 << ": ";
        cin >> daftarpemain[i].namapemain;
        daftarpemain[i].sisakartu = 0;
        daftarpemain[i].aktif = true;
    }

    dekkartu();

    for (int i = 0; i < totalpemain; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            daftarpemain[i].kartuditangan[daftarpemain[i].sisakartu] = ambilkartu();
            daftarpemain[i].sisakartu++;
        }
    }

    uno kartuawal = ambilkartu();
    while (kartuawal.warna == "Wild")
    {
        kartuambil[sisakartuambil] = kartuawal;
        sisakartuambil++;
        kartuawal = ambilkartu();
    }
    kartuyangdibuang[jumlahkartubuang] = kartuawal;
    jumlahkartubuang++;

    string warnasekarang = kartuawal.warna;
    string angkasekarang = kartuawal.angka;

    int giliran = 0;
    bool arahmain = true;
    int sisapemain = totalpemain;

    while (sisapemain > 1)
    {
        // Membersihkan layar terminal secara cross-platform
        cout << "\033[2J\033[1;1H";

        cout << "=========================================\n";
        cout << "STATUS MEJA SAAT INI:\n";
        cetakKartuMeja(warnasekarang, angkasekarang);
        cout << "Warna Main   : \033[1m" << getWarnaKode(warnasekarang) << warnasekarang << "\033[0m\n";
        cout << "Arah Putaran : " << (arahmain ? "Searah Jarum Jam ->" : "<- Berlawanan Jarum Jam") << "\n";
        cout << "Sisa pemain aktif: " << sisapemain << "\n";
        cout << "=========================================\n";
        cout << "\nGILIRAN SEKARANG: \033[1;32m" << daftarpemain[giliran].namapemain << "\033[0m\n\n";

        ditangan(&daftarpemain[giliran]);

        int pilih;
        cout << "\nPilih nomor kartu yang ingin diletakkan: ";
        cin >> pilih;

        while (true)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Pilihan Tidak Valid, Pilih ulang: ";
                cin >> pilih;
            }
            else
            {
                break;
            }
        }

        if (pilih < 1 || pilih > daftarpemain[giliran].sisakartu + 1)
        {
            cout << "Pilihan salah! Anda otomatis mengambil kartu.\n";
            pilih = daftarpemain[giliran].sisakartu + 1;
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

        bool skip = false;

        if (pilih == daftarpemain[giliran].sisakartu + 1)
        {
            uno kartuBaru = ambilkartu();
            cout << "\nAnda mendapat kartu:\n";
            cetakKartuMeja(kartuBaru.warna, kartuBaru.angka);

            if (kartuBaru.warna == warnasekarang || kartuBaru.angka == angkasekarang || kartuBaru.warna == "Wild")
            {
                char mainkan;
                cout << "Kartu cocok! Langsung mainkan? (y/n): ";
                cin >> mainkan;

                if (mainkan == 'y' || mainkan == 'Y')
                {
                    daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = kartuBaru;
                    daftarpemain[giliran].sisakartu++;
                    pilih = daftarpemain[giliran].sisakartu;
                }
                else
                {
                    daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = kartuBaru;
                    daftarpemain[giliran].sisakartu++;
                    skip = true;
                }
            }
            else
            {
                daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = kartuBaru;
                daftarpemain[giliran].sisakartu++;
                cout << "Kartu tidak cocok. Giliran dilewati.\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                skip = true;
            }
        }

        if (!skip)
        {
            uno kartudipilih = daftarpemain[giliran].kartuditangan[pilih - 1];

            if (kartudipilih.warna != warnasekarang && kartudipilih.angka != angkasekarang && kartudipilih.warna != "Wild")
            {
                cout << "\n[KARTU TIDAK COCOK!] Anda otomatis mengambil 1 kartu penalti.\n";
                daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = ambilkartu();
                daftarpemain[giliran].sisakartu++;
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            }
            else
            {
                hapuskartu(&daftarpemain[giliran], pilih - 1);
                kartuyangdibuang[jumlahkartubuang] = kartudipilih;
                jumlahkartubuang++;

                warnasekarang = kartudipilih.warna;
                angkasekarang = kartudipilih.angka;

                if (kartudipilih.angka == "Skip")
                {
                    int target_skip = giliran;
                    do
                    {
                        if (arahmain)
                            target_skip = (target_skip + 1) % totalpemain;
                        else
                            target_skip = (target_skip - 1 + totalpemain) % totalpemain;
                    } while (!daftarpemain[target_skip].aktif);

                    cout << "\nPemain [" << daftarpemain[target_skip].namapemain << "] Kena SKIP!\n";
                    giliran = target_skip;
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
                else if (kartudipilih.angka == "Reverse")
                {
                    arahmain = !arahmain;
                    cout << "\nArah permainan DIBALIK!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
                else if (kartudipilih.angka == "Draw Two")
                {
                    int target = giliran;
                    do
                    {
                        if (arahmain)
                            target = (target + 1) % totalpemain;
                        else
                            target = (target - 1 + totalpemain) % totalpemain;
                    } while (!daftarpemain[target].aktif);

                    daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = ambilkartu();
                    daftarpemain[target].sisakartu++;
                    daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = ambilkartu();
                    daftarpemain[target].sisakartu++;

                    cout << "\n"
                         << daftarpemain[target].namapemain << " Kena +2 dan gilirannya dilewati!\n";
                    giliran = target;
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
                else if (kartudipilih.warna == "Wild")
                {
                    int warnaBaru = 0;
                    while (warnaBaru < 1 || warnaBaru > 4 || cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nPilih warna baru:\n1. Red\n2. Yellow\n3. Green\n4. Blue\nPilihan (1-4): ";
                        cin >> warnaBaru;
                    }

                    if (warnaBaru == 1)
                        warnasekarang = "Red";
                    else if (warnaBaru == 2)
                        warnasekarang = "Yellow";
                    else if (warnaBaru == 3)
                        warnasekarang = "Green";
                    else
                        warnasekarang = "Blue";

                    if (kartudipilih.angka == "Wild Draw4")
                    {
                        int target = giliran;
                        do
                        {
                            if (arahmain)
                                target = (target + 1) % totalpemain;
                            else
                                target = (target - 1 + totalpemain) % totalpemain;
                        } while (!daftarpemain[target].aktif);

                        for (int k = 0; k < 4; k++)
                        {
                            daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = ambilkartu();
                            daftarpemain[target].sisakartu++;
                        }
                        cout << "\n"
                             << daftarpemain[target].namapemain << " Kena +4 dan gilirannya dilewati!\n";
                        giliran = target;
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                    }
                }
            }
        }

        if (daftarpemain[giliran].sisakartu == 1)
        {
            cout << "\n\033[1;31m====================================\n";
            cout << "       " << daftarpemain[giliran].namapemain << " Berkata: UNO!!!\n";
            cout << "====================================\033[0m\n";
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

        if (daftarpemain[giliran].sisakartu == 0)
        {
            cout << "\n\033[1;32mSelamat! " << daftarpemain[giliran].namapemain << " MENANG dan SELESAI!\033[0m\n";
            daftarpemain[giliran].aktif = false;
            sisapemain--;
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

        do
        {
            if (arahmain)
            {
                giliran = (giliran + 1) % totalpemain;
            }
            else
            {
                giliran = (giliran - 1 + totalpemain) % totalpemain;
            }
        } while (!daftarpemain[giliran].aktif);
    }

    cout << "\n=========================================\n";
    cout << "             GAME OVER                   \n";
    cout << "=========================================\n";
    for (int i = 0; i < totalpemain; i++)
    {
        if (daftarpemain[i].aktif)
        {
            cout << "Pemain yang kalah (Terakhir bertahan): " << daftarpemain[i].namapemain << "\n";
        }
    }

    return 0;
}
