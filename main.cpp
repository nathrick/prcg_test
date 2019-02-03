#include <iostream>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

#include "platercg.hpp"

int main()
{
    cv::VideoCapture cap("../res/sample.mp4");
    cv::Mat frame;

    platercg::KNN_Rcg k{"../res/default_labels.xml", "../res/default_data.xml"};

    std::string plate_num;

    while(cap.read(frame))
    {
        cv::imshow("original", frame);
        cv::Mat possiblePlates;

        auto plates = k.licensePlates(frame);

        if(!plates.empty())
        {
            for(auto &p : plates)
            {
                std::cout << "Plate number: " << p.m_strChars << std::endl;
                cv::imshow("plate", p.m_imgPlate);
            }
        }

        cv::waitKey(15);
    }

    return 0;
}
