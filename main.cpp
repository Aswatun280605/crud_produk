#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int pilihMenu(); // deklarasi fungsi
void chekDatabase(fstream &data); //deklarasi fungsih


int main()
{
    fstream data;
    chekDatabase(data);


   int pilihan = pilihMenu();
   char is_continue;

   while(pilihan != 5)
   {
      switch(pilihan)
      {
            case 1 :
                cout << "Menu tambah produk" << endl;
                break;
            case 2 :
                cout << "Menu lihat produk" << endl;
                break;
             case 3 :
                cout << "Menu ubah produk" << endl;
                break;
             case 4 :
                cout << "Menu hapus produk" << endl;
                break;
            default :
                cout << "Menu tidak valid" << endl;
                break;
      }

      label_continue:
      cout << "lanjutkan?[y/n] :";
      cin  >> is_continue;
      if(is_continue == 'y' | is_continue == 'Y') {
          pilihan = pilihMenu();
      } else if(is_continue == 'n' | is_continue == 'N') {
          break;
      } else {
          goto label_continue;
      }
   }


    return 0;
}
int pilihMenu()
{
     int input;
    cout << "Program CRUD Produk" << endl;
    cout << "===================" << endl;
    cout << "1. Tambah Produk" << endl;
    cout << "2. Lihat Produk" << endl;
    cout << "3. Ubah Produk" << endl;
    cout << "4. Hapus Produk" << endl;
    cout << "5. selesai" << endl;
    cout << "===================" << endl;
    cout << "masukkan pilihan?[1-5]";
    cin >> input;
    return input;
}
void chekDatabase(fstream &data)
{
    data.open("data.bin", ios::out | ios::in | ios::binary);
    if(data.is_open()) {
        cout << "database ditemukan!" << endl;
    } else {
        cout << "database belum ada, buat baru" << endl;
        data.close();
        data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);

    }
}
