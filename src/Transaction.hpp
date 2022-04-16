#ifndef __TRANSACTION_HPP__
#define __TRANSACTION_HPP__

#include <ctime>
#include <time.h>
#include <cmath>
#include <math.h>
#include <sys/types.h>
#include <vector>
#include <string>

struct Transaction_info {
    std::string TO, FROM;
    double AMOUNT;
    time_t TIMESTAMP;
    double FEE;
};

class Transaction {
    public:
        Transaction();
        ~Transaction();

        /**
         * @brief Add transaction
         * 
         * @param tx_info 
         */
        void addTransaction(Transaction_info* tx_info);

        void setSign(std::string hash, int nonce, int diff);
        
        /**
         * @brief Get the Sign object
         * 
         * @return std::string 
         */
        std::string getSign() const { return this->Sign; }

        Transaction *setTreeTransaction(Transaction* tx);

        Transaction_info* getInfo() const;

    private:
        unsigned int long tx_Index = 0;
        Transaction_info* info = NULL;
        unsigned int Nonce = 0;
        std::string Sign = "";
        unsigned int diff = 0;

        Transaction *Tparent = NULL;
        Transaction *Tleft = NULL;
        Transaction *Tright = NULL;
};

#endif // __TRANSACTION_HPP__