#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "Block.hpp"
#include <jsonrpccpp/server.h>

namespace COIN_GDS_ {

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
};

#endif // __CHAIN_H__