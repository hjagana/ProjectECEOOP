#include "GameXMLHandler.hpp"

int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue){
    return booleanValue ? "true": "false";
}

// std::vector<Dungeon> GameXMLHandler::getStudents() {
//     return students;
// }

GameXMLHandler::GameXMLHandler() {
}

std::string xmlChToString(const XMLCh* xmlChName, int length = -1){
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char * chStarName = xercesc::XMLString::transcode(xmlChName); 
    if(length == -1){
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else{
        std::string StrName(chStarName,0,length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char * strGet){
    XMLCh * xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh * xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

void GameXMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;   
        if (DEBUG > 1) {
			std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

void GameXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) {
    char *qNameStr = xercesc::XMLString::transcode(qName);
    if (DEBUG > 1) {
        std::cout <<  CLASSID << ".startElement qName: " << qNameStr << std::endl;
    }
    if (case_insensitive_match(qNameStr, "Dungeon")) {
        std::string nameDungeon = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // nameDungeon = std::stoi(nameDungeon);
        // students.resize(maxStudents);
        std::string widthDungeon = xmlChToString(getXMLChAttributeFromString(attributes, "width"));
        int width = std::stoi(widthDungeon);

        std::string topHeightDungeon = xmlChToString(getXMLChAttributeFromString(attributes, "topHeight"));
        topHeightDungeon = std::stoi(topHeightDungeon);
        std::string gameHeightDungeon = xmlChToString(getXMLChAttributeFromString(attributes, "gameHeight"));
        int gameheight = std::stoi(gameHeightDungeon);
        std::string bottomHeightDungeon = xmlChToString(getXMLChAttributeFromString(attributes, "bottomHeight"));
        bottomHeightDungeon = std::stoi(bottomHeightDungeon);
        
        // dungeon = new Dungeon();
        dungeon = Dungeon::getDungeon(nameDungeon, width, gameheight);
        
        // displayableVector.push_back(dungeon); // push dungeon to stack
    } else if (case_insensitive_match(qNameStr, "Rooms")) { 
        // room vector?

    } else if (case_insensitive_match(qNameStr, "Room")){
        std::string room = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        room = std::stoi(room);
        Room* r = new Room(room);

        // Dungeon* d = new Dungeon();
        dungeon -> addRoom(r);
        displayableVector.push_back(r); // push room to stack


    } else if (case_insensitive_match(qNameStr, "visible")) {
        bVisible = true;
    } else if (case_insensitive_match(qNameStr, "posX")) {
        bPosX = true;
    } else if (case_insensitive_match(qNameStr, "posY")) {
        bPosY = true;
    } else if (case_insensitive_match(qNameStr, "width")) {
        bWidth = true;
    } else if (case_insensitive_match(qNameStr, "height")) {
        bHeight = true;
    } else if (case_insensitive_match(qNameStr, "Scroll")) {
        std::string scrollName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // scrollName = std::stoi(scrollName);
        std::string scrollRoom = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        int sRoom = std::stoi(scrollRoom);
        std::string scrollSerial = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
        int sSerial = std::stoi(scrollSerial);
        Scroll * s = new Scroll(scrollName);
        s -> setID(sRoom, sSerial);
        displayableVector.push_back(s); // push scroll to stack

    } else if (case_insensitive_match(qNameStr, "ItemAction")) {
        std::string nameIA = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // nameIA = std::stoi(nameIA);
        std::string typeIA = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        // typeIA = std::stoi(typeIA);
        Creature* c = new Creature();
        ItemAction *iA = new ItemAction(c);
        actionVector.push_back(iA); // push itemAction to stack

    } else if (case_insensitive_match(qNameStr, "actionMessage")) {
        bAM = true;
    } else if (case_insensitive_match(qNameStr, "actionIntValue")) {
        bAIV = true;
    } else if (case_insensitive_match(qNameStr, "actionCharValue")) {
        bACV = true;
    } else if (case_insensitive_match(qNameStr, "Player")) {
        std::string playerName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // playerName = std::stoi(playerName);
        std::string playerRoom = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        playerRoom = std::stoi(playerRoom);
        std::string playerSerial = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
        playerSerial = std::stoi(playerSerial);
        // Item* iS = new Item();
        // Item* iA = new Item ();
        
        Player *p = new Player();
        // p -> setName(playerName);
        // p -> setID(playerRoom, playerSerial);
        displayableVector.push_back(p); // push player into stack

        // Creature *p = new Player();
        // // Player *p = new Player(); ???
        // // p -> setWeapon(iS);
        // // p -> setArmor(iA);
        // displayableVector.push_back(p); // push player into stack

    } else if (case_insensitive_match(qNameStr, "hp")) {
        bHP = true;
    } else if (case_insensitive_match(qNameStr, "hpMoves")) {
        bHPmoves = true;
    } else if (case_insensitive_match(qNameStr, "maxhit")) {
        bMaxHit = true;
    } else if (case_insensitive_match(qNameStr, "CreatureAction")) {
        std::string nameCA = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // nameCA = std::stoi(nameCA);
        std::string typeCA = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        // typeCA = std::stoi(typeCA);
        Creature* c = new Creature();
        CreatureAction *cA = new CreatureAction(c); // push Creature Action into stack
        actionVector.push_back(cA);

    } else if (case_insensitive_match(qNameStr, "Sword")) {
        std::string nameSword = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // nameSword = std::stoi(nameSword);
        std::string roomSword = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        int rSword = std::stoi(roomSword);
        std::string serialSword = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
        int sSword = std::stoi(serialSword);
        Sword *s = new Sword(nameSword);
        s -> setID(rSword, sSword);
        displayableVector.push_back(s); // push sword into stack

    } else if (case_insensitive_match(qNameStr, "ItemIntValue")) {
        bIIV = true;
    } else if (case_insensitive_match(qNameStr, "Monster")) {
        std::string monsterName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // monsterName = std::stoi(monsterName);
        std::string monsterRoom = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        int mRoom = std::stoi(monsterRoom);
        std::string monsterSerial = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
        int mSerial = std::stoi(monsterSerial);
        Monster *m = new Monster();
        m -> setName(monsterName);
        m -> setID(mRoom, mSerial);
        displayableVector.push_back(m); // push monster into stack

    } else if (case_insensitive_match(qNameStr, "type")) {
        bType = true;
    } else if (case_insensitive_match(qNameStr, "Armor")) {
        std::string armorName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        // armorName = std::stoi(armorName);
        std::string armorRoom = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        int aRoom = std::stoi(armorRoom);
        std::string armorSerial = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
        int aSerial = std::stoi(armorSerial);
        Armor *a = new Armor(armorName);
        a -> setName(armorName);
        a -> setID(aRoom, aSerial);
        displayableVector.push_back(a); // push armor into stack

    } else if (case_insensitive_match(qNameStr, "Passages")) {
        // continue; ??
    } else if (case_insensitive_match(qNameStr, "Passage")) {
        std::string passageR1 = xmlChToString(getXMLChAttributeFromString(attributes, "room1"));
        int pR1 = std::stoi(passageR1);
        std::string passageR2 = xmlChToString(getXMLChAttributeFromString(attributes, "room2"));
        int pR2 = std::stoi(passageR2);
        Passage *p = new Passage();
        p -> setID(pR1, pR2);
        displayableVector.push_back(p); // push passage into stack

    } else {
        std::cout <<"Unknown qname: " << qNameStr << std::endl;
    }
    xercesc::XMLString::release(&qNameStr);
}

void GameXMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName)  {
    // Displayable
    // Action
    //.peek function
    // if (bVisible) {
    //     if (std::stoi(data) == 1) {
    //         Displayable* e =  displayableVector.back();
    //         e->setVisible();
    //     else {
    //         Displayable* e =  displayableVector.back();
    //         e->setInvisible();
    //     }
    // }
    if (bVisible) {
        if (std::stoi(data) == 1) {
            displayableVector.back()->setVisible();
        } else {
            displayableVector.back()->setInvisible();
        }
        bVisible = false;
    } else if(bPosX){
        displayableVector.back()->setPosX(std::stoi(data));
        bPosX = false;
    } else if (bPosY) {
        displayableVector.back()->setPosY(std::stoi(data));
        bPosY = false;
    } else if (bWidth){
        displayableVector.back()->setWidth(std::stoi(data));
        bWidth = false;
    } else if (bHeight) {
        displayableVector.back()->setHeight(std::stoi(data));
        bHeight = false;
    } else if(bAM) {
        actionVector.back()->setMessage(data);
        bAM = false;
    } else if (bAIV) {
        actionVector.back()->setIntValue(std::stoi(data));
        bAIV = false;
    } else if (bACV) {
        char c = *data.c_str();
        actionVector.back()->setCharValue(c);
        bACV = false;
    } else if (bHP) {
        displayableVector.back()->setHp(std::stoi(data));
        bHP = false;
    } else if (bHPmoves) {
        displayableVector.back()->setHpMove(std::stoi(data));
        bHPmoves = false;
    } else if (bMaxHit) {
        displayableVector.back()->setMaxhit(std::stoi(data));
        bMaxHit = false;
    } else if (bIIV) {
        displayableVector.back()->setIntValue(std::stoi(data));
        bIIV = false;
    } else if (bType) {
        char c = *data.c_str();
        displayableVector.back()->setType(c);
        bType = false;
    }

    char *qNameStr = xercesc::XMLString::transcode(qName);
    // CHECK IF STACKS ARE EMPTY (DISPLAYABLE AND ACTION)
    // if (displayableVector.back() == NULL) {
    //     std::cout << "Stack is Empty!" << std::endl;
    // } else 
    if (case_insensitive_match(qNameStr, "Room")) {
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "Scroll")) {
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "ItemAction")) {
        actionVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "Player")){
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "CreatureAction")) {
        actionVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "Sword")) {
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr,  "Monster")) {
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "Armor")) {
        displayableVector.pop_back();
    } else if (case_insensitive_match(qNameStr, "Passage")) {
        displayableVector.pop_back();
    }

    // EMAD HELPED WITH THIS CODE  -->
    // if (case_insensitive_match(qNameStr, "Room")) {
    //     if (typeid(displayableVector.back()).name() == "Room*") 
    //         if (displayableVector.back() == NULL) {
    //             std::cout << "Stack is Empty!" << std::endl;
    //         } else {
    //             Room* r = displayableVector.back(); // might not be necessary
    //             dispalyableVector.pop_back();
    //         }
    // }
    // char *  qNameStr = xercesc::XMLString::transcode(qName);
    // if (case_insensitive_match(qNameStr,"Students")) {
    //     if (studentCount != maxStudents) {
    //         std::cout <<"wrong number of students parsed, should be " << maxStudents << ", is " << studentCount << std::endl;
    //     }
    // } else if (case_insensitive_match(qNameStr,"Student")) {
    //     studentBeingParsed = nullptr;
    // } else if (case_insensitive_match(qNameStr,"Activity")) {
    //     activityBeingParsed->toString();
    //     activityBeingParsed = nullptr;
    // }
    xercesc::XMLString::release(&qNameStr);

}

Dungeon* GameXMLHandler::returnDungeon() {
    return dungeon;
}

void GameXMLHandler::fatalError(const xercesc::SAXParseException& exception) {
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}

void GameXMLHandler::addDisplay(Displayable *display) {
    displayableVector[displayCount++] = display;
}