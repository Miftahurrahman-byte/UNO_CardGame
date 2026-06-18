 // GAME LOOP UTAMA 
    while (sisapemain > 1) { 
        system("cls"); 
        cout << "=========================================\n"; 
        cout << "STATUS MEJA SAAT INI:\n"; 
        cout << "Kartu Teratas: [" << warnasekarang << " " << 
angkasekarang << "]\n"; 
        cout << "Arah Putaran : " << (arahmain ? "Searah Jarum Jam ->" : 
"<- Berlawanan Jarum Jam") << "\n"; 
        cout << "Sisa pemain aktif: " << sisapemain << "\n"; 
        cout << "=========================================\n"; 
        cout << "\nGILIRAN SEKARANG: " << 
daftarpemain[giliran].namapemain << "\n"; 
         
        ditangan(giliran); 
         
        // [... Di sini letak proses input dan eksekusi kartu oleh tim 
lain ...] 
 
        // Cek jika sisa kartu tinggal 1 (UNO) 
        if (daftarpemain[giliran].sisakartu == 1) { 
            cout << "\n====================================\n"; 
            cout << "        " << daftarpemain[giliran].namapemain << " 
Berkata: UNO!!!\n"; 
            cout << "====================================\n"; 
            system("pause"); 
        } 
 
        // Cek jika kartu habis (Selesai/Menang) 
        if (daftarpemain[giliran].sisakartu == 0) { 
            cout << "\n Selamat! " << daftarpemain[giliran].namapemain << 
" MENANG dan SELESAI!\n"; 
            daftarpemain[giliran].aktif = false; 
            sisapemain--; 
            system("pause"); 
        } 
 
        // Cari pemain berikutnya yang masih aktif untuk iterasi turn 
selanjutnya 
        do { 
            giliran = (arahmain) ? (giliran + 1) % totalpemain : (giliran - 1 + totalpemain) % totalpemain; 
        } while (!daftarpemain[giliran].aktif); 
    } 
 
    // GAME OVER OUTRO 
    cout << "\n=========================================\n"; 
    cout << "              GAME OVER                  \n"; 
    cout << "=========================================\n"; 
    for (int i = 0; i < totalpemain; i++) { 
        if (daftarpemain[i].aktif) { 
            cout << "Pemain yang kalah (Terakhir bertahan): " << 
daftarpemain[i].namapemain << "\n"; 
} 
} 
return 0; 
}