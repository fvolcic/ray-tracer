#include <iostream> 
#include "vec3.h"
#include "color.h"
using namespace std; 

int main(){

    const int width = 255; 
    const int height = 255; 

    cout << "P3\n" << width << " " << height << "\n255\n";

    for(int row = 0; row < height; ++row){
        for(int col = 0; col < width; ++col){
            Vec3 pixel(col/(double)(height-1), row/(double)(width-1), 0.25); 
            write_color(std::cout, pixel.get_unit_vec()); 
        }
    }
    
}