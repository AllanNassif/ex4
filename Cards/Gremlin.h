

#ifndef GREMLIN_H_
#define GREMLIN_H_

#include "Battle.h"

class Gremlin : public Battle {

public:
    
    /*
     * C'tor for Gremlin class
     * 
     * @return
     * New Gremlin Card with 5 force, 2 coins loot, and 10 health points to decrease
     * 
    */
    Gremlin();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Gremlin(const Gremlin&) = default;
    virtual ~Gremlin() = default;
    Gremlin& operator=(const Gremlin&) = default;


private:

    /* default foce in Germlin Card*/
    static const int DEFAULT_FORCE = 5;
    
    /* default loot in Germlin Card */
    static const int DEFAULT_LOOT = 2;
    
    /* default hp to decrease in Gremlin card */
    static const int DEFAULT_HP_TO_DECREASE = 10;
    
};


#endif //GREMLIN_H_