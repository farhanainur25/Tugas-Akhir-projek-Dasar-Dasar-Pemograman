#include <iostream>
using namespace std;

void gambarPapan(char papan[3][3]) { // Fungsi untuk menggambar papan permainan
    cout << "--------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| " << papan[i][0] << " | " << papan[i][1] << " | " << papan[i][2] << " |\n";
        cout << "-------------\n";
    }
}

bool cekPemenang(char papan[3][3], char simbol) {  // Fungsi untuk mengecek apakah ada pemenang
    for (int i = 0; i < 3; i++) {                  // Cek baris dan kolom
        if (papan[i][0] == simbol && papan[i][1] == simbol && papan[i][2] == simbol)
            return true;                           // Ada pemenang
        if (papan[0][i] == simbol && papan[1][i] == simbol && papan[2][i] == simbol)
            return true;                          // Ada pemenang
    }
    if (papan[0][0] == simbol && papan[1][1] == simbol && papan[2][2] == simbol)      // Cek diagonal
        return true;       // Ada pemenang
    if (papan[0][2] == simbol && papan[1][1] == simbol && papan[2][0] == simbol)
        return true;        // Ada pemenang
    return false;
}

bool cekSeri(char papan[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
	
	cout <<"==================================================="<<endl;
	cout <<"||            UNIVERSITAS AHMAD DAHLAN           ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"|| Nama   : Farhan Ainur Rahmat                  ||"<<endl;
	cout <<"|| NIM    : 2300018026                           ||"<<endl;
	cout <<"|| Kelas  : A                                    ||"<<endl;
	cout <<"|| Tugas  : DASAR DASAR PEMOGRAMAN               ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"||                S1 INFORMATIKA                 ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"||           SELAMAT DATANG DI PERMAINAN         ||"<<endl;
	cout <<"||                  TIC TAC TOE                  ||"<<endl;
	cout <<"==================================================="<<endl;
	
    char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    string namaPemainX, namaPemainO, kelasPemainX, kelasPemainO;
    char pemainSekarang = 'X';
    int baris, kolom;

    cout << "Masukkan nama pemain X: ";
    getline(cin, namaPemainX);
    cout << "Masukkan kelas pemain X: ";
    getline(cin, kelasPemainX);

    cout << "Masukkan nama pemain O: ";
    getline(cin, namaPemainO);
    cout << "Masukkan kelas pemain O: ";
    getline(cin, kelasPemainO);

    do {
        gambarPapan(papan);

        cout << "Giliran pemain " << ((pemainSekarang == 'X') ? namaPemainX : namaPemainO) << " (" << ((pemainSekarang == 'X') ? kelasPemainX : kelasPemainO) << ")\n";
        cout << "Masukkan baris (0-2) dan kolom (0-2) yang ingin diisi (pisahkan dengan spasi): ";
        cin >> baris >> kolom;

        if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2 || papan[baris][kolom] != ' ') {
            cout << "Input tidak valid. Coba lagi.\n";
            continue;
        }

        papan[baris][kolom] = pemainSekarang;

        if (cekPemenang(papan, pemainSekarang)) {
            gambarPapan(papan);
            cout << "Selamat! Pemain " << pemainSekarang << " (" << ((pemainSekarang == 'X') ? namaPemainX : namaPemainO) << ") menang!\n";
            cout << "TERIMA KASIH TELAH PERMAINAN TIC TAC TOE KAMI !!"<<endl;
            break;
        }

        if (cekSeri(papan)) {
            gambarPapan(papan);
            cout << "Permainan seri!\n";
            break;
        }

        pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X';

    } while (true);

    char jawaban;
    cout << "Apakah anda Ingin bermain lagi? (y/n): ";
    cin >> jawaban;

    if (jawaban == 'y' || jawaban == 'Y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                papan[i][j] = ' ';
            }
        }
        pemainSekarang = 'X';
        main();
    }

    return 0;
}
