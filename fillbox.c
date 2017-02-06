#include <linux/fb.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

typedef struct{
	int x;
	int y;
} point;

struct fb_fix_screeninfo finfo;
struct fb_var_screeninfo vinfo;
long screensize;
uint8_t *fbp;
int fb_fd;

uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo);
inline uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo)
{
    return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}

void drawLine(point start, point finish, int deltax, int deltay, int p){
	int p1;
	while( (start.x != finish.x) || (start.y != finish.y)){
		if(start.y == finish.y){
		while(start.x < finish.x){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 255;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 0;
			start.x++;
		}
		}
		else if(start.x == finish.x){
			while(start.y < finish.y){
				long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
				*(fbp + location) = 255;
				*(fbp + location +1) = 0;
				*(fbp + location +2) = 0;
				*(fbp + location + 3) = 0;
				start.y++;
			}
		}
		else{
			long long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 255;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 0;

			if(p>=0){
				start.x++;
				start.y++;
				p1 = p + 2*deltay - 2*deltax;
			}
			else{
				start.x++;
				p1 = p + 2*deltay;
			}
		}
	}
	
}

void drawLinex(point start, point finish, int deltax, int deltay, int p){
	int p1;
	while( (start.x != finish.x) || (start.y != finish.y)){
		if(start.y == finish.y){
		while(start.x < finish.x){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 255;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;
			start.x++;
		}
		}
		else if(start.x == finish.x){
			while(start.y < finish.y){
				long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
				*(fbp + location) = 0;
				*(fbp + location +1) = 255;
				*(fbp + location +2) = 0;
				*(fbp + location + 3) = 50;
				start.y++;
			}
		}
		else{
			long long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 255;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;

			if(p>=0){
				start.x++;
				start.y++;
				p1 = p + 2*deltay - 2*deltax;
			}
			else{
				start.x++;
				p1 = p + 2*deltay;
			}
		}
	}
	
}

void drawLine2(point start, point finish, int deltax, int deltay, int p){
	int p1;
	if(start.y == finish.y){
		while(start.x <= finish.x){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 255;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;
			start.x++;
		}
	}
	else if(start.x == finish.x){
		while(start.y >= finish.y){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 255;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;
			start.y--;
		}
	}
	else{
		long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
		*(fbp + location) = 255;
		*(fbp + location +1) = 0;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		if(p>=0){
			start.x++;
			start.y--;
			p1 = p + 2*deltay - 2*deltax;
		}
		else{
			start.x++;
			p1 = p + 2*deltay;
		}
		drawLine2(start,finish,deltax,deltay,p1);
	}
}

