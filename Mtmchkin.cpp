
#include "Mtmchkin.h"


const std::string Mtmchkin::classType[NUMBER_OF_CLASSES] = {"Ninja","Healer","Warrior"};


/* --------------------------------------- Public Functions of Mtmchkin Class ---------------------------------------*/


Mtmchkin::Mtmchkin(const std::string &fileName) :m_numberOfRounds(INITIAL_NUMBER_OF_ROUNDS) {
    
    printStartGameMessage();
    std::ifstream cardFile(fileName);
    if (!cardFile.is_open()){
        throw DeckFileNotFound();
    }
    initializeCardDeck(cardFile);
    initializePlayerQueue();

}


void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    int rank = 1;
    printPlayerQueue(rank,m_playerWonQueue);
    printPlayerQueue(rank,m_playerPlayingQueue);
    printPlayerQueue(rank,m_playerLostQueue);
    
}

void Mtmchkin::printPlayerQueue(int& rank ,const std::deque<std::unique_ptr<Player>>& queue){
    int queueSize = queue.size();
    for(int i = 0 ; i < queueSize ; i++){
        Player* currentPlayer = (queue.at(i)).get();
        printPlayerLeaderBoard(rank,*currentPlayer);
        rank++;
    }
}


void Mtmchkin::playRound(){

    printRoundStartMessage(getNumberOfRounds() + 1);
    int playersPlayingSize = m_playerPlayingQueue.size();
    for (int i =0 ; i < playersPlayingSize ; i++){

        std::unique_ptr<Player> currentPlayer = std::move(m_playerPlayingQueue.front());
        m_playerPlayingQueue.pop_front();
        Player* currentPlayerPointer = currentPlayer.get();
        printTurnStartMessage(currentPlayerPointer->getName());

        std::unique_ptr<Card> currentCard = std::move(m_cardQueue.front());
        m_cardQueue.pop();
        Card* currentCardPointer = currentCard.get();
        currentCardPointer->applyEncounter(*currentPlayerPointer);
        m_cardQueue.push(std::move(currentCard));

        if(currentPlayerPointer->getLevel() == MAX_LEVEL){
            m_playerWonQueue.push_back(std::move(currentPlayer));
            continue;  
        }
        else if(currentPlayerPointer->isKnockedOut()){
            m_playerLostQueue.push_front(std::move(currentPlayer));
            continue;
        }
        m_playerPlayingQueue.push_back(std::move(currentPlayer));
    }
    if (isGameOver()){
        printGameEndMessage();
    } 
    m_numberOfRounds++;
}

bool Mtmchkin::isGameOver() const{
    if(m_playerPlayingQueue.size() <= 0){
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}





/* -------------------------------------- Private Functions of Mtmchkin Class --------------------------------------*/


void Mtmchkin::initializeCardDeck(std::ifstream& cardFile){

    int lineNumber = 1;
    while(cardFile.peek() != EOF){
        std::string cardName;
        getline(cardFile,cardName,LINE_BREAK);
        insertCard(cardName,lineNumber);
        lineNumber++; 
    }
    if(m_cardQueue.size() < MINIMUM_CARDS_IN_DECK){
        throw DeckFileInvalidSize();
    }

}

void Mtmchkin::insertCard(const std::string& cardName , int lineNumber) {
    
 
    if(cardName == "Gremlin"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Gremlin())));
    }
    else if(cardName == "Witch"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Witch())));
    }
    else if(cardName == "Dragon"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Dragon())));
    }
    else if(cardName == "Merchant"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Merchant())));
    }
    else if(cardName == "Treasure"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Treasure())));
    }
    else if(cardName == "Well"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Well())));
    }
    else if(cardName == "Barfight"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Barfight())));
    }
    else if(cardName == "Mana"){
        m_cardQueue.push(std::move(std::unique_ptr<Card> (new Mana())));
    }
    else{
        throw DeckFileFormatError(lineNumber);
    }

}


