#include <stdio.h>
#include "vc.h"
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	IVC *image,*image2,*image3;
	int x, y;
	long int pos;

	image = vc_image_new(256, 256, 1, 255);
	image2 = vc_image_new(256, 256, 1, 255);
	image3 = vc_image_new(256, 256, 1, 255);
	
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	/*VERTICAL*/

	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y* image->bytesperline + x * image->channels;

			image->data[pos] = (unsigned char)x;
		}
	}
	
	vc_write_image("gradiente.pbm", image);
	vc_image_free(image);
	

	/*HORIZONTAL*/

	for (x = 0; x < image2->width; x++)
	{
		for (y = 0; y < image2->height; y++)
		{
			pos = y* image2->bytesperline + x * image2->channels;

			image2->data[pos] = (unsigned char)y;
		}
	}

	vc_write_image("gradienteHorizontal.pbm", image2);
	vc_image_free(image2);


	/*DIAGONAL*/


	for (x = 0; x < image3->width; x++)
	{
		for (y = 0; y < image3->height; y++)
		{
			pos = y* image3->bytesperline + x * image3->channels;

			image3->data[pos] = (unsigned char)(x+y) /2;
		}
	}

	vc_write_image("gradienteDiagonal.pbm", image3);
	vc_image_free(image3);


	printf("Press any key to exit...\n");
	getchar();

	return 0;
}