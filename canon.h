#include "gambar.h"

typedef struct{
	int kemiringan; //kemiringan moncong Canon, kemiringan peluru yang keluar
}canon;

extern canon prime;

void puterCanon(int a); //memutar kemiringan Canon ke kiri atau kanan
void gambarCanon(); //menggambar Canon pada buffer, posisi objek berada di dalam gambar
