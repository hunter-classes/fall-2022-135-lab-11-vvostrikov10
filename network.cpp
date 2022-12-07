#include "network.h"
#include "profile.h"
#include "network.h"
#include <iostream>


bool Network::isFollowing(int i1, int i2){
    return following[i1][i2];
}

int Network::findID(std::string usrn){
    for (int i = 0; i < numUsers; i++){
        if (profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

Network::Network(): numUsers(0) {
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

bool is_alnumstring(std::string s){
    if(s.length() == 0){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if (!(isalnum(s[i]))){
            return false;
        }
    }
    return true;
}



bool Network::addUser(std::string usrn, std::string dspn){
    if (is_alnumstring(usrn) && numUsers < MAX_USERS && findID(usrn) == -1){
        Profile newProfile(usrn, dspn);
        profiles[numUsers] = newProfile;
        numUsers++;
        return true;
    }
    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
    int i1 = findID(usrn1);
    int i2 = findID(usrn2);
    if (i1 != -1 && i2 != -1){
        following[i1][i2] = true;
        return true;
    }
    return false;
}

void Network::printDot(){
    std::cout << "digraph {" << std::endl;
    for (int i = 0; i < numUsers; i++){
        std::cout <<"\t\"@" << profiles[i].getUsername() << "\"" << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if (following[i][j]){
                std::cout << "\t\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << std::endl;
            }
        }
    }
    std::cout << "}" << std::endl;
}
