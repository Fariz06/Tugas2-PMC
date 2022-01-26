#include <stdio.h>
#include <stdlib.h>

// 13220029 Fariz Iftikhar Falakh
// Round Robin Algorithm
// Catatan :
// 1. Tidak berhasil mengimplementasikan round robin algorithm dikarenakan
//    tidak dapat mencari exit time, di mana exit time dibutuhkan untuk menghitung Turnaround time dan waiting time
// 2. Gagal di iterasi pertama untuk menampilkan tabel output, sehingga setelah iterasi pertama, program langsung exit
// 3. Hanya dapat menampilkan tabel input dengan benar
// Rumus :  Turn Around time = Exit time – Arrival time
//          Waiting time = Turn Around time – Burst time -> Burst time bisa dibilang waktu pemrosesan
// Kemungkinan solusi : Mengimplementasikan gantt chart untuk mencari exit time
// Referensi : 1. https://www.edureka.co/blog/round-robin-scheduling-in-c/
//             2. https://www.easycodingzone.com/2021/06/c-program-of-round-robin-scheduling.html
int main()
{
    /*Kamus*/
    int jumlah_proses;
    int arr_input[100][3],i,j,k,l;
    int waktu_kuantum;
    int total,x, counter = 0, waktu_tunggu = 0, waktu_tat = 0;
    float waktu_tunggu_avg, waktu_tat_avg;


    printf("Masukkan jumlah proses : ");
    scanf("%d", &jumlah_proses);
    x = jumlah_proses;
    printf("Masukkan waktu kuantum : ");
    scanf("%d", &waktu_kuantum);

    /* Algoritma*/
    for(i=0; i<jumlah_proses; i++)
    {
        for(j=0;j<3;j++)
        {
            if (j==0)
            {
                arr_input[i][j] = i+1;
            }
            else if (j==1)
            {
                printf("Masukkan waktu kedatangan dari proses %d : ", i+1);
                scanf("%d", &arr_input[i][j]);
            }
            else
            {
                printf("Masukkan waktu pemrosesan dari proses %d : ", i+1);
                scanf("%d", &arr_input[i][j]);
                total = total + arr_input[i][j];
            }
        }
    }
    printf("\nProses ; Waktu Kedatangan ; Waktu pemrosesan\n");
    for (i = 0; i < jumlah_proses; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", arr_input[i][j]);
        }
        printf("\n");
    }
    printf("Waktu kuantum = %d\n", waktu_kuantum);
    printf("Total Waktu yang diperlukan = %d\n", total);
    printf("\nProses \t Waktu pemrosesan \t Waktu Turnaround \t Waktu Tunggu");
    for(total=0,i=0;x!=0;)
    {
        if (arr_input[i][2] < waktu_kuantum+1 && arr_input[i][2] > 0)
        {
            total = total + arr_input[i][2];
            arr_input[i][2] = 0;
            counter = 1;
        }
        else if(arr_input[i][2] > 0)
        {
            arr_input[i][2] = arr_input[i][2] - waktu_kuantum;
            total = total + waktu_kuantum;
        }
        if(arr_input[i][2] == 0 && counter == 1)
        {
            x--;
            printf("\nProses[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, arr_input[i][2], arr_input[i][2] - arr_input[i][1], total - arr_input[i][1] - arr_input[i][2]);
            waktu_tunggu = waktu_tunggu + total - arr_input[i][1] - arr_input[i][2];
            waktu_tat = waktu_tat + total - arr_input[i][1];
            counter = 0;
        }
        if(i == jumlah_proses - 1)
        {
            i = 0;
        }
        else if(arr_input[i+1][1] < total+1)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

waktu_tunggu_avg = waktu_tunggu * 1.0 / jumlah_proses;
waktu_tat_avg = waktu_tat * 1.0 / jumlah_proses;
printf("\n\n Waktu tunggu rata-rata :\t%f", waktu_tunggu_avg);
printf("\n Waktu turnaround rata-rata:\t%f\n", waktu_tat_avg);
return 0;
}
