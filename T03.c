#include <stdio.h>
#include <string.h>

#define HARGA_PER_KG 15000

typedef struct {
    char namaPelanggan[50];
    float berat;
    // Penambahan variabel integer untuk tiap jenis
    int cp, b, s, r, kk; 
    long totalHarga;
} LaundryOrder;

int main() {
    char tanggal[20];
    int i, n;

    while (1) {
        printf("\n==================================================\n");
        printf("       SISTEM OPERASIONAL LAUNDRY DEL (V2)      \n");
        printf("==================================================\n");
        printf("Masukkan Tanggal (DD-MM-YYYY) [ketik 'EXIT' untuk keluar]: ");
        scanf("%s", tanggal);
        getchar();

        if (strcasecmp(tanggal, "EXIT") == 0) break;

        printf("Jumlah pelanggan hari ini: ");
        scanf("%d", &n);
        getchar();

        LaundryOrder orders[n];
        long pendapatanHarian = 0;

        for (i = 0; i < n; i++) {
            printf("\n--- Data Pelanggan ke-%d ---\n", i + 1);
            printf("Nama Pelanggan: ");
            fgets(orders[i].namaPelanggan, sizeof(orders[i].namaPelanggan), stdin);
            orders[i].namaPelanggan[strcspn(orders[i].namaPelanggan, "\n")] = 0;

            printf("Berat (kg): ");
            scanf("%f", &orders[i].berat);

            // Input jumlah per jenis pakaian
            printf("Input jumlah pakaian per jenis:\n");
            printf("  > Celana Panjang (CP): "); scanf("%d", &orders[i].cp);
            printf("  > Baju (B)           : "); scanf("%d", &orders[i].b);
            printf("  > Selimut (S)        : "); scanf("%d", &orders[i].s);
            printf("  > Rok (R)            : "); scanf("%d", &orders[i].r);
            printf("  > Kaos Kaki (KK)     : "); scanf("%d", &orders[i].kk);
            getchar(); // Clear buffer

            orders[i].totalHarga = orders[i].berat * HARGA_PER_KG;
            pendapatanHarian += orders[i].totalHarga;
        }

        // OUTPUT LIST BARANG & REKAPITULASI
        printf("\n\n==========================================================================\n");
        printf("REKAPITULASI LAUNDRY DEL - TANGGAL: %s\n", tanggal);
        printf("==========================================================================\n");
        printf("%-15s | %-8s | %-30s | %-12s\n", "Nama", "Berat", "List Barang", "Total Bayar");
        printf("--------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            // Membuat format string list barang secara ringkas
            char listBarang[100];
            sprintf(listBarang, "%d CP, %d B, %d S, %d R, %d KK", 
                    orders[i].cp, orders[i].b, orders[i].s, orders[i].r, orders[i].kk);

            printf("%-15s | %-5.1f kg | %-30s | Rp %-10ld\n", 
                   orders[i].namaPelanggan, orders[i].berat, listBarang, orders[i].totalHarga);
        }
        
        printf("--------------------------------------------------------------------------\n");
        printf("TOTAL PENDAPATAN HARI INI: Rp %ld\n", pendapatanHarian);
        printf("==========================================================================\n");
        
        printf("\nSesi tanggal %s selesai. Masukkan tanggal baru untuk lanjut.\n", tanggal);
    }

    return 0;
}