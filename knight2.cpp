#include "knight2.h"


bool checkPrime(int n) {
    if (n <= 1) return 0;
    else if (n == 2) return 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
bool checkPytago(int n) {//323
    int a = n % 10;
    n = n / 10;
    int b = n % 10;
    n = n / 10;
    int c = n % 10;
    if (a <= 0 || b <= 0 || c <= 0) return 0;
    int maxvalue = max(max(a, b), c);
    if (maxvalue == a) {
        if (a * a == b * b + c * c)
            return 1;
    }
    if (maxvalue == b) {
        if (b * b == a * a + c * c)
            return 1;
    }
    if (maxvalue == c) {
        if (c * c == b * b + a * a)
            return 1;
    }
    return 0;
}

/* * * BEGIN implementation of class Events * * */
Events::Events(const string& filename) {
    fstream file(filename, ios::in);
    file >> this->size;
    events = new int[size];
    for (int i = 0; i < size; i++) {
        file >> events[i];
    }
    file.close();
}

int Events::count() const {
    return size;
}
int Events::get(int i) const {
    return (size > 0 && i < size&& i >= 0) ? events[i] : -1;
}
/* * * END implementation of class Events * * */



/* * * BEGIN implementation of class BaseBag * * */

void BagPaladinKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}
void BagLancelotKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}
void BagDragonKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}
void BagNormalKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}

BaseItem* BagPaladinKnight::get(ItemType itemType) {
    
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->getitem()->getItemtype() == itemType) {
            BaseItem* tmp = ptr->getitem();
            ptr->setItem(head->getitem());
            head->setItem(tmp);
            Node* tmp_p = head;
            head = head->getnext();
            delete tmp_p;
            --size;
            return tmp;
        }
        ptr = ptr->getnext();
    }
    return nullptr;

}
BaseItem* BagLancelotKnight::get(ItemType itemType) {
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->getitem()->getItemtype() == itemType) {
            BaseItem* tmp = ptr->getitem();
            ptr->setItem(head->getitem());
            head->setItem(tmp);
            Node* tmp_p = head;
            head = head->getnext();
            delete tmp_p;
            --size;
            return tmp;
        }
        ptr = ptr->getnext();
    }
    return nullptr;

}
BaseItem* BagDragonKnight::get(ItemType itemType) {
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->getitem()->getItemtype() == itemType) {
            BaseItem* tmp = ptr->getitem();
            ptr->setItem(head->getitem());
            head->setItem(tmp);
            Node* tmp_p = head;
            head = head->getnext();
            delete tmp_p;
            --size;
            return tmp;
        }
        ptr = ptr->getnext();
    }
    return nullptr;

}
BaseItem* BagNormalKnight::get(ItemType itemType) {
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->getitem()->getItemtype() == itemType) {
            BaseItem* tmp = ptr->getitem();
            ptr->setItem(head->getitem());
            head->setItem(tmp);
            Node* tmp_p = head;
            head = head->getnext();
            delete tmp_p;
            --size;
            return tmp;
        }
        ptr = ptr->getnext();
    }
    return nullptr;


}
bool BagPaladinKnight::insertFirst(BaseItem* item) {


    if (head == nullptr)
        head = new Node(item, nullptr);
    else {
        Node* newItem = new Node(item, head);
        head = newItem;
    }
    size++;
    return 1;

}
bool BagLancelotKnight::insertFirst(BaseItem* item) {
    if (size > 16)
        return 0;

    if (head == nullptr)
        head = new Node(item, nullptr);
    else {
        Node* newItem = new Node(item, head);
        head = newItem;
    }
    size++;
    //knight->bag=head;
    return 1;

}
bool BagDragonKnight::insertFirst(BaseItem* item) {
    if (size > 14 || item->getItemtype()==Antidote) return 0;
    if (item->getItemtype() == Antidote) return 0;
    if (head == nullptr)
        head = new Node(item, nullptr);
    else {
        Node* newItem = new Node(item, head);
        head = newItem;
    }
    //knight->bag=head;
    size++;
    return 1;

}
bool BagNormalKnight::insertFirst(BaseItem* item) {
    if (size > 19)
        return 0;
    if (head == nullptr)
        head = new Node(item, nullptr);
    else {
        Node* newItem = new Node(item, head);
        head = newItem;
    }
    //knight->bag=head;
    size++;
    return 1;

}
string BagPaladinKnight::toString() const {
    Node* tmp = head;
    string typeitem[5] = { "Antidote", "PhoenixI","PhoenixII", "PhoenixIII", "PhoenixIV" };
    string s("");
    if (size == 0) {
        s += "Bag[count=" + to_string(size) + ";]";
        return s;
    }
    s += "Bag[count=" + to_string(size) + ";" + typeitem[tmp->getitem()->getItemtype()];
    tmp = tmp->getnext();
    while (tmp != nullptr) {
        s += "," + typeitem[tmp->getitem()->getItemtype()];
        tmp = tmp->getnext();
    }
    s += "]";
    return s;
}
string BagLancelotKnight::toString() const {
    Node* tmp = head;
    string typeitem[5] = { "Antidote", "PhoenixI","PhoenixII", "PhoenixIII", "PhoenixIV" };
    string s("");
    if (size == 0) {
        s += "Bag[count=" + to_string(size) + ";]";
        return s;
    }
    s += "Bag[count=" + to_string(size) + ";" + typeitem[tmp->getitem()->getItemtype()];
    tmp = tmp->getnext();
    while (tmp != nullptr) {
        s += "," + typeitem[tmp->getitem()->getItemtype()];
        tmp = tmp->getnext();
    }
    s += "]";
    return s;
}
string BagDragonKnight::toString() const {
    Node* tmp = head;
    string typeitem[5] = { "Antidote", "PhoenixI","PhoenixII", "PhoenixIII", "PhoenixIV" };
    string s("");
    if (size == 0) {
        s += "Bag[count=" + to_string(size) + ";]";
        return s;
    }
    s += "Bag[count=" + to_string(size) + ";" + typeitem[tmp->getitem()->getItemtype()];
    tmp = tmp->getnext();
    while (tmp != nullptr) {
        s += "," + typeitem[tmp->getitem()->getItemtype()];
        tmp = tmp->getnext();
    }
    s += "]";
    return s;
}

