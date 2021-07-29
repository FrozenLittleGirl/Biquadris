#ifndef _RANDOM_H_
#define _RANDOM_H_
#include <string>
#include <random>

const char chart[7]{ 'S', 'Z', 'I', 'J', 'L', 'O', 'T' };

char setChar(double prob1, double prob2, int sd, bool set_sd);

#endif
