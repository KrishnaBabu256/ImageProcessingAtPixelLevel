#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main (int argc , char** argv)
{
	if(argc < 2)
	{
		cout << " Provide Input Image for Conversion " << endl;
		return -1;
	}
	// i j k are variables for loops
	unsigned int i=0,j=0,k=0,width=0,height=0,chanals=0;
	// to store pixel values 
	unsigned char r,g,b,res;
	// read the image into Mat	
	cv::Mat input = cv::imread(argv[1],cv::IMREAD_COLOR);
	if(input.empty())
	{
		cout << " Image is not loaded Properly " << endl;
		return -1;
	}
	// display the input image
	cv::namedWindow("input",WINDOW_NORMAL);
	cv::imshow("input",input);
	cv::waitKey(0);
	// collect the image information
	width = input.cols;
	height = input.rows;
	chanals = input.channels();
	//cout << " w and h is " << width << " " << height << " " << chanals << endl;
	//create a pointer to point the Mat container and assign 
	unsigned char* img_ptr = (unsigned char*)input.data;
	unsigned char* gray_ptr = NULL;
	// create a another pointer for output image and allocate memory
	gray_ptr = (unsigned char*)malloc(width*height);
	if(chanals == 3)
	{
		for(i = 0; i < height; i ++)
		{
			for(j = 0; j < width; j++)
			{
				// opencv uses BGR color space format 
				b = img_ptr[chanals*(width*i+j)+0];  // collect 'b' channel values
				g = img_ptr[chanals*(width*i+j)+1];  // collect 'g' channel values
				r = img_ptr[chanals*(width*i+j)+2];  // collect 'r channel values'
				res = (b+g+r)/3;                     //technique 1 for converting into 1 channel is averaging
				*(gray_ptr+(width*i+j)) = res;       //technique 2 for converting into 1 channel is res = (0.11*b+0.5*g+0.39*r);
			}
		}
	}
	else
	{
		cout << " Input image is not 3 channel image " << endl;
		return -1;
	}
	// assign the pointer address to Mat address  to display the image
	cv::Mat gray_Image = cv::Mat(input.size(),CV_8UC1,gray_ptr,width);

	cv::namedWindow("gray_Image",WINDOW_NORMAL);
	cv::imshow("gray_Image",gray_Image);
	cv::waitKey(0);

	return 0;	
}