string BagNormalKnight::toString() const {
    Node* tmp = head;
    string typeitem[5] = { "Antidote", "PhoenixI","PhoenixII", "PhoenixIII", "PhoenixIV" };
    string s("");
    if (size == 0) {
        s += "Bag[count=" + to_string(size) + ";]";
        return s;
    }
    s += "Bag[count=" + to_string(size) + ";" + typeitem[tmp->getitem()->getItemtype()];
    tmp = tmp->getnext();
    while (tmp != nullptr) {
        s += "," + typeitem[tmp->getitem()->getItemtype()];
        tmp = tmp->getnext();
    }
    s += "]";
    return s;
}

/* * * END implementation of class BaseBag * * */



/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = { "PALADIN", "LANCELOT", "DRAGON", "NORMAL" };
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id)
        + ",hp:" + to_string(hp)
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    BaseKnight* knight = nullptr;
    if (checkPrime(maxhp)) {
        knight = new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        knight->setKnight(PALADIN);
        knight->hp = maxhp;
        knight->setbasebag(new BagPaladinKnight(knight, knight->getphoenixdownI(), knight->getantidote()));
    }
    else if (maxhp == 888) {
        knight = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        knight->setKnight(LANCELOT);
        knight->hp = maxhp;
        knight->setbasebag(new BagLancelotKnight(knight, knight->getphoenixdownI(), knight->getantidote()));
    }
    else if (checkPytago(maxhp)) {
        knight = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        knight->setKnight(DRAGON);
        knight->hp = maxhp;
        knight->setbasebag(new BagDragonKnight(knight, knight->getphoenixdownI(), knight->getantidote()));
    }
    else {
        knight = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        knight->setKnight(NORMAL);
        knight->hp = maxhp;
        knight->setbasebag(new BagNormalKnight(knight, knight->getphoenixdownI(), knight->getantidote()));
    }
    return knight;
}
//This is a derived class of BaseKnight : 
PaladinKnight::PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
}

LancelotKnight::LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
}

DragonKnight::DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
}

NormalKnight::NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
}
/* * * END implementation of class BaseKnight * * */



