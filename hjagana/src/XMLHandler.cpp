#include "XMLHandler.hpp"

//From https://www.tutorialspoint.com/case-insensitive-string-comparison-in-cplusplus
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

XMLHandler::XMLHandler() {
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

Dungeon* XMLHandler::returnDungeon() {
    return dungeon;
}

void XMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){

        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }

        if (case_insensitive_match(qNameStr,"Dungeon")) {
			std::string itemName = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string dungeonWidth = xmlChToString(getXMLChAttributeFromString(attributes,"width"));
            int width = std::stoi(dungeonWidth);
            std::string topHeightString = xmlChToString(getXMLChAttributeFromString(attributes,"topHeight"));
            int topHeight = std::stoi(topHeightString);
            std::string gameHeightString = xmlChToString(getXMLChAttributeFromString(attributes,"gameHeight"));
            int gameHeight = std::stoi(gameHeightString);
            std::string bottomHeightString = xmlChToString(getXMLChAttributeFromString(attributes,"bottomHeight"));
            int bottomHeight = std::stoi(bottomHeightString);

            dungeon = &Dungeon::getDungeon(itemName, width, gameHeight);

            dungeon->setwidth(width);
            dungeon->setTopHeight(topHeight);
            dungeon->setGameHeight(gameHeight);
            dungeon->setBottomHeight(bottomHeight);

        } else if (case_insensitive_match(qNameStr,"Rooms")) {

        }else if (case_insensitive_match(qNameStr,"Room")) {
            std::string roomCountString = xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            // int roomCount = std::stoi(roomCountString);
            Room * room;
            room = new Room(roomCountString);

            displaysVector.push_back(room);

            dungeon->addRoom((Room *) room);

        } else if (case_insensitive_match(qNameStr,"visible")) {
            bVisible = true;

        } else if (case_insensitive_match(qNameStr,"posX")) {
            bPosX = true;

        } else if (case_insensitive_match(qNameStr,"posY")) {
            bPosY = true;

        } else if (case_insensitive_match(qNameStr,"width")) {
            bWidth = true;

        } else if (case_insensitive_match(qNameStr,"height")) {
            bHeight = true;

        } else if (case_insensitive_match(qNameStr,"type")) {
            bType = true;

        } else if (case_insensitive_match(qNameStr,"Scroll")) {
			std::string scrollNameString = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string roomCountString = xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            int roomCount = std::stoi(roomCountString);
            std::string serialString = xmlChToString(getXMLChAttributeFromString(attributes,"serial"));
            int serial = std::stoi(serialString);

            Scroll * scroll;
            scroll = new Scroll(scrollNameString);
            scroll->setId(roomCount, serial);
            scroll->setName("Scroll");

            displaysVector.push_back(scroll);

            // dungeon->addItem(scroll);

        } else if (case_insensitive_match(qNameStr,"ItemAction")) {
            std::string itemActionNameString = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string itemActionTypeString = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
            Creature*  creature;
            creature = new Creature();
            ItemAction * itemaction;
            itemaction = new ItemAction(creature);
            actionVector.push_back(itemaction);

        } else if (case_insensitive_match(qNameStr,"actionMessage")) {
            bActionMessage = true;

        } else if (case_insensitive_match(qNameStr,"actionIntValue")) {
            bActionIntValue = true;

        } else if (case_insensitive_match(qNameStr,"actionCharValue")) {
            bActionCharValue = true;

        } else if (case_insensitive_match(qNameStr,"Player")) {
            std::string playerNameString = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string playerRoomString = xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            // int playerRoomNum = std::stoi(playerRoomString);
            std::string playerSerialString = xmlChToString(getXMLChAttributeFromString(attributes,"serial"));
            // int playerSerialNum = std::stoi(playerSerialString);

            Player *player;
            player = new Player();

            player->setName(playerNameString);

            displaysVector.push_back(player);
            dungeon->addPlayer(player);

        } else if (case_insensitive_match(qNameStr,"hp")) {
            bHp = true;

        } else if (case_insensitive_match(qNameStr,"hpMoves")) {
            bHpMoves = true;

        } else if (case_insensitive_match(qNameStr,"maxHit")) {
            bMaxHit = true;

        } else if (case_insensitive_match(qNameStr,"CreatureAction")) {
            std::string creatureActionName = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string creatureActionType = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
            
            Creature * creature;
            creature = new Creature;
            CreatureAction *creatureaction;
            creatureaction = new CreatureAction(creature);

            actionVector.push_back(creatureaction);

        }else if (case_insensitive_match(qNameStr, "Sword")){
            std::string swordName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            std::string swordRoom = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
            int swordRoomNum = std::stoi(swordRoom);
            std::string swordSerial = xmlChToString(getXMLChAttributeFromString(attributes, "serial"));
            int swordSerialNum = std::stoi(swordSerial);

            Sword * sword;
            sword = new Sword(swordName);
            sword->setId(swordRoomNum, swordSerialNum);
            sword->setName("Sword");

            displaysVector.push_back(sword);
            // dungeon->addItem(sword);

        } else if (case_insensitive_match(qNameStr,"ItemIntValue")) {
            bItemIntValue = true;

        } else if (case_insensitive_match(qNameStr,"Monster")) {
            std::string monsterNameString = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string monsterRoomString = xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            int monsterRoomNum = std::stoi(monsterRoomString);
            std::string monsterSerialString = xmlChToString(getXMLChAttributeFromString(attributes,"serial"));
            int monsterSerialNum = std::stoi(monsterSerialString);

            Monster *monster;
            monster = new Monster();
            monster->setName(monsterNameString);
            monster->setId(monsterRoomNum, monsterSerialNum);

            displaysVector.push_back(monster);
            dungeon->addCreatue(monster);

        } else if (case_insensitive_match(qNameStr,"Armor")) {
            std::string armorNameString = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            // int roomCount= std::stoi(roomCountString);
            std::string armorRoomString = xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            int armorRoomNum = std::stoi(armorRoomString);
            std::string armorSerialString = xmlChToString(getXMLChAttributeFromString(attributes,"serial"));
            int armorSerialNum = std::stoi(armorSerialString);
            Armor *armor;
            armor = new Armor(armorNameString);
            armor->setName("Armor");
            armor->setId(armorRoomNum, armorSerialNum);

            displaysVector.push_back(armor);
            // dungeon->addItem(armor);

        } else if(case_insensitive_match(qNameStr, "Passages")){

        } else if (case_insensitive_match(qNameStr,"Passage")) {
            std::string passageRoom1String = xmlChToString(getXMLChAttributeFromString(attributes,"room1"));
            int passageRoom1 = std::stoi(passageRoom1String);
            std::string passageRoom2String = xmlChToString(getXMLChAttributeFromString(attributes,"room2"));
            int passageRoom2 = std::stoi(passageRoom2String);
            
            Passage * passage;
            passage = new Passage();
            passage->setId(passageRoom1, passageRoom2);

            displaysVector.push_back(passage);
            dungeon->addPassage(passage);
        } else {
            std::cout <<"Unknown qname: " << qNameStr << std::endl;
        }
        xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName)  {
    char * qNameStr = xercesc::XMLString::transcode(qName);

    if (bVisible) {
        Displayable *elementName = displaysVector.back();
        if (std::stoi(data) == 1){
            elementName->setVisible();
        }
        else{
            elementName->setInvisible();
        }
        bVisible = false;

    } else if (bPosX) {
        Displayable *elementName = displaysVector.back();
        elementName->setXPos(std::stoi(data));
        bPosX = false;

    } else if (bPosY) {
        Displayable *elementName = displaysVector.back();
        elementName->setYPos(std::stoi(data));
        bPosY = false;

    } else if (bWidth) {
        Displayable *elementName = displaysVector.back();
        elementName->setWidht(std::stoi(data));
        bWidth = false;

    } else if (bHeight) {
        Displayable *elementName = displaysVector.back();
        elementName->setHeight(std::stoi(data));
        bHeight = false;

    } else if (bType) {
        Displayable *elementName = displaysVector.back();
        elementName->setType(*data.c_str());
        bType = false;

    } else if (bActionMessage) {
        Action *elementName = actionVector.back();
        elementName->setMessage(data);
        bActionMessage = false;

    } else if (bActionIntValue) {
        Action *elementName = actionVector.back();
        elementName->setIntValue(std::stoi(data));
        bActionIntValue = false;

    } else if (bActionCharValue) {
        Action *elementName = actionVector.back();
        char actionChar = *data.c_str();
        elementName->setCharValue(actionChar);
        bActionCharValue = false;

    } else if (bHp) {
        Displayable *elementName = displaysVector.back();
        elementName->setHp(std::stoi(data));
        bHp = false;

    } else if (bHpMoves) {
        Displayable *elementName = displaysVector.back();
        elementName->setHpMove(std::stoi(data));
        bHpMoves = false;

    } else if (bMaxHit) {
        Displayable *elementName = displaysVector.back();
        elementName->setMaxHit(std::stoi(data));
        bMaxHit = false;

    } else if (bItemIntValue) {
        Displayable *elementName = displaysVector.back();
        elementName->setIntValue(std::stoi(data));
        bItemIntValue = false;
    }

    //check if stack is empty?? maybe if you want
    if (case_insensitive_match(qNameStr,"Room")){
        displaysVector.pop_back();

    } else if (case_insensitive_match(qNameStr, "Scroll")){
        Item* item = (Item*) displaysVector.back();

        displaysVector.pop_back();

        Room * room = dynamic_cast<Room*> (displaysVector.back());
        if(room){
            item->setXPos(room->getXPos() + item->getXPos());
            item->setYPos(room->getYPos() + item->getYPos());
            dungeon->addItem(item);
        }
        else{
            Player * player = dynamic_cast<Player*> (displaysVector.back());
            if(player){
                player->setWeapon(item);
            }
        }
    } else if (case_insensitive_match(qNameStr, "ItemAction")){
        actionVector.pop_back();

    } else if (case_insensitive_match(qNameStr, "Player")){
        Player* player = (Player*) displaysVector.back();

        displaysVector.pop_back();
        Room * room = (Room*) displaysVector.back();
        room->setCreature(player);
        player->setXPos(room->getXPos() + player->getXPos());
        player->setYPos(room->getYPos() + player->getYPos());

    } else if (case_insensitive_match(qNameStr, "CreatureAction")){
        actionVector.pop_back();

    } else if (case_insensitive_match(qNameStr, "Sword")){
        Item* item = (Item*) displaysVector.back();

        displaysVector.pop_back();

        Room * room = dynamic_cast<Room*> (displaysVector.back());
        if(room){
            item->setXPos(room->getXPos() + item->getXPos());
            item->setYPos(room->getYPos() + item->getYPos());
            dungeon->addItem(item);
        }
        else{
            Player * player = dynamic_cast<Player*> (displaysVector.back());
            if(player){
                player->setWeapon(item);
            }
        }
        

    } else if (case_insensitive_match(qNameStr, "Monster")){
        Monster* monster = (Monster*) displaysVector.back();

        displaysVector.pop_back();
        Room * room = (Room*) displaysVector.back();
        room->setCreature(monster);
        monster->setXPos(room->getXPos() + monster->getXPos());
        monster->setYPos(room->getYPos() + monster->getYPos());

    } else if (case_insensitive_match(qNameStr, "Armor")){
        // Armor *armor;
        // armor = new Armor(armorNameString);
        // armor->setName(armorNameString);
        // armor->setId(armorRoomNum, armorSerialNum);

        // displaysVector.push_back(armor);
        Item* item = (Item*) displaysVector.back();

        displaysVector.pop_back();

        Room * room = dynamic_cast<Room*> (displaysVector.back());
        if(room){
            item->setXPos(room->getXPos() + item->getXPos());
            item->setYPos(room->getYPos() + item->getYPos());
            dungeon->addItem(item);
            //add to dungeon?
        }
        else{
            Player * player = dynamic_cast<Player*> (displaysVector.back());
            if(player){
                player->setArmor(item);
            }
        }
    //this works
    //but what to do when its not a part of a room and a part of the player??
    //if player you can set weapon
    } else if (case_insensitive_match(qNameStr, "Passage")){
        displaysVector.pop_back();
    }
    xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;   
        if (DEBUG > 1) {
			std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

void XMLHandler::fatalError(const xercesc::SAXParseException& exception)
{
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}
