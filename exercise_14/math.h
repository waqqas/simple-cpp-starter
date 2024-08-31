#pragma once

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// float max(float a, float b)
// {
//     return (a > b) ? a : b;
// }

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}