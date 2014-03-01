#include<stdio.h>
#include<stdlib.h>
#include"vc.h"

int main(void)
{
	IVC *image,*image2;

	image = vc_read_image("../Images/Classic/lenna.ppm");
	image2 = vc_read_image("../Images/HSVTestImage01.ppm");

	if(image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	vc_rgb_to_hsv(image);
	vc_write_image("HSVTeste_out.ppm",image);
	vc_image_free(image);

	/*Extrair Amarelo*/
	vc_rgb_to_hsv_get_yellow(image2);
	vc_write_image("HVT_Extract_Yellow.ppm", image2);
	vc_image_free(image2);

	//system("FilterGear HSVTeste_out.ppm");

	printf("Press any key...");
	getchar();

	return 1;
}