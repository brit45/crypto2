#include "Transaction.hpp"
#include "Sha256.hpp"

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <error.h>

Transaction::Transaction() {}
Transaction::~Transaction() {}

void Transaction::addTransaction(Transaction_info *tx_info) {
    this->info = tx_info;
    this->tx_Index++;
}

void Transaction::setSign(std::string hash, int nonce, int diff) {

    if(this->Sign != "") return;

    std::string v = sha256(
        std::to_string(this->info->AMOUNT)+
        this->info->TO+
        this->info->FROM+
        std::to_string(this->info->TIMESTAMP)+
        std::to_string(this->info->FEE));

    if(v == hash) {
        this->Nonce = nonce;
        this->Sign = hash;
        this->diff = diff;
    }
    else return;
}

Transaction* Transaction::setTreeTransaction(Transaction* tx) {

    if(this->Tparent == NULL)
        this->Tparent = tx;

    int index = tx->tx_Index;

    if(index%2 == 0) {
        tx->Tleft = tx;
    }
    else {
        tx->Tright= tx;
    }

    return this->setTreeTransaction(tx);
}

Transaction_info* Transaction::getInfo() const {
    return this->info;
}