#include "random.h"

using namespace std;

char setChar(double prob1, double prob2, int sd, bool set_sd) {
    static default_random_engine gen;
    static discrete_distribution<int> dist{ prob1, prob1, prob2, prob2, prob2, prob2, prob2 };
    static bool flag = set_sd;
    if (flag) {
        gen.seed(sd);
        flag = false;
    }
    return chart[dist(gen)];
}
