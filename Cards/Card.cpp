
#include "Card.h"


Card::Card(const std::string& cardName) : m_cardName(cardName) {}

const std::string& Card::getCardName() const {
    return m_cardName;
}


void Card::printCardInfo(std::ostream& stream) const{
    
    printCardDetails(stream,getCardName());
    printEndOfCardDetails(stream);

}

std::ostream& operator<<(std::ostream& stream, const Card& card) {

    card.printCardInfo(stream);
    return stream;

}