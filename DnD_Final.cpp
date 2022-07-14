#include <iostream>
#include <string>
#include <random>

using namespace std;

//Global variables
static  string CHARACTER_CLASSES[] = {"Barbarian", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Sorcerer", "Warlock", "Wizard"};
static  string ALIGNMENTS[] = {"Lawful_Good", "Chaotic_Good", "Lawful_Neutral", "True_Neutral", "Chaotic_Neutral", "Lawful_Evil", "Chaotic_Evil"};
static  string BACKGROUNDS[] = {"Criminal", "Entertainer", "Gladiator", "Hermit", "Knight", "Noble", "Pirate", "Sage", "Spy"};

//atoi() - easy fix to an int array later down the road
static string LEVELS[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

class Attributes 
{
    public:
        string getStrength();
        string getDexterity();
        string getConstitution();
        string getIntelligence();
        string getCharisma();
        string getWisdom();
        Attributes(string strength, string dexterity, string constitution, string intelligence, string charisma, string wisdom);
        Attributes();
    private:
        string strength;
        string dexterity;
        string constitution;
        string intelligence;
        string charisma;
        string wisdom;
};

string Attributes::getStrength()
{
    return this->strength;
}

string Attributes::getDexterity()
{
    return this->dexterity;
}

string Attributes::getConstitution()
{
    return this->constitution;
}

string Attributes::getIntelligence()
{
    return this->intelligence;
}

string Attributes::getCharisma()
{
    return this->charisma;
}

string Attributes::getWisdom()
{
    return this->wisdom;
}

Attributes::Attributes()
{
    
}
Attributes::Attributes(string strength, string dexterity, string constitution, string intelligence, string charisma, string wisdom)
{
    this->strength = strength;
    this->dexterity = dexterity;
    this->constitution = constitution;
    this->intelligence = intelligence;
    this->charisma = charisma;
    this->wisdom = wisdom;
}

static int arrayLength(string *array)
{
    size_t i = 0;
    while(!array[i].empty())
    {
        ++i;
    }
    return i;
}

//https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
//Didn't know how to really get or uses a random vaiable in C++ so used this method found online!
int RandomSelections(string arraySize[])
{
    int size = arrayLength(arraySize);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, size);

    auto random_integer = uni(rng);

    return (random_integer % size);
}

bool CorrectInput(string usersCharacterChoices, string listOfOptions[])
{
    if(usersCharacterChoices == "random" || usersCharacterChoices == "Random"){
        return true;
    }
    bool exists = false;

    for(int i = 0; i <= sizeof(listOfOptions); i++)
    {
        if(usersCharacterChoices == listOfOptions[i])
            exists = true;
    }

    return exists;
}

bool CorrectNumsInput(string usersCharacterChoices, string listOfOptions[])
{
    if(usersCharacterChoices == "random" || usersCharacterChoices == "Random"){
        return true;
    }
    bool exists = false;
    int size = arrayLength(listOfOptions);

    for(int i = 0; i <= size; i++)
    {
        if(usersCharacterChoices == listOfOptions[i])
            exists = true;
    }

    return exists;
}

void DisplayAttributes(string options[])
{
    for(int i = 0; i <= sizeof(options)+1; i++)
        cout << "Level " + to_string(i) << endl;
}

void setTrait(string input, string &trait, string options[])
{
    if(input == "random" || input == "Random")
    {
        trait = options[RandomSelections(options)];
    }

    else
    {
        trait = input;
    }
}

string printAttributes(Attributes attribute)
{
    cout << "Strength level: " + attribute.getStrength() << endl;
    cout << "Dexterity level: " + attribute.getDexterity() << endl;
    cout << "Constitution level: " + attribute.getConstitution() << endl;
    cout << "Intelligence level: " + attribute.getIntelligence() << endl;
    cout << "Charisma level: " + attribute.getCharisma() << endl;
    cout << "Wisdom level: " + attribute.getWisdom() << endl;
}


Attributes attributesSetUp()
{
    string input = "";
    string strengthLevel = "";
    string dexterityLevel = "";
    string constitutionLevel = "";
    string intelligenceLevel = "";
    string charismaLevel = "";
    string wisdomLevel = "";
    bool attributesCreationComplete = false;

    while(!attributesCreationComplete)
    {
        if(strengthLevel.empty())
        {
            cout << "Please select your characters' Strength level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, strengthLevel, LEVELS);
            cout << "" << endl;
        }

        if(dexterityLevel.empty())
        {
            cout << "Please select your characters' Dexterity level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, dexterityLevel, LEVELS);
            cout << "" << endl;
        }

        if(constitutionLevel.empty())
        {
            cout << "Please select your characters' Constitution level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, constitutionLevel, LEVELS);
            cout << "" << endl;
        }

        if(intelligenceLevel.empty())
        {
            cout << "Please select your characters' Intelligence level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, intelligenceLevel, LEVELS);
            cout << "" << endl;

        }

        if(charismaLevel.empty())
        {
            cout << "Please select your characters' Charisma level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, charismaLevel, LEVELS);
            cout << "" << endl;
        }
        
        if(wisdomLevel.empty())
        {
            cout << "Please select your characters' Wisdom level(number only): " << endl;
            DisplayAttributes(LEVELS);
            cin >> input;
            if(!CorrectNumsInput(input, LEVELS)) 
            {
                continue;
            }
            setTrait(input, wisdomLevel, LEVELS);
            cout << "" << endl;
        }

        attributesCreationComplete = true;
    }
    Attributes playerAttributes = Attributes(strengthLevel, dexterityLevel, constitutionLevel, intelligenceLevel, charismaLevel, wisdomLevel);

    return playerAttributes;
}

class Character
{
    public:
        string getName();
        string getCharacterClass();
        string getAlignment();
        string getBackground();
        string getStartingLevel();
        Attributes getAttribute();
        Character(string name, string characterClass, string alignment, string background, string startingLevel, Attributes attribute);
    
    private:
        string name;
        string characterClass;
        string alignment;
        string background;
        string startingLevel;  
        Attributes attribute;
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

string Character::getStartingLevel()
{
    return this->startingLevel;
}

Attributes Character::getAttribute()
{
    return this->attribute;
}

Character::Character(string name, string characterClass, string alignment, string background, string startingLevel, Attributes attribute)
{
    this->name = name;
    this->characterClass = characterClass;
    this->alignment = alignment;
    this->background = background;
    this->startingLevel = startingLevel;
    this->attribute = attribute;
}

void printCharacter(Character character)
{
    cout << character.getName() + "'s character details are: " << endl;
    cout << "Class: " + character.getCharacterClass() << endl;
    cout << "Alignment: " + character.getAlignment() << endl;
    cout << "Background: " + character.getBackground() << endl;
    cout << "Character level: " + character.getStartingLevel() << endl;
    printAttributes(character.getAttribute());
}

void DisplayStartingMenu()
{
    string userSelectedOption = "";
    cout << "Welcome to the DnD character creation screen!\n";
    cout << "Please choose the character creation mode: \n";
    cout << "1. Manual\n";
    cout << "2. Random\n";
}


void DisplayOptions(string options[])
{
    int size = arrayLength(options);

    for(int i = 0; i < size; i++) 
    {
        cout << to_string(i) + ". " + options[i] << endl;

    }
}

void DisplayLevels()
{
    int size = arrayLength(LEVELS);

    for(int i = 0; i < size; i++)
    {
        cout << "Level " + LEVELS[i] << endl;
    }
}

// returns a Character object
Character CreateCharacter(string mode) 
{
    string input = "";
    string name = "";
    string characterClass = "";
    string alignment = "";
    string background = "";
    string level = "";
    Attributes playerAttributes = Attributes();
    bool characterCreationComplete = false;
    
    if(mode == "manual" || mode == "Manual") 
    {
        cout << "You can type 'random' at any time to have your selections randomly picked for you!" << endl;
        cout << "===================================================================================" << endl;

        while(!characterCreationComplete)
        {
            if(name.empty())
            {
                cout << "Please enter a name for the character: ";
                cin >> name;
                cout << "" << endl;
            }

            if(characterClass.empty())
            {
                cout << "Please choose a character class: " << endl;
                DisplayOptions(CHARACTER_CLASSES);
                cin >> input;
                if(!CorrectInput(input, CHARACTER_CLASSES)) 
                {
                    continue;
                }
                setTrait(input, characterClass, CHARACTER_CLASSES);
                cout << "" << endl;
            }

            if(alignment.empty())
            {
                cout << "Please choose an aligntment: " << endl;
                DisplayOptions(ALIGNMENTS);
                cin >> input;
                if(!CorrectInput(input, ALIGNMENTS))
                {
                    continue;
                }
                setTrait(input, alignment, ALIGNMENTS);
                cout << "" << endl;
            }

            if(background.empty())
            {
                cout << "Please choose a background: " << endl;
                DisplayOptions(BACKGROUNDS);
                cin >> input;
                if(!CorrectInput(input, BACKGROUNDS))
                {
                    continue;
                }
                setTrait(input, background, BACKGROUNDS);
                cout << "" << endl;
            }

            if(level.empty())
            {
                cout << "Please enter a starting level(number only): " << endl;
                DisplayLevels();
                cin >> input;
                if(!CorrectNumsInput(input, LEVELS))
                {
                    continue;
                }
                setTrait(input, level, LEVELS);
                cout << "" << endl;
            }
            
            characterCreationComplete = true;      
        }

        cout << name + " now it's time to pick your attribute stats!" << endl;
        playerAttributes = attributesSetUp();
    }

    else if(mode == "random" || mode == "Random") 
    {
        cout << "Please enter a name for the character: ";
        cin >> name;
        cout << "" << endl;

        characterClass = CHARACTER_CLASSES[RandomSelections(CHARACTER_CLASSES)];
        alignment = ALIGNMENTS[RandomSelections(ALIGNMENTS)];
        background = BACKGROUNDS[RandomSelections(BACKGROUNDS)];
        level = LEVELS[RandomSelections(LEVELS)];

        string strength = LEVELS[RandomSelections(LEVELS)];
        string dexterity = LEVELS[RandomSelections(LEVELS)];
        string constitution = LEVELS[RandomSelections(LEVELS)];
        string intelligence = LEVELS[RandomSelections(LEVELS)];
        string charisma = LEVELS[RandomSelections(LEVELS)];
        string wisdom = LEVELS[RandomSelections(LEVELS)];
        playerAttributes = Attributes(strength, dexterity, constitution, intelligence, charisma, wisdom);
    }

    else 
    {
        cout << "Incorrect Mode selected. Please enter either manuel or random" << endl;
    }

    Character playerCharacter = Character(name, characterClass, alignment, background, level, playerAttributes);
   
    return playerCharacter;
}

int main()
{
    DisplayStartingMenu();
    string characterCreationMode = "";
    cin >> characterCreationMode;

    cout << "===================================================================================" << endl;
    //This note is to inform the user that I didn't want to use a transformer becuase I don't know how :)
    cout << "NOTE: All options are case sensitive!!" << endl;
    Character myCharacter = CreateCharacter(characterCreationMode);
    printCharacter(myCharacter);
    return 0;
}

/*user@Users-iMac project % ./dnd
users@Users-iMac project % g++ dnd.cpp -o dnd*/
