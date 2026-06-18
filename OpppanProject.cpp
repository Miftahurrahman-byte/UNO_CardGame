void ditangan(int indeksPemain) {
    cout << "Kartu di tangan Anda:\n";
    for (int i = 0; i < daftarpemain[indeksPemain].sisakartu; i++) {
        cout << i + 1 << ". [" << daftarpemain[indeksPemain].kartuditangan[i].warna << " " 
             << daftarpemain[indeksPemain].kartuditangan[i].angka << "]\n";
    }
    cout << daftarpemain[indeksPemain].sisakartu + 1 << ". [Ambil Kartu dari Dek]\n";
}

// Menghapus kartu (Array Shifting standar)
void hapuskartu(int indeksPemain, int indeksKartu) {
    for (int i = indeksKartu; i < daftarpemain[indeksPemain].sisakartu - 1; i++) {
        daftarpemain[indeksPemain].kartuditangan[i] = daftarpemain[indeksPemain].kartuditangan[i + 1];
    }
    daftarpemain[indeksPemain].sisakartu--;
}