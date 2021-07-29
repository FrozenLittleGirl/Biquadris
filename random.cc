#include "random.h"

int setChar(double prob1, double prob2, int sd, bool set_sd) {
    static default_random_engine gen;
    static discrete_distribution<int> dist{ prob1, prob1, prob2, prob2, prob2, prob2, prob2 };
    static bool flag = set_seed;
    if (flag) {
        gen.seed(seed);
        flag = false;
    }
    return chart[dist(gen)];
}
