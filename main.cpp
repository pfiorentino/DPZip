#include "dpzip.h"
#include <QDebug>

int main() {
    DPZip app(4);
    //app.compress("/Users/paul/test_cpp/", "/Users/paul/pipo.ecf");
    //app.compress("/Users/paul/Downloads/", "/Users/paul/pipo.ecf");
    app.compress("/Users/paul/Documents/", "/Users/paul/pipo.ecf");
    app.uncompress("/Users/paul/pipo.ecf", "/Users/paul/test_cpp_u/");

    return 0;
}

