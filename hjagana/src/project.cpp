#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "XMLHandler.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <atomic> 
#include <thread>
#include <sstream>

#include "ObjectDisplayGrid.hpp"
#include "GridChar.hpp"
#include "KeyboardListener.hpp"

// set to false when done running
std::atomic_bool isRunning(true);

// grid properties
// int WIDTH = 150;
// int HEIGHT = 50;
int MESSAGES = 5;


//run display is for threading
//on the object display grid
//write line adds one line
//add object to display will add to the display grid
//i and j are the x and y
//each thing in the dungeon
//then call add object 
//player will add @ 5,5

//iterate through list of rooms
//print room to print display grid

//add more functions to dungeon

//vector of rooms in the dungeon
//vector of creatures inside each room



void runDisplay(ObjectDisplayGrid* grid, Dungeon *dungeonGrid) {
    dungeonGrid->Draw();

    // // loop over each step, doubling each time
    // // stop loop if isRunning is swapped to false
    // for (int step = 1; (isRunning && step < WIDTH / 2); step *= 2) {
    //     // write a message, but don't update yet
    //     grid->writeLine(1, "Step " + std::to_string(step));

    //     // print characters to the screen
    //     for (int i = 0; i < WIDTH; i++) {
    //         for (int j = 0; j < HEIGHT; j++) {
    //             char c;
    //             if (i % step == 0 && j % step == 0) {
    //                 c = 'X';
    //             }
    //             else {
    //                 c = '.';
    //             }
    //             grid->addObjectToDisplay(new GridChar(c), i, j);
    //         }
    //     }

    //     // update the grid
    //     grid->update();

    //     // wait a bit to rejoin
    //     // wait in a few steps to update faster on keypress
    //     for (int i = 0; (isRunning && i < 5); i++) {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(400));
    //     }
    // }
}

// void runDisplay(ObjectDisplayGrid* grid, Dungeon *dungeonGrid) {
//     std::vector<Room *> roomVector = dungeonGrid->getRooms();
//     std::vector<Creature *> creatureVector = dungeonGrid->getCreatures();
//     std::vector<Item *> itemVector = dungeonGrid->getItems();
//     std::vector<Passage *> passageVector = dungeonGrid->getPassages();

//     for (Room* room : roomVector) {
//         int width = room->getWidth();
//         int height = room->getHeight();
//         int offsetx = room->getXPos();
//         int offsetY = room->getYPos();

//         for (int i = 0; i <= width; i++) {
//             for (int j = 0; j <= height; j++) {
//                 char c;
//                 if(i == 0 || i == width || j == 0 || j == height){
//                     c = 'X';
//                 }
//                 else{
//                     c = ' ';
//                 }
//                 grid->addObjectToDisplay(new GridChar(c), i + offsetx, j + offsetY);
//             }
//         }

//         grid->update();

//         // wait a bit to rejoin
//         // wait in a few steps to update faster on keypress
//         for (int i = 0; (isRunning && i < 5); i++) {
//             std::this_thread::sleep_for(std::chrono::milliseconds(400));
//         }
//     }
// }

int main(int argc, char* argv[]) {
    std::string fileName;
    try{
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return 1;
    }
    // std::string filenames[7] = {"badScroll.xml", "death.xml", "dropPack.xml", "dungeon.xml", "hallucinate.xml", "testDrawing.xml", "wear.xml"};
    // fileName = "../xmlFiles/" + filenames[0];
    fileName = argv[1];
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();
    Dungeon* dungeon;
    try {
        XMLHandler* handler = new XMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh * fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);
        dungeon = handler->returnDungeon();
        delete parser;
        delete handler;
    } catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cout << "Exception message is: \n"
                << message << "\n";
            xercesc::XMLString::release(&message);
            return -1;
    }
    catch (const xercesc::SAXParseException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
            << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
    catch(std::exception& e){
        std::cout << e.what() << '\n';
    }
    catch(...){
        std::cout << "Unexpected Exception \n" ;
        return -1;
    }
    
    xercesc::XMLPlatformUtils::Terminate();


    int width = dungeon->getwidth();
    int height = dungeon->getGameHeight() + dungeon->getBottomHeight() + dungeon->getTopHeight();
    ObjectDisplayGrid* pGrid = ObjectDisplayGrid::getGrid(width, height, MESSAGES);
    pGrid->setTopMessageHeight(dungeon->getTopHeight());
    // ObjectDisplayGrid grid(WIDTH, HEIGHT, MESSAGES);
    // ObjectDisplayGrid* pGrid = &grid;
    Player *player = dungeon->getPlayer();
    // thread to wait for key press
    KeyboardListener listener(pGrid, player, dungeon);
    std::thread keyboardThread(&KeyboardListener::run, &listener);

    // thread to update display
    std::thread displayThread(runDisplay, pGrid, dungeon);

    // wait for the keyboard thread to finish, then notify the display to stop
    keyboardThread.join();
    isRunning = false;

    // wait for the display thread to finish
    displayThread.join();


	return 0;
}