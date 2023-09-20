#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"
static int hades = 0;
static int omegaweapon = 0;
static int id_tmp = 1;
static int index = 0;
static int last_id_tmp = 0;
enum ItemType { Antidote = 0, PhoenixdownI, PhoenixdownII, PhoenixdownIII, PhoenixdownIV };

//Forward Declaration
class BaseOpponent;
class BaseItem;
class BaseBag;


enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };

class Events {
private:
    int* events;
    int size;
public:
    Events(const string& filename);
    int count() const;
    int get(int i) const;
    ~Events() {
        delete[] events;
    }
};

class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag* bag;
    KnightType knightType;

public:
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    void setKnight(KnightType knightType) {
        this->knightType = knightType;
    }
    string toString() const;
    BaseBag* getbasebag() {
        return bag;
    }
    void setbasebag(BaseBag* bag) {
        this->bag = bag;
    }
    KnightType getknighttype() {
        return knightType;
    }
    int getlevel() {
        return level;
    }
    void setlevel(int level) {
        this->level = level;
    }
    int getantidote() {
        return antidote;
    }
    void setantidote(int antidote) {
        this->antidote = antidote;
    }
    int getphoenixdownI() {
        return phoenixdownI;
    }
    void setphoenixdownI(int phoenixdownI) {
        this-> phoenixdownI= phoenixdownI;
    }
    int gethp() {
        return hp;
    }
    int getmaxhp() {
        return maxhp;
    }
    void sethp(int hp) {
        this->hp = hp;
    }
    void setgil(int gil) {
        this->gil = gil;
    }
    int getgil() {
        return gil;
    }
};

class PaladinKnight : public BaseKnight {
public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class LancelotKnight : public BaseKnight {
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class DragonKnight : public BaseKnight {
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class NormalKnight : public BaseKnight {
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

/// @BaseItem
class BaseItem {
protected:
    ItemType* itemType = new ItemType;
public:
 
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;
    virtual ItemType getItemtype() = 0;
    virtual void  setItemtype(int Itemtype) = 0;
};

class ANTIDOTE : public BaseItem {
protected:
    int poison = 0;
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    ItemType getItemtype() ;
    void  setItemtype(int Itemtype) { int a = 5; };
    // string tostring() ;
};
class PhoenixDownI :public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    ItemType getItemtype();
    void  setItemtype(int Itemtype) { int a = 5; };
   // string tostring();

};

class PhoenixDownII : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    ItemType getItemtype();
    void  setItemtype(int Itemtype) { int a = 5; };
   // string tostring();
};

class PhoenixDownIII : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    ItemType getItemtype();
    void  setItemtype(int Itemtype) { int a = 5; };
   // string tostring();
};

class PhoenixDownIV : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    ItemType getItemtype();
    void  setItemtype(int Itemtype) { int a = 5; };
    //string tostring();
};

class BaseBag {
public:
    BaseKnight* knight;

public:
    class Node;
    int size = 0;

    virtual int getSize() {
        return this->size;
    }
    virtual void setSize(int size) {
         this->size=size;
    }
    virtual bool insertFirst(BaseItem* item) {
        return false;
    }
    virtual BaseItem* get(ItemType itemType) {
        return nullptr;
    }
    virtual string toString() const {
        return "";
    }
    virtual void deletenode() {}
    virtual Node* gethead() {
        return nullptr;
    }
    virtual ~BaseBag(){}
    virtual BaseItem* findmatchedphonix(BaseKnight* knight) {
      return nullptr;
    }
    class Node {
    protected:
        BaseItem* item;
        Node* next;

    public:
        Node(BaseItem* item, Node* next) {
            this->item = item;
            this->next = next;
        }
        BaseItem* getitem() {
            return item;
        }
        Node* getnext() {
            return next;
        }
        void setnext(Node* a) {
            this->next = a;
        }
        void setItem(BaseItem* a) {
            this->item = a;
        }

    };

};

class BagPaladinKnight : public BaseBag {
protected:
    Node* head = NULL;

    BaseKnight* knight;
    int size = 0;
    BaseItem* item;
public:


