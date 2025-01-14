#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Konsumen {
    char nama[50];
    int nomorAntrian;
    struct Konsumen *next;
};

struct Konsumen *buatNode(char nama[], int nomorAntrian) {
    struct Konsumen *newNode = (struct Konsumen *)malloc(sizeof(struct Konsumen));
    strcpy(newNode->nama, nama);
    newNode->nomorAntrian = nomorAntrian;
    newNode->next = NULL;
    return newNode;
}

void tambahAntrian(struct Konsumen **head, struct Konsumen **tail, char nama[]) {
    static int nomorAntrian = 0;
    struct Konsumen *newNode = buatNode(nama, ++nomorAntrian);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

struct Konsumen *panggilAntrian(struct Konsumen **head) {
    if (*head == NULL) {
        printf("\nAntrian kosong!\n");
        return NULL;
    } else {
        struct Konsumen *temp = *head;
        *head = (*head)->next;
        return temp;
    }
}

void tampilkanAntrian(struct Konsumen *head) {
    if (head == NULL) {
        printf("\nAntrian kosong!\n");
        return;
        }
    printf("\n===============================\n");
    printf("            Antrian           ");
    printf("\n===============================\n");
    while (head != NULL) {
        printf("Nama: %s, Nomor Antrian: %d\n", head->nama, head->nomorAntrian);
        head = head->next;
        }
        printf("===============================\n");
}


int main() {
    struct Konsumen *head = NULL;
    struct Konsumen *tail = NULL;
    int pilihan;

    do {
        printf("\n============================\n");
        printf("\  Program Antrian Konsumen   ");
        printf("\n============================\n");
        printf("Menu:\n");
        printf("1. Tambahkan Antrian\n");
        printf("2. Panggil Antrian\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                char nama[50];
                printf("\nMasukkan nama konsumen: ");
                scanf(" %[^\n]", nama);
                tambahAntrian(&head, &tail, nama);
                printf("Konsumen ditambahkan ke antrian!\n");
                break;
            }
            case 2: {
                struct Konsumen *konsumen = panggilAntrian(&head);
                if (konsumen != NULL) {
                    printf("\nKonsumen atas nama: %s, dengan nomor antrian: %d keluar dari antrian\n", konsumen->nama, konsumen->nomorAntrian);
                    free(konsumen);
                }
                break;
            }
            case 3:
                tampilkanAntrian(head);
                break;
            case 4:
                printf("\nKeluar dari program.\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return 0;
}
