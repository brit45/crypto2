#include <iostream>
#include "Account.hpp"
#include <fstream>
#include <ostream>
#include <sys/stat.h>
#include <jsoncpp/json/json.h>
#include <cstdio>
#include <string>
#include "Sha256.hpp"


struct stat st;
/**
 * @brief Verify if directory exist.
 * 
 * @param path 
 * @return true 
 * @return false 
 */
bool has_Dir(std::string path) {
    if(stat(path.c_str(),&st) == 0) {
        if(st.st_mode & S_IFDIR != 0) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Make directory.
 * 
 * @param dir_name 
 * @return true 
 * @return false 
 */
bool Create_Directory(std::string dir_name) {

    const int dir_err = mkdir(dir_name.c_str(), 0777);
    if (-1 == dir_err)
    {
        std::printf("Error creating directory!\n");

        return false;

    }
    return true;
}

namespace COIN_GDS_ {

    Word_Seed::Word_Seed() {}

    std::string Word_Seed::CreateSeed() const {
        srand(time(NULL));

        std::string l;

        for(int i =0;i< 12; i++) {
            l.append(this->word_list[rand()%this->ListWord_Len()]);
            if(i < 12) {
                l.append(" ");
            }
        }

        return l;
    }
    
    Account::Account() {

        this->Path_DIR = (std::string)std::getenv("HOME")+ "/.cryptos";
        this->Path_CONFIG = (std::string)std::getenv("HOME")+ "/.cryptos/config";

        if(!has_Dir(this->Path_DIR)) {
            
            if(!Create_Directory(this->Path_DIR)) {
                return;
            }
            
            std::cout << "[ ! ]\tCreate directory for Crytos on '" << this->Path_DIR+"'" << std::endl;

            std::ofstream os;
            Json::Value js;

            os.open(this->Path_CONFIG);

            js["VERSION"] = "0.0.1";
            js["CONFIG"]["PORT"] = 9120;
            js["CONFIG"]["IP"] = "127.0.0.1";
            js["CONFIG"]["WALLET"]["PATH"] = this->Path_DIR+"/wallet";
            js["CONFIG"]["WALLET"]["PUB_KEY"] = this->Path_DIR+"/wallet/id_rsa.pub";
            js["CONFIG"]["WALLET"]["PRIV_KEY"] = this->Path_DIR+"/wallet/id_rsa";
            js["CONFIG"]["NETWORK"]["TYPE"][0] = "Main:net";
            js["CONFIG"]["NETWORK"]["TYPE"][1] = "Test:net";
            js["CONFIG"]["NETWORK"]["TYPE"][2] = "Dev:net";
            js["CONFIG"]["NETWORK"]["DEFAULT"] = "Main:net";

            os << js;
            std::cout << js << std::endl;
        }

        // Load Config
        std::fstream fs;

        fs.open(this->Path_CONFIG);

        if(fs.is_open()) {

            if(this->LoadAccount()) {
                return;
            }
        }
        else {
            return;
        }

        fs.close();
    }

    bool Account::LoadAccount() {

        std::fstream fs;

        fs.open(this->Path_CONFIG);

        if(fs.is_open()) {
        
            Json::Reader jx;
            Json::Value js;

            jx.parse(fs,js);

            this->Path_WALLET = js["CONFIG"]["WALLET"]["PATH"].asString();
            this->secretPriv = js["CONFIG"]["WALLET"]["PRIV_KEY"].asString();
            this->secretPub = js["CONFIG"]["WALLET"]["PUB_KEY"].asString();

            for(int i = 0; i < js["CONFIG"]["NETWORK"]["TYPE"].size();i++) {

                this->Net_Type[i] = js["CONFIG"]["NETWORK"]["TYPE"][i].asString();
                std::string l = this->Path_DIR+"/"+(std::string)this->Net_Type[i].c_str();

                if(!has_Dir(l)) {

                    if(!Create_Directory(l)) {
                        std::cerr << "Error to Create Directory ' " << l << " '" << std::endl;
                        return false;
                    }
                }
            }
            this->Version = js["VERSION"].asString();

            std::cout << js << std::endl;
        }
        else {
            std::cerr << "Error Open Config file Failed" << std::endl;
            return false;
        }

        fs.close();

        if(!has_Dir(this->Path_WALLET)) {

            if(!Create_Directory(this->Path_WALLET)) {
                return false;
            }

            fs.open(this->Path_WALLET+"/id");

            if(fs.is_open()) {
                Json::Reader jx;
                Json::Value js;

                jx.parse(fs,js);

                std::cout << js << std::endl;
            }
            else {
                std::cerr << "Error Open Wallet file failed." << std::endl;
                this->CreateAccount();
                return false;
            }
        }

        return true;
    }

    bool Account::CreateAccount() {

        std::ofstream ofs;
        ofs.open(this->Path_WALLET+"/id");

        Json::Value js;

        js["SEED"]  =  "testdeseed";

        ofs << js;

        ofs.close();
    }

};
