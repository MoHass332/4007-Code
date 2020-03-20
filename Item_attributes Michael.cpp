#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
public:
    string name; //declaring variables
    int weight;
    int value;

    Item(string n, int w, int v) : name(n), value(v), weight(w) {

    }

    virtual void print(void) {}
};

class Weapon : public Item
{
public:
    int damage;

    Weapon(int d, string n, int w, int v) :damage(d), Item(n, w, v) {} // show Damage ,  name, weight & value

    void print(void) { std::cout << " Name: " << name << "| Weight -> " << weight << " Value -> " << value << " Damage -> " << damage << endl; } // will display weapon name
};

class Armor : public Item
{
public:
    int block;

    Armor(int b, string n, int w, int v) :block(b), Item(n,w,v) {};

    void print(void) { std::cout << " Name: "<< name << "| Weight -> "<< weight << " Value -> " << value << " Block -> "<< block << endl; } // will display armor
};

class Inventory
{
public:
    vector<Item*> items; // Gets the item list
};


int main(void)
{
    Inventory myInventory;
    Item *wep1 = new Weapon(6, "Iron Sword", 5, 10); // Adding an items to the list
    Item *wep2 = new Weapon(5,"Dagger",4,7);


    Item *arm1 = new Armor(3, "Shield", 4, 8);
    Item *RareArmor = new Armor(55, "Shiny armor", 10, 200);



    myInventory.items.push_back(wep1);// adding the item include its values to the vector ↑
    myInventory.items.push_back(wep2);

    myInventory.items.push_back(arm1);
    myInventory.items.push_back(RareArmor);



    for (int i = 0; i < myInventory.items.size(); i++)
       myInventory.items[i]->print();

    for (int i = 0; i < myInventory.items.size(); i++)
       delete myInventory.items[i];

    return 0;
}