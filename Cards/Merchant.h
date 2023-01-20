

#ifndef MERCHANT_H_
#define MERCHANT_H_

#include "Card.h"

class Merchant : public Card {

public:
    
    /*
     * C'tor for Merchant class
     * 
     * @return
     * New Merchant Card 
     * 
    */
    Merchant();

    /*
     * Handling the player's applyEncounter with Merchant card:
     * if input is 0 - the player doesnt purchase the card.
     * if input is 1 - the player will purchase health points.
     * if input is 2 - the player will purchase force.
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Merchant(const Merchant&) = default;
    virtual ~Merchant() = default;
    Merchant& operator=(const Merchant&) = default;


private:

    /*
     * handlePayment - handle the payment accordingly to the player decision.
     * 
     * @return
     *  void
    */
    void handlePayment(Player& player,int playerDecision) const;

    /**
     * playerMerchantDecision - the player decision on merchant
     * 
     * @return
     * returns the player decision
    */
    int playerMerchantDecision() const;

    /* invalid decision of card to purchase */
    static const int INVALID_DECISION = -1;

    /* default hp to increase in Merchant card */
    static const int DEFAULT_MERCHANT_HEAL = 1;

    /* default hp to increase merchant card cost */
    static const int DEFAULT_MERCHANT_HEAL_COST = 5;

    /* default force to increase in Merchant card*/
    static const int DEFAULT_FORCE_TO_INCREASE = 1;
    
    /* default force to increase merchant card cost*/
    static const int DEFAULT_FORCE_TO_INCREASE_COST = 10;

    /* dont buy any boost */
    static const int DONT_PURCHASE_CARD = 0;

    /* dont purchase card cost */
    static const int DONT_PURCHASE_CARD_COST = 0;

    /* buying health points */
    static const int PURCHASE_HP = 1;

    /* buying force boost */
    static const int PURCHASE_FORCE = 2;

    /* line break */
    static const char LINE_BREAK = '\n';

    
};


#endif //MERCHANT_H_