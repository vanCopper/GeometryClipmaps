///////////////////////////////////////////
#pragma once
///////////////////////////////////////////
#include <glm/glm.hpp>
using namespace glm;
///////////////////////////////////////////
class Bitmap
{
public:

    Bitmap();
    Bitmap(const char* filename);
    Bitmap(int x, int y, int bpp, unsigned char* data = 0);
    ~Bitmap();

    void load(const char* filename);
    void save(const char* filename);
    void save_float(const char* filename);
    void load_float(const char* filename);
    void set(int x, int y, int bpp, unsigned char* data);
    void blur(int radius);
    void set_pixel(int x, int y, int r, int g, int b);
    int  get_pixel(int x, int y);
    vec3 get_pixel3f(int x, int y);

public:

    unsigned char* data;
    int width;
    int height;
    int bpp;

private:

    unsigned char bmp[54];
};

