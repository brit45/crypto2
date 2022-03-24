#include "Block.hpp"
#include "Sha256.hpp"
#include <fstream>

namespace COIN_GDS_ {

    Block::Block(Transaction *tx, std::string prev, unsigned long int pos) {
        this->Previous = prev;
        this->position = pos;

        std::string root;

        for(int i = 0; i < tx->getSizeOfValidateTransactionList(); i++) {
            root.append("<"+std::to_string(tx->getValidateTransaction(i)->AMOUNT)+" | ");
            root.append(tx->getValidateTransaction(i)->TO+" | ");
            root.append(tx->getValidateTransaction(i)->FROM+" | ");
            root.append(std::to_string(tx->getValidateTransaction(i)->TIMESTAMP)+">");
        }

        this->Hash = sha256(this->Previous + root);
    }
    
    Block::~Block() {}

    void Block::Genesis() {

        this->Hash = sha256("The new day is the nemesis of the previous days.");
        this->position = 0;
        this->Previous = nullptr;
        this->Sign = nullptr;
        this->Lenght = sizeof(this);
    }
};