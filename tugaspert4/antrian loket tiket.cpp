#include <iostream>
#include <queue>
using namespace std;

// Struktur data untuk representasi pelanggan
struct Pelanggan {
    string nama;
    int nomorAntrian;
};

int main() {
    // Buat objek queue untuk mewakili antrian pelanggan
    queue<Pelanggan> antrian;

    // Nomor antrian yang akan diberikan ke pelanggan selanjutnya
    int nomorAntrianSelanjutnya = 1;

    // Loop utama program
    while (true) {
        // Tampilkan menu
        cout << "Silakan pilih menu:\n";
        cout << "1. Tambah pelanggan ke antrian\n";
        cout << "2. Layani pelanggan selanjutnya\n";
        cout << "3. Keluar\n";

        // Baca pilihan pengguna
        int pilihan;
        cin >> pilihan;

        // Proses pilihan pengguna
        switch (pilihan) {
            case 1: {
                // Buat objek Pelanggan baru
                Pelanggan pelangganBaru;

                // Baca nama pelanggan
                cout << "Masukkan nama pelanggan: ";
                cin >> pelangganBaru.nama;

                // Berikan nomor antrian ke pelanggan baru
                pelangganBaru.nomorAntrian = nomorAntrianSelanjutnya;

                // Tambahkan pelanggan baru ke antrian
                antrian.push(pelangganBaru);

                // Tampilkan nomor antrian pelanggan
                cout << "Nomor antrian Anda adalah: " << pelangganBaru.nomorAntrian << endl;

                // Tingkatkan nomor antrian selanjutnya
                nomorAntrianSelanjutnya++;

                break;
            }
            case 2: {
                // Periksa apakah antrian kosong
                if (antrian.empty()) {
                    cout << "Tidak ada pelanggan dalam antrian.\n";
                } else {
                    // Ambil pelanggan selanjutnya dari antrian
                    Pelanggan pelangganSelanjutnya = antrian.front();
                    antrian.pop();

                    // Tampilkan nama dan nomor antrian pelanggan yang dilayani
                    cout << "Loket sedang melayani pelanggan dengan nama " << pelangganSelanjutnya.nama
                         << " (nomor antrian " << pelangganSelanjutnya.nomorAntrian << ").\n";
                }

                break;
            }
            case 3: {
                // Keluar dari loop utama program
                return 0;
            }
            default: {
                // Pilihan tidak valid
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
            }
        }

        // Tampilkan pesan separator
        cout << "----------------------------------------\n";
    }
}
