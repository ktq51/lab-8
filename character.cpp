#include "character.h"

Character::Character()
{
    name = " ";
    race = " ";
    sex = " ";

    playerRace = {"Elf", "Dwarf", "Firelord", "Goblin", "Human"};

    health = 0, totalhealth = 0, maxhealth = 0, heal = 0;

    level = 1, current_xp = 0, base_xp = 83, xp_to_level = base_xp, min_level = 1, maxlevel = 60;
}

void Character:: characterCreation(){

int counter = 0;

    //basic
    std:: cout<< "Enter character name: ";
    std::getline(std::cin, name);

    std:: cout<< "Enter character race: ";
    std:: cout<< "Elf\n";
    std:: cout<< "Dwarf\n";
    std:: cout<< "Firelord\n";
    std:: cout<< "Goblin\n";
    std:: cout<< "Human\n";
    std:: cout<< "Type below your race\n\n";
    std:: cin >> race;

    for(int i = 0; i < race.size(); i++) race[i] = std::tolower(race[i]);

    if(race == "elf"){
        health = 80;
    }
    else if(race == "dwarf"){
        health = 120;
    }
    else if(race == "firelord"){
        health = 150;
    }
    else if(race == "goblin"){
        health = 82;
    }
    else if(race == "human"){
        health = 68;
    }
    else{
        health = 100;
    }

    std:: cout<<"\n";
    std:: cout<< "Enter chartacter sex: ";
    std:: cin>> sex;
    system("sleep 2");
    system("clear");

    //fun
    for(int i = 0; i<=counter; i++){
        if(i == 0){
            std::cout<<"Creating character.\n";
        }
        if(i == 1){
            std::cout<<"Creating character..\n";
        }
        if(i == 2){
            std::cout<<"Creating character...\n";
            break;
        }
        system("sleep 2");
        system("clear");
        counter++;
    }

    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    totalhealth = health;
    maxhealth = totalhealth;
}
