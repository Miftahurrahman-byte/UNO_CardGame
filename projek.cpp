 int pilih; 
        cout << "\nPilih nomor kartu yang ingin diletakkan: "; 
        cin >> pilih; 
 
        if (pilih < 1 || pilih > daftarpemain[giliran].sisakartu + 1) { 
            cout << "Pilihan salah! Anda otomatis mengambil kartu.\n"; 
            pilih = daftarpemain[giliran].sisakartu + 1; 
            system("pause"); 
        } 
 
        bool skip = false; 
 
        // PILIHAN 1: Ambil kartu dari dek 
        if (pilih == daftarpemain[giliran].sisakartu + 1) { 
            uno kartuBaru = ambilkartu(); 
            cout << "\nAnda mengambil kartu: [" << kartuBaru.warna << " " 
<< kartuBaru.angka << "]\n"; 
             
            if (kartuBaru.warna == warnasekarang || kartuBaru.angka == 
angkasekarang || kartuBaru.warna == "Wild") { 
                char mainkan; 
                cout << "Kartu cocok! Langsung mainkan? (y/n): "; 
                cin >> mainkan; 
                 
                if (mainkan == 'y' || mainkan == 'Y') { 
                    
daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = 
kartuBaru; 
                    daftarpemain[giliran].sisakartu++; 
                    pilih = daftarpemain[giliran].sisakartu; 
                } else { 
                    
daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = 
kartuBaru; 
                    daftarpemain[giliran].sisakartu++; 
                    skip = true; 
                } 
            } else { 
                
daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = 
kartuBaru; 
                daftarpemain[giliran].sisakartu++; 
                cout << "Kartu tidak cocok. Giliran dilewati.\n"; 
                system("pause"); 
                skip = true; 
            } 
        } 
 
        // PILIHAN 2: Validasi kecocokan lempar kartu 
        if (!skip) { 
            uno kartudipilih = daftarpemain[giliran].kartuditangan[pilih - 1]; 
 
            if (kartudipilih.warna != warnasekarang && kartudipilih.angka 
!= angkasekarang && kartudipilih.warna != "Wild") { 
                cout << "\n[KARTU TIDAK COCOK!] Anda mengambil 1 kartu 
penalti.\n"; 
                
daftarpemain[giliran].kartuditangan[daftarpemain[giliran].sisakartu] = 
ambilkartu(); 
                daftarpemain[giliran].sisakartu++; 
                system("pause"); 
            }  
            else { 
                hapuskartu(giliran, pilih - 1); 
                kartuyangdibuang[jumlahkartubuang] = kartudipilih; 
                jumlahkartubuang++; 
                 
                warnasekarang = kartudipilih.warna; 
                angkasekarang = kartudipilih.angka;
