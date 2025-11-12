#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load image
    Mat img = imread("images/input.jpg");
    if(img.empty()){
        cout << "Error: image not found!" << endl;
        return -1;
    }

    // Pixelation strength
    int pixel_size = 20;

    // Resize down
    Mat smallImg;
    resize(img, smallImg, Size(img.cols / pixel_size, img.rows / pixel_size), 0, 0, INTER_LINEAR);

    // Resize up with nearest neighbor
    Mat pixelatedImg;
    resize(smallImg, pixelatedImg, Size(img.cols, img.rows), 0, 0, INTER_NEAREST);

    // Show images
    imshow("Original", img);
    imshow("Pixelated", pixelatedImg);

    waitKey(0);
    destroyAllWindows();

    // Save result
    imwrite("images/pixelated_output.jpg", pixelatedImg);

    return 0;
}
