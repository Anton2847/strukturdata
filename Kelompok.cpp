#include <iostream>
using namespace std;

#define max 50 // Ukuran maksimal tumpukan

struct tumpukan { // Definisi struktur tumpukan
    int atas; // Posisi atas tumpukan
    string data[max]; // Array untuk menyimpan data dalam tumpukan
} T; // Membuat sebuah instance tumpukan

void awal() { // Fungsi untuk menginisialisasi tumpukan
    T.atas = -1; // Mengatur posisi atas tumpukan menjadi -1 (kosong)
}

int kosong() { // Fungsi untuk memeriksa apakah tumpukan kosong
    if (T.atas == -1) {
        return 1; // Mengembalikan 1 jika tumpukan kosong
    } else {
        return 0; // Mengembalikan 0 jika tumpukan tidak kosong
    }
}

int penuh() { // Fungsi untuk memeriksa apakah tumpukan penuh
    if (T.atas == max - 1) { 
        return 1; // Mengembalikan 1 jika tumpukan penuh
    } else {
        return 0; // Mengembalikan 0 jika tumpukan tidak penuh
    }
}

void input(string data) { // Fungsi untuk memasukkan data ke dalam tumpukan
    if (penuh() == 1) { // Jika tumpukan penuh
        cout << "Data penuh. Data " << data << " tidak dapat dimasukkan." << endl;
    } else { // Jika tumpukan tidak penuh
        T.atas++; // Menambahkan posisi atas tumpukan
        T.data[T.atas] = data; // Menyimpan data dalam tumpukan
        cout << "Data " << data << " berhasil dimasukkan." << endl;
    }
}
// Fungsi untuk menghapus sebuah tim dari tumpukan
void hapus() {
    if (kosong() == 1) { // Jika tumpukan kosong
        cout << "Data kosong. Tidak ada data yang dapat dihapus." << endl;
    } else { // Jika tumpukan tidak kosong
        string timHapus;
        cout << "Masukkan nama tim yang ingin dihapus: ";
        cin.ignore();
        getline(cin,timHapus);

        int indexTim = -1; 
        for (int i = 0; i <= T.atas; i += 5) { // Melakukan perulangan melalui tumpukan dengan penambahan sebanyak 5 (karena setiap tim memiliki 5 elemen)
            if (T.data[i] == timHapus) { // Memeriksa apakah nama tim cocok dengan input
                indexTim = i; // Menyimpan indeks tim
                break;
            }
        }

        if (indexTim == -1) { // Jika tim tidak ditemukan
            cout << "Tim tidak ditemukan." << endl;
        } else { // Jika tim ditemukan
            char konfirmasi;
            cout << "Apakah Anda yakin ingin menghapus tim " << T.data[indexTim] << "? (Y/N): ";
            cin >> konfirmasi;

            if (konfirmasi == 'Y' || konfirmasi == 'y') { // Jika pengguna mengonfirmasi penghapusan
                cout << "Tim berhasil dihapus :)" << endl;
                // Menghapus tim dan informasinya
                for (int i = indexTim; i < T.atas - 4; i += 5) {// Melakukan perulangan melalui tim-tim yang tersisa setelah tim yang dihapus
                    for (int j = 0; j < 5; j++) {
                        T.data[i + j] = T.data[i + j + 5];// Memindahkan data dari setiap tim naik sebanyak 5 posisi
                    }
                }
                T.atas -= 5; // Mengurangi posisi atas tumpukan sebanyak 5

            } else {
                cout << "Penghapusan tim dibatalkan." << endl;
            }
        }
    }
}
// Fungsi untuk menampilkan semua tim dalam tumpukan
void tampil() {
    if (kosong() == 1) {// Jika tumpukan kosong
        cout << "Data kosong. Tidak ada data yang ditampilkan." << endl;
    } else { // Jika tumpukan tidak kosong
        int timCount = 1;
        for (int i = 0; i <= T.atas; i += 5) { // Melakukan perulangan melalui tumpukan dengan penambahan sebanyak 5 (karena setiap tim memiliki 5 elemen)
            cout << "====[ Tim " << timCount << " " << T.data[i] << " ]====" << endl;
            cout << "GH    	      : " << T.data[i + 1] << endl;
            cout << "Coach         : " << T.data[i + 2] << endl;
            cout << "Owner         : " << T.data[i + 3] << endl;
            cout << "Tahun Berdiri : " << T.data[i + 4] << endl;
            timCount++;
        }
        cout << endl;
    }
}
// Fungsi untuk mengedit nama sebuah tim
void edit() {
    if (kosong() == 1) { // Jika tumpukan kosong
        cout << "Data kosong. Tidak ada data yang dapat diedit." << endl;
    } else { // Jika tumpukan tidak kosong
        string timBaru;
        cout << "Masukkan nama tim yang ingin diedit : ";
        cin.ignore();
        getline(cin,timBaru);

        int indexTim = -1; // Melakukan perulangan melalui tumpukan dengan penambahan sebanyak 5 (karena setiap tim memiliki 5 elemen)
        for (int i = 0; i <= T.atas; i += 5) { // Memeriksa apakah nama tim cocok dengan input
            if (T.data[i] == timBaru) { // Menyimpan indeks tim
                indexTim = i;
                break;
            }
        }

        if (indexTim == -1) { // Jika tim tidak ditemukan
            cout << "Tim tidak ditemukan." << endl;
        } else { // Jika tim ditemukan
            string namaTimBaru;
            cout << "Nama tim baru			    : ";
        	getline(cin,namaTimBaru);
            T.data[indexTim] = namaTimBaru; // Memperbarui nama tim
            cout << "Tim berhasil diedit :)" << endl;
        }
    }
}
// Fungsi untuk mencari tim berdasarkan nama
void cariTim() {
    if (kosong() == 1) { // Jika tumpukan kosong
        cout << "Data kosong. Tidak ada data yang dapat dicari." << endl;
    } else { // Jika tumpukan tidak kosong
        string timCari;
        cout << "Masukkan nama tim yang ingin dicari : ";
        cin.ignore();
        getline(cin,timCari);

        int indexTim = -1;
        for (int i = 0; i <= T.atas; i += 5) { // Melakukan perulangan melalui tumpukan dengan penambahan sebanyak 5 (karena setiap tim memiliki 5 elemen)
            if (T.data[i] == timCari) {  // Memeriksa apakah nama tim cocok dengan input
                indexTim = i; // Menyimpan indeks tim
                break;
            }
        }

        if (indexTim == -1) { // Jika tim tidak ditemukan
            cout << "Tim tidak ditemukan." << endl;
        } else { // Jika tim ditemukan
            cout << "====[ Tim " << timCari << " ]====" << endl;
            cout << "GH    	      : " << T.data[indexTim + 1] << endl;
            cout << "Coach         : " << T.data[indexTim + 2] << endl;
            cout << "Owner         : " << T.data[indexTim + 3] << endl;
            cout << "Tahun Berdiri : " << T.data[indexTim + 4] << endl;
        }
    }
}
// Fungsi untuk mengurutkan tim secara alfabetis
void sortTim() {
    if (kosong() == 1) { // Jika tumpukan kosong
        cout << "Data kosong. Tidak ada data yang dapat diurutkan." << endl;
    } else { // Jika tumpukan tidak kosong
        int n = (T.atas + 1) / 5; // Jumlah tim
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                string timSekarang = T.data[j * 5]; // Nama tim saat ini
                string timBerikutnya = T.data[(j + 1) * 5]; // Nama tim berikutnya

                if (timSekarang > timBerikutnya) {
                    // Tukar posisi tim saat ini dengan tim berikutnya
                    for (int k = 0; k < 5; k++) {
                        swap(T.data[j * 5 + k], T.data[(j + 1) * 5 + k]);
                    }
                }
            }
        }
        cout << "Tim berhasil diurutkan berdasarkan abjad." << endl;
    }
}

