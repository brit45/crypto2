#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include "Transaction.hpp"

class Block {
    public:
        Block();
        Block(Transaction* tx,std::string prev, unsigned long int pos, std::string auth);
        ~Block();

        void Genesis();

        Transaction* getTransaction(unsigned int pos) const { return this->Tx[pos]; }

        std::string getHash() const { return this->Hash; }
        std::string getParent() const { return this->Previous; }
        int getSize() const { return this->Lenght; }
        int getPosition() const { return this->position; }

    private:
        std::string Hash;
        std::string Previous;
        unsigned int Lenght = 0;
        unsigned long int position = 0;
        std::string Author;
        std::vector<Transaction*> Tx;

};
#endif // __BLOCK_H__
