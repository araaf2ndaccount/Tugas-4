#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

/*
    Nama : Mamet Adil Araaf
    Nim  : A11.2017.10656
*/

using namespace std;

int main()
{
    vector< vector<string> > items {{"item1","1"},{"item2","2"},{"item3","3"},{"item4","4"},{"item5","5"}};
    vector<int>::iterator it;
    vector<int>inventory;
    int maks_invent;
    bool first= true;

    cout<< "Jumlah Item : "<< items.size() << endl;
    cout<< "Masukkan maksimal inventory : ";
    cin>>maks_invent;
    while(first){
        cout << "\nINVENTORY MENU" << endl;
        cout << "1. Tampilkan Inventory" <<endl;
        cout << "2. Tambah Item" <<endl;
        cout << "3. Hapus Item" <<endl;
        int pilihan;
        cout << "Masukkan Pilihan Menu Anda : ";
        cin >> pilihan;
        switch(pilihan){
            case 1 :
                if(inventory.empty()){
                    cout<<"Inventorymu Kosong Isikan Segera !!"<< endl;
                }
                else{
                    int i=1;
                    for(it=inventory.begin(); it!=inventory.end(); it++){
                        cout << i << ". " << items[*it][0] << ", stat : " << items[*it][1] << endl;
                        i++;
                    }
                }
                break;
            case 2 :
                if(maks_invent == inventory.size()){
                    cout << "Inventory Anda Penuh Segera Hapus" << endl;
                }
                else{
                    srand(static_cast<unsigned int>(time(0)));
                    int item_random;
                    item_random = rand()%items.size();
                    cout << "Anda Mendapatkan Item : " << items[item_random][0] << "\nStats : " << items[item_random][1] << endl;
                    inventory.push_back(item_random);
                    cout << "Jumlah Inventorymu Sekarang : " << inventory.size() << endl;
                }
            break;
            case 3 :
                if(inventory.empty()){
                    cout << "Inventory masih kosong" << endl;
                }
                else{
                    int hapus;
                    int i=1;
                    for(it=inventory.begin(); it!=inventory.end(); it++){
                            cout << i << ". " << items[*it][0] << ", stat : " << items[*it][1] << endl;
                            i++;
                    }
                    cout << "Hapus Item ke- :  ";
                    cin >> hapus;
                    inventory.erase(inventory.begin()+hapus-1);
                    cout << "Jumlah Inventorymu Sekarang : " << inventory.size() << endl;
                }
            break;
            default :
                cout << "Pilian Tidak Tersedia" << endl;
                first = false;
        }

    }
    return 0;
}
