#include "Transaction.hpp"

#include <iostream>
#include <string>
#include <iostream>
#include <error.h>

Transaction::Transaction() {}
Transaction::~Transaction() {}

void Transaction::addTransaction(Transaction_info *tx_info) {
    this->tx_Unvalidate.push_back(tx_info);
    this->tx_Index++;
}

void Transaction::UpdateTransaction() {
    if(this->tx_Index > this->tx_Unvalidate.size()) {
        std::cerr << "Error: Unvalid size index." << std::endl;
        this->tx_Index = this->tx_Unvalidate.size();
    }
}