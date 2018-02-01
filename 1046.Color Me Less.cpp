#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
    int r;
    int g;
    int b;
} Color;

int main(int argc, char* argv[]) {
    int min,i,j,dis;
    int r,g,b;
    Color map[16];
    for(i=0;i<16;++i)
        std::cin>>map[i].r>>map[i].g>>map[i].b;
    while(std::cin>>r>>g>>b&&r!=-1&&g!=-1&&b!=-1) {
        min=-1;
        j=-1;
        for(i=0;i<16;++i) {
            dis=(map[i].r-r)*(map[i].r-r)+
                (map[i].g-g)*(map[i].g-g)+
                (map[i].b-b)*(map[i].b-b);
            if(min<0||min>dis) {
                min=dis;
                j=i;
            }
        }
        std::cout<<"("<<r<<","<<g<<","<<b<<") maps to ("
            <<map[j].r<<","<<map[j].g<<","<<map[j].b<<")"<<std::endl;
    }
}