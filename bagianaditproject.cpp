uno ambilkartu()
{
    if (sisakartuambil == 0)
    {
        cout << "\n[SISTEM] Dek habis! Mengambil dari tumpukan buang.\n";
        uno kartuTeratas = kartuyangdibuang[jumlahkartubuang - 1];

        for (int i = 0; i < jumlahkartubuang - 1; i++)
        {
            text_kosong[i] = kartuyangdibuang[i];
        }
        sisakartuambil = jumlahkartubuang - 1;

        kartuyangdibuang[0] = kartuTeratas;
        jumlahkartubuang = 1;

        for (int i = 0; i < sisakartuambil; i++)
        {
            int acak = rand() % sisakartuambil;
            uno temp = kartuambil[i];
            kartuambil[i] = kartuambil[acak];
            kartuambil[acak] = temp;
        }
    }
    sisakartuambil--;
    return kartuambil[sisakartuambil];
}