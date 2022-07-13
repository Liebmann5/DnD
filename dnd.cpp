#include <iostream>
#include <string>

using namespace std;

//Global variables
static  string CHARACTER_CLASSES[] = {"Barbarian", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Sorcerer", "Warlock", "Wizard"};
static  string ALIGNMENTS[] = {"Lawful Good", "Chaotic Good", "Lawful Neutral", "True Neutral", "Chaotic Neutral", "Lawful Evil", "Chaotic Evil"};
static  string BACKGROUNDS[] = {"Criminal", "Entertainer", "Gladiator", "Hermit", "Knight", "Noble", "Pirate", "Sage", "Spy"};
static  int STARTING_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

class Attribute {

};

class Character
{
    public:
        string getName();
        string getCharacterClass();
        string getAlignment();
        string getBackground();
        int getStartingLevel();
        Attribute getAttributes();
        Character(string name, string characterClass, string alignment, string background, int startingLevel);
    
    private:
        string name;
        string characterClass;
        string alignment;
        string background;
        int startingLevel;  
        Attribute attributes;
};

string Character::getName()
{
    return this->name;
}

string Character::getCharacterClass()
{
    return this->characterClass;
}

string Character::getAlignment()
{
    return this->alignment;
}

string Character::getBackground()
{
    return this->background;
}

int Character::getStartingLevel()
{
    return this->startingLevel;
}

Character::Character(string name, string characterClass, string alignment, string background, int startingLevel)
{
    this->name = name;
    this->characterClass = characterClass;
    this->alignment = alignment;
    this->background = background;
    this->startingLevel = startingLevel;
}

void printCharacter(Character character)
{
    cout << "======================================================" << endl;
    cout << "The character details are: " << endl;
    cout << character.getName() << endl;
    cout << character.getCharacterClass() << endl;
    cout << character.getAlignment() << endl;
    cout << character.getBackground() << endl;
    cout << to_string(character.getStartingLevel()) << endl;
}

void DisplayStartingMenu()
{
    string userSelectedOption = "";
    cout << "Welcome to the DnD character creation screen!" << endl;
    cout << "Please choose the character creation mode: " << endl;
    cout << "1. Manual " << endl;
    cout << "2. Random" << endl;
}


void DisplayOptions(string options[])
{
    for(int i = 0; i < sizeof(options); i++) {
        cout << to_string(i) + ". " + options[i] <<endl;
    }
}


// returns a Character object
Character CreateCharacter(string mode) 
{
    string nameInput = "";
    string characterClassInput = "";
    string alignmentInput = "";
    string backgroundInput = "";
    int levelInput = 0;
    
    if(mode == "manual") {
       

        cout << "Please enter a name for the character: " ;
        cin >> nameInput;
        cout << "" << endl;

        cout << "Please choose the character class: " << endl;
        DisplayOptions(CHARACTER_CLASSES);
        cin >> characterClassInput;
        cout << "" << endl;

        cout << "Please choose an aligntment: " << endl;
        DisplayOptions(ALIGNMENTS);
        cin >> alignmentInput;
        cout << "" << endl;

        cout << "Please choose a backgroun: " << endl;
        DisplayOptions(BACKGROUNDS);
        cin >> backgroundInput;
        cout << "" << endl;

        cout << "Please choose a starting level: " <<endl;
        //DisplayOptions(STARTING_LEVELS);
        cin >> levelInput;
        cout << "" << endl;


    }
    else if(mode == "random") {

    }
    else {
        cout << "Incorrect Mode selected. Please enter either manuel or random" <<endl;
    }


    // calling the character constructor
    Character playerCharacter = Character(nameInput, characterClassInput, alignmentInput, backgroundInput, levelInput);

    return playerCharacter;

}

int main()
{
    DisplayStartingMenu();
    string characterCreationMode = "";
    cin >> characterCreationMode;

    Character myCharacter = CreateCharacter(characterCreationMode);
    printCharacter(myCharacter);
    return 0;
}

