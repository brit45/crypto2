#ifndef __TRANSACTION_HPP__
#define __TRANSACTION_HPP__

#include <ctime>
#include <time.h>
#include <cmath>
#include <math.h>
#include <sys/types.h>
#include <vector>
#include <string>

namespace COIN_GDS_ {
    

    struct Transaction_info {
        std::string TO, FROM;
        double AMOUNT;
        time_t TIMESTAMP;
        double FEE = (2*100)/AMOUNT;
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

            /**
             * @brief Get the Unvalidate Transaction object
             * 
             * @param tx_index 
             * @return Transaction_info
             */
            Transaction_info *getUnvalidateTransaction(int tx_index) const { if(tx_index <= this->tx_Unvalidate.size()) { return this->tx_Unvalidate[tx_index] ;} else { return; } }
            
            /**
             * @brief Get the Unvalidate Transaction object
             * 
             * @param tx_index 
             * @return Transaction_info* 
             */
            Transaction_info *getValidateTransaction(int tx_index) const { if(tx_index <= this->tx_Validate.size()) { return this->tx_Validate[tx_index] ;} else { return; } }
            
            /**
             * @brief Update list of transaction.
             */
            void UpdateTransaction();

            /**
             * @brief Get the Size Transaction List object
             * 
             * @return unsigned int 
             */
            unsigned int getSizeOfUnvalidateTransactionList() const { return this->tx_Unvalidate.size(); }

            /**
             * @brief Get the Size Of Validate Transaction List object
             * 
             * @return unsigned int 
             */
            unsigned int getSizeOfValidateTransactionList() const { return this->tx_Validate.size(); }

            /**
             * @brief Get the Sign object
             * 
             * @return std::string 
             */
            std::string getSign() const { return this->Sign; }

        private:
            std::vector<Transaction_info*> tx_Unvalidate;
            std::vector<Transaction_info*> tx_Validate;
            unsigned int long tx_Index;
            std::string Sign;
    };

};

#endif // __TRANSACTION_HPP__