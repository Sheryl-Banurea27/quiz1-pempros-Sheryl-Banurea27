#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char kode[5];
    char nama[30];
    int harga;
} Menu;

Menu daftarMenu[] = {
    {"NGS", "Nasi Goreng Spesial", 15000},
    {"AP",  "Ayam Penyet", 20000},
    {"SA",  "Sate Ayam (10 Tusuk)", 25000},
    {"BU",  "Bakso Urat", 18000},
    {"MAP", "Mie Ayam Pangsit", 15000},
    {"GG",  "Gado-Gado", 15000},
    {"SAM", "Soto Ayam", 17000},
    {"RD",  "Rendang Daging", 25000},
    {"IB",  "Ikan Bakar", 35000},
    {"NUK", "Nasi Uduk Komplit", 20000}
};

int main() {
    char inputKode[10];
    int porsiButet;
    
    char pesananNama[50][30];
    int pesananPorsi[50];
    int pesananHarga[50];
    long pesananTotal[50];
    int jumlahPesanan = 0;
    long totalSeluruhnya = 0;

    printf("--- Input Pesanan (Ketik 'END' untuk selesai) ---\n");

    while (1) {
        scanf("%s", inputKode);
        if (strcmp(inputKode, "END") == 0) break;

        scanf("%d", &porsiButet);
        
        int ditemukan = -1;
        for (int i = 0; i < 10; i++) {
            if (strcmp(inputKode, daftarMenu[i].kode) == 0) {
                ditemukan = i;
                break;
            }
        }

        if (ditemukan != -1) {
            int totalPorsi = porsiButet * 3; 
            strcpy(pesananNama[jumlahPesanan], daftarMenu[ditemukan].nama);
            pesananPorsi[jumlahPesanan] = totalPorsi;
            pesananHarga[jumlahPesanan] = daftarMenu[ditemukan].harga;
            pesananTotal[jumlahPesanan] = (long)totalPorsi * daftarMenu[ditemukan].harga;
            
            totalSeluruhnya += pesananTotal[jumlahPesanan];
            jumlahPesanan++;
        }
    }

    char kupon[10] = "Tanpa";
    int diskonPersen = 0;

    if (totalSeluruhnya >= 500000) { strcpy(kupon, "Hitam"); diskonPersen = 25; }
    else if (totalSeluruhnya >= 400000) { strcpy(kupon, "Hijau"); diskonPersen = 20; }
    else if (totalSeluruhnya >= 300000) { strcpy(kupon, "Merah"); diskonPersen = 15; }
    else if (totalSeluruhnya >= 200000) { strcpy(kupon, "Kuning"); diskonPersen = 10; }
    else if (totalSeluruhnya >= 100000) { strcpy(kupon, "Biru"); diskonPersen = 5; }

    long potongan = totalSeluruhnya * diskonPersen / 100;
    long bayarAkhir = totalSeluruhnya - potongan;

    printf("\n%-25s %-7s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("========================================================\n");
    for (int i = 0; i < jumlahPesanan; i++) {
        printf("%-25s %-7d %-10d %-10ld\n", pesananNama[i], pesananPorsi[i], pesananHarga[i], pesananTotal[i]);
    }
    printf("========================================================\n");
    printf("Total Belanja      : Rp %ld\n", totalSeluruhnya);
    printf("Kupon Didapat      : Kupon %s (%d%%)\n", kupon, diskonPersen);
    printf("Potongan Diskon    : Rp %ld\n", potongan);
    printf("--------------------------------------------------------\n");
    printf("Total Pembayaran   : Rp %ld\n", bayarAkhir);

    return 0;
}