#include<stdio.h>
#include<stdlib.h>
#include"vc.h"

int main(void)
{
	IVC *image,*image2,*image3;

	image = vc_read_image("Images/Additional/fruits.ppm");
	image2 = vc_read_image("Images/Additional/fruits.ppm");
	image3 = vc_read_image("Images/Additional/fruits.ppm");

	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	vc_rgb_get_red_gray(image);
	vc_write_image("fruits_get_red.ppm", image);
	vc_image_free(image);

	vc_rgb_get_red_gray(image2);
	vc_write_image("fruits_get_green.ppm", image2);
	vc_image_free(image2);

	vc_rgb_get_blue_gray(image3);
	vc_write_image("fruits_get_green.ppm", image3);
	vc_image_free(image3);

	system("FilterGear fruits_get_red.ppm");

	printf("Press any key...");
	getchar();

	return 1;
}