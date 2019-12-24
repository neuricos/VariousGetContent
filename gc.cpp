#include <iostream>
#include <fstream>
#include <cstdlib>

#define BUF_SIZE 2048

int main(int argc, char *argv[]) {
    using namespace std;

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        exit(1);
    }

    ifstream inFile(string(argv[1]), ifstream::in);
    char buf[BUF_SIZE];

    while (inFile.good()) {
        inFile.read(buf, BUF_SIZE);
        cout << buf;
        if (inFile.gcount() < BUF_SIZE) break;
    }
    inFile.close();

    return 0;
}
