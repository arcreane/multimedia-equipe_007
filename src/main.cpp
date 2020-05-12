/* Include external libraries */
#include <iostream>

/* Include our modules */
#include "imageManipulator.hpp"

/* Macros */
#define QUIT_APP 1

/* Namespaces */
using namespace std;

/* Print help function */
void printHelp()
{
    cout << "Please enter one of these commands :" << endl;
    cout << "\t- Press " << QUIT_APP << " to quit" << endl;
}

/* Execute command (just for now as we don't have graphic interface) */
int execute(int cmd)
{
    switch(cmd){
        case QUIT_APP:
            return -1;
        default:
            break;
    }
    return 0;
}

/* Main programm */
int main(int argc, char **argv)
{
    cout << "Multimedia Application Project : Team 7" << endl;
    bool stop = false;
    int cmd;
    // Program loop
    while (!stop)
    {
        printHelp();
        cin >> cmd;
        switch(execute(cmd)){
            case -1:
                stop = true;
                break;
            default:
                // continue
                break;
        }
    }
    // Success
    return 0;
}