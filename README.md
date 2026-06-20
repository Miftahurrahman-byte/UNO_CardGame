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

void isiASCII(string n, string ascii[])
{
    if (n == "0")
    {
        ascii[0] = "  #######  "; ascii[1] = " ##     ## "; ascii[2] = " ##     ## "; ascii[3] = " ##     ## "; ascii[4] = " ##     ## "; ascii[5] = " ##     ## "; ascii[6] = "  #######  ";
    }
    else if (n == "1")
    {
        ascii[0] = "     ##    "; ascii[1] = "    ###    "; ascii[2] = "   ####    "; ascii[3] = "     ##    "; ascii[4] = "     ##    "; ascii[5] = "     ##    "; ascii[6] = "   ######  ";
    }
    else if (n == "2")
    {
        ascii[0] = "  #######  "; ascii[1] = "        ## "; ascii[2] = "        ## "; ascii[3] = "  #######  "; ascii[4] = "  ##       "; ascii[5] = "  ##       "; ascii[6] = "  #######  ";
    }
    else if (n == "3")
    {
        ascii[0] = "  #######  "; ascii[1] = "        ## "; ascii[2] = "        ## "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
    else if (n == "4")
    {
        ascii[0] = "  ##   ##  "; ascii[1] = "  ##   ##  "; ascii[2] = "  ##   ##  "; ascii[3] = "  #######  "; ascii[4] = "       ##  "; ascii[5] = "       ##  "; ascii[6] = "       ##  ";
    }
    else if (n == "5")
    {
        ascii[0] = "  #######  "; ascii[1] = "  ##       "; ascii[2] = "  ##       "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
    else if (n == "6")
    {
        ascii[0] = "  #######  "; ascii[1] = "  ##       "; ascii[2] = "  ##       "; ascii[3] = "  #######  "; ascii[4] = "  ##   ##  "; ascii[5] = "  ##   ##  "; ascii[6] = "  #######  ";
    }
    else if (n == "7")
    {
        ascii[0] = "###########"; ascii[1] = "         ##"; ascii[2] = "        ## "; ascii[3] = "       ##  "; ascii[4] = "      ##   "; ascii[5] = "     ##    "; ascii[6] = "    ##     ";
    }
    else if (n == "8")
    {
        ascii[0] = "   #####   "; ascii[1] = "  ##   ##  "; ascii[2] = "  ##   ##  "; ascii[3] = "   #####   "; ascii[4] = "  ##   ##  "; ascii[5] = "  ##   ##  "; ascii[6] = "   #####   ";
    }
    else if (n == "9")
    {
        ascii[0] = "  #######  "; ascii[1] = " ##     ## "; ascii[2] = " ##     ## "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
    else if (n == "Skip")
    {
        ascii[0] = "  #######  "; ascii[1] = " ##    /## "; ascii[2] = " ##   / ## "; ascii[3] = " ##  /  ## "; ascii[4] = " ## /   ## "; ascii[5] = " ##/    ## "; ascii[6] = "  #######  ";
    }
    else if (n == "Reverse")
    {
        ascii[0] = " #######   "; ascii[1] = " ##    ##  "; ascii[2] = " ##    ##  "; ascii[3] = " #######   "; ascii[4] = " ##  ##    "; ascii[5] = " ##   ##   "; ascii[6] = " ##    ##  ";
    }
    else if (n == "Draw Two")
    {
        ascii[0] = "           "; ascii[1] = "  #   #### "; ascii[2] = " ###     # "; ascii[3] = "  #   #### "; ascii[4] = "      #    "; ascii[5] = "      #### "; ascii[6] = "           ";
    }
    else if (n == "Wild Draw4")
    {
        ascii[0] = "           "; ascii[1] = "  #   #  # "; ascii[2] = " ###  #  # "; ascii[3] = "  #   #### "; ascii[4] = "         # "; ascii[5] = "         # "; ascii[6] = "           ";
    }
    else if (n == "Wild")
    {
        ascii[0] = " #        # "; ascii[1] = " #        # "; ascii[2] = " #    #   # "; ascii[3] = " #   ###  # "; ascii[4] = " # ## ## # "; ascii[5] = " ###   ### "; ascii[6] = " #        # ";
    }
    else
    {
        for (int i = 0; i < 7; i++)
            ascii[i] = "           ";
    }
}

void cetakKartuMeja(string w, string n)
{
    string kode = getWarnaKode(w);
    string ascii[7];
    isiASCII(n, ascii);

    cout << "++=============++\n";
    cout << "||              ||\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "|| " << kode << ascii[i] << "\033[0m ||\n";
    }
    cout << "||              ||\n";
    cout << "++=============++\n";
}

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
    
    .
    .
}

