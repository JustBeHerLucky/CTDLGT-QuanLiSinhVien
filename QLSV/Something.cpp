#include "Something.h"

int toINT(string str)
{
    unsigned int x = 0;
    for (int i = 0; i < str.length(); i++) {
        int a = (int)(str[i] - '0');
        x = x + (a * (int)pow(10, str.length() - i-1));
    }
    return x;
}

float toFloat(string str) {
    float num_float = std::stof(str);
    return num_float;
}
