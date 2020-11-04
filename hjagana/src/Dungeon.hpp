#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <string>
#include <vector>

#include "Room.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Passage.hpp"
#include "Player.hpp"
// #include "ObjectDisplayGrid.hpp"

class Dungeon{
    private:
    static Dungeon * dungeonCreated;
    // int roomCount = 0;
    std::vector<Room * > rooms; 
    // int creatureCount = 0;
    std::vector<Monster * > creatures; 
    // int passageCount = 0;
    std::vector<Passage * > passages; 
    // int itemCount = 0;
    std::vector<Item * > items; 

    Player *player;

    int width;
    int topHeight;
    int gameHeight;
    int bottomHeight;


    public:
        Dungeon(); 
        virtual void addRoom(Room *room);
        virtual void addCreatue(Monster *creature);
        virtual void addPassage(Passage *passage);
        virtual void addPlayer(Player *_player);
        virtual void addItem(Item *item);

        static Dungeon& getDungeon(std::string name, int width, int gameHeight);
        virtual std::vector<Room *> getRooms();
        virtual std::vector<Monster *> getCreatures();
        virtual std::vector<Passage *> getPassages();
        virtual std::vector<Item *> getItems();
        virtual Player* getPlayer();

        virtual void Draw();

        virtual void setwidth(int _width);
        virtual int getwidth();
        virtual void setTopHeight(int _topheight);
        virtual int getTopHeight();
        virtual void setGameHeight(int _gameHeight);
        virtual int getGameHeight();
        virtual void setBottomHeight(int _bottomHeight);
        virtual int getBottomHeight();

        virtual bool checkMove(int x, int y);
        virtual bool checkCollision(int x, int y);
        virtual bool addItemToPack(int x, int y);
        virtual bool dropItemFromPack(int itemNum);

        virtual void displayItemsInPack();

        virtual bool checkArmor();
        virtual bool checkArmorInPack(int armorNum);

};

#endif /* DUNGEON_H_ */