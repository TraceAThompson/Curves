#include <iostream>
#include "CImg.h"
#include <vector>

using namespace cimg_library;
using namespace std;

int main() {
	CImg<unsigned char> orig(500, 500, 1, 3, 0);
	
	
	//creating vectors to store user input
	vector<float> pts_x;
	vector<float> pts_y;
	
	
	CImgDisplay window(orig, "Click control points");
    unsigned char color[] = { 255,128,64 };
    while (!window.is_closed()){

	    window.wait();
	    if (window.button()){
			int x = window.mouse_x();
			int y = window.mouse_y();
			cout << x << ", " << y << endl;
			orig.draw_circle(x, y, 5, color);
			window.display(orig);
			
			pts_x.push_back(x);
			pts_y.push_back(y);
		}
  }
 
  
  float stepSize = 0.01;
  for (float step = 0.0; step <= 1.0; step += stepSize) {
	  int numPoints = pts_x.size();
	  int numLevels = numPoints - 1;
	  
	  vector<float> oldPts_x(pts_x); 
	  vector<float> oldPts_y(pts_y);
	  vector<float> newPts_x(numPoints);
      vector<float> newPts_y(numPoints);
  
	  
	  for (int level = 0; level < numLevels; level++) {
		  newPts_x.clear();
		  newPts_y.clear();
		  
		  //cout << "check 1" << endl; used this to check how far code was going when I was getting errors
		  for (int i = 0; i < numPoints - 1; i++) {
			  //cout << "check 2" << endl; used this to check how far code was going when I was getting errors
			  
			  newPts_x.push_back((1.0 - step) * oldPts_x[i] + step * oldPts_x[i + 1]);
			  newPts_y.push_back((1.0 - step) * oldPts_y[i] + step * oldPts_y[i + 1]); 
		  }
		  newPts_x.swap(oldPts_x);
		  newPts_y.swap(oldPts_y);
		  
  }
  		  orig.draw_circle(oldPts_x[0], oldPts_y[0], 7, color);
}
  CImgDisplay disp(orig);
  while (!disp.is_closed())
	disp.wait(); 
  
  
  
  
  return 0;
}
  