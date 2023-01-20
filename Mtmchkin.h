#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <map>
#include <memory>
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include "Cards/Battle.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Exception.h"


class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    * @exception
    * DeckFileNotFound - if the file has not been found.
    * DeckFileFormatError(lineNumber) - if the file format has errior in line <lineNumber>.
    * DeckFileInvalidSize - if the deck size is invalid.
    * std::bad_alloc - if failed to allocate the requested space for new card or new player.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction
    * in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin& otherMtmchkin) = delete;
    Mtmchkin& operator=(const Mtmchkin& otherMtmchkin) = delete;

private:
   
    int m_numberOfRounds;
    std::deque<std::unique_ptr<Player>> m_playerWonQueue;
    std::deque<std::unique_ptr<Player>> m_playerPlayingQueue;
    std::deque<std::unique_ptr<Player>> m_playerLostQueue;
    std::queue<std::unique_ptr<Card>> m_cardQueue;


    /*
     * initializeCardDeck - initazlie the card queue given input stream
     * 
     * @param cardFile - input file with all card names.
     * @return  
     *     void
     * @exception
     * DeckFileInvalidSize - if the deck size is invalid.
     * DeckFileFormatError(lineNumber) - if the file format has errior in line <lineNumber>.
     * std::bad_alloc - if failed to allocate the requested space for new card.
    */
    void initializeCardDeck(std::ifstream& cardFile);

    /*
     * insertCard - inserts a new card to the queue
     * 
     * @param cardName - the card to be inserted
     * @param lineNumber - the line number on the input file with all card names
     * @return 
     *     void
     * @exception
     * DeckFileFormatError(lineNumber) - if the file format has errior in line <lineNumber>.
     * std::bad_alloc - if failed to allocate the requested space for new card.
     * 
    */
    void insertCard(const std::string& cardName,int lineNumber);


    /*
     * initializePlayerQueue - initialize the player queue.
     * 
     * @return
     *     void
     * @exception
     * std::bad_alloc - if failed to allocate the requested space for new player.
    */
    void initializePlayerQueue();

    /*
     * insertPlayer - inserts new player to the player queue.
     * 
     * @param playerName - the name of the player
     * @param className - the class of the player
     * @return
     *     void
     * @exception
     * std::bad_alloc - if failed to allocate the requested space for new player.
    */
    void insertPlayer(const std::string& playerName,const std::string& className);

    /*
     * initializeTeamSize - initialize the team size by the user
     * 
     * @return
     * integer of the team size.
    */
    int initializeTeamSize() const;

    /*
     * initializeNames - initialize the player and class name
     * 
     * @param playerFullName - the player name and class name.
     * @param playerName - the string that will contain the player name.
     * @param className - the string that will contain the class name.
     * @return
     *     void
    */
    static void initializeNames(const std::string& playerFullName, std::string& playerName,std::string& className);

    /**
     * validPlayerName - checks if the player name is valid
     * 
     * @param playerName - the player name to check
     * @return
     * true - if the playerName is valid , else will be returned false.
    */
    static bool validPlayerName(const std::string& playerName);

    /**
     * validClassName - checks if the class name is valid
     * 
     * @param className - the class name to check
     * @return
     * true - if the className is valid , else will be returned false.
    */
    static bool validClassName(const std::string& className);

    /*
     * countWords - counts the words in string
     * 
     * @param string - the string to count the words
     * @return
     * integer of the number of the words
    */
    static int countWords(const std::string& string);


    /*
     * printPlayerQueue - prints the player leaderboard with their rank
     * 
     * @param rank - the rank of the first player in the queue
     * @param queue - the queue with the players to print.
     * @return 
     *      void
    */
    static void printPlayerQueue(int& rank ,const std::deque<std::unique_ptr<Player>>& queue);

    /* initial number of rounds */
    static const int INITIAL_NUMBER_OF_ROUNDS = 0;

    /* number of diffrent cards */
    static const int NUMBER_OF_CARDS = 8;  

    /* number of diffrent classes */
    static const int NUMBER_OF_CLASSES = 3;

    /* array with all different classes names */
    static const std::string classType[NUMBER_OF_CLASSES];

    /* minimum cards in deck */
    static const int MINIMUM_CARDS_IN_DECK = 5;

    /* full player input words <name> <class_name> */
    static const int FULL_PLAYER_WORDS = 2;

    /* minimum players playing */
    static const int MINIMUM_TEAM_SIZE = 2;

    /* maximum players playing */
    static const int MAXIMUM_TEAM_SIZE = 6;

    /* maximum player name length */
    static const int MAX_PLAYER_NAME_LENGTH = 15;

    /* spacebar */
    static const char SPACE = ' ';

    /* line break */
    static const char LINE_BREAK = '\n';
    

};



#endif /* MTMCHKIN_H_ */
