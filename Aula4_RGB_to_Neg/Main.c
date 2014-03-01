#include<stdio.h>
#include<stdlib.h>
#include "vc.h"

int main(void)
{
	IVC *image;
	
	image = vc_read_image("../Images/Additional/cablecar.ppm");
	
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	vc_rgb_negative(image);

	vc_write_image("rgb_to_negative.ppm", image);

	vc_image_free(image);

	//system("FilterGear rgb_to_negative.ppm");

	printf("Press any key...");
	getchar();

	return 1;
}