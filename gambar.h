#ifndef GAMBAR_H
#define GAMBAR_H


// variabel statik global buffer_*
// tipe data titik, warna
#include "glob_var_type.h"


unsigned char buffer_r[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
unsigned char buffer_g[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
unsigned char buffer_b[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
unsigned char buffer_a[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];

// Melakukan assign warna c pada 
// posisi c pada matriks framebuffer
void bufferDrawDot(titik p, warna c);

//memasukka warna pixel pada driver
void DrawDot(titik p, warna c);

// Melakukan assign warna default ke matriks 
// buffer (bukan matriks framebuffer) berupa
// segi empat yang dibentuk oleh dua titik p0 dan p1
void refreshBuffer(titik p0, titik p1);

// Memuat/assign nilai dari matriks buffer
// ke matriks framebuffer.
void loadBuffer();


//================================================
void bufferDrawLine(titik p0, titik p1, warna c);	//mmengganti nilai pixel sehingga tergambar garis dari p0 ke p1


#endif //GAMBAR_H