    BagPaladinKnight(BaseKnight* knight, int a, int b) {
        int num_of_phonix1 = a <= 5 ? a : 5;
        int  num_of_antidote = b <= 5 ? b : 5;
        while (num_of_phonix1 > 0) {
            item=new PhoenixDownI;
            item->getItemtype();
            (insertFirst(item));
        
            num_of_phonix1--;
        }
        while (num_of_antidote) {
            item = new ANTIDOTE;
            item->getItemtype();
            (insertFirst(item));
            num_of_antidote--;
        }
        this->knight = knight;
       
    }
    Node* gethead() {
        return head;
    }
     int getSize() {
        return this->size;
     }
     void setSize(int size) {
         this->size = size;
     }
    bool insertFirst(BaseItem* item);
    BaseItem* get(ItemType itemType);
    string toString() const;
    void deletenode();
    BaseItem* findmatchedphonix(BaseKnight* knight) {
        Node* tmp = head;
        while (tmp!=nullptr) {
            if (tmp->getitem()->canUse(knight)) {
                tmp->getitem()->use(knight);
                return get(tmp->getitem()->getItemtype());
                
            }
            else {
                tmp=tmp->getnext();
            }
        }
        return nullptr;
    }
    ~BagPaladinKnight() {
        Node* tmp = head;
        while (tmp != nullptr) {
            head = head->getnext();
            delete tmp;
            tmp = head;
        }
    }
};

class BagLancelotKnight : public BaseBag {
private:
    Node* head = NULL;

    BaseKnight* knight;
    int size = 0;
    BaseItem* item;
public:

    BagLancelotKnight(BaseKnight* knight, int a, int b) {
        int num_of_phonix1 = a <= 5 ? a : 5;
        int  num_of_antidote = b <= 5 ? b : 5;
        while (num_of_phonix1 > 0) {
            item = new PhoenixDownI;
            item->getItemtype();
            insertFirst(item);
            num_of_phonix1--;
        }
        while (num_of_antidote) {
            item = new ANTIDOTE;
            item->getItemtype();
            insertFirst(item);
            num_of_antidote--;
        }
        this->knight = knight;
    }
    Node* gethead() {
        return head;
    }
    int getSize() {
        return this->size;
    }
    void setSize(int size) {
        this->size = size;
    }
    bool insertFirst(BaseItem* item);
    BaseItem* get(ItemType itemType);
    string toString() const;
    void deletenode();
    BaseItem* findmatchedphonix(BaseKnight* knight) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->getitem()->canUse(knight)) {
                tmp->getitem()->use(knight);
                return get(tmp->getitem()->getItemtype());

            }
            else {
                tmp=tmp->getnext();
            }
        }
        return nullptr;
    }
    ~BagLancelotKnight() {
        Node* tmp = head;
        while (tmp != nullptr) {
            head = head->getnext();
            delete tmp;
            tmp = head;
        }
    }
};

class BagDragonKnight : public BaseBag {
private:
    Node* head = NULL;

    BaseKnight* knight;
    int size = 0;
    BaseItem* item;
public:

    BagDragonKnight(BaseKnight* knight, int a, int b) {
        int num_of_phonix1 = a <= 5 ? a : 5;
        int  num_of_antidote = b <= 5 ? b : 5;
        while (num_of_phonix1 > 0) {
            item = new PhoenixDownI;
            item->getItemtype();
            insertFirst(item);
            num_of_phonix1--;
        }
        while (num_of_antidote) {
            item = new ANTIDOTE;
            item->getItemtype();
            insertFirst(item);
            num_of_antidote--;
        }
        this->knight = knight;
    }
    Node* gethead() {
        return head;
    }
    int getSize() {
        return this->size;
    }
    void setSize(int size) {
        this->size = size;
    }
    bool insertFirst(BaseItem* item);
    BaseItem* get(ItemType itemType);
    string toString() const;
    void deletenode();
    BaseItem* findmatchedphonix(BaseKnight* knight) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->getitem()->canUse(knight)) {
                tmp->getitem()->use(knight);
                return get(tmp->getitem()->getItemtype());

            }
            else {
                tmp=tmp->getnext();
            }
        }
        return nullptr;
    }
    ~BagDragonKnight() {
        Node* tmp = head;
        while (tmp != nullptr) {
            head = head->getnext();
            delete tmp;
            tmp = head;
        }
    }
};

