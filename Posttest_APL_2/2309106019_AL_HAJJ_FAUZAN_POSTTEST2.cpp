#include <iostream>
#include <cstdlib>
#include <limits> 

using namespace std;

#define tebalCyan "\033[1m\033[36m"
#define merah "\033[31m"
#define cyan "\033[36m"
#define kuning "\033[33m"
#define putih "\033[0m"
#define hijau "\033[32m"
#define tebalhijau "\033[1;32m"
#define biru "\033[1;34m"

string nama_user;
string pass_user;
string nama;
double harga;
int stok; 
int pilihan;

struct Barang {
    string nama_barang;
    double harga_barang;
    int stok_barang;
};

Barang barang[2][3];

void clearscreen() {
    cout << "\033[2J\033[1;1H";
}

void tampilkan_barang_dalam_vending_machine() {
    clearscreen();
    cout << kuning << "Barang dalam vending machine:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Nama: " << barang[i][j].nama_barang << ", Harga: RP" << barang[i][j].harga_barang << ", Stok: " << barang[i][j].stok_barang << endl;
        }
    }
}

void login() {
    clearscreen();
    cout << hijau << "Login User" << putih << endl;
    int salah = 0;
    while (salah < 3) {
        cout << tebalhijau << "Masukkan username Anda:" << putih << endl;
        getline(cin, nama_user);
        cout << tebalhijau << "Masukkan password Anda:" << putih << endl;
        getline(cin, pass_user);
        if (nama_user == "Al Hajj Fauzan" && pass_user == "2309106019") {
            clearscreen();
            cout << kuning << "Login berhasil!" << putih << endl;
            clearscreen();
            cout << kuning << "Selamat datang " << nama_user << "!" << putih << endl;
            return;
        } else {
            salah++;
            clearscreen();
            cout << merah << "Username atau password Anda tidak sesuai, silahkan dicoba ulang" << putih << endl;
        }
    }
    cout << merah << "Kesalahan Anda telah melebihi batas, silahkan untuk mengaktifkan ulang program" << putih << endl;
    exit(EXIT_FAILURE);
}

void menu_CRUD() {
    cout << tebalCyan << "[>>>>--------> Menu CRUD Vending Machine <--------<<<<]" << putih << endl;
    cout << biru << "|1. Menambahkan barang ke Vending Machine             |" << endl;
    cout << "|2. Tampilkan barang pada Vending Machine             |" << endl;
    cout << "|3. Perbarui harga dan stok dalam Vending Machine     |" << endl;
    cout << "|4. Hapus barang dari Vending Machine                 |" << endl;
    cout << "|5. Keluar                                            |" << putih << endl;
    cout << tebalCyan << "[xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx]\n" << putih << endl;
}

void tambah_barang() {
    clearscreen();
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    do 
    {
        cout << "Masukkan nama barang: ";
        getline(cin, nama);
    } while (nama.empty() || nama.find_first_not_of(' ') == string::npos);
    do 
    {
        cout << "Masukkan harga baru: ";
        if (!(cin >> harga)) { 
            cout << merah << "Inputan tidak valid, harus menggunakan angka!" << putih << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }
        break; 
    } 
    while (true);
    do 
    {
        cout << "Masukkan stok baru: ";
        if (!(cin >> stok)) { 
            cout << merah << "Inputan tidak valid, harus menggunakan angka!" << putih << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }
        break; 
    } 
    while (true);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (barang[i][j].nama_barang.empty()) {
                barang[i][j].nama_barang = nama;
                barang[i][j].harga_barang = harga;
                barang[i][j].stok_barang = stok;
                clearscreen();
                cout << kuning << "Barang berhasil ditambahkan." << putih << endl;
                return;
            }
        }
    }
    cout << merah << "Vending Machine penuh. Tidak bisa menambahkan barang baru." << putih << endl;
}

void perbarui_barang() {
    clearscreen();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    do 
    {
        cout << "Masukkan nama barang yang ingin diperbarui: ";
        getline(cin, nama);
    } while (nama.empty() || nama.find_first_not_of(' ') == string::npos);
    do 
    {
        cout << "Masukkan harga baru: ";
        if (!(cin >> harga)) { 
            cout << merah << "Inputan tidak valid, harus menggunakan angka!" << putih << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }
        break; 
    } while (true);
    do {
        cout << "Masukkan stok baru: ";
        if (!(cin >> stok)) { 
            cout << merah << "Inputan tidak valid, harus menggunakan angka!" << putih << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }
        break; 
    } 
    while (true);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (barang[i][j].nama_barang == nama) {
                barang[i][j].harga_barang = harga;
                barang[i][j].stok_barang = stok;
                clearscreen();
                cout << kuning << "Barang berhasil diperbarui." << putih << endl;
                return;
            }
        }
    }
    cout << merah << "Barang tidak ditemukan." << putih << endl;
}

void hapus_barang() {
    clearscreen();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    do 
    {
        cout << "Masukkan nama barang yang ingin dihapus: ";
        getline(cin, nama);
    } 
    while (nama.empty() || nama.find_first_not_of(' ') == string::npos);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (barang[i][j].nama_barang == nama) {
                barang[i][j].nama_barang.clear();
                barang[i][j].harga_barang = 0;
                barang[i][j].stok_barang = 0;
                clearscreen();
                cout << kuning << "Barang berhasil dihapus." << putih << endl;
                return;
            }
        }
    }
    cout << merah << "Barang tidak ditemukan." << putih << endl;
}

int main() {
    clearscreen();
    login();
    do {
        menu_CRUD();
        cout << "Pilih menu yang diinginkan: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearscreen();
            cout << merah << "Inputan harus berupa angka!" << putih << endl;
        } 
        else {
            switch (pilihan) {
                case 1:
                    clearscreen();
                    tambah_barang();
                    break;
                case 2:
                    clearscreen();
                    tampilkan_barang_dalam_vending_machine();
                    break;
                case 3:
                    clearscreen();
                    tampilkan_barang_dalam_vending_machine();
                    perbarui_barang();
                    break;
                case 4:
                    clearscreen();
                    tampilkan_barang_dalam_vending_machine();
                    hapus_barang();
                    break;
                case 5:
                    cout << "Keluar dari program." << endl;
                    break;
                default:
                    clearscreen();
                    cout << merah << "Inputan salah, silahkan dicoba ulang." << putih << endl;
                    break;
            }
        }
    } while (pilihan != 5);
    return 0;
}
