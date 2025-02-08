#pragma once
#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H



class MainController {

public:

    void mainLoop();

protected:
    enum PROG_STATE
    {
        START,
        IDLE,
        ANALYZE
    };

    PROG_STATE currentState = START;
    std::string commandinput;


    std::string helpmsg = "List of commands: \nhelp: Displays this message\nexit: Exits the program";
};





#endif