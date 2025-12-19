#include <iostream>
#include <stdio.h>
#define K 256
struct RGBbuffer{

	struct pixel{
	uint8_t px[3];};
pixel pxBFR[K];//this is 256 elements arr, but each element is pixel's type, means each elemnt is 3B arr itself
}imgLoad;

int main(){
	const *char IMG;
	uint8_t img[768];
	RGBbuffer::pixel arr;//it's 3 B array
IMG= "/home/Desktop/king/img.png" //path to img addr
file* f=fopen(IMG, "rb");
fread(img,1,768,f);
fclose();
	
	//let's take img size as 16x16x3 that's 256x3=768
for(int pixelNo=0;pixelNo<256; pixelNo++){
	for(uint8_t ch=0; ch<3; ch++){
		arr.px[ch]=img[pixelNo*3+ch];}

		imgLoad.pxBFR[pixelNo]=arr;
}

}
