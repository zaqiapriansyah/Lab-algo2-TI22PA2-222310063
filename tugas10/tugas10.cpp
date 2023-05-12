#include <iostream>
#include <string>

using namespace std;

class Perpustakaan {
private:
    string buku;
    bool dipinjam;

public:
    Perpustakaan(string judul) {
        buku = judul;
        dipinjam = false;
    }

    string getBuku() {
        return buku;
    }

    bool isDipinjam() {
        return dipinjam;
    }

    void setDipinjam(bool status) {
        dipinjam = status;
    }
};

class Pelajar {
private:
    string nama;
    Perpustakaan* perpustakaan;

public:
    Pelajar(string name) {
        nama = name;
        perpustakaan = nullptr;
    }

    string getNama() {
        return nama;
    }

    void pinjamBuku(Perpustakaan* pustaka) {
        if (pustaka->isDipinjam()) {
            cout << "Maaf, buku sedang dipinjam." << endl;
        } else {
            perpustakaan = pustaka;
            perpustakaan->setDipinjam(true);
            cout << "Buku '" << perpustakaan->getBuku() << "' berhasil dipinjam oleh " << nama << "." << endl;
        }
    }

    void kembalikanBuku() {
        if (perpustakaan != nullptr) {
            perpustakaan->setDipinjam(false);
            cout << "Buku '" << perpustakaan->getBuku() << "' berhasil dikembalikan oleh " << nama << "." << endl;
            perpustakaan = nullptr;
        } else {
            cout << "Anda belum meminjam buku." << endl;
        }
    }
};

int main() {
    Perpustakaan buku1("Harry Potter");
    Perpustakaan buku2("Lord of the Rings");

    Pelajar pelajar1("John");
    Pelajar pelajar2("Jane");

    pelajar1.pinjamBuku(&buku1);
    pelajar2.pinjamBuku(&buku2);
    pelajar1.kembalikanBuku();
    pelajar2.kembalikanBuku();

    return 0;
}