#include "dpzip.h"
#include <QDebug>
#include <unistd.h>

int main()
{
    DPZip app(8);
    app.compress("/Users/paul/Downloads", "/Users/paul/pipo.ecf");

    return 0;
}

