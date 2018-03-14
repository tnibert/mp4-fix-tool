#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int return_largest_contour( cv::Mat image )
{
    // this is waiting for a key press before outputting...
    int largest_area=0;
    int largest_contour_index=0;
    Rect bounding_rect;
    double a;
    //image = imread("cat.jpg", 1);  
    //namedWindow( "Display window", CV_WINDOW_AUTOSIZE );  
    //imshow( "Display window", image );
    Mat gray;
    cvtColor(image, gray, CV_BGR2GRAY);
    Canny(gray, gray, 100, 200, 3);
    /// Find contours   
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    RNG rng(12345);
    findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    /// Draw contours
    //Mat drawing = Mat::zeros( gray.size(), CV_8UC3 );
    //cout << contours.size();
    for( int i = 0; i< contours.size(); i++ )
    {

        a=contourArea( contours[i],false);  //  Find the area of contour
        if(a>largest_area){
            largest_area=a;
            largest_contour_index=i;                //Store the index of largest contour
            bounding_rect=boundingRect(contours[i]); // Find the bounding rectangle for biggest contour
        }

        //cout << "NEXT" << endl;
        //cout << largest_area << endl;
        //cout << contours[i] << endl;
        //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        //drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }

    //cout << largest_area << endl;

    //imshow( "Result window", drawing );
    //waitKey(0);
    return largest_area;
}

/*int main()
{
    Mat image = imread("cat.jpg", 1);
    cout << return_largest_contour(image);
    return 0;
}*/