void drawLine2x(point start, point finish, int deltax, int deltay, int p){
	int p1;
	if(start.y == finish.y){
		while(start.x <= finish.x){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 255;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;
			start.x++;
		}
	}
	else if(start.x == finish.x){
		while(start.y >= finish.y){
			long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 255;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 50;
			start.y--;
		}
	}
	else{
		long location = (start.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (start.y+vinfo.yoffset) * finfo.line_length;
		*(fbp + location) = 0;
		*(fbp + location +1) = 255;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		if(p>=0){
			start.x++;
			start.y--;
			p1 = p + 2*deltay - 2*deltax;
		}
		else{
			start.x++;
			p1 = p + 2*deltay;
		}
		drawLine2x(start,finish,deltax,deltay,p1);
	}
}

void cetakHitam(int x, int y){
    long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
	*(fbp + location) = 0;
	*(fbp + location +1) = 0;
	*(fbp + location +2) = 0;
	*(fbp + location + 3) = 0;
}

void cetakPutih(int x, int y){
    long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
	*(fbp + location) = 255;
	*(fbp + location +1) = 255;
	*(fbp + location +2) = 255;
	*(fbp + location + 3) = 0;
}

void cetakBlank(){
    int x,y;
	for (y=0;y<vinfo.yres;y++)
	{
		for (x=0;x<vinfo.xres;x++){
			long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 0;
		}
	}
}

void drawBeam(point start, point finish, int deltax, int deltay, int p){	
	int p1;
	if(start.y == finish.y) { // garis ke kiri - BELUM BISA
		while(start.x <= finish.x) {
			cetakPutih(start.x, start.y);
			start.x += 10;
		}
	}
	else if(start.x == finish.x) { // garis lurus keatas
		while(start.y >= finish.y) {
			// Beam-like shooter - not using draw_circle()
			int savey = start.y;
			for(int i = 0; i < 10 && start.y>=finish.y ; i++) { // cetak 10 pixel biar seperti beam
				cetakPutih(start.x, start.y);
				start.y -= 1;
			}

			usleep(5000);
			for(int i = 0; i < 10 && savey>=finish.y ; i++) { // timpa beam yang sudah dicetak dengan hitam
				cetakHitam(start.x, savey);
				savey -= 1;
			}

		}
		
	}
	else {
		if(p>=0) { // garis miring gradien positif
			// Beam-like shooter - not using draw_circle()
			int savex = start.x;
			int savey = start.y;
			for(int i = 0; i < 10; i++) { // cetak 10 pixel biar seperti beam
				cetakPutih(start.x, start.y);
				start.x += 1;
				start.y -= 1;
			}
			usleep(5000);
			for(int i = 0; i < 10; i++) { // timpa beam yang sudah dicetak dengan hitam

				cetakHitam(savex, savey);
				savex += 1;
				savey -= 1;
			}
			p1 = p + 2*deltay - 2*deltax;
		}
		else { // ini ngga tau buat apa, ngga pernah masuk sini
			start.x++;
			p1 = p + 2*deltay;
		}
		drawBeam(start,finish,deltax,deltay,p1);
	}
}



void solidFill(point firepoint){
	point fp;
	fp.x = firepoint.x+1;
	fp.y = firepoint.y;
	long location = (fp.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (fp.y+vinfo.yoffset) * finfo.line_length;
	if(*(fbp + location)==0 && *(fbp + location +1)==0 && *(fbp + location +2) ==0){
		*(fbp + location) =255;
		*(fbp + location +1) = 0;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		solidFill(fp);
	}
	
	fp.x = firepoint.x-1;
	fp.y = firepoint.y;
	location = (fp.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (fp.y+vinfo.yoffset) * finfo.line_length;
	if(*(fbp + location)==0 && *(fbp + location +1)==0 && *(fbp + location +2) ==0){
		*(fbp + location) =255;
		*(fbp + location +1) = 0;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		solidFill(fp);
	}

	fp.x = firepoint.x;
	fp.y = firepoint.y+1;
	location = (fp.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (fp.y+vinfo.yoffset) * finfo.line_length;
	if(*(fbp + location)==0 && *(fbp + location +1)==0 && *(fbp + location +2) ==0){
		*(fbp + location) =255;
		*(fbp + location +1) = 0;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		solidFill(fp);
	}

	fp.x = firepoint.x;
	fp.y = firepoint.y-1;
	location = (fp.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (fp.y+vinfo.yoffset) * finfo.line_length;
	if(*(fbp + location)==0 && *(fbp + location +1)==0 && *(fbp + location +2) ==0){
		*(fbp + location) =255;
		*(fbp + location +1) = 0;
		*(fbp + location +2) = 0;
		*(fbp + location + 3) = 50;
		solidFill(fp);
	}
}

int main()
{
	fb_fd = open("/dev/fb0",O_RDWR);

	//Get variable screen information
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);
	vinfo.grayscale=0;
	vinfo.bits_per_pixel=32;
	ioctl(fb_fd, FBIOPUT_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);


	screensize = vinfo.yres_virtual * finfo.line_length;

	fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);

	int x,y;

	cetakBlank();
	int arr = 5;
	point p[arr];
	int k = 180;
	p[0].x = 0+k;
	p[0].y = 0+k;
	
	p[1].x = 0+k;
	p[1].y = 50+k;
	
	p[2].x = 50+k;
	p[2].y = 50+k;
	
	p[3].x = 50+k;
	p[3].y = 0+k;
	
	p[4].x = 0+k;
	p[4].y = 0+k;
	
	point fp;
	fp.x = 25+k;
	fp.y = 25+k;
	
	//n faktor penambah buat bikin animasi
	for(int n=0; n<120; n+=20){
		point temp;
		temp.x = fp.x+n;		
		temp.y = fp.y;
		cetakBlank();
		for(int i=0; i<arr-1; i++){
			point start, finish;
			//kalo start x nya dikanan, di swap dlu
			if(p[i].x>p[i+1].x){
				start = p[i+1];
				finish = p[i];
			}
			else{
				start = p[i];
				finish = p[i+1];
			}
			start.x+=n;
			finish.x+=n;
			
			//rumus bersenham itu
			int deltay = finish.y - start.y;
			int deltax = finish.x - start.x;
			int px = 2*deltay -deltax;
			//kalo start y > finish y pake drawline2
			if(deltay < 0){
				deltay = deltay * -1;
				drawLine2(start,finish,deltax,deltay,px);
			}
			else{
				drawLine(start,finish,deltax,deltay,px);
			}
		}
		solidFill(temp);
		if(n+20 < 120)
			usleep(150000);

		
	}	
	usleep(300000);
	cetakBlank();
	return 0;
}