class BagNormalKnight : public BaseBag {
private:
    Node* head = NULL;

    BaseKnight* knight;
    int size = 0;
    BaseItem* item;
public:

    BagNormalKnight(BaseKnight* knight, int a, int b) {
        int num_of_phonix1 = a <= 5 ? a : 5;
        int  num_of_antidote = b <= 5 ? b : 5;
        while (num_of_phonix1 > 0) {

            item = new PhoenixDownI;
            item->getItemtype();
            insertFirst(item);

            num_of_phonix1--;
        }
        while (num_of_antidote) {
            item = new ANTIDOTE;
            item->getItemtype();
            insertFirst(item);
            num_of_antidote--;
        }
        this->knight = knight;
    }
    Node* gethead() {
        return head;
    }
     int getSize() {
        return this->size;
     }
     void setSize(int size) {
         this->size = size;
     }
    bool insertFirst(BaseItem* item);
    BaseItem* get(ItemType itemType);
    string toString() const;
    void deletenode();
    BaseItem* findmatchedphonix(BaseKnight* knight) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->getitem()->canUse(knight)) {
                tmp->getitem()->use(knight);
                return get(tmp->getitem()->getItemtype());

            }
            else {
               tmp= tmp->getnext();
            }
        }
        return nullptr;
    }
    ~BagNormalKnight() {
        Node* tmp = head;
        while (tmp != nullptr) {
            head = head->getnext();
            delete tmp;
            tmp = head;
        }
    }
};

class ArmyKnights {
private:
    BaseKnight** allKnight;
    int size;
    int PaladinShield = 0, LancelotSpear = 0, GuinevereHair = 0, ExcaliburSword = 0;
    int event;
public:
    ArmyKnights(const string& file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent* opponent);
    bool adventure(Events* events);
    int count() const { return size; };
    BaseKnight* lastKnight() const {
        if (size == 0) return nullptr;
        else {
           return allKnight[id_tmp];

        }
    };

    bool hasPaladinShield() const {
        return PaladinShield > 0 ? 1 : 0;
    };
    bool hasLancelotSpear() const {
        return LancelotSpear > 0 ? 1 : 0;
    };
    bool hasGuinevereHair() const {
        return GuinevereHair > 0 ? 1 : 0;
    };
    bool hasExcaliburSword() const {
        return ExcaliburSword > 0 ? 1 : 0;
    };

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseOpponent {
public:
    int levelO;
    int base_damage;
    int gil;
    int get_levelO() {
        return this->levelO;
    }
    int calculate_levelO(int index, int ma_event);
    static BaseOpponent* getlopcon(int i);
};

class Madbear : public BaseOpponent {
public:
    Madbear() {
        base_damage = 10;
        gil = 100;
    }
};

class Bandit : public BaseOpponent {
public:
    Bandit() {
        base_damage = 15;
        gil = 150;
    }

};

class LordLupin : public BaseOpponent {
public:
    LordLupin() {
        base_damage = 45;
        gil = 450;
    }

};

class Elf : public BaseOpponent {
public:
    Elf() {
        base_damage = 75;
        gil = 750;
    }

};

class Troll :public BaseOpponent {
public:
    Troll() {
        base_damage = 95;
        gil = 800;
    }
};

class Tornbery :public BaseOpponent {

};
class QueenOfCards :public BaseOpponent {

};
class NinaDeRings :public BaseOpponent {

};
class DurianGarden :public BaseOpponent {

};
class OmegaWeapon :public BaseOpponent {

};
class Hades :public BaseOpponent {

};

class KnightAdventure {
private:
    ArmyKnights* armyKnights;
    Events* events;

public:
    KnightAdventure();
    ~KnightAdventure() {
        delete armyKnights;
        delete events;
    } // TODO:

    void loadArmyKnights(const string&);
    void loadEvents(const string&);
    void run();
};

#endif // __KNIGHT2_H__