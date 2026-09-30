#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// FUNGSI INPUT ANGKA
int inputAngka(string pesan) {
    int angka;

    while (true) {
        cout << pesan;

        if (cin >> angka) {
            return angka;
        }

        cout << "Input harus berupa angka!\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// FLOWCHART A
int main() {

    // Data menu makanan dan minuman
    string namaMenu[] = {
        "Nasi Goreng",
        "Mie Goreng",
        "Ayam Geprek",
        "Nasi Ayam",
        "Sate Ayam",
        "Es Teh",
        "Es Jeruk",
        "Kopi"
    };

    // Harga masing-masing menu
    int hargaMenu[] = {
        15000,
        13000,
        18000,
        20000,
        22000,
        5000,
        7000,
        8000
    };

    const int jumlahMenu = 8;

    // Variabel untuk menentukan transaksi baru
    char pesanLagi = 'y';


    cout << "       PROGRAM PEMESANAN MAKANAN\n";

    // Perulangan transaksi baru
    while (pesanLagi == 'y' || pesanLagi == 'Y') {

        // Reset data setiap transaksi baru
        int jumlahPesanan[8] = {0};
        int total = 0;

        cout << "\n========== DAFTAR MENU ==========\n";

        // FLOWCHART B

        while (true) {

            cout << "\n";

            // Menampilkan daftar menu
            for (int i = 0; i < jumlahMenu; i++) {
                cout << i + 1 << ". "
                     << left << setw(20) << namaMenu[i]
                     << "Rp" << hargaMenu[i] << '\n';
            }

            cout << "0. Selesai Memesan\n";


            // Input pilihan menu
            int pilihan = inputAngka("Pilih nomor menu: ");


            if (pilihan == 0) {

                if (total == 0) {
                    cout << "Anda belum memesan menu. "
                         << "Silakan pilih menu terlebih dahulu.\n";

                    continue;
                }
                break;
            }


            if (pilihan < 1 || pilihan > jumlahMenu) {

                cout << "Menu tidak tersedia! "
                     << "Silakan pilih kembali.\n";

                continue;
            }


            int jumlah = inputAngka("Jumlah pesanan: ");


            // Validasi jumlah pesanan
            if (jumlah <= 0) {

                cout << "Jumlah pesanan harus lebih dari 0!\n";

                continue;
            }

            int subtotal = hargaMenu[pilihan - 1] * jumlah;


            // Menyimpan jumlah pesanan
            jumlahPesanan[pilihan - 1] += jumlah;


            // Menambahkan subtotal ke total belanja
            total += subtotal;


            cout << "Subtotal: Rp" << subtotal << '\n';
            cout << "Total sementara: Rp" << total << '\n';

            char tambahPesanan;

            cout << "Tambah pesanan? (y/n): ";
            cin >> tambahPesanan;


            // Validasi input y/n
            while (tambahPesanan != 'y' &&
                   tambahPesanan != 'Y' &&
                   tambahPesanan != 'n' &&
                   tambahPesanan != 'N') {

                cout << "Masukkan y atau n: ";
                cin >> tambahPesanan;
            }


            // Jika tidak ingin menambah pesanan
            if (tambahPesanan == 'n' ||
                tambahPesanan == 'N') {

                break;
            }
        }

        // FLOWCHART C
        int diskon = 0;


        // Memeriksa apakah mendapatkan diskon
        if (total >= 100000) {
            diskon = total * 10 / 100;
        }

        // Menghitung total yang harus dibayar
        int totalBayar = total - diskon;


        // Menampilkan ringkasan pembayaran
        cout << "\n========== RINGKASAN ==========\n";
        cout << "Total belanja : Rp" << total << '\n';
        cout << "Diskon        : Rp" << diskon << '\n';
        cout << "Total bayar   : Rp" << totalBayar << '\n';

        // FLOWCHART D
        int uang;
        do {

            uang = inputAngka("Uang pembayaran: Rp");


            if (uang < 0) {

                cout << "Uang pembayaran tidak boleh negatif!\n";
            }

            else if (uang < totalBayar) {

                cout << "Uang kurang Rp"
                     << totalBayar - uang
                     << ". Silakan bayar kembali.\n";
            }

        }
        while (uang < totalBayar);


        // Menghitung kembalian
        int kembalian = uang - totalBayar;

        // FLOWCHART E

        cout << "             STRUK PEMBELIAN\n";

        // Header tabel struk
        cout << left
             << setw(20) << "Nama Menu"
             << setw(8) << "Jumlah"
             << "Subtotal\n";


        // Menampilkan menu yang dipesan
        for (int i = 0; i < jumlahMenu; i++) {

            if (jumlahPesanan[i] > 0) {

                cout << left
                     << setw(20) << namaMenu[i]
                     << setw(8) << jumlahPesanan[i]
                     << "Rp"
                     << hargaMenu[i] * jumlahPesanan[i]
                     << '\n';
            }
        }


        // Menampilkan ringkasan transaksi
        cout << "Total belanja : Rp" << total << '\n';
        cout << "Diskon        : Rp" << diskon << '\n';
        cout << "Total bayar   : Rp" << totalBayar << '\n';
        cout << "Uang diterima : Rp" << uang << '\n';
        cout << "Kembalian     : Rp" << kembalian << '\n';


        cout << "========================================\n";
        cout << "Terima kasih sudah memesan!\n";


        // FLOWCHART F

        cout << "\nIngin melakukan transaksi baru? (y/n): ";
        cin >> pesanLagi;


        // Validasi pilihan transaksi baru
        while (pesanLagi != 'y' &&
               pesanLagi != 'Y' &&
               pesanLagi != 'n' &&
               pesanLagi != 'N') {

            cout << "Masukkan y atau n: ";
            cin >> pesanLagi;
        }

    }


    cout << "\nProgram selesai. Sampai jumpa!\n";


    return 0;
}