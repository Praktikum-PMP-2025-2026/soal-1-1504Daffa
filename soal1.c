//Soal 1 Modul Praktikum 2 : Pemulihan Sensor Fragmen
// Nama : Daffa Rafandy Tarigan
// NIM : 13224068
// Modul 2 Praktikum Hari Senin 20 April 2026
#include <stdio.h>
#include <math.h>

#define MAX 1000

int main() {
    int N;
    int arr[MAX];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] == -1) {
            int kiri = -1, kanan = -1;

            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] != -1) {
                    kiri = arr[j];
                    break;
                }
            }
                
            for (int j = i + 1; j < N; j++) {
                if (arr[j] != -1) {
                    kanan = arr[j];
                    break;
                }
            }

            if (kiri != -1 && kanan != -1) {
                arr[i] = (kiri + kanan) / 2;
            } else if (kiri != -1) {
                arr[i] = kiri;
            } else if (kanan != -1) {
                arr[i] = kanan;
            } else {
                arr[i] = 0;
            }
        }
    }

    printf("RECOVERED");
    for (int i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < N; i++) {
        if (current_sum < 0) {
            current_sum = arr[i];
        } else {
            current_sum += arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("MAX_SUM %d\n", max_sum);

    return 0;
}
