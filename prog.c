#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;

void header();
void alokasi();
void menu_utama();
void menu_hapus();
void menu_sisip();
void menu_sisip_awal();
void menu_sisip_akhir();
void menu_sisip_after();
void menu_sisip_before();
void menu_hapus_awal();
void menu_hapus_akhir();
void menu_hapus_after();
void sisip_awal(int);
void sisip_akhir(int);
void sisip_after(int, int);
void sisip_before(int, int);
void hapus_awal();
void hapus_akhir();
void hapus_after(int);
void tampil_list();

Node *p, *head = NULL;

main() {
	do {
		menu_utama();
	} while (1);
}

void alokasi() {
	p = (Node *) malloc(sizeof(Node));
	if (p == NULL) {
		puts("Tidak ada memori yang tersedia");
		exit(0);
	}
}

void header() {
	puts("Single Linked List --> Menu Tunggal Bertipe Integer");
	puts("Rizal Asrul Pambudi @ D4 Teknik Informatika - PENS");
	puts("Sabtu, 03 Maret 2013");
	puts("================================================================");
}

void menu_utama() {
	char pilih;

	system("cls");
	header();
	printf("\n");
	puts("MENU UTAMA");
	puts("====================");
	puts("1. Input Data");
	puts("2. Hapus Data");
	puts("3. Tampil Data");
	puts("4. Keluar");
	fflush(stdin);
	printf("Masukkan Menu: ");
	pilih = getchar();
	fflush(stdin);
	switch (pilih) {
	case '1': 
		menu_sisip();
		break;
	case '2':
		menu_hapus();
		break;
	case '3':
		tampil_list();
		break;
	case '4':
		exit(0);
	default:
		menu_utama();
	}
}

void menu_sisip() {
	char pilih;

	system("cls");
	header();
	printf("\n");
	puts("INPUT DATA");
	puts("====================");
	puts("1. Sisip Awal");
	puts("2. Sisip After");
	puts("3. Sisip Before");
	puts("4. Sisip Akhir");
	fflush(stdin);
	printf("\nMasukkan Menu: ");
	pilih = getchar();
	fflush(stdin);
	switch (pilih) {
	case '1': 
		menu_sisip_awal();
		break;
	case '2':
		menu_sisip_after();
		break;
	case '3':
		menu_sisip_before();
		break;
	case '4':
		menu_sisip_akhir();
		break;
	default:
		menu_sisip();
	}
}

void menu_hapus() {
	char pilih;

	system("cls");
	header();
	printf("\n");
	puts("HAPUS DATA");
	puts("====================");
	puts("1. Hapus Awal");
	puts("2. Hapus After");
	puts("3. Hapus Akhir");
	fflush(stdin);
	printf("\nMasukkan Menu: ");
	pilih = getchar();
	fflush(stdin);
	switch (pilih) {
	case '1': 
		menu_hapus_awal();
		break;
	case '2':
		menu_hapus_after();
		break;
	case '3':
		menu_hapus_akhir();
		break;
	default:
		menu_hapus();
	}
}

void menu_sisip_awal() {
	int x;
	char pilih;

	system("cls");
	header();
	printf("\n");
	puts("SISIP AWAL");
	puts("====================");
	do {
		printf("Masukkan Data: ");
		scanf("%d", &x);
		sisip_awal(x);
		fflush(stdin);
		printf("Lagi? ");
		pilih = getchar();
		fflush(stdin);
		printf("\n");
	} while (pilih =='y' || pilih == 'Y');
	menu_utama();
}

void menu_sisip_akhir() {
	int x;
	char pilih;

	system("cls");
	header();
	printf("\n");
	puts("SISIP AKHIR");
	puts("====================");
	do {
		printf("Masukkan Data: ");
		scanf("%d", &x);
		sisip_akhir(x);
		fflush(stdin);
		printf("Lagi? ");
		pilih = getchar();
		fflush(stdin);
		printf("\n");
	} while (pilih =='y' || pilih == 'Y');
	menu_utama();
}