/* * * BEGIN implementation of class ArmyKnights * * */
bool ArmyKnights::adventure(Events* events) {
    while (index < events->count()) {
        BaseKnight* knight = allKnight[id_tmp];
        this->event = events->get(index);
        if (event <= 11) {
            BaseOpponent* opponent = new BaseOpponent();
            fight(opponent);
        }
        else if (event == 112) {
            BaseItem* baseitem = new PhoenixDownII();
            
            if (knight->getbasebag()->insertFirst(baseitem) == 0) {
                int a = id_tmp - 1;
                while (a >= 1) {
                    BaseKnight* knight1 = allKnight[a];
                    if (knight1->getbasebag()->insertFirst(baseitem) != 0) {
                        break;
                    }
                    a -= 1;
                }
            }

        }
        else if (event == 113) {
            BaseItem* baseitem = new PhoenixDownIII();
            if (knight->getbasebag()->insertFirst(baseitem) == 0) {
                int a = id_tmp - 1;
                while (a >= 1) {
                    BaseKnight* knight1 = allKnight[a];
                    if (knight1->getbasebag()->insertFirst(baseitem) != 0) {
                        break;
                    }
                    a -= 1;
                }
            }
        }
        else  if (event == 114) {
            BaseItem* baseitem = new PhoenixDownIV();
            if (knight->getbasebag()->insertFirst(baseitem) == 0) {
                int a = id_tmp - 1;
                while (a >= 1) {
                    BaseKnight* knight1 = allKnight[a];
                    if (knight1->getbasebag()->insertFirst(baseitem) != 0) {
                        break;
                    }
                    a -= 1;
                }
            }
        }
        else  if (event == 95) {
            PaladinShield = 1;
        }
        else if (event == 96) {
            LancelotSpear = 1;
        }
        else  if (event == 97) {
            GuinevereHair = 1;
        }
        else  if (event == 98) {
            if (PaladinShield == 1 && LancelotSpear == 1 && GuinevereHair == 1)
                ExcaliburSword = 1;
        }
        else if (event == 99) {
            if (ExcaliburSword == 1) {
                last_id_tmp = id_tmp; printInfo(); return 1;
            }
            if (PaladinShield == 1 && LancelotSpear == 1 && GuinevereHair == 1) {
                int a = id_tmp; int ulti = 5000; int l = 0; last_id_tmp = id_tmp;
                while (a > 0) {
                    BaseKnight* knight = allKnight[a];
                    if (knight->getknighttype() == DRAGON) {
                        int damage = knight->gethp() * knight->getlevel() * 0.075;
                        if (damage >= ulti) {
                            for (id_tmp; id_tmp > a; id_tmp--) {
                                BaseKnight* knight1 = allKnight[id_tmp];
                                if (knight1->getknighttype() == NORMAL) {
                                    l = 1;
                                    break;
                                }

                            }
                            if (l == 0) id_tmp = a;  
                            printInfo();
                            return 1;
                        }
                        else { a -= 1; --size; ulti = ulti - damage; }
                    }
                    else if (knight->getknighttype() == LANCELOT) {
                        int damage = knight->gethp() * knight->getlevel() * 0.05;
                        if (damage >= ulti) {
                            for (id_tmp; id_tmp > a; id_tmp--) {
                                BaseKnight* knight1 = allKnight[id_tmp];
                                if (knight1->getknighttype() == NORMAL) {
                                    l = 1;
                                    break;
                                }

                            }
                            if (l == 0) id_tmp = a;
                            printInfo();
                            return 1;
                        }
                        else { a -= 1; --size; ulti = ulti - damage; }
                    }
                    else if (knight->getknighttype() == PALADIN) {
                        int damage = knight->gethp() * knight->getlevel() * 0.06;
                        if (damage >= ulti) {
                            for (id_tmp; id_tmp > a; id_tmp--) {
                                BaseKnight* knight1 = allKnight[id_tmp];
                                if (knight1->getknighttype() == NORMAL) {
                                    l = 1;
                                    break;
                                }

                            }
                            if (l == 0) id_tmp = a;
                            printInfo();
                            return 1;
                        }
                        else { a -= 1; --size; ulti = ulti - damage; }
                    }
                    else { a -= 1; }
                    if (a == 0) {
                        size = 0;  printInfo(); return 0;
                    }
                }
            }
            else { last_id_tmp = id_tmp; size = 0;  printInfo(); return 0; }
        }
        index++;
        printInfo();
    }
}
bool ArmyKnights::fight(BaseOpponent* opponent) {
    opponent->calculate_levelO(index, event);
    BaseKnight* knight = allKnight[id_tmp]; PhoenixDownI phonix1;
    if (event == 1 || event == 2 || event == 3 || event == 4 || event == 5) {

        if (knight->getlevel() >= opponent->get_levelO() || knight->getknighttype() == LANCELOT || knight->getknighttype() == PALADIN) {
            if ((knight->getgil() + opponent->getlopcon(event)->gil) <= 999)
                knight->setgil(knight->getgil() + opponent->getlopcon(event)->gil);
            else {
                int a = id_tmp-1;
                int b = knight->getgil() + opponent->getlopcon(event)->gil - 999;
                knight->setgil(999);
                while (a > 0) {
                    BaseKnight* knight = allKnight[a];
                    if ((knight->getgil() + b) <= 999) {
                        knight->setgil(knight->getgil() + b);
                        break;
                    }
                    else {
                        b = knight->getgil() + b - 999;
                        knight->setgil(999);
                    }
                    a--;
                }
            }
        }
        else {
            knight->sethp(knight->gethp() - opponent->getlopcon(event)->base_damage * (opponent->get_levelO() - knight->getlevel()));
            knight->getbasebag()->findmatchedphonix(knight);
            if (knight->gethp() <= 0) {
                delete allKnight[id_tmp]; id_tmp--; size = id_tmp; return 0;
            }

        }
    }
    else if (event == 6) {
        //Antidote antidote;
        if (knight->getlevel() >= opponent->get_levelO()) {
            if ((knight->getlevel() + 1) <= 10)
                knight->setlevel(knight->getlevel() + 1);
        }
        else {
            if (knight->getknighttype() == DRAGON) return 1;
            else if (knight->getantidote() > 0) {
                knight->setantidote(knight->getantidote() - 1);
                knight->getbasebag()->get(Antidote);

            }
            else {
                if (knight->getbasebag()->getSize() <= 3) {
                    while (knight->getbasebag()->getSize() > 0) {
                        knight->getbasebag()->deletenode();
                    }
                }
                    
                else {
                    for (int i = 0; i < 3; i++) {
                        knight->getbasebag()->deletenode();
                    }
                }
                knight->sethp(knight->gethp() - 10);
                knight->getbasebag()->findmatchedphonix(knight);
                if (knight->gethp() <= 0) {
                    delete allKnight[id_tmp]; id_tmp--; size = id_tmp; return 0;
                }
            }

        }
    }
    else if (event == 7) {
        if (knight->getlevel() >= opponent->get_levelO()) {
            if ((knight->getgil() * 2) <= 999)
                knight->setgil(knight->getgil() * 2);
            else {
                int a = id_tmp-1;
                int b = knight->getgil() * 2 - 999;
                knight->setgil(999);
                while (a > 0) {
                    BaseKnight* knight = allKnight[a];
                    if ((knight->getgil() + b) <= 999) {
                        knight->setgil(knight->getgil() + b);
                        break;
                    }
                    else {
                        b = knight->getgil() + b - 999;
                        knight->setgil(999);
                    }
                    a--;
                }
            }
        }
        else if (knight->getknighttype() != PALADIN)
        {
            knight->setgil(knight->getgil() / 2.0);
        }
    }
    else if (event == 8) {
        if (knight->getgil() >= 50) {
            if (knight->gethp() < (1 / 3.0) * knight->getmaxhp()) {
                knight->setgil(knight->getgil() - 50);
                knight->sethp(knight->gethp() + (1 / 5.0) * knight->getmaxhp());
            }
        }
        else if (knight->getknighttype() == PALADIN) {
            knight->sethp(knight->gethp() + (1 / 5.0) * knight->getmaxhp());
        }
    }
    else if (event == 9) {
        knight->sethp(knight->getmaxhp());
    }
    else if (event == 10) {
        if (omegaweapon == 0) {
            if (knight->getknighttype() == DRAGON || (knight->gethp() == knight->getmaxhp() && knight->getlevel() == 10)) {
                knight->setlevel(10);
                knight->setgil(999);
                omegaweapon = 1;
            }
            else {
                knight->sethp(0);
                knight->getbasebag()->findmatchedphonix(knight);
                if (knight->gethp() <= 0) {
                    delete allKnight[id_tmp]; id_tmp--; size = id_tmp; return 0;
                }

            }
        }
    }
    else if (event == 11) {
        if (hades == 0) {
            if (knight->getlevel() == 10 || knight->getknighttype() == PALADIN && knight->getlevel() >= 8) {
                PaladinShield = 1;
                hades = 1;
            }
            else {
                knight->sethp(0);
                knight->getbasebag()->findmatchedphonix(knight);
                if (knight->gethp() <= 0) {
                    delete allKnight[id_tmp]; id_tmp--; size = id_tmp; return 0;
                }

            }
        }
    }
    return 1;
}

