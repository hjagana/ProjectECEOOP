#include <iostream>
#include <string>
#include <atomic> 
#include <thread>
#include <sstream>
#include "ObjectDisplayGrid.hpp"
#include "GridChar.h"
#include "KeyboardListener.h"
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "GameXMLHandler.hpp"
#include <exception>


// set to false when done running
std::atomic_bool isRunning(true);

// grid properties
int WIDTH = 150;
int HEIGHT = 41;
int MESSAGES = 5;

void runDisplay(ObjectDisplayGrid* grid, Dungeon* d) {
    d -> draw();
}

// void runDisplay(ObjectDisplayGrid* grid, Dungeon* d) {
//     std::vector<Room*> rVector = d->getRooms();
//     std::vector<Creature*> cVector = d->getCreatures();
//     std::vector<Item*> iVector = d->getItems();
//     std::vector<Passage*> pVector = d->getPassages();
//     for (auto x: rVector) {
//         int w = x -> getWidth();
//         int h = x -> getHeight();
//         int xPos = x -> getPosX();
//         int yPos = x -> getPosY();
//         // std::vector<Creature*> cVector = x->getCreature(); // uses Room to get creature Vector
//         // std::vector<Creature*> cVector = d->getCreatures(); // uses Creature to get crature Vector
//         for (int i = 0; i < w; i++) {
//             for (int j = 0; j < h; j++) {
//                 char c;
//                 if (i == 0 || i == (w-1) || j == 0 || j == (h-1)) {
//                     c = 'X';
//                 }
//                 else {
//                     c = ' ';
//                 }
//                 grid->addObjectToDisplay(new GridChar(c), i + xPos, j + yPos);
//             }
//         }
//         // update the grid
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
    fileName = "../xmlfiles/testDrawing.xml";
    // switch (argc) {
    //     case 2:
    //         fileName = "./xmlfiles/" + ((std::string) argv[1]);
    //         break;
    //     default:
    //         std::cout << "C++ Test <xmlfilename>" << std::endl;
    // }
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();
    Dungeon* gameDungeon;
    try {
        GameXMLHandler* handler = new GameXMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh * fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);
        //std::vector<Student> students = handler->getStudents();
        // for (Student student : students) {
        //     std::cout << student.toString() << std::endl;
        //     student.freeActivities();

        // }
        gameDungeon = handler -> returnDungeon();
		delete parser;
		delete handler;
        /*
         * the above is a different form of 
         for (int i = 0; i < students.length; i++) {
            std::cout << students[i] << std::endl;
        }
        */
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
    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included

    // get dungeon
    

    // create an initialize the object display grid
    // ObjectDisplayGrid grid(gameDungeon->getWidth(), gameDungeon->getGameHeight(), MESSAGES);
    ObjectDisplayGrid* pGrid = ObjectDisplayGrid::getGrid(gameDungeon->getWidth(), gameDungeon->getGameHeight(), MESSAGES);
    // ObjectDisplayGrid grid(WIDTH, HEIGHT, MESSAGES);
    // ObjectDisplayGrid* pGrid = grid;
    // Displayable grid(WIDTH, HEIGHT, MESSAGES);
    // Displayable* pGrid= &grid;

    // thread to wait for key press
    Player *player = gameDungeon -> getPlayer();
    KeyboardListener listener(pGrid, player, gameDungeon);
    std::thread keyboardThread(&KeyboardListener::run, &listener);

    // thread to update display
    // std::thread displayThread(runDisplay, pGrid);
    std::thread displayThread(runDisplay, pGrid, gameDungeon);
    // pGrid -> runDisplay(pGrid, gameDungeon);
    // wait for the keyboard thread to finish, then notify the display to stop
    keyboardThread.join();
    isRunning = false;

    // wait for the display thread to finish
    displayThread.join();
    delete(pGrid);

    return 0;
}



