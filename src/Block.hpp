#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include "Transaction.hpp"

namespace COIN_GDS_ {

    class Block {
        public:
            Block(Transaction* tx,std::string prev, unsigned long int pos);
            ~Block();

            void Genesis();

        private:
            std::string Hash = nullptr;
            std::string Previous = nullptr;
            std::string Sign = nullptr;
            unsigned int Lenght = 0;
            unsigned long int position = 0;
            std::vector<Transaction_info*> Tx;

    };
};
#endif // __BLOCK_H__
