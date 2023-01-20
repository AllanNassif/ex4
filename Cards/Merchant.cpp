
#include "Merchant.h"


Merchant::Merchant(): Card("Merchant") {}


void Merchant::applyEncounter(Player& player) const{

    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int playerDecision = playerMerchantDecision();
    handlePayment(player,playerDecision);
    
}

int Merchant::playerMerchantDecision() const{
    
    int playerDecision = INVALID_DECISION;
    std::string stringPlayerDecision;
    bool firstIteration = true;
    do{
        if(!firstIteration){
            printInvalidInput();
        }
        firstIteration = false;
        try{
            std::getline(std::cin,stringPlayerDecision,LINE_BREAK);
            int stringPlayerDecisionSize = stringPlayerDecision.size();
            for(int i = 0 ; i < stringPlayerDecisionSize ; i++){
                if(!isdigit(stringPlayerDecision[i])){
                    throw std::runtime_error::exception();
                }
            }
            playerDecision = std::stoi(stringPlayerDecision);
        } catch(std::exception&) {}
        
    }while(playerDecision != DONT_PURCHASE_CARD && playerDecision != PURCHASE_HP && playerDecision != PURCHASE_FORCE);

    return playerDecision;

}

void Merchant::handlePayment(Player& player,int playerDecision) const{

    if(playerDecision == DONT_PURCHASE_CARD){
        printMerchantSummary(std::cout,player.getName(),DONT_PURCHASE_CARD,DONT_PURCHASE_CARD_COST);
    }
    else if(playerDecision == PURCHASE_HP){
        if(player.pay(DEFAULT_MERCHANT_HEAL_COST)){
            player.heal(DEFAULT_MERCHANT_HEAL);
            printMerchantSummary(std::cout,player.getName(),PURCHASE_HP,DEFAULT_MERCHANT_HEAL_COST);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout,player.getName(),PURCHASE_HP,DONT_PURCHASE_CARD_COST);

        }
    }
    else{
        if(player.pay(DEFAULT_FORCE_TO_INCREASE_COST)){
            player.buff(DEFAULT_FORCE_TO_INCREASE);
            printMerchantSummary(std::cout,player.getName(),PURCHASE_FORCE,DEFAULT_FORCE_TO_INCREASE_COST);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout,player.getName(),PURCHASE_FORCE,DONT_PURCHASE_CARD_COST);

        }
    }

}
