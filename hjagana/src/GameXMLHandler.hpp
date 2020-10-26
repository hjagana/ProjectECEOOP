#ifndef GAMEXMLHANDLER_H_
#define GAMEXMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include "Action.hpp"
#include "Armor.hpp"
#include "BlessCurseOwner.hpp"
#include "ChangedDisplayedType.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"
#include "Displayable.hpp"
#include "DropPack.hpp"
#include "Dungeon.hpp"
#include "EndGame.hpp"
#include "GameXMLHandler.hpp"
#include "Hallucinate.hpp"
#include "Item.hpp"
#include "ItemAction.hpp"
#include "Magic.hpp"
#include "Monster.hpp"
#include "ObjectDisplayGrid.hpp"
#include "Passage.hpp"
#include "Player.hpp"
#include "Remove.hpp"
#include "Room.hpp"
#include "Scroll.hpp"
#include "Structure.hpp"
#include "Sword.hpp"
#include "Teleport.hpp"
#include "YouWin.hpp"

class GameXMLHandler : public xercesc::DefaultHandler {

private:
/** Keeps track of the characters on the screen */
    int DEBUG = 1;
    std::string CLASSID = "GameXMLHandler";
    std::string data;
    //std::vector<Student> students;
    std::vector<Room> rooms;
    int maxStudents = 0;
    int studentCount = 0;
    // Student * studentBeingParsed ;
    // Activity * activityBeingParsed ;
    bool bVisible = false;
    bool bPosX = false;
    bool bPosY = false;
    bool bWidth = false;
    bool bHeight = false;
    // bool bMeetingTime = false;
    // bool bMeetingDay = false;
    bool bAM = false; //action message
    bool bAIV = false; // action int value
    bool bACV = false; // action char value
    bool bHP = false; // DISPLAYABLE
    bool bHPmoves = false; // DISPLAYABLE
    bool bMaxHit = false; // DISPLAYABALE
    bool bIIV = false; // item int value
    bool bType = false;
    //void addStudent(Student student);
    Dungeon* dungeon;
public:
    // std::vector<Student>getStudents();
    GameXMLHandler();//StudentXMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh * const ch, const XMLSize_t length ) ;
    void addDisplay(Displayable *display);
    Dungeon* returnDungeon();
    std::string toString();
    int displayCount = 0;
    std::vector<Displayable*> displayableVector;
    std::vector<Action*> actionVector;
};

#endif 