void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight* lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

ArmyKnights::ArmyKnights(const string& file_armyknights) {
    fstream file(file_armyknights, ios::in);
    file >> this->size;
    allKnight = new BaseKnight * [size + 1];
    int i = 1;
    int maxhp, level, gil, antidote, phoenixdownI;
    while (i <= size) {
        file >> maxhp >> level >> phoenixdownI >> gil >> antidote;

        allKnight[i] = BaseKnight::create(id_tmp++, maxhp, level, gil, antidote, phoenixdownI);
        i += 1;
    }
    id_tmp = i - 1;
    file.close();
}

ArmyKnights::~ArmyKnights() {
    
    for (int i = 1; i <= last_id_tmp; i++) {
        delete this->allKnight[i];
    }
    delete[] this->allKnight;
}
/* * * END implementation of class ArmyKnights * * */


/* * * BEGIN implementation of class BaseOpponent * * */
int BaseOpponent::calculate_levelO(int index, int ma_event) {
    this->levelO = (index + ma_event) % 10 + 1;
    return this->levelO;
}

BaseOpponent* BaseOpponent::getlopcon(int i) {
    BaseOpponent* opponent = nullptr;
    if (i == 1) {
        opponent = new Madbear;
    }
    if (i == 2) {
        opponent = new Bandit;
    }
    if (i == 3) {
        opponent = new LordLupin;
    }
    if (i == 4) {
        opponent = new Elf;
    }
    if (i == 5) {
        opponent = new Troll;
    }
    return opponent;
}

