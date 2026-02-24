#include <stdio.h>

int main() {
    int N, kelompok, nilai_awal;
    int total = 0;

    printf("Masukkan jumlah data (N): ");
    scanf("%d", &N);
    printf("Masukkan nilai pertama (Yohana): ");
    scanf("%d", &nilai_awal);
    printf("Pilih kelompok (1: Ganjil, 2: Genap): ");
    scanf("%d", &kelompok);

    int deret[N];
    deret[0] = nilai_awal;

    for (int i = 1; i < N; i++) {
        if (i % 2 != 0) {
           
            deret[i] = deret[i-1] - 10;
        } else {
            deret[i] = deret[i-1] + 15;
        }
    }

    
    printf("\nDeret yang terbentuk: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", deret[i]);
    }

    for (int i = 0; i < N; i++) {
        int posisi = i + 1; 
        if (kelompok == 1 && posisi % 2 != 0) {
            total += deret[i];
        } else if (kelompok == 2 && posisi % 2 == 0) {
            total += deret[i];
        }
    }

    printf("\nTotal Nilai Kelompok %s: %d\n", (kelompok == 1 ? "Ganjil" : "Genap"), total);

    return 0;
}