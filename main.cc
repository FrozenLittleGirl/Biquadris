#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "need more sequence.txt" << std::endl;
        return 1;
    }

    return 0;
}
