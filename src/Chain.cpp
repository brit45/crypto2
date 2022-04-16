#include "Chain.hpp"

Chain::Chain() {}

void Chain::addBlock(Block* blk) {
    this->BLK.push_back(blk);
}

void Chain::addTransaction(Transaction* tx) {
    this->TX.push_back(tx);
}

void Chain::CreateTransaction(Transaction_info* tx) {
    Transaction* t;
    t->addTransaction(tx);
    this->addTransaction(t);
}


Block* Chain::getBlockData(int pos) {
    return this->BLK[pos];
}


void Chain::Create_Genesis() {

    Block *blk = new Block();
    blk->Genesis();
    this->BLK.push_back(blk);
    blk->~Block();
}