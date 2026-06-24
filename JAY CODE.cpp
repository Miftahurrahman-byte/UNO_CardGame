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