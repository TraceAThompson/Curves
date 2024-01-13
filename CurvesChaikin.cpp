//g++ -o exe cpp -O2 -lgdi32 
#include <iostream>
#include "CImg.h"
#include <vector>

using namespace cimg_library;
using namespace std;

int main() {
	CImg<unsigned char> orig(500, 500, 1, 3, 0);
	
	
	//creating vectors to store user input
	vector<int> coords_x;
	vector<int> coords_y;
	vector<int> newc_x;
	vector<int> newc_y;
	
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
			
			coords_x.push_back(x);
			coords_y.push_back(y);
		}
  }
 
 
  for (int j = 0; j < 6; j++) {
  	color[0] = rand()%256;
	color[1] = rand()%256;
	color[2] = rand()%256;
	for (int i = 0; i < coords_x.size() - 1; i++) {
		orig.draw_line(coords_x[i], coords_y[i], coords_x[i+1], coords_y[i+1], color);
		float q_x = 0;
		float q_y = 0;
		float r_x = 0;
		float r_y = 0;
		q_x = 0.75*coords_x[i] + 0.25*coords_x[i+1];
		r_x = 0.25*coords_x[i] + 0.75*coords_x[i+1];
		q_y = 0.75*coords_y[i] + 0.25*coords_y[i+1];
		r_y = 0.25*coords_y[i] + 0.75*coords_y[i+1];
		newc_x.push_back(q_x);
		newc_x.push_back(r_x);
		newc_y.push_back(q_y); 
		newc_y.push_back(r_y); 
	}
	
	
	CImgDisplay disp(orig);
		while (!disp.is_closed())
		disp.wait(); 
	
	newc_x.swap(coords_x);
	newc_y.swap(coords_y);
	newc_x.clear();
	newc_y.clear();
  }
	cout << "Window closed, proceeding now\n";
	return 0;
};