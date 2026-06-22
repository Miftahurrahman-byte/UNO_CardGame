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