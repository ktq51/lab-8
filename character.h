#pragma once

#include "header.h"

class Character

{
public:
    Character();

        std:: string name , race , sex ;
        std:: vector <std:: string> playerRace;
        int health , totalhealth , maxhealth , heal ;

        int level, current_xp, base_xp, xp_to_level, min_level, maxlevel;

    void characterCreation();    
};
