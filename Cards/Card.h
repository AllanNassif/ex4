
#ifndef Card_H
#define Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"


class Card {

public:
    
    /*
     * C'tor for Card class
     * 
     * @param cardName - name of the card 
     * @return
     * New Card
     * 
    */
    Card(const std::string& cardName);

    /*
     * Handling the player's applyEncounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * getCardName - gets the card name
     *
     * @return 
     * return the name of the card.
    */
    const std::string& getCardName() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card&) = default;

protected:

    /**
     * operator<< - prints the card details with the output stream given in the following format:
     * 
     * 
     * @param stream - output stream
     * @param card - Card to print
     * @return
     * return the output stream that has been used
     * 
    */
    friend std::ostream& operator<<(std::ostream& stream, const Card& card);

    /*
     * printCardInfo - Prints the card info
     *
     * @param stream - output stream
     * @return
     *      void
    */
    virtual void printCardInfo(std::ostream& stream) const;


private:

    std::string m_cardName;

};




#endif //Card_H
