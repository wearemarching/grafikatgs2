#include "canon.h"
#include <time.h>
#include <math.h> 
#include <stdio.h>

const float rad = 3.14159265/180.0;

canon prime;
//memutar kemiringan Canon ke kiri atau kanan
void puterCanon(int a) {
	prime.kemiringan += a;
}

//menggambar Canon pada buffer, posisi objek berada di dalam gambar
void gambarCanon() {
	warna x = {100,99,0,98};

	for (int i = 640; i < 950; i++) {
		for (int j = 550; j < 650; j++) {
			titik e = {j, i};	
		
			bufferDrawDot(e, x);	
		}
	}

	int theta = (prime.kemiringan);
	int range = 40;

	titik p0 = {600, 650};
	titik p1 = {600, 650-range};
	
	titik p0kiri = {570,650};
	titik p1kiri = {570,650-range};
	
	titik p0kanan = {630,650};
	titik p1kanan = {630,650-range};
	
	
	int xx = p1.x;
	int yy = p1.y;
	
	
	
	
	p1.x = ((cos(theta*rad) * (p1.x-p0.x)) - (sin(theta*rad) * (p1.y-p0.y))) + p0.x;
	p1.y = ((sin(theta*rad) * (p1.x-p0.x)) + (cos(theta*rad) * (p1.y-p0.y))) + p0.y;

	p1kiri.x = ((cos(theta*rad) * (p1kiri.x-p0kiri.x)) - (sin(theta*rad) * (p1kiri.y-p0kiri.y))) + p0kiri.x;
	p1kiri.y = ((sin(theta*rad) * (p1kiri.x-p0kiri.x)) + (cos(theta*rad) * (p1kiri.y-p0kiri.y))) + p0kiri.y;
	
	p1kanan.x = ((cos(theta*rad) * (p1kanan.x-p0kanan.x)) - (sin(theta*rad) * (p1kanan.y-p0kanan.y))) + p0kanan.x;
	p1kanan.y = ((sin(theta*rad) * (p1kanan.x-p0kanan.x)) + (cos(theta*rad) * (p1kanan.y-p0kanan.y))) + p0kanan.y;
	
	//bufferDrawLine(p0, p1, x);
	bufferDrawLine(p0kiri, p1kiri, x);
	bufferDrawLine(p0kanan, p1kanan, x);
	bufferDrawLine(p1kiri, p1kanan, x);
} 
