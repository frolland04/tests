#include <iostream>
#include "logger.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Logger logger_instance;
    logger_instance.init();
    logger_instance.log_item("coucou!");

    cout << "Bye Bye!" << endl;
    return 0;
}
