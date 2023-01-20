

#ifndef DRAGON_H_
#define DRAGON_H_

#include "Battle.h"

class Dragon : public Battle {

public:
    
    /*
     * C'tor for Dragon class
     * 
     * @return
     * New Dragon Card with 25 force, 1000 coins loot, and 100 health points to decrease
     * 
    */
    Dragon();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon&) = default;
    virtual ~Dragon() = default;
    Dragon& operator=(const Dragon&) = default;


protected:

    /*
     * printCardInfo - Prints the card info of Dragon Card
     *
     * @param stream - output stream
     * @return
     *      void
    */
    virtual void printCardInfo(std::ostream& stream) const override;

private:

    /* default foce in Dragon Card*/
    static const int DEFAULT_FORCE = 25;
    
    /* default loot in Dragon Card */
    static const int DEFAULT_LOOT = 1000;
    
    /* default hp to decrease in Dragon card */
    static const int DEFAULT_HP_TO_DECREASE = 100;

    
};


#endif //DRAGON_H_