int main() {
    int pil;
    string tim, homebase, coach, owner, tahun_berdiri;
    awal();

    do {
        cout << "\n===[Team Esport Nasional]===\n";
        cout << "[1]. Input Team\n";
        cout << "[2]. Tampil Team\n";
        cout << "[3]. Edit Team\n";
        cout << "[4]. Hapus Team\n";
        cout << "[5]. Cari Team\n";
        cout << "[6]. Urutkan Tim (A-Z)\n";
        cout << "[7]. Keluar\n";
        cout << "====================\n";
        cout << "Masukkan Pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1:
                cout << "Masukkan nama tim	 : ";
                cin.ignore();
                getline(cin,tim);
                cout << "Masukkan nama GH	 : ";
                getline(cin,homebase);
                cout << "Masukkan nama coach      : ";
                getline(cin,coach);
                cout << "Masukkan nama owner      : ";
                getline(cin,owner);
                cout << "Masukkan tahun berdiri	 : ";
                getline(cin,tahun_berdiri);
                input(tim);
                input(homebase);
                input(coach);
                input(owner);
                input(tahun_berdiri);
                break;
            case 2:
                tampil();
                break;
            case 3:
                edit();
                break;
            case 4:
                hapus();
                break;
            case 5:
                cariTim();
                break;
            case 6:
                sortTim();
                break;
            case 7:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }

        cout << endl;
    } while (pil != 7);

    return 0;
}
