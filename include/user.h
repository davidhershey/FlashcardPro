#ifndef USER
#define USER

#include <vector>
#include "deck.h"
#include <QString>
class User
{
private:
    std::vector<Deck*> decks;
    QString password;
    QString first_name;
    QString last_name;
    //ADD STATS INFO IN HERE
public:
    QString username;
    User(QString usrn_in, QString pw_in, QString fn_in, QString ln_in, std::vector<Deck*> decks_in = std::vector<Deck*>());
    ~User();
    bool sameName(QString check);
};

#endif // USER

