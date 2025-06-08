#include <stdio.h>
#include <math.h>

// Definisi konstanta untuk simulasi
#define YEARS 100
#define INFLATION 0.03      // Inflasi tahunan (3%)
#define RETURN 0.07         // Return investasi tahunan (7%)

int main() {
    // Deklarasi variabel untuk input dan proses
    double salary, saving_rate_percent, target_expense, target_wealth, initial_asset;
    int age;

    // Input umur user
    printf("Masukkan umur saat ini: ");
    scanf("%d", &age);

    // Input gaji tahunan user
    printf("Masukkan gaji tahunan saat ini (mis. 60000000): ");
    scanf("%lf", &salary);

    // Input persentase tabungan dari gaji
    printf("Masukkan persentase tabungan dari gaji (mis. 30 untuk 30%%): ");
    scanf("%lf", &saving_rate_percent);

    // Input asset yang sudah dimiliki saat ini
    printf("Masukkan asset yang sudah dimiliki saat ini (mis. 100000000): ");
    scanf("%lf", &initial_asset);

    // Hitung saving rate dalam desimal dan pengeluaran tahunan
    double saving_rate = saving_rate_percent / 100.0;
    double expense = salary * (1 - saving_rate);

    // Hitung return riil setelah inflasi
    double real_return = (1 + RETURN) / (1 + INFLATION) - 1;

    // Inisialisasi kekayaan awal dari input user
    double W = initial_asset;
    double h = 1.0;      // Langkah waktu (tahun)
    int year = 0;        // Tahun simulasi

    // Input target pengeluaran tahunan saat financial freedom
    printf("Masukkan target pengeluaran tahunan saat ingin financial freedom (mis. 120000000): ");
    scanf("%lf", &target_expense);

    // Hitung target aset = 25 x target pengeluaran tahunan
    target_wealth = 25 * target_expense;

    // Tampilkan header tabel hasil simulasi
    printf("\nTahun\tUmur\tAsset (Rp)\t\tTarget (Rp)\n");
    printf("---------------------------------------------------------\n");

    // Buka file hasil.csv untuk menyimpan hasil simulasi
    FILE *fp = fopen("hasil.csv", "w");
    if (fp == NULL) {
        printf("Gagal membuat file hasil.csv\n");
        return 1;
    }
    // Tulis header ke file CSV
    fprintf(fp, "Tahun,Umur,Asset,Target\n");

    // Mulai simulasi pertumbuhan aset tiap tahun
    while (year < YEARS) {
        // Tampilkan dan simpan hasil tahun berjalan
        printf("%d\t%d\t%.2f\t%.2f\n", year, age + year, W, target_wealth);
        fprintf(fp, "%d,%d,%.2f,%.2f\n", year, age + year, W, target_wealth);

        // Hitung jumlah tabungan tahun ini
        double income = saving_rate * salary;

        // Metode RK4 untuk menghitung pertumbuhan aset
        // dW/dt = income + real_return * W
        double k1 = h * (income + real_return * W);
        double k2 = h * (income + real_return * (W + 0.5 * k1));
        double k3 = h * (income + real_return * (W + 0.5 * k2));
        double k4 = h * (income + real_return * (W + k3));

        // Update nilai asset (W) dengan hasil RK4
        W += (k1 + 2*k2 + 2*k3 + k4) / 6.0;

        // Update salary dan expense karena inflasi
        salary *= (1 + INFLATION);
        expense = salary * (1 - saving_rate);

        // Jika asset sudah mencapai atau melebihi target, tampilkan info dan keluar loop
        if (W >= target_wealth) {
            printf("%d\t%d\t%.2f\t%.2f\n", year+1, age + year + 1, W, target_wealth);
            fprintf(fp, "%d,%d,%.2f,%.2f\n", year+1, age + year + 1, W, target_wealth);
            printf("\n>>> Target asset tercapai di tahun ke-%d (umur %d) dengan aset Rp %.2f\n", year+1, age + year + 1, W);
            break;
        }

        // Lanjut ke tahun berikutnya
        year++;
    }

    // Jika simulasi berakhir tanpa mencapai target asset
    if (W < target_wealth) {
        printf("\n>>> Simulasi berakhir tanpa mencapai target asset.\n");
    }
    // Tutup file hasil.csv
    fclose(fp);

    return 0;
}
