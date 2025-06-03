#include <iostream>
#include <string>
using namespace std;

class Pesanan {
public:
    int ID_pesanan;
    string nama_pesanan;
    string waktu;
    int harga;

    Pesanan(int ID, string nm, string w, int h) {
        ID_pesanan = ID;
        nama_pesanan = nm;
        waktu = w;
        harga = h;
    }
};

class MenuItem {
    public:
    string nama;
    string waktu;
    int harga;
};

const int JUMLAH_MENU = 5;
MenuItem daftarMenu[JUMLAH_MENU] = {
    {"Nasi Goreng", "10 menit", 15000},
    {"Mie Ayam", "7 menit", 12000},
    {"Sate Ayam", "12 menit", 20000},
    {"Bakso", "8 menit", 13000},
    {"Ayam Geprek", "9 menit", 18000}
};

class Node {
    public:
    Pesanan data;
    Node* next;
    Node(Pesanan p) : data(p), next(nullptr) {}
};

class AntrianPesanan {
private:
    Node* front;
    Node* rear;

public:
    AntrianPesanan() : front(nullptr), rear(nullptr) {}

    void tambah_pesan(Pesanan pesanan) {
        Node* baru = new Node(pesanan);
        if (rear == nullptr) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }
    }

    void hapus_pesan() {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* hapus = front;
        front = front->next;
        delete hapus;
        if (front == nullptr) rear = nullptr;
    }

    void display() {
        if (front == nullptr) {
            cout << "Antrian pesanan kosong" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            Pesanan& current = temp->data;
            cout << "ID pesanan     : " << current.ID_pesanan << endl;
            cout << "Nama pesanan   : " << current.nama_pesanan << endl;
            cout << "Lama pesanan   : " << current.waktu << endl;
            cout << "Harga pesanan  : Rp" << current.harga << endl;
            cout << "--------------------------" << endl;
            temp = temp->next;
        }
    }

    bool hapus_ID(int id_pilihan) {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return false;
        }

        Node* current = front;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.ID_pesanan == id_pilihan) {
                if (prev == nullptr) {
                    front = front->next;
                } else {
                    prev->next = current->next;
                }

                if (current == rear) {
                    rear = prev;
                }

                delete current;
                cout << "Pesanan dengan ID " << id_pilihan << " berhasil dihapus." << endl;
                return true;
            }
            prev = current;
            current = current->next;
        }

        cout << "Tidak ada pesanan dengan ID " << id_pilihan << endl;
        return false;
    }

    void update(int id_pilihan) {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            if (current->data.ID_pesanan == id_pilihan) {
                cout << "\n=== Daftar Menu Baru ===" << endl;
                for (int i = 0; i < JUMLAH_MENU; ++i) {
                    cout << i + 1 << ". " << daftarMenu[i].nama
                         << " (" << daftarMenu[i].waktu
                         << ", Rp" << daftarMenu[i].harga << ")\n";
                }

                int pilihanMenu;
                cout << "Pilih menu baru (1-" << JUMLAH_MENU << "): ";
                cin >> pilihanMenu;

                if (pilihanMenu < 1 || pilihanMenu > JUMLAH_MENU) {
                    cout << "Pilihan tidak valid!" << endl;
                    return;
                }

                MenuItem m = daftarMenu[pilihanMenu - 1];
                current->data.nama_pesanan = m.nama;
                current->data.waktu = m.waktu;
                current->data.harga = m.harga;

                cout << "Pesanan berhasil diupdate." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Pesanan dengan ID " << id_pilihan << " tidak ditemukan." << endl;
    }

    void search(int id_pilihan) {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            if (current->data.ID_pesanan == id_pilihan) {
                cout << "Pesanan ditemukan:\n";
                cout << "ID pesanan     : " << current->data.ID_pesanan << endl;
                cout << "Nama pesanan   : " << current->data.nama_pesanan << endl;
                cout << "Waktu pesanan  : " << current->data.waktu << endl;
                cout << "Harga pesanan  : Rp" << current->data.harga << endl;
                cout << "--------------------------" << endl;
                return;
            }
            current = current->next;
        }

        cout << "Pesanan dengan ID " << id_pilihan << " tidak ditemukan." << endl;
    }
};

void menu(AntrianPesanan &antrian) {
    int pilihan;
    do {
        cout << "\n=== MENU ANTRIAN PESANAN ===" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Tampilkan Antrian" << endl;
        cout << "3. Hapus Pesanan Depan" << endl;
        cout << "4. Hapus Pesanan Berdasarkan ID" << endl;
        cout << "5. Update Pesanan Berdasarkan ID" << endl;
        cout << "6. Cari Pesanan Berdasarkan ID" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int id, pilihanMenu;
                cout << "Masukkan ID Pesanan: ";
                cin >> id;

                cout << "\n=== Daftar Menu ===" << endl;
                for (int i = 0; i < JUMLAH_MENU; ++i) {
                    cout << i + 1 << ". " << daftarMenu[i].nama
                         << " (" << daftarMenu[i].waktu
                         << ", Rp" << daftarMenu[i].harga << ")\n";
                }

                cout << "Pilih menu (1-" << JUMLAH_MENU << "): ";
                cin >> pilihanMenu;

                if (pilihanMenu < 1 || pilihanMenu > JUMLAH_MENU) {
                    cout << "Pilihan menu tidak valid!" << endl;
                    break;
                }

                MenuItem m = daftarMenu[pilihanMenu - 1];
                Pesanan p(id, m.nama, m.waktu, m.harga);
                antrian.tambah_pesan(p);
                cout << "Pesanan berhasil ditambahkan!" << endl;
                break;
            }
            case 2:
                antrian.display();
                break;
            case 3:
                antrian.hapus_pesan();
                break;
            case 4: {
                int id;
                cout << "Masukkan ID yang ingin dihapus: ";
                cin >> id;
                antrian.hapus_ID(id);
                break;
            }
            case 5: {
                int id;
                cout << "Masukkan ID pesanan yang ingin diupdate: ";
                cin >> id;
                antrian.update(id);
                break;
            }
            case 6: {
                int id;
                cout << "Masukkan ID pesanan yang ingin dicari: ";
                cin >> id;
                antrian.search(id);
                break;
            }
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

int main() {
    AntrianPesanan antrian_pesanan;
    menu(antrian_pesanan);
    return 0;
}
