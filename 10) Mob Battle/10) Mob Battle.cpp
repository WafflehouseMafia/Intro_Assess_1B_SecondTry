// 10) Mob Battle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <thread> //This is what you need for the sleep_for command
using namespace std;



struct Attack // Definitely not just copying attack skills from the Limbus Company enemies of the exact same name. Who would ever do that.
{
    string name;
    int basePower;
    int coinNumber;
    int coinValue;
    int coinHeads = (rand() % (coinNumber + 1)); //Originally had this as a set value, which was dumb. Setting it to 2 means each roll was either all heads or all tails. This gives a NUMBER of coins that could be heads.

    // "Magnificent Spring Breeze" = 14 base, +6 on 1 coin, range 14 - 20

    // "Time of Harvest" = base 8, +6 on 3 coins, range 8 - 26
};

struct Enemy
{
    string name;
    float health;
    float attack;
    Attack Skill; //Why did I do this. This is was more complex than it needs to be

};

int Clash(struct Enemy& Dongbaek, struct Enemy& Dongrang) //Forgot to add a reference to the actual struct for a while, so the health wouldn't update. Fixed that now.
{

    Dongbaek.Skill = { "Magnificent Spring Breeze", 14, 1, +6 }; //Skill name, minimum value, number of coins to flip, and value added on flipping heads
    Dongrang.Skill = { "Time of Harvest", 8 , 3, +6 }; //Same as above

    float BaekRoll = Dongbaek.Skill.basePower + (Dongbaek.Skill.coinValue * Dongbaek.Skill.coinHeads);
    float RangRoll = Dongrang.Skill.basePower + (Dongrang.Skill.coinValue * Dongrang.Skill.coinHeads);

    cout << "The clash begins and blows fly, each trying to get a strike through.\n\n";

    if (BaekRoll > RangRoll)
    {
        Dongrang.health = Dongrang.health - Dongbaek.attack * (BaekRoll / 10); //From running it through, seems to do either 28 damage on tails, since it's damage * 1.4, or 40 on heads since it's damage *2.
        cout << Dongbaek.Skill.name << " wins the clash!\n\n";
        cout << "\nWith a swing of her fan, a blizzard of petals follows in its wake.\n\n";
        cout << "\nDongrang is overwhelmned in the blizzard and takes " << Dongbaek.attack * (BaekRoll / 10) << " damage, falling down to " << Dongrang.health << ".\n";
        return Dongrang.health;
    }

    else if (BaekRoll < RangRoll)
    {
        Dongbaek.health = Dongbaek.health - Dongrang.attack * (RangRoll / 10); //Updated values, so now it's more 50/50 on whether they win the clash, while keeping their damage as feast or famine.
        cout << Dongrang.Skill.name << " wins the clash!\n\n";
        cout << "\nDongrang's scythe comes down, gouging all in its way.\n\n";
        cout << "\nDongbaek is left staggering, the deep cut having dealt " << Dongrang.attack * (RangRoll / 10) << " damage and dropping her to " << Dongbaek.health << " health.\n";
        return Dongbaek.health;
    }

    else if (BaekRoll == RangRoll)
        cout << "\nYet neither seems to gain the edge.\n\n"; //Haven't seen it roll equal yet. Something might be wrong somewhere in the calc. gotta check it later


}



int main()
{

    srand(time(0));

    Enemy Dongbaek = { "Dongbaek", 300, 20 }; //Now that the combat function is working, changing health value to something slightly higher so that fights don't end in potentially 2 turns.
    Enemy Dongrang = { "Dongrang", 200, 20 }; //Since this guy can hit way harder, giving them less total health

    for (int i = 1; Dongbaek.health > 0 && Dongrang.health > 0; i++)
    {
        cout << "\n\nTurn " << i << "!\n\n";
        std::this_thread::sleep_for(std::chrono::seconds{ 1 }); //This command is essentially just Sleep, but not locked to Windows. IMPORTANT: only takes int, not float. if you need .1 seconds, just go to milliseconds

        Clash(Dongbaek, Dongrang);
        std::this_thread::sleep_for(std::chrono::milliseconds{ 2500 });
    }

    cout << "\n\n\nBattle done!\n\n";

    if (Dongbaek.health <= 0 && Dongrang.health > 0) //Pretty simple stuff. If Dongbaek hits either 0 or negative health while Dongrang still has even a little bit of health, Dongrang wins
    {
        cout << "\n\n\nDongbaek, the Spicebush, is left withering. Dongrang is left the winner, with " << Dongrang.health << " health left.\n\n\n";
    }
    else if (Dongrang.health <= 0 && Dongbaek.health > 0) //If Dongrang hits either 0 or negative health while Dongbaek still has a bit of health left, Dongbaek wins
    {
        cout << "\n\n\nDongrang, The One Who Denies All, falls to earth with a final cry. Dongbaek has emerged victorious with " << Dongbaek.health << " health left\n\n\n";
    }
    else if (Dongbaek.health <= 0 && Dongrang.health <= 0) //If they somehow both hit 0 or negative, they both lose. No way that can happen currently, but best to implement a failsafe.
    {
        cout << "\n\n\nWith one last strike both combatants slump in defeat, both struck down in tandem as their final breath mix in the open air.\n\n\n";
    }


}
