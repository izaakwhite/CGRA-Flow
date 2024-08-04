#define WIDTH 32
#define HEIGHT 32

struct Pixel {
    int r;
    int g;
    int b;
     Pixel(int red = 0, int green = 0, int blue = 0) : r(red), g(green), b(blue) {}
};

Pixel screen[WIDTH][HEIGHT];

void setPixel(int x, int y, int red, int green, int blue) {
    screen[x][y] = Pixel(red, green, blue);
}

void darkenPixel(int x, int y) {
    screen[x][y].r /= 2;
    screen[x][y].g /= 2;
    screen[x][y].b /= 2;
}

void kernel(Pixel pixels[WIDTH][HEIGHT]) {
    for(int x = 0; x < WIDTH; ++x) {
        for(int y = 0; y < HEIGHT; ++y) {
            darkenPixel(x, y);
        }
    }
    // Make all pixels red
    for(int x = 0; x < WIDTH; ++x) {
        for(int y = 0; y < HEIGHT; ++y) {
            setPixel(x, y, 255, 0, 0);
        }
    }
    // Make half of the pixels green and the other half blue
    for(int x = 0; x < WIDTH; ++x) {
        for(int y = 0; y < HEIGHT; ++y) {
            if(y % 2 == 0) {
                setPixel(x, y, 0, 255, 0);
            } else {
                setPixel(x, y, 0, 0, 255);
            }
        }
    }
}
int main(){
    kernel(screen);
    return 0;
}