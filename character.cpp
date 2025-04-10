#include "Character.h"

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
    std:: cin >> name;

    std:: cout<< "Enter character race: ";
    std:: cout<< "Elf\n";
    std:: cout<< "Dwarf\n";
    std:: cout<< "Firelord\n";
    std:: cout<< "Goblin\n";
    std:: cout<< "Human\n";
    std:: cout<< "Type below your race\n\n";
    std:: cin >> race;

    std::for_each(race.begin(), race.end(), [](char & c){
        c= :: tolower(c);
    });

    for(int i = 0; i<sizeof(playerRace); i++){
        if(race == "Elf"){
            health = 80;
        }
        if(race == "Dwarf"){
            health = 120;
        }
        if(race == "Fire lord"){
            health = 150;
        }
        if(race == "Goblin"){
            health = 82;
        }
        if(race == "Human"){
            health = 68;
        }
        else{
            health = 100;
            break;
        }
    }

    std:: cout<<"/n";
    std:: cout<< "Enter chartacter sex: ";
    std:: cin>> sex;
    system("cls");

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
        Sleep(400);
        system("cls");
        counter++;
    }

    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    totalhealth = health;
    maxhealth = totalhealth;
}