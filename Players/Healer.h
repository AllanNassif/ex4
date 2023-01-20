
#ifndef Healer_H_
#define Healer_H_

#include "Player.h"

class Healer : public Player {

public:

    /*
     * C'tor for Healer class
     * 
     * @param name - The name of the player.
     * @return
     * New player of type Healer - level 1 , with 10 coins, with 5 force , with full hp(100)
     * 
    */
    Healer(const std::string& name);

    /*
     * heal - increases the hp of the player by twice the amount given as an argument, up to maxHP.
     * 
     * @param hpToAdd - Integer of the amount of hp to be added twice.
     * @return
     *     void
    */
    void heal(int hpToAdd) override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Healer(const Healer&) = default;
    virtual ~Healer() = default;
    Healer& operator=(const Healer&) = default;

protected:

    /*
     * getJobName - gets the name of the job.
     * 
     * @return
     * string with the name of the Healer job.
    */
    virtual std::string getJobName() const override;
    
};




#endif // Healer_H_