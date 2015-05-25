#include "dpzip.h"
#include <QDebug>

int main()
{
    DPZip app(8);
    app.compress("/Users/paul/test_cpp/", "/Users/paul/pipo.ecf");

    return 0;
}

