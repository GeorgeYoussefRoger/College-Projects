# **Cipher Project**
*CS112_A2_T4_S15,16_20230438_20230342_20230107.cpp*

This project is a C++ application designed to encrypt and decrypt messages using various classical cipher techniques. The program supports multiple ciphers such as the Atbash cipher, Morse code and XOR cipher. Users can input text and choose their preferred cipher method for encoding or decoding the message.

## **Features**
- Encode and decode messages using classical cipher techniques:
 - Affine Cipher
 - Route Cipher
 - Atbash Cipher
 - Vignere Cipher
 - Baconian Cipher
 - Simple Substitution Cipher
 - Polybuis Square Cipher
 - Morse Code
 - XOR Cipher
 - Rail-fence Cipher
- Error handling and user-friendly interface
- Detailed comments for code clarity

## **Usage**
Example:
1. Choose "1" for Encryption.
2. Input your message (ex. "HELLO").
3. Choose "8" for "Morse Code" 
4. The encoded Morse code will be displayed.

## **Contributions**
This project was a collaborative effort with contributions from multiple team members. Here’s a breakdown of the work:

**George Youssef:**
- Implemented the Baconian cipher, Simple Substitution cipher, and Morse code functionalities.
- Organized the code output structure and added detailed comments for clarity.

**Mina Maher:** 
- Implemented the XOR cipher, Polybuis Square cipher, and Rail-fence cipher functionalities.
- Created the the encryption menu, decryption menu and main menu.

**Mohamed Adel:** 
- Implemented the Affine cipher, Route cipher, Atbash Cipher and Vignere cipher functionalities.
- Performed code reviews and ensured error handling was in place.



# **Image Filters Program**
*CS112_A3_Part2A_S15,16_20230438_20230107_20230342.cpp*

This project is a C++ implementation of an image processing program that applies a variety of filters to images. The program utilizes an Image class designed by our Professor Dr. Mohamed El-Ramely, which provides basic image manipulation capabilities. Users can load images, apply filters such as Grayscale, Flip and Frame.

## **Features**
- Load and Save Images: Load images from files and save the processed results to new files.
- Apply Filters:
 - Grayscale: Convert the image to shades of gray.
 - Black & White: Convert the image to black and white.
 - Invert: produces a photographic negative effect, where light areas become dark and vice versa.
 - Merge: Combine two images into one with two options:
                 1. Resize the smaller image or both images to the biggest height and the biggest width and then merge.
                 2. Merge the common area of the smaller width and the smaller height.
 - Flip: Flips the image horizontally or vertically
 - Rotate: Rotate the image clockwise by 90, 180 or 270
 - Brightness: Makes the image darker or lighter by 50% from the original image.
 - Crop: Crops the image to the specified dimensions.
 - Frame: Adds a frame (a simple one or a fancy one) in the requested color.
 - Edge Detection: Identifies and highlight the boundaries of objects within an image.
 - Resize: Resizing the image to the specified dimensions.
 - Blur: Makes the image blurry.
 - Sunlight: Applies natural sunlight.
 - Purple: Makes the image look purple.
 - Infrared: produces an infrared photographic image.

## **Usage**
### Using Clion
- Make sure that the following header files are in the same directory as your main function (ex. main.cpp)
   - Image_Class.h
   - stb_image.h
   - stb_image_write.h
*Note: You will find the header files in the repo*

- Make sure that the image you wish to apply filter to is in the same directory as your main function (ex. main.cpp) and in the "cmake-build-debug" file

- Example:
  1. Choose "1" to load an image
  2. Enter the filename of the image to load (make sure its extension is .jpg or .png or .bmp or .jpeg): example.bmp
  3. Choose "2" to apply grayscale
  4. Grayscale filter applied.
  5. Choose "2" to save the image
  6. Enter a filename to save the result (make sure its extension is .jpg or .png or .bmp or .jpeg) : grayscale_example.bmp
  7. Imaged saved as grayscale_example.bmp
  8. You can find the image in the "cmake-build-debug" file

## **Contributions**
This project was a collaborative effort with contributions from multiple team members. Here’s a breakdown of the work:

**George Youssef:**
- Implemented the Grayscale, Merge, Brightness and Edge Detection filters.
- Organized the code output structure and added detailed comments for clarity.

**Mina Maher:**
- Implemented the Invert, Rotate, Frame, Blur, Sunlight and Infrared filters.
- Created the menus and the load and save image algorithms.

**Mohamed Adel:**
- Implemented the Black & White, Flip, Crop, Resize and Purple filters.
- Performed code reviews and ensured error handling was in place.

## Image Class
The Image class, provided by the professor, serves as the backbone of the project, handling all the core operations related to image manipulation, including:
- Loading and saving (.jpg or .png or .bmp or .jpeg) files.
- Accessing and modifying pixel data.
- Supporting various color channels (RGB) for image processing.
