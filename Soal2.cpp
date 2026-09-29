#include <iostream>
using namespace std;

int main() {
    const int MAX = 200;
    char pesan[MAX];
    int n = 0;

    cout << "=== PROGRAM SANDI ALIEN ===" << endl;
    cout << "Masukkan pesan yang ingin disandikan: ";

    char c;
    while (cin.get(c)) {
        if (c == '\n') break;
        if (n < MAX - 1) {
            pesan[n] = c;
            n++;
        }
    }
    pesan[n] = '\0';

    char hasil[MAX];
    int prevNilai = 0; 

    for (int i = 0; i < n; i++) {
        char asli = pesan[i];
        char huruf = asli;

        bool isLowercase = (huruf >= 'a' && huruf <= 'z');


        if (isLowercase) {
            huruf = huruf - 'a' + 'A';
        }

    
        if (huruf < 'A' || huruf > 'Z') {
            hasil[i] = asli;
            continue;
        }

        int nilaiAsli = huruf - 'A' + 1;      
        int geseran = (i == 0) ? 0 : prevNilai; 

        int nilaiBaru = (nilaiAsli + geseran - 1) % 26 + 1;

        char hurufBaru = 'A' + (nilaiBaru - 1);
        hasil[i] = isLowercase ? (hurufBaru - 'A' + 'a') : hurufBaru;
        prevNilai = nilaiAsli; 
    }
    hasil[n] = '\0';

    cout << endl;
    cout << "Pesan asli   : " << pesan << endl;
    cout << "Pesan sandi  : " << hasil << endl;

    return 0;
}