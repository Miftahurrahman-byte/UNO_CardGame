uno ambilkartu()
{
    if (sisakartuambil == 0)
    {
        cout << "\n[SISTEM] Dek habis! Mengambil dari tumpukan buang.\n";
        uno kartuTeratas = kartuyangdibuang[jumlahkartubuang - 1];

        for (int i = 0; i < jumlahkartubuang - 1; i++)
        {
            kartuambil[i] = kartuyangdibuang[i];
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

string getWarnaKode(string w)
{
    if (w == "Red")
        return "\033[1;31m";
    if (w == "Green")
        return "\033[1;32m";
    if (w == "Yellow")
        return "\033[1;33m";
    if (w == "Blue")
        return "\033[1;34m";
    if (w == "Wild")
        return "\033[1;35m";
    return "\033[0m";
}

void isiASCII(string n, string ascii[])
{
    if (n == "0")
    {
        ascii[0] = "  #######  "; ascii[1] = " ##     ## "; ascii[2] = " ##     ## "; ascii[3] = " ##     ## "; ascii[4] = " ##     ## "; ascii[5] = " ##     ## "; ascii[6] = "  #######  ";
    }
    else if (n == "1")
    {
        ascii[0] = "     ##    "; ascii[1] = "    ###    "; ascii[2] = "   ####    "; ascii[3] = "     ##    "; ascii[4] = "     ##    "; ascii[5] = "     ##    "; ascii[6] = "   ######  ";
    }
    else if (n == "2")
    {
        ascii[0] = "  #######  "; ascii[1] = "        ## "; ascii[2] = "        ## "; ascii[3] = "  #######  "; ascii[4] = "  ##       "; ascii[5] = "  ##       "; ascii[6] = "  #######  ";
    }
    else if (n == "3")
    {
        ascii[0] = "  #######  "; ascii[1] = "        ## "; ascii[2] = "        ## "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
    else if (n == "4")
    {
        ascii[0] = "  ##   ##  "; ascii[1] = "  ##   ##  "; ascii[2] = "  ##   ##  "; ascii[3] = "  #######  "; ascii[4] = "       ##  "; ascii[5] = "       ##  "; ascii[6] = "       ##  ";
    }
    else if (n == "5")
    {
        ascii[0] = "  #######  "; ascii[1] = "  ##       "; ascii[2] = "  ##       "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
    else if (n == "6")
    {
        ascii[0] = "  #######  "; ascii[1] = "  ##       "; ascii[2] = "  ##       "; ascii[3] = "  #######  "; ascii[4] = "  ##   ##  "; ascii[5] = "  ##   ##  "; ascii[6] = "  #######  ";
    }
    else if (n == "7")
    {
        ascii[0] = "###########"; ascii[1] = "         ##"; ascii[2] = "        ## "; ascii[3] = "       ##  "; ascii[4] = "      ##   "; ascii[5] = "     ##    "; ascii[6] = "    ##     ";
    }
    else if (n == "8")
    {
        ascii[0] = "   #####   "; ascii[1] = "  ##   ##  "; ascii[2] = "  ##   ##  "; ascii[3] = "   #####   "; ascii[4] = "  ##   ##  "; ascii[5] = "  ##   ##  "; ascii[6] = "   #####   ";
    }
    else if (n == "9")
    {
        ascii[0] = "  #######  "; ascii[1] = " ##     ## "; ascii[2] = " ##     ## "; ascii[3] = "  #######  "; ascii[4] = "        ## "; ascii[5] = "        ## "; ascii[6] = "  #######  ";
    }
