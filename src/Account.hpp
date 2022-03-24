#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <cstring>


class Word_Seed {
    
    public:
        Word_Seed();
        unsigned int ListWord_Len() const { return sizeof(this->word_list); }
        std::string CreateSeed() const;
    
    private:
        std::string word_list[24] = {
            "apple",
            "store",
            "hospital",
            "wallet",
            "open",
            "close",
            "horse",
            "cat",
            "dog",
            "in",
            "out",
            "house",
            "male",
            "female",
            "kid",
            "child",
            "adult",
            "one",
            "hat",
            "values",
            "fork",
            "work",
            "monney",
            "monkey"
        };
};

class Account {
    public:
        Account();

        bool CreateAccount();
        bool LoadAccount();
    
    private:

        std::string Path_DIR;
        std::string Path_CONFIG;
        std::string Path_WALLET;

        std::string Seed;
        std::string secretPub;
        std::string secretPriv;

        std::string Net_Default;
        std::string Net_Type[3];
        unsigned int Port;
        std::string IP;
        std::string Version;
};

#endif // __ACCOUNT_H__