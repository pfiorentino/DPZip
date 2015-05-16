#include <iostream>
#include "filepool.h"

using namespace std;

int main()
{
    cout << "Building pool" << endl;

    FilePool pool("/Users/paul/test_cpp");

    cout << "Done" << endl;
    cout << "Number of files: " << pool.count() << endl;


    return 0;
}