void menu_sisip_after() {
	int x, y;
	char pilih;

	system("cls");
	header();
	printf("\n");
	if (head == NULL) {
		puts("Data tidak ditemukan");
		getche();
		menu_utama();
	}
	puts("SISIP AFTER");
	puts("====================");
	printf("Setelah data apa? ");
	scanf("%d", &y);
	printf("Masukkan Data: ");
	scanf("%d", &x);
	printf("\n");
	sisip_after(x,y);
	menu_utama();
}

void menu_sisip_before() {
	int x, y;
	char pilih;

	system("cls");
	header();
	printf("\n");
	if (head == NULL) {
		puts("Data tidak ditemukan");
		getche();
		menu_utama();
	}
	puts("SISIP BEFORE");
	puts("====================");
	printf("Sebelum data apa? ");
	scanf("%d", &y);
	printf("Masukkan Data: ");
	scanf("%d", &x);
	printf("\n");
	sisip_before(x,y);
	menu_utama();
}

void menu_hapus_awal() {
	system("cls");
	header();
	printf("\n");
	if (head == NULL) {
		puts("Data belum tersedia");
		getche();
	}
	else {
		hapus_awal();
		puts("Data telah terhapus");
		getche();
	}
	menu_utama();
}

void menu_hapus_after() {
	int x;

	system("cls");
	header();
	printf("\n");
	if (head == NULL) {
		puts("Data belum tersedia");
		getche();
	}
	else {
		printf("Setelah data apa? ");
		scanf("%d", &x);
		hapus_after(x);
		puts("Data telah terhapus");
		getche();
	}
	menu_utama();
}

void menu_hapus_akhir() {
	system("cls");
	header();
	printf("\n");
	if (head == NULL) {
		puts("Data belum tersedia");
		getche();
	}
	else {
		hapus_akhir();
		puts("Data telah terhapus");
		getche();
	}
	menu_utama();
}

void sisip_awal(int x) {
	alokasi();
	p->data = x;
	p->next = head;
	head = p;
}

void sisip_akhir(int x) {
	Node *tail;

	alokasi();
	p->data = x;
	p->next = NULL;
	if (head == NULL)
		sisip_awal(x);
	else {
		tail = head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = p;
	}
}

void sisip_after(int x, int y) {
	Node *after;

	alokasi();
	p->data = x;
	after = head;
	while (after->data != y) {
		after = after->next;
		if (after->next == NULL) {
			puts("Data tidak ditemukan");
			getche();
			menu_utama();
		}
	}
	p->next = after->next;
	after->next = p;
}

void sisip_before(int x, int y) {
	Node *before, *prevbefore;

	alokasi();
	p->data = x;
	before = head;
	while (before->data != y) {
		prevbefore = before;
		before = before->next;
		if (before == NULL) {
			puts("Data tidak ditemukan");
			getche();
			menu_utama();
		}
	}
	p->next = before;
	prevbefore->next = p;
}

void hapus_awal() {
	Node *hapus;

	hapus = head;
	head = hapus->next;
	free(hapus);
	hapus = NULL;
}

void hapus_after(int x) {
	Node *hapus, *after;

	after = head;
	while (after->data != x) {
		after = after->next;
		if (after->next == NULL) {
			puts("Data tidak ditemukan");
			getche();
			menu_utama();
		}
	}
	hapus = after->next;
	after->next = hapus->next;
	free(hapus);
	hapus = NULL;
}

void hapus_akhir() {
	Node *hapus, *tail;

	if (head->next == NULL)
		hapus_awal();
	else {
		hapus = head;
		while (hapus->next != NULL) {
			tail = hapus;
			hapus = hapus->next;
		}
		free(hapus);
		hapus = NULL;
		tail->next = NULL;
	}
}

void tampil_list() {
	Node *baca;

	system("cls");
	header();
	printf("\n");
	if (head == NULL)
		puts("Data tidak tersedia");
	else {
		baca = head;
		puts("TAMPIL DATA");
		puts("====================");
		while (baca != NULL) {
			printf("%d\n", baca->data);
			baca = baca->next;
		}
	}
	getche();
	menu_utama();
}