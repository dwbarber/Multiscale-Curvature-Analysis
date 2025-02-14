#include "maincontroller.h"
#include<stdio.h> 
#include<stdlib.h>
#include<iostream>
#include"userInputCLI.h"
#include<string>
#include"dataContainer.h"
#include "userData.h"
#include "fileHandler.h"


using namespace std;



void MainController::mainLoop(void){
    switch(currentState){
        //prints startup message, sets progstate to idle
        case START:
            std::cout << "This program was developed by Worcester Polytechnic Institute's Surface Metrology Lab.\nFor more information, please visit https://www.surfacemetrology.org/ and https://wp.wpi.edu/surfacemetrology/.\nThis software is distributed under the GPL-3.0 License.\n";
            currentState = IDLE;
            break;
        //awaits user input to start analysis
        case IDLE:
            commandinput = cliInput::getString("Please enter a command");
            if(commandinput == "help"){
                std::cout << helpmsg;
            }
            else if(commandinput == "exit"){
                exit(0);
            }
            else if(commandinput == "analysis"){
                currentState = ANALYZE;
            }
            else{
                std::cout << "Invalid command, type 'help' for a list of commands";
            }
            

            break;
        //runs analysis
        case ANALYZE:
            std::cout << "Running analysis";
                UserData uData;
                DataContainer data;
                switch(currentAnalysisState){
                    case NEWANALYSIS:
                        currentAnalysisState = USERINPUT;
                        break;
                    case USERINPUT:
                        //get user input for the first time
                        //get file path
                        uData.setInputFilePath(cliInput::getString("Please enter the file path"));
                        point* pointArray = FileHandler::fileRead(uData.getInputFilePath());
                        if(pointArray == nullptr){
                            std::cout << "Invalid file path";
                        }
                        else{
                            data.initDataZero(pointArray);
                        }
                        
                        //get min and max scale
                        break;
                    default:
                        break;
                }
            break;
    }
}