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
}