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

void ditangan(pemain *p)
{
    cout << "Kartu di tangan Anda:\n";
    int sisa = p->sisakartu;
    int maxPerBaris = 5;

    for (int start = 0; start < sisa; start += maxPerBaris)
    {
        int end = min(start + maxPerBaris, sisa);

        for (int i = start; i < end; i++)
        {
            if (i + 1 < 10)
                cout << "  " << i + 1 << ".              ";
            else
                cout << " " << i + 1 << ".              ";
        }
        cout << "\n";

        for (int i = start; i < end; i++)
        {
            cout << "++=============++  ";
        }
        cout << "\n";

        for (int i = start; i < end; i++)
        {
            cout << "||             ||  ";
        }
        cout << "\n";

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

        for (int i = start; i < end; i++)
        {
            cout << "||             ||  ";
        }
        cout << "\n";

        for (int i = start; i < end; i++)
        {
            cout << "++=============++  ";
        }
        cout << "\n\n";
    }

    cout << sisa + 1 << ". [ AMBIL KARTU BARU DARI DEK ]\n";
}

void hapuskartu(pemain *p, int indeksKartu)
{
    for (int i = indeksKartu; i < p->sisakartu - 1; i++)
    {
        p->kartuditangan[i] = p->kartuditangan[i + 1];
    }
    p->sisakartu--;
}