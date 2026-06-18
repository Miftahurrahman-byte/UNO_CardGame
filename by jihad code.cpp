 if (kartudipilih.angka == "Skip") { 
                    int target_skip = giliran; 
                    do { 
                        target_skip = (arahmain) ? (target_skip + 1) % totalpemain : (target_skip - 1 + totalpemain) % totalpemain; 
                    } while (!daftarpemain[target_skip].aktif); 
                     
                    cout << "\nPemain [" << 
daftarpemain[target_skip].namapemain << "] Kena SKIP!\n"; 
                    giliran = target_skip;  
                    system("pause"); 
                }  
                else if (kartudipilih.angka == "Reverse") { 
                    arahmain = !arahmain; 
                    cout << "\nArah permainan DIBALIK!\n"; 
                    system("pause"); 
                }  
                else if (kartudipilih.angka == "Draw Two") { 
                    int target = giliran; 
                    do { 
                        target = (arahmain) ? (target + 1) % totalpemain 
: (target - 1 + totalpemain) % totalpemain; 
                    } while (!daftarpemain[target].aktif); 
 
                    
daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = 
ambilkartu(); daftarpemain[target].sisakartu++; 
                    
daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = 
ambilkartu(); daftarpemain[target].sisakartu++; 
                     
                    cout << "\n" << daftarpemain[target].namapemain << "Kena +2 dan gilirannya dilewati!\n"; 
                    giliran = target;  
                    system("pause"); 
                }  
                else if (kartudipilih.warna == "Wild") { 
                    int warnaBaru = 0; 
                    while (warnaBaru < 1 || warnaBaru > 4) { 
                        cout << "\nPilih warna baru:\n1. Red\n2. Yellow\n3. Green\n4. Blue\nPilihan (1-4): "; 
                        cin >> warnaBaru; 
                    } 
                     
                    if (warnaBaru == 1) warnasekarang = "Red"; 
                    else if (warnaBaru == 2) warnasekarang = "Yellow"; 
                    else if (warnaBaru == 3) warnasekarang = "Green"; 
                    else warnasekarang = "Blue"; 
 
                    if (kartudipilih.angka == "Wild Draw4") { 
                        int target = giliran; 
                        do { 
                            target = (arahmain) ? (target + 1) % 
totalpemain : (target - 1 + totalpemain) % totalpemain; 
                        } while (!daftarpemain[target].aktif); 
 
                        for (int k = 0; k < 4; k++) { 
                            
daftarpemain[target].kartuditangan[daftarpemain[target].sisakartu] = 
ambilkartu(); 
                            daftarpemain[target].sisakartu++; 
                        } 
                        cout << "\n" << daftarpemain[target].namapemain 
<< " Kena +4 dan gilirannya dilewati!\n"; 
                        giliran = target;  
                        system("pause"); 
                    } 
                } 
            } 
        }