/* * * END implementation of class BaseOpponent * * */



/* * * BEGIN implementation of class BaseItem * * */

bool ANTIDOTE::canUse(BaseKnight* knight) {
    if (poison!=0)
        return 1;
    return 0;
}
bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->gethp() <= 0) return 1;
    return 0;
}
bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 4) return 1;
    return 0;
}
bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 3) return 1;
    return 0;
}
bool PhoenixDownIV::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 2) return 1;
    return 0;
}
void ANTIDOTE::use(BaseKnight* knight) {
    knight->setantidote(knight->getantidote() - 1);
}
void PhoenixDownI::use(BaseKnight* knight) {
    knight->sethp(knight->getmaxhp());
}
void PhoenixDownII::use(BaseKnight* knight) {
    knight->sethp(knight->getmaxhp());
}
void PhoenixDownIII::use(BaseKnight* knight) {
    if (knight->gethp() <= 0)
        knight->sethp((knight->getmaxhp()) / 3);
    else { knight->sethp(knight->gethp() + ((knight->getmaxhp()) / 4)); }
}
void PhoenixDownIV::use(BaseKnight* knight) {
    if (knight->gethp() <= 0)
        knight->sethp((knight->getmaxhp()) / 2);
    else { knight->sethp(knight->gethp() + ((knight->getmaxhp()) / 5)); }
}
ItemType ANTIDOTE::getItemtype() {
    return Antidote;
}
ItemType PhoenixDownI::getItemtype() {
    return PhoenixdownI;
}
ItemType PhoenixDownII::getItemtype() {
    return PhoenixdownII;
}
ItemType PhoenixDownIII::getItemtype() {
    return PhoenixdownIII;
}
ItemType PhoenixDownIV::getItemtype() {
    return PhoenixdownIV;
}
/* * * BEGIN implementation of class BaseItem * * */




KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

void KnightAdventure::loadArmyKnights(const string& filename) {
    armyKnights = new ArmyKnights(filename);
}

void KnightAdventure::loadEvents(const string& filename) {
    events = new Events(filename);
}

void KnightAdventure::run() {
    bool win_Ultimeci = armyKnights->adventure(events);
    armyKnights->printResult(win_Ultimeci);
}
/* * * END implementation of class KnightAdventure * * */