/*
Program: This program contains a number of filters that you can apply to your images.
Authors: George Youssef Roger
*/

#include "Image_Class.h"
using namespace std;

// Global pointer to hold the current image
Image* ptr = nullptr;

// Function prototypes
void mainmenu();
void applyFilter(Image& image);
void save_image();

void gray(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= image.channels;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = avg;
            }
        }
    }
}

void merge(Image& img) {
    cout << "Enter The Name of the Second Image with (.png, .jpeg, .jpg, .bmp):";
    string photo2;
    cin >> photo2;
    Image img2(photo2);
    while (true) {
        try {
            img2.loadNewImage(photo2);
            break;
        }
        catch (invalid_argument) {
            cout << "Invalid Photo" << endl;
            merge(img);
        }
    }
    cout << "Choose:\n";
    cout << "1. Resize to the biggest width and height\n";
    cout << "2. Merge the common area of the smaller width and height\n==>";
    string choice;
    cin >> choice;
    if (choice == "1") {
        int new_width = (img.width > img2.width) ? img.width : img2.width;
        int new_height = (img.height > img2.height) ? img.height : img2.height;
        Image resized_image1(new_width, new_height);
        Image resized_image2(new_width, new_height);

        // Resize img1
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                int orig_width = i * img.width / new_width;
                int orig_height = j * img.height / new_height;
                for (int k = 0; k < img.channels; k++) {
                    resized_image1.setPixel(i, j, k, img.getPixel(orig_width, orig_height, k));
                }
            }
        }

        // Resize img2
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                int orig_width = i * img2.width / new_width;
                int orig_height = j * img2.height / new_height;
                for (int k = 0; k < img2.channels; k++) {
                    resized_image2.setPixel(i, j, k, img2.getPixel(orig_width, orig_height, k));
                }
            }
        }

        // Merge the resized images
        Image merged_image(new_width, new_height);
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                for (int k = 0; k < img.channels; k++) {
                    int pixel1 = resized_image1.getPixel(i, j, k);
                    int pixel2 = resized_image2.getPixel(i, j, k);
                    merged_image.setPixel(i, j, k, max(pixel1, pixel2));
                }
            }
        }
        img = merged_image;
    }

    else if (choice == "2") {
        int new_width = (img.width > img2.width) ? img2.width : img.width;
        int new_height = (img.height > img2.height) ? img2.height : img.height;
        Image resized_image1(new_width, new_height);
        Image resized_image2(new_width, new_height);

        // Resize img1
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                int orig_width = i * img.width / new_width;
                int orig_height = j * img.height / new_height;
                for (int k = 0; k < img.channels; k++) {
                    resized_image1.setPixel(i, j, k, img.getPixel(orig_width, orig_height, k));
                }
            }
        }

        // Resize img2
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                int orig_width = i * img2.width / new_width;
                int orig_height = j * img2.height / new_height;
                for (int k = 0; k < img2.channels; k++) {
                    resized_image2.setPixel(i, j, k, img2.getPixel(orig_width, orig_height, k));
                }
            }
        }

        // Merge the resized images
        Image merged_image(new_width, new_height);
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                for (int k = 0; k < img.channels; k++) {
                    int pixel1 = resized_image1.getPixel(i, j, k);
                    int pixel2 = resized_image2.getPixel(i, j, k);
                    merged_image.setPixel(i, j, k, max(pixel1, pixel2));
                }
            }
        }
        img = merged_image;
    }

    else {
        cout << "Invalid Choice\n";
        merge(img);
    }
}

void brightness(Image& img) {
    float percentage;
    cout << "Enter the percentage to adjust brightness (-50 to 50):";
    if (!(cin >> percentage)) {
        cout << "Invalid input. Please enter a number." << endl;
        // Clear the error state of cin and ignore the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        brightness(img);
    }
    if (percentage >= -50 && percentage <= 50) {
        float factor = 1 + (percentage / 100);
        for (int i = 0; i < img.width; i++) {
            for (int j = 0; j < img.height; j++) {
                for (int k = 0; k < img.channels; k++) {
                    // Calculate index of current pixel in the image array
                    int index = (j * img.width + i) * img.channels + k;
                    // Calculate new pixel value
                    int new_value = img.imageData[index] * factor;
                    // Make the value between [0, 255]
                    img.imageData[index] = (new_value < 0) ? 0 : ((new_value > 255) ? 255 : new_value);
                }
            }
        }
    }
    else {
        cout << "Invalid Value\n";
        brightness(img);
    }
}

