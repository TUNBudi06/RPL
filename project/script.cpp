#include <conio.h> //sebuah header yang berfungsi mendeklarasikan getch
#include <iostream> //sebuah header standard sebagai standard input output (deklarasi cin,cout,getline )
#include <string.h> //sebuah header yang digunakan untuk mendeklarasikan sebuah variabel sebagai string
#include <Windows.h> //sebuah hedaer untuk mendeklarasikan fungsi standard windows seperti Sleep
using namespace std;

struct  tiket {
    double harga;
    string text;
};


 
void gpan(){
    cout<<("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void header() {
    cout<<(
        "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
        "                      BIOSKOP ABAL-ABAL\n"
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
    );
}

void printOut(){ //usablechar* namez,char* names[200],int jtiket,double value,double total
    system("cls");
    cout<<(
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
        " NO |   NAME                          | NO KURSI | JAM    |  NAMA FILM         | TANGGAL      |  HARGA(Rp.)\n"
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
    );
}

void editor(int kno,string nama,int kseat,string hour,string fn,string tgl,int price) {
   string no = to_string(kno),seat=to_string(kseat),harga=" "+to_string(price);
   string ed,
    nomer ="    |",
    name = "                                 |",
    kursi = "          |",
    jam = "        |",
    filmname = "                    |",
    date="              |";
    const int inomer=nomer.length(),iname=name.length(),ikursi=kursi.length(),
        ijam=jam.length(),ifilmname=filmname.length(),idate=date.length();
    
    char     new_nomer[inomer],new_name[name.length()],new_kursi[kursi.length()],
           new_jam[jam.length()],new_filmname[filmname.length()],new_date[date.length()];

    strcpy(new_nomer,nomer.c_str());strcpy(new_name,name.c_str());strcpy(new_kursi,kursi.c_str());
    strcpy(new_jam,jam.c_str());strcpy(new_filmname,filmname.c_str());strcpy(new_date,date.c_str());

    const int ino=nomer.length(),inama=nama.length(),iseat=seat.length(),
        ihour=hour.length(),ifn=fn.length(),itgl=tgl.length();
    
    int array=0,cut,iarray;
    int alllength = inomer + iname + ikursi + ijam + ifilmname + idate;
    array=0;
    for(int x=0;x<alllength;x++){
        array = array + 1;iarray = array -  1;
        if (x<inomer && x<(ino-4))       { new_nomer[array] = no[iarray];    }
        if (x <inama && x<(iname-3))     { new_name[array] = nama[iarray];   }
        if (x<iseat)                     { new_kursi[array] = seat[iarray];  }
        if (x<ihour && x<(ijam-3))      { new_jam[array] = hour[iarray];    }
        if (x<ifn && x<(ifilmname-3))   { new_filmname[array] = fn[iarray]; }
        if (x<itgl && x<(idate-3))      { new_date[array] = tgl[iarray];    }
    }
    ed +=new_nomer;ed+=new_name;ed+=new_kursi;ed= ed + new_jam + new_filmname + new_date + harga;
    cout<<ed<<endl;
}

 double disc(int x){
    int total;
    if(x<100000){
        total=x * 0.01; 
    } else if(x<200000){
        total=x*0.04;
    } else {
        total=x*0.10;
    }
    return total;
 }

 int* set_kursi(int jum_tiket){ // sebuah reference (bintang) yaitu sebagai mengalokasikan dan menyimpan sebuah array dalam suatu offset
    int x=0;
    static signed int pil_seat[64];
    //static membuat sebuah array menjadi sebuah memory tetap dan dapat dibaca oleh fungsi
    //perbedaan bahwa variabel dalam sebuah fungsi itu nilainnya tetap ketika hanya dipanggil
    //signed mendeklarasikan bahwa sbuah array tidak boleh memiliki nilai negatif
    for(int chair=1;chair<=jum_tiket;chair++){
        pilihan_seat:
        cout<<"Masukkan Kursi "<<chair<<" (maksimum kursi yang dapat dipesan 64) : ";cin>>pil_seat[chair]; 
        if (! (pil_seat[chair] <= 64)){
            cout<<"jumlah kursi maks 64"<<endl;
            Sleep(1);
            goto pilihan_seat;
        } //sebagai untuk check size number
        for(int check=1;check < chair;check++){
            if (pil_seat[check]== pil_seat[chair]){ 
                cout<<"kursi yang diketik sudah dipesan sebelumnya!!!"<<endl;
                Sleep(1);
                goto pilihan_seat;
            }
        } // sebagai untuk mengecheck apakah ada kesamaan dalam sebuah array
    }
    return pil_seat;
 }

 void stored_film(string name,string *nama,double *price){
    pilihan_film:
    int pil_film;
    system("cls");
    header();
    cout<<" Hai "<<name<<endl
    <<" Selamat datang dibioskop Abal_Abal"<<endl
    <<" Ini adalah film kami yang tersedia"<<endl
    <<" 1. ONE PIECE RED                    RP.49000"<<endl
    <<" 2. QODRAT                           Rp.47000"<<endl
    <<" 3. THE BOSS BABY 2                  Rp.50000"<<endl
    <<" 0. exit                                     "<<endl
    <<" Masukkan pilihan anda: ";
    cin>>pil_film;
    switch(pil_film){
        case 1 :
            *nama = "ONE PIECE RED";
            *price = 49000;
            break;
        case 2 :
            *nama = "QODRAT";
            *price = 47000;
            break;
        case 3 :
            *nama = "THE BOSS BABY 2";
            *price = 50000;
            break;
        case 0 :
            exit(0);
            break;
        default:
            cout<<"Masukkan Salah!!";
            Sleep(1);
            goto pilihan_film;
    }
 }



int main() { 
    tiket film;
    int jum_tiket,uang=0,total,sub;
    int tot_disc;
    string name,jam,tgl;
    system("cls");
    header();
    cout<<" Masukkan Nama Anda: ";getline(cin,name);
    stored_film(name,&film.text,&film.harga);
    
    cout<<"Masukkan Tanggal Pemesanan: ";cin>>tgl;
    cout<<"Masukkan Waktu Penayangan: ";cin>>jam;
    cout<<"Masukkan Jumlah Tiket yang Mau Dibeli: ";cin>>jum_tiket;
    int *pil_seat = set_kursi(jum_tiket){};
    cout<<"press ENTER to continuo";
    getch();

    system("cls");
    header();
    cout
    <<"Pesanan tiket atas Nama: "<<name<<endl
    <<"Nama film: "<<film.text<<endl
    <<"harga tiket: "<<film.harga<<endl
    <<"jumlah tiket yang dipesan: "<<jum_tiket<<endl
    <<"Nomor kursi yang dipesan: ";
    for(int chair=1;chair<=jum_tiket;chair++){
        cout<<pil_seat[chair];
        if(! (chair == jum_tiket)){
            cout<<",";
        }
    }
    cout<<endl
    <<"JADWAL NONTON"<<endl
    <<"Tanggal : "<<tgl<<endl
    <<"Waktu : "<<jam<<endl<<endl;
    total=film.harga*jum_tiket;
    cout<<"Total Pesanan: "<<total<<endl
    <<"Total discount: "<<disc(total)<<endl;
    tot_disc=(total-disc(total));
    cout<<"Harga yang harus dibayar: "<<tot_disc<<endl;
    cout<<"Masukkan uang anda: ";cin>>uang;
    cout<<"Press ENTER to start print tiket struk"<<endl;
    getch();

    
    printOut();
    for(int chair=1;chair<=jum_tiket;chair++){
        Sleep(0.5);
        editor(chair,name,pil_seat[chair],jam,film.text,tgl,film.harga);
    }
    gpan();
    cout 
    <<"                                                                                     UANG ANDA:"<<uang<<endl
    <<"                                                                                 TOTAL PESANAN:"<<tot_disc<<endl
    <<"                                                                              (-)--------------------------"<<endl
    <<"                                                                                SISA UANG ANDA: "<<(uang-tot_disc)<<endl;
    getch();
    return 0;
}
