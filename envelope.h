#ifndef ENVELOPE_H
#define ENVELOPE_H
#include <string>
using namespace std;

class Envelope {
private:
    string name;
    double budget;
    double spent;

public:
    // Constructors
    Envelope();

    // Functions
    void createEnvelope(string username);
    void viewEnvelopes(string username);
    void fillEnvelope(string username);
    //void deductFromEnvelope(string username, string envName, double amount);
    void deleteEnvelope(string username);
};

#endif