void edges(Image& img) {
    // Converting the image to black and white
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            unsigned  int avg = 0;
            for (int k = 0; k < 3; k++) {
                avg += img(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average

            // Set all channels to the average value
            img(i, j, 0) = avg;
            img(i, j, 1) = avg;
            img(i, j, 2) = avg;

            if (avg > 127) {
                img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = 225;
            }
            else {
                img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = 0;
            }
        }
    }

    // Applying Sobel edge detection method
    int horizontal[3][3] = {{-1,0,1},
                            {-2,0,2},
                            {-1,0,1}};

    int vertical[3][3] = {{-1,-2,-1},
                          {0,0,0},
                          {1,2,1}};

    // Create temporary image to store gradient magnitudes
    Image magnitude(img.width, img.height);

    // Apply edges operator to calculate gradient magnitudes
    for (int i = 1; i < img.width - 1; i++) {
        for (int j = 1; j < img.height - 1; j++) {
            // Calculate gradient in x and y direction
            int magnitudeX = 0, magnitudeY = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    magnitudeX += horizontal[x + 1][y + 1] * img(i + x, j + y, 0);
                    magnitudeY += vertical[x + 1][y + 1] * img(i + x, j + y, 0);
                }
            }
            // Store gradient magnitude in temporary image
            magnitude(i, j, 0) = sqrt(magnitudeX * magnitudeX + magnitudeY * magnitudeY);
        }
    }
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            // If gradient magnitude is not zero set as black (0), else white (255)
            img(i, j, 0) = magnitude(i, j, 0) ? 0 : 255;
            img(i, j, 1) = img(i, j, 0); // Set other channels the same
            img(i, j, 2) = img(i, j, 0); // Set other channels the same
        }
    }
}


// Function to apply selected filter
void applyFilter(Image& image) {
    cout << "Choose the filter you want to apply:\n";
    cout << "1. Grayscale\n2. Merge\n3. Brightness\n4. Edge detection\n==>";
    string choice;
    cin >> choice;

    if (choice == "1") {
        gray(image);
    }
    else if(choice == "2"){
        merge(image);
    }
    else if(choice == "3"){
        brightness(image);
    }
    else if(choice == "4"){
        edges(image);
    }
    else {
        cout << "Invalid Choice" << endl;
        applyFilter(image);
    }
    cout << "Filter applied successfully" << endl;
    ptr =& image;
}

// Main menu function
void mainmenu() {
    Image image; // Create an instance of the Image class
    string photo;

    bool running = true;
    while (running) {
        cout << "Choose:\n1. Load image\n2. Save image\n3. Apply another filter to the image\n4. Exit\n==>" << endl;
        string choice;
        cin >> choice;

        if (choice == "1") {
            // Load image from file
            if (ptr != nullptr) {
                cout << "Their is a loaded image already" << endl;
                cout << "Choose:\n1. Ignore the old image and work on the new one\n2. Return to main menu\n==>" << endl;
                string ans;
                cin >> ans;
                if (ans == "1") {
                }
                else if (ans == "2") {
                    mainmenu();
                }
            }
            cout << "Enter the name of the image file to load:";
            cin >> photo;
            try {
                image.loadNewImage(photo); // Assuming Image class has a method to load image
                applyFilter(image);
            }
            catch (const invalid_argument& e) {
                cout << "Invalid name" << endl;
            }
        }

        else if (choice == "2") {
            save_image(); // Save the current image
        }

        else if (choice == "3") {
            if (ptr == nullptr) {
                cout << "Enter another choice" << endl;
                mainmenu();
            }
            applyFilter(image);
        }

        else if (choice == "4") {
            if (ptr != nullptr) {
                cout << "Are you Sure you want to exit without saving ?" << endl;
                cout << "1. Yes\n2. No\n==>" << endl;
                string ch;
                cin >> ch;
                if (ch == "1") {
                    exit(0);
                }

                else if (ch == "2") {
                    save_image();
                    mainmenu();
                }
            }
            exit(0);
        }

        else {
            cout << "Invalid Choice" << endl;
        }
    }
}


// Function to save the image
void save_image() {
    string newimage;
    bool x = true;
    if (ptr == nullptr) {
        cout << "No image to save. Please load an image first." << endl;
        mainmenu();
    }
    while (x) {
        cout << "Enter the name of the image to save:";
        cin >> newimage;
        if (newimage.size() < 5) {
            cout << "Please enter a valid file name:";
            continue;
        }
        string ext = newimage.substr(newimage.size() - 4);
        string ext_long = newimage.substr(newimage.size() - 5);
        if (ext == ".jpg" || ext == ".png" || ext == ".bmp" || ext_long == ".jpeg") {
            ptr->saveImage(newimage);
            cout << "Image saved as " << newimage << endl;
            x = false;
            ptr = nullptr;
        }
        else {
            cout << "Enter a valid name:";
        }
    }
}

int main() {
    cout << "----- Welcome to Image Filters -----\n";
    mainmenu();
    return 0;
}