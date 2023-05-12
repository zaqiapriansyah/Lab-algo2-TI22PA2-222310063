#include <iostream>
#include <string>

class Mahasiswa {
protected:
    std::string status;
    std::string nama;
    int umur;
    std::string jurusan;
    std::string fakultas;

public:
    Mahasiswa(const std::string& status, const std::string& nama, int umur, const std::string& jurusan, const std::string& fakultas)
        : status(status), nama(nama), umur(umur), jurusan(jurusan), fakultas(fakultas) {}

    virtual void getInfo() {
        std::cout << "Status: " << status << std::endl;
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Umur: " << umur << std::endl;
        std::cout << "Jurusan: " << jurusan << std::endl;
        std::cout << "Fakultas: " << fakultas << std::endl;
    }
};

class MahasiswaAktif : public Mahasiswa {
private:
    int semester;

public:
    MahasiswaAktif(const std::string& status, const std::string& nama, int umur, const std::string& jurusan, const std::string& fakultas, int semester)
        : Mahasiswa(status, nama, umur, jurusan, fakultas), semester(semester) {}

    void getInfo() override {
        Mahasiswa::getInfo();
        std::cout << "Semester: " << semester << std::endl;
    }
};

class MahasiswaNonAktif : public Mahasiswa {
private:
    std::string alasan;

public:
    MahasiswaNonAktif(const std::string& status, const std::string& nama, int umur, const std::string& jurusan, const std::string& fakultas, const std::string& alasan)
        : Mahasiswa(status, nama, umur, jurusan, fakultas), alasan(alasan) {}

    void getInfo() override {
        Mahasiswa::getInfo();
        std::cout << "Alasan: " << alasan << std::endl;
    }
};

int main() {
    MahasiswaAktif mhsAktif("Aktif", "John Doe", 20, "Teknologi Informasi", "Informatika", 2);
    MahasiswaNonAktif mhsNonAktif("Non-Aktif", "Jane Smith", 22, "Sistem Informasi", "Informatika", "Kesehatan");

    Mahasiswa* mhs1 = &mhsAktif;
    Mahasiswa* mhs2 = &mhsNonAktif;

    mhs1->getInfo();
    std::cout << std::endl;
    mhs2->getInfo();

    return 0;
}