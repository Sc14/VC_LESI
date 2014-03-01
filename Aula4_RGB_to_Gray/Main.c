#include<stdio.h>
#include<stdlib.h>
#include"vc.h"

int main(void)
{
	IVC *image[2]; //IVC *image,*image2;

	image[0] = vc_read_image("../Images/Additional/yacht.ppm");
	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);

	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	vc_rgb_to_gray(image[0],image[1]);
	vc_write_image("yacht_to_gray.ppm", image[1]);
	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("FilterGear yacht_to_gray.ppm");

	printf("Press any key...");
	getchar();

	return 1;
}