#include <iostream>
#include <string>

using namespace std;

const int MAX_TIKET = 100;
//STRUK TIKET: menyimpan informasi tike, termasuk ID,nama event, dan jumlah tiket.
//ARRAY POINTER: menggunakan untuk menyimpan pointer ke struct tiket, dengan maksimum 100 tiket.
//FUNGSI DAN PROSEDURr:tambah_tiket() yaitu menambahkan tiket kedalam array. kemudian tampilkan_tiket()yaitu menampilkan semua tiket yang ada. setelah itu, update_tiket()yaitu memperbarui informasi berdasarkan ID. dan terakhir hapus_tiket()yaitu menghapus tiket dari array berdasarkan ID.
//POINTER:menggunakan new untuk alokasi pada objek tiket dan delete untuk menghapus objek tersebut ketika tidak lagi diperlukan.
struct Tiket {
    int id;
    string nama_event;
    int jumlah_tiket;
};
void tambah_tiket(Tiket* tiket_array[], int& tiket_count) {
    if (tiket_count >= MAX_TIKET) {
        cout << "Kuota tiket penuh!\n";
        return;
    }

    Tiket* tiket_baru = new Tiket;
    cout << "Masukkan ID Tiket: ";
    cin >> tiket_baru->id;
    cout << "Masukkan Nama Event: ";
    cin.ignore(); 
    getline(cin, tiket_baru->nama_event);
    cout << "Masukkan Jumlah Tiket: ";
    cin >> tiket_baru->jumlah_tiket;
    tiket_array[tiket_count++] = tiket_baru;
    cout << "Tiket berhasil ditambahkan!\n";
}
void tampilkan_tiket(Tiket* tiket_array[], int tiket_count) {
    if (tiket_count == 0) {
        cout << "Tiket telah habis.\n";
        return;
    }
    cout << "Daftar Tiket:\n";
    for (int i = 0; i < tiket_count; i++) {
        cout << "ID: " << tiket_array[i]->id
             << ", Nama Event: " << tiket_array[i]->nama_event
             << ", Jumlah Tiket: " << tiket_array[i]->jumlah_tiket << endl;
    }
}
void update_tiket(Tiket* tiket_array[], int tiket_count) {
    int id;
    cout << "Masukkan ID Tiket yang ingin diperbarui: ";
    cin >> id;

    for (int i = 0; i < tiket_count; i++) {
        if (tiket_array[i]->id == id) {
            cout << "Masukkan Nama Event baru: ";
            cin.ignore(); 
            getline(cin, tiket_array[i]->nama_event);
            cout << "Masukkan Jumlah Tiket baru: ";
            cin >> tiket_array[i]->jumlah_tiket;
            cout << "Tiket berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Tiket dengan ID " << id << " tidak ditemukan.\n";
}
void hapus_tiket(Tiket* tiket_array[], int& tiket_count) {
    int id;
    cout << "Masukkan ID Tiket yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < tiket_count; i++) {
        if (tiket_array[i]->id == id) {
            delete tiket_array[i];
            tiket_array[i] = tiket_array[tiket_count - 1]; 
            tiket_count--;
            cout << "Tiket berhasil dihapus!\n";
            return;
        }
    }
    cout << "Tiket dengan ID " << id << " tidak ditemukan.\n";
}
int main() {
    Tiket* tiket_array[MAX_TIKET];
    int tiket_count = 0;
    int pilihan;

    while (true) {
        cout << "\n=== Sistem Pembelian Tiket Event Run ===\n";
        cout << "1. Tambah Tiket\n";
        cout << "2. Tampilkan Tiket\n";
        cout << "3. Update Tiket\n";
        cout << "4. Hapus Tiket\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambah_tiket(tiket_array, tiket_count);
                break;
            case 2:
                tampilkan_tiket(tiket_array, tiket_count);
                break;
            case 3:
                update_tiket(tiket_array, tiket_count);
                break;
            case 4:
                hapus_tiket(tiket_array, tiket_count);
                break;
            case 5:
                for (int i = 0; i < tiket_count; i++) {
                    delete tiket_array[i];
                }
                return 0;
            default:
                cout << "Pilihan tidak sesuai. Silakan dicoba lagi.\n";
}
}
}