void Mtmchkin::initializePlayerQueue() {

    int teamSize =  initializeTeamSize();
    printInsertPlayerMessage();
    for(int size = 0 ; size < teamSize ;){
        std::string fullPlayerName;
        getline(std::cin, fullPlayerName , LINE_BREAK);
        if(countWords(fullPlayerName) != FULL_PLAYER_WORDS){
            printInvalidInput();
            continue;
        }
        std::string playerName;
        std::string className;
        initializeNames(fullPlayerName, playerName,className);
        if(!validPlayerName(playerName)){
            printInvalidName();
            continue;
        }
        if(!validClassName(className)){
            printInvalidClass();
            continue;
        }
        insertPlayer(playerName,className);
        if(size < teamSize - 1){
            printInsertPlayerMessage();
        }
        size++;


    }

}

void Mtmchkin::insertPlayer(const std::string& playerName,const std::string& className){

    if(className == "Ninja"){
        m_playerPlayingQueue.push_back(std::move(std::unique_ptr<Player> (new Ninja(playerName))));
    }
    else if(className == "Warrior"){
        m_playerPlayingQueue.push_back(std::move(std::unique_ptr<Player> (new Warrior(playerName))));
    }
    else if(className == "Healer"){
        m_playerPlayingQueue.push_back(std::move(std::unique_ptr<Player> (new Healer(playerName))));
    }
}

int Mtmchkin::initializeTeamSize() const {

    int teamSize = 0;
    bool firstIteration = true;
    printEnterTeamSizeMessage();

    do{
        if(!firstIteration){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
        firstIteration = false;
        std::string stringTeamSize;
        try{
            getline(std::cin ,stringTeamSize , LINE_BREAK);
            int stringSize = stringTeamSize.size();
            for(int i = 0 ; i< stringSize ; i++){
                if(!isdigit(stringTeamSize[i])){
                    throw std::runtime_error::exception();
                }
            }
            teamSize = std::stoi(stringTeamSize);
        } 
        catch(std::exception&) {}


    } while(teamSize < MINIMUM_TEAM_SIZE || teamSize > MAXIMUM_TEAM_SIZE);

    return teamSize;

}



void Mtmchkin::initializeNames(const std::string& playerFullName, std::string& playerName,std::string& className){

    int fullNameSize = playerFullName.size();
    int firstCharacterIndex = 0;
    int iterationNumber = 1;
    for(int index = 0 ; index < fullNameSize ; ) {
        int length = 0;
        while(playerFullName[index] == SPACE && index < fullNameSize ){
            index++;
            firstCharacterIndex = index;
        }
        while(playerFullName[index] != SPACE && index < fullNameSize) {
            index++;
            length++;
        }
        if(iterationNumber == 1){
            playerName = playerFullName.substr(firstCharacterIndex, length);
            iterationNumber++;
        }
        else{
            className = playerFullName.substr(firstCharacterIndex,length);
            break;
        }
    }
}


int Mtmchkin::countWords(const std::string& string){

    int wordsCounter = 0;
    int stringSize = string.size();
    for(int index = 1 ; index < stringSize ; index ++) {
        if(string[index] == SPACE && string[index-1] != SPACE){
            wordsCounter++;
        }
    }
    if(string[stringSize - 1] != SPACE) {
        wordsCounter++;
    }
    return wordsCounter;

} 


bool Mtmchkin::validPlayerName(const std::string& playerName){


    if(playerName.length() > MAX_PLAYER_NAME_LENGTH || playerName.length() <= 0){
        return false;
    }
    for(char character : playerName ){
        if(!isalpha(character)){
            return false;
        }
    }
    return true;

}

bool Mtmchkin::validClassName(const std::string& className){
    for(int i=0; i<NUMBER_OF_CLASSES; i++){
        if(className == classType[i]){
            return true;
        }
    }
    return false;
}