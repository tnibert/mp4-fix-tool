#include "opencv2/opencv.hpp"
#include <iostream>
#include "process.h"
 
using namespace std;
using namespace cv;
 
int main(int argc, char** argv){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap(argv[1]); 
  double framenum = 0;
  int frame_contour;

  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  cout << "Total Frames: " << cap.get(CV_CAP_PROP_FRAME_COUNT) << "\n";
     
  while(1){
 
    Mat frame;
    // Capture frame-by-frame
    cap >> frame;
  
    // If the frame is empty, reset to start
    if (frame.empty())
    {
      cap.set(CV_CAP_PROP_POS_FRAMES, 1);
      cap >> frame;
    }

    frame_contour = return_largest_contour(frame);

    cout << "Frame Number: " << cap.get(CV_CAP_PROP_POS_FRAMES) << " Largest Contour: " << frame_contour << "\n";
    // Display the resulting frame
    imshow( "Frame", frame );
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
    else if(c==101)     // if you press 'e' - enter a frame number
    {
        cin >> framenum;
        cap.set(CV_CAP_PROP_POS_FRAMES, framenum-1);
    }
    else if(c==112)     // 'p' - pause
    {
        // will crash if we go past last frame
        do
        {
            c = (char)waitKey();

            if(c==110)   // 'n' - next
            {
                cap >> frame;
                imshow("Frame", frame );
                cout << "Frame Number: " << cap.get(CV_CAP_PROP_POS_FRAMES) << "\n";
            }
        }
        while(c==110);
    }

  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}
