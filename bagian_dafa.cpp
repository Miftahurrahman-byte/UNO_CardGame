while (sisapemain > 1)
    {
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

        if (daftarpemain[giliran].sisakartu == 1)
        {
            cout << "\n\033[1;31m====================================\n";
            cout << "        " << daftarpemain[giliran].namapemain << " Berkata: UNO!!!\n";
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
    cout << "              GAME OVER                  \n";
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