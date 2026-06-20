while (sisapemain > 1)
    {
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

