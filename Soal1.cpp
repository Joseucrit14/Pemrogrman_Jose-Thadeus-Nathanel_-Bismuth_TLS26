#include <iostream>
using namespace std;
 
int main() {
    const int MAX = 1000;
    bool hidup[MAX];
    int urutanEliminasi[MAX];
    int jumlahEliminasi = 0;
 
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;
 
    if (N <= 0 || N > MAX) {
        cout << "Jumlah astronot tidak valid." << endl;
        return 0;
    }
    if (K < 2) K = 2; 
 
    for (int i = 0; i < N; i++) {
        hidup[i] = true;
    }
 
    int sisa = N;
    int idx = 0; 
 
    while (sisa > 1) {
        int count = 0;

        while (true) {
            if (hidup[idx]) {
                count++;
                if (count == K) break;
            }
            idx = (idx + 1) % N;
        }
 
        int nomorEliminasi = idx + 1;
        hidup[idx] = false;
        sisa--;
 
        urutanEliminasi[jumlahEliminasi] = nomorEliminasi;
        jumlahEliminasi++;
 
        if (nomorEliminasi % 2 == 0) {
            K = K + 2; 
        } else {
            K = K - 1; 
        }
        if (K < 2) K = 2; 
 
        idx = (idx + 1) % N;
    }
 
    int selamat = -1;
    for (int i = 0; i < N; i++) {
        if (hidup[i]) {
            selamat = i + 1;
            break;
        }
    }
 
    cout << endl;
    cout << "Urutan astronot yang dieliminasi:" << endl;
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << (i + 1) << ". Astronot nomor " << urutanEliminasi[i] << endl;
    }
 
    cout << endl;
    cout << "Astronot terakhir yang bertahan: nomor " << selamat << endl;
 
    return 0;
}