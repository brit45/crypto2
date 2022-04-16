#include "Block.hpp"
#include "Sha256.hpp"
#include <fstream>

Block::Block() {}

Block::Block(Transaction *tx, std::string prev, unsigned long int pos, std::string auth) {

    this->Tx.push_back(tx);

    std::string h;

    for(int i=0; i < this->Tx.size();i++) {
        h.append(Tx[i]->getSign());
    }

    this->Hash = sha256(prev + h);
    this->position++;
    this->Author = auth;
}

Block::~Block() {}

void Block::Genesis() {

    this->Hash = sha256("The new day is the nemesis of the previous days.");
    this->position = 0;
    this->Previous = "";
}
