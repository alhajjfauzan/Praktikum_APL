#include <iostream>
using namespace std;

string nama_user;
string pass_user;
string pilihan;
int salah = 0;
int pilih_angka;
double jumlah_rupiah;
double jumlah_dollar;
double jumlah_euro;
double jumlah_yen;


#define tebalCyan "\033[1m\033[36m" 
#define merah "\033[31m"     
#define cyan "\033[36m"   
#define kuning "\033[33m"  
#define putih "\033[0m"
#define hijaw "\033[32m"

int main() {
    cout << hijaw << "Login User" << putih << endl;
    while (salah < 3) {
        cout << "Masukkan username Anda:" << putih << endl;
        getline(cin, nama_user);
        cout << "Masukkan sandi/password Anda:" << putih << endl;
        getline(cin, pass_user);
        if (nama_user == "Al Hajj Fauzan" && pass_user == "2309106019") {
            cout << kuning << "Login berhasil!" << putih << endl;
            cout << kuning << "Selamat datang " << nama_user << "!" << putih << endl;
            do {
                cout << hijaw << "[>>>----->Menu Konversi Mata Uang<-----<<<]" << putih << endl;
                cout << tebalCyan << "|1. Konversi Rupiah ke (Dollar, Euro, Yen)|" << endl;
                cout << "|2. Konversi Dollar ke (Rupiah, Euro, Yen)|" << endl;
                cout << "|3. Konversi Euro ke (Rupiah, Dollar, Yen)|" << endl;
                cout << "|4. Konversi Yen ke (Rupiah, Dollar, Euro)|" << endl;
                cout << "|5. Keluar                                |" << endl;
                cout << "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|" << putih << endl;
                
                do {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << merah << "Inputan tidak valid, harus menggunakan integer!" << putih << endl;
                    }
                    cout << "Pilih konversi yang diinginkan: ";
                    cin >> pilih_angka;
                } while (cin.fail());

                switch (pilih_angka) {
                    case 1:
                        do {
                            cout << "Masukkan jumlah Rupiah yang ingin dikonversikan:" << putih << endl; 
                            cin >> jumlah_rupiah;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << merah << "Input tidak valid. Harap masukkan angka." << putih << endl;
                            } else {
                                cout << kuning << "Hasil konversi ke Dollar = " << putih << jumlah_rupiah * 0.000064 << endl;
                                cout << kuning << "Hasil konversi ke Euro = " << putih << jumlah_rupiah * 0.00006 << endl;
                                cout << kuning << "Hasil konversi ke Yen = " << putih << jumlah_rupiah * 0.0096 << endl;
                                break;
                            }
                        } while (true);
                        break;
                    case 2:
                        do {
                            cout << "Masukkan jumlah Dollar yang ingin dikonversikan:" << putih << endl;
                            cin >> jumlah_dollar;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << merah << "Input tidak valid. Harap masukkan angka." << putih << endl;
                            } else {
                                cout << kuning << "Hasil konversi ke Rupiah = " << putih << jumlah_dollar * 15700 << endl;
                                cout << kuning << "Hasil konversi ke Euro = " << putih << jumlah_dollar * 0.92 << endl;
                                cout << kuning << "Hasil konversi ke Yen = " << putih << jumlah_dollar * 150.10 << endl;
                                break;
                            }
                        } while (true);
                        break;
                    case 3:
                        do {
                            cout << "Masukkan jumlah Euro yang ingin dikonversikan:" << putih << endl; 
                            cin >> jumlah_euro;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << merah << "Input tidak valid. Harap masukkan angka." << putih << endl;
                            } else {
                                cout << kuning << "Hasil konversi ke Rupiah = " << putih << jumlah_euro * 17043 << endl;
                                cout << kuning << "Hasil konversi ke Dollar = " << putih << jumlah_euro * 1.09 << endl;
                                cout << kuning << "Hasil konversi ke Yen = " << putih << jumlah_euro * 162.93 << endl;
                                break;
                            }
                        } while (true);
                        break;
                    case 4: 
                        do {
                            cout << "Masukkan jumlah Yen yang ingin dikonversikan:" << putih << endl; 
                            cin >> jumlah_yen;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << merah << "Input tidak valid. Harap masukkan angka." << putih << endl;
                            } else {
                                cout << kuning << "Hasil konversi ke Rupiah = " << putih << jumlah_yen * 104.61 << endl;
                                cout << kuning << "Hasil konversi ke Dollar = " << putih << jumlah_yen * 0.0067 << endl;
                                cout << kuning << "Hasil konversi ke Euro = " << putih << jumlah_yen * 0.0061 << endl;
                                break;
                            }
                        } while (true);
                        break;
                    case 5:
                        cout << "Terima kasih!" << endl;
                        return 0;
                    default:
                        cout << merah << "Pilihan tidak valid. Silakan pilih lagi." << putih << endl;
                }
                 do {
                    cout << "Apakah Anda ingin kembali ke menu? (Y/N)";
                    cin >> pilihan;
                    if (pilihan == "N" || pilihan == "n") {
                        cout << "Terima kasih !" << endl;
                        return 0;
                    } else if (pilihan != "Y" && pilihan != "y") {
                        cout << merah << "Pilihan tidak valid. Silakan pilih Y untuk kembali ke menu atau N untuk keluar." << putih << endl;
                    } else {
                        break;
                    }
                } while (true);
            } while (true);
        } else {
            salah++;
            cout << merah << "Username atau password Anda tidak sesuai, silahkan dicoba ulang" << putih << endl;
        }
    }

    cout << merah << "Kesalahan Anda telah melebihi batas, silahkan untuk mengaktifkan ulang program" << putih << endl;
    return 0;
}
