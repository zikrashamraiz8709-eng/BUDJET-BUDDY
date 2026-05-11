#ifndef USER_H
#define USER_H
#include<iostream>
class User {
private:
    std::string username, password;

public:
    void registerUser();
    bool loginUser(std::string u, std::string p);
};

#endif
