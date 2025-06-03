#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Pesanan {
    public:
    int ID_pesanan;
    string nama_pesanan;
    string waktu;
    int harga;

    Pesanan(int ID,string nm, string w, int h) {
        ID_pesanan = ID;
        nama_pesanan = nm;
        waktu = w;
        harga = h;
    }
};

class AntrianPesanan{
    private:
    queue<Pesanan> pesan;
    public:
    void tambah_pesan(Pesanan pesanan){
        pesan.push(pesanan);
    }

    void hapus_pesan(){
        if (!pesan.empty()) {
            pesan.pop();
        } else {
            cout << "Antrian kosong" << endl;
        }
    }

    void display() {
        queue<Pesanan> temp = pesan;
        if(pesan.empty()){
            cout<<"Antrian pesanan kosong"<<endl;
            return;
        }else{
            while(!temp.empty()){
                Pesanan current = temp.front();
                cout<<"ID pesanan : "<<current.ID_pesanan<<" ";
                cout<<"Nama pesanan : "<<current.nama_pesanan<<" ";
                cout<<"Lama pesanan : "<<current.waktu<<" ";
                cout<<"Harga pesanan : Rp"<<current.harga<<endl<<" ";
                temp.pop();
            }
        }
    }

    bool hapus_ID(int id_pilihan){
        if(pesan.empty()){
            cout<<"Antrian kosong"<<endl;
            return false;
        }
        queue<Pesanan> temp;
        bool found = false;
        while(!pesan.empty()){
            Pesanan current = pesan.front();
            pesan.pop();
            if(current.ID_pesanan == id_pilihan){
                found = true;
            }else{
                temp.push(current);
            }
        }
        pesan = temp;
        if(!found){
            cout<<"Tidak ada pesanan"<<endl;
        }
        return found;
    }

    
};

int main (){
    AntrianPesanan antrian_pesanan;

    Pesanan p1(101, "Nasi Goreng Spesial", "15 menit", 25000);
    Pesanan p2(202, "Mie Ayam Bakso", "10 menit", 18000);
    Pesanan p3(305, "Soto Ayam Lamongan", "20 menit", 22000);
    Pesanan p4(101, "Nasi Goreng Gila", "18 menit", 27000); // ID sama dengan p1
    Pesanan p5(400, "Gado-Gado", "12 menit", 15000);


    antrian_pesanan.tambah_pesan(p1);
    antrian_pesanan.tambah_pesan(p2);
    antrian_pesanan.tambah_pesan(p3);
    antrian_pesanan.tambah_pesan(p4);
    antrian_pesanan.tambah_pesan(p5);

    cout << "Antrian Awal:"<<endl;
    antrian_pesanan.display();

    cout << "\nMenghapus pesanan dengan ID 202 (Mie Ayam Bakso):" << endl;
    if (antrian_pesanan.hapus_ID(202)) {
        cout << "Penghapusan berhasil." << endl;
    } else {
        cout << "Penghapusan gagal." << endl;
    }
    antrian_pesanan.display();

    cout << "\nMenghapus pesanan dengan ID 999 (tidak ada):" << endl;
    antrian_pesanan.hapus_ID(999);
    antrian_pesanan.display();

    cout << "\nMenghapus pesanan dengan ID 101 (akan menghapus semua yang cocok):" << endl;
    // Implementasi ini akan menghapus SEMUA pesanan dengan ID yang cocok
    // Jika hanya ingin menghapus satu, modifikasi diperlukan
    antrian_pesanan.hapus_ID(101);
    antrian_pesanan.display();
    
    cout << "\nMenghapus pesanan depan:" << endl;
    antrian_pesanan.hapus_pesan();
    antrian_pesanan.display();

    return 0;
    }
