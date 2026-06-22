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
