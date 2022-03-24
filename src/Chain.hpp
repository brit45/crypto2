#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "Block.hpp"
#include "Transaction.hpp"
#include <vector>
#include <jsonrpccpp/server.h>


class Chain {
    
    public:

        Chain();
        
        void addBlock(Block* blk);
        void addTrasaction(Transaction* tx);

        Json::Value Find(Transaction *tx) const;

    private:
    
        std::vector<Block*> BLK;
        std::vector<Transaction*> TX;
};

#endif // __CHAIN_H__