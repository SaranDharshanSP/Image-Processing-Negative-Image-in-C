#include <stdio.h>
#include <stdlib.h>

// Include the stb_image and stb_image_write libraries
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(void) {
    int width, height, channels;
    unsigned char *img = stbi_load("amm.jpg", &width, &height, &channels, 0);

    if (img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    size_t img_size = width * height * channels;

    // Allocate memory for the new image
    unsigned char *nimg = malloc(img_size);
    if (nimg == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    // Check the number of channels in the image
    switch (channels) {
        case 1:
        case 2:
            // For 1 or 2 channel images, apply inversion
            for (unsigned char *a = img, *b = nimg; a != img + img_size; a += channels, b += channels) {
                *b = (uint8_t)(255 - *a);
                if (channels == 2) {
                    *(b + 1) = *(a + 1);
                }
            }
            break;

        default:
            // For 3 or 4 channel images, apply inversion channel-wise
            for (unsigned char *a = img, *b = nimg; a != img + img_size; a += channels, b += channels) {
                *b = (uint8_t)(255 - *a);
                *(b + 1) = (uint8_t)(255 - *(a + 1));
                *(b + 2) = (uint8_t)(255 - *(a + 2));
                if (channels == 4) {
                    *(b + 3) = *(a + 3);
                }
            }
    }

    // Write the inverted image to a new file
    stbi_write_("nan.jpg", width, height, channels, nimg, width * channels);

    // Free the allocated memory
    free(nimg);
}
