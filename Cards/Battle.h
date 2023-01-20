

#ifndef BATTLE_H_
#define BATTLE_H_

#include "Card.h"

class Battle : public Card {

public:
    
    /*
     * C'tor for Battle class
     * 
     * @param name - name of the battle card
     * @param loot - loot of battle card
     * @param force - force of battle card
     * @param damage - health points to reduce upon lossing in battle card
     * @return
     * Battle Card
     * 
    */
    Battle(const std::string& name ,int loot, int force , int damage);


    /*
     * Handling the player's applyEncounter with Battle card
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const; 

    /*
     * applyVictory - updating the player stats if the player won the battle
     * 
     * @param player - the player to update the stats
     * @return  
     *     void
     * 
    */
    virtual void applyVictory(Player &player) const;


    /*
     * applyDefeat - updating the player stats if the player lost the battle
     * 
     * @param player - the player to update the stats
     * @return  
     *     void
     * 
    */
    virtual void applyDefeat(Player &player) const;
    

    /*
     * battleResult - checks if the player won the fight
     * 
     * @return
     * true - if the player won the fight.
     * false - if the player lost the fight.
    */
    bool battleResult(Player& player) const;

    /*
     * getLoot - gets the loot of battle card
     * 
     * @return
     * returns the loot of battle card.
    */
    int getLoot() const;

    /*
     * getForce - gets the force of battle card
     * 
     * @return
     * returns the force of battle card.
    */
    int getForce() const;

    /*
     * getDamage - gets the health points to reduce of battle card
     * 
     * @return
     * returns the health points to reduce.
     * 
    */
    int getDamage() const;
    

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Battle(const Battle&) = default;
    Battle& operator=(const Battle&) = default;

    /* pure virtual destructor for abstract class */
    virtual ~Battle() = 0;

protected:

    /*
     * printCardInfo - Prints the card info
     *
     * @param stream - output stream
     * @return
     *      void
    */
    virtual void printCardInfo(std::ostream& stream) const;

private:

    int m_loot;
    int m_force;
    int m_damage;

    
};


#endif //BATTLE_H_