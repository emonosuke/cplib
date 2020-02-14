#include <bits/stdc++.h>

struct XorShift
{
    uint32_t w, x, y, z;
    XorShift(uint32_t seed = time(nullptr))
    {
        w = seed;
        x = w << 13;
        y = (w >> 9) ^ (x << 6);
        z = y >> 7;
    }
 
    uint32_t rand()
    {
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19) ^ (t ^ (t >> 8)));
    }
 
    // [min,max] int
    int randInt(int min = 0, int max = 0x7FFFFFFF)
    {
        return rand() % (max - min + 1) + min;
    }
 
    // [min,max] double
    double randDouble(double min = 0, double max = 1)
    {
        return (double)(rand() % 0xFFFF) / 0xFFFF * (max - min) + min;
    }

    void SetDefault()
    {
        w = 123456789;
        x = 362436069;
        y = 521288629;
        z = 88675123;
    }
};