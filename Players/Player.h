

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>



/*The max level of player*/
static const int MAX_LEVEL = 10;

class Player {

public:
    


    /*
     * levelUp - increases the level by one.The level can be increased till level 10.
     * 
     * @return
     *     void
    */
    void levelUp();

    /*
     * getName - gets the name of the player.
     * 
     * @return
     * name of the player.
    */
    const std::string& getName() const;

    /*
     * getLevel - gets the level of the player.
     * 
     * @return
     * Integer of the player level.
    */
    int getLevel() const;

    /*
     * getForce - gets the force of the player.
     * 
     * @return
     * Integer of the player force.
    */
    int getForce() const;

    /*
     * getHP - gets the Health Points of the player.
     * 
     * @return
     * Integer of the player current hp.
    */
    int getHP() const;

    /*
     * getCoins - gets the amount of coins of the player.
     * 
     * @return
     * Integer of the player current coins.
    */
    int getCoins() const;

    

    /*
     * buff - increases the force of the player by the amount given as an argument.
     * 
     * @param forceToAdd - non negative integer of the amount of force to be added.
     * @return
     *     void
    */
    void buff(int forceToAdd);


    /*
     * unbuff - reduces the force of the player by the amount given as an argument
     * 
     * @param forceToReduce - non negative integer of the amount of the force to be reduced
     * @return  
     *     void
    */
    void unBuff(int forceToReduce);


    /*
     * heal - increases the hp of the player by the amount given as an argument, up to maxHP.
     * 
     * @param hpToAdd - non negative integer of the amount of hp to be added.
     * @return
     *     void
    */
    virtual void heal(int hpToAdd);

    /*
     * damamge - decreases the hp of the player by the amount given as an argument, up to 0.
     * 
     * @param hpToReduce - non negative nteger of the amount of hp to be reduced.
     * @return 
     *     void
    */
    void damage(int hpToReduce);

    /*
     * isKnockedOut - checks if the hp of the player is 0.
     * 
     * @return
     * true - if the hp of the player is 0, 
     * false - if the hp of the player is not 0.
    */
    bool isKnockedOut() const;

    /*
     * addCoins - adds the amount of coins of the player
     * 
     * @param coinsToAdd - non negative integer of the amount of coins to add to the player
     * @return
     *     void
    */
    virtual void addCoins(int coinsToAdd);

    /*
     * pay - makes a payment - decreases the amount of coins of the player
     * 
     * @param coinsToReduce - non negative integer of the amount of coins to be reducded.
     * @return
     * true - if the payment has been successfuly made,
     * false - thhe payment has been failed(the amount of coins have not been changed).
    */
    bool pay(int coinsToReduce);

    /*
     * getAttackStrength - gets the attack strength of player
     * the attack strength is defined to be the force of the player added with the level of the player
     * 
     * @return
     * Attack strength - player force + player level.
    */
    virtual int getAttackStrength() const;

    /*
     * C'tor for Player class
     * 
     * @param name - The name of the player.
     * @return
     * New player - level 1 , with 10 coins, with 5 force , with full hp(100)
     * 
    */
    Player(const std::string& name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& otherPlayer) = default;

protected:

    /*
     * operator << - prints the player details in the format:
     * <name> <level> <force> <health points> <coins> <job>
     * 
     * @param stream - output stream
     * @param player - player to print
     * @return
     * Returns the output stream that has been used.
    */
    friend std::ostream& operator<<(std::ostream& stream,const Player& player);

    /*
     * printInfo - prints the player details
     * 
     * @param stream - output stream
     * @return
     *     void
     * 
    */
    virtual void printInfo(std::ostream& stream) const;


    /*
     * getJobName - gets the name of the job.
     * 
     * @return
     * string with the name of the player job.
    */
    virtual std::string getJobName() const = 0;

private:

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

    /*Initial level of player*/
    static const int INITIAL_LEVEL = 1;

    /*Initial coins of player*/
    static const int INITIAL_COINS = 10;

    /*Initial default force of player*/
    static const int INITIAL_FORCE = 5;

    /*Initial default max hp of player*/
    static const int DEFAULT_MAX_HP = 100;




};




#endif // PLAYER_H_