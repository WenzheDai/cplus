#include <iostream>
#include <opencv2/opencv.hpp>


int main() {
    cv::Mat img;
    img = cv::imread("/home/dwz/work/infer_sam/images/dog.jpg");
    std::cout << "img size:" << img.size() << std::endl;
    std::cout << "img data:" << img.data << std::endl;
    std::cout << "img total: " << img.total() << std::endl;
    return 0;
}