#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "Block.hpp"
#include "Transaction.hpp"
#include <vector>


class Chain {
    
    public:

        Chain();
        
        void addBlock(Block* blk);
        void addTransaction(Transaction* tx);

        void Create_Genesis();

        void CreateTransaction(Transaction_info* tx);

        Block *getBlockData(int pos);

        unsigned int size() const { return this->BLK.size(); }
            
        std::vector<Block*> BLK;
        std::vector<Transaction*> TX;
};

#endif // __CHAIN_H__