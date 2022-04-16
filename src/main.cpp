#include <iostream>
#include "Block.hpp"
#include "Transaction.hpp"
#include "Chain.hpp"
#include "Sha256.hpp"
#include <random>
#include <cmath>

void Mining_transaction(int diff, std::string hash, Chain blockchain) {

    srand(time(NULL));

    std::string valid;

    for(int i=0;i<diff;i++) valid.append("0");


    bool run = true;
    for(int i=0;i<blockchain.TX.size();i++) {

        while(run) {
            int nonce = rand();

            if(sha256(hash+std::to_string(nonce)).substr(0,diff) == valid) {
                
                blockchain.TX[i]->setSign(sha256(hash+std::to_string(nonce)),nonce,diff);

                std::string parent = blockchain.BLK[blockchain.size()-1]->getParent();
                int pos = blockchain.BLK[blockchain.size()-1]->getPosition();

                std::cout << "Block Size : " << blockchain.BLK[i]->getSize() << std::endl;

                // Block *blk = new Block(blockchain.TX[i],parent, pos, hash);

                // blockchain.BLK.push_back(blk);

                run = false;
            }
        }

    }

    
}

int main(int argc, const char** argv) {

    Chain Blockchain;

    if(Blockchain.size() == 0) {
        Blockchain.Create_Genesis();
    }

    Transaction_info tx;
    tx.AMOUNT = 1000.0;
    tx.TO = "Marvin";
    tx.FROM = "Pierre";
    tx.TIMESTAMP = time(NULL);
    tx.FEE = (2*100)/tx.AMOUNT;

    Blockchain.CreateTransaction(&tx);

    Mining_transaction(4,"marvin",Blockchain);

    
    return 0;
}