# Image Processing using STB Image Library

![Repository Banner](https://socialify.git.ci/SaranDharshanSP/Image-Processing-Negative-Image-in-C/image?font=KoHo&language=1&name=1&owner=1&pattern=Floating%20Cogs&stargazers=1&theme=Dark)

This repository contains a simple C program for image processing using the STB Image library. The program loads an image, performs pixel manipulation, and saves the result as a new image.

## Getting Started

### Prerequisites

- [STB Image Library](https://github.com/nothings/stb) (already included in the repository)

### Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/SaranDharshanSP/Image-Processing-Negative-Image-in-C.git
   cd your-repo
   ```

2. Compile the program:

   ```sh
   gcc -o Image-Processing-Negative-Image-in-C image_processing.c -lm
   ```

## Usage

1. Make sure you have an image named `amm.jpg` in the same directory as the executable.

2. Run the compiled program:

   ```sh
   ./image_processing
   ```

   The program will process the image, create a new image named `nan.jpg`, and save it in the same directory.

## Example

| Input Image | Output Image |
|-------------|--------------|
| [Input Image]() | [Output Image]() |

## Description

This program demonstrates basic image processing using the STB Image library. The following steps are performed:

1. Load an image named `amm.jpg`.
2. Determine the image's width, height, and number of color channels.
3. Allocate memory for a new image (`nimg`) to store the manipulated pixels.
4. Depending on the number of channels, invert pixel values:
   - For grayscale images (1 or 2 channels), invert pixel values.
   - For RGB images (3 channels), invert each channel's pixel value.
5. Save the manipulated image as `nan.jpg`.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to open an issue or submit a pull request.


