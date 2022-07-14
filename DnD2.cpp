#include <iostream>
#include <string>
#include <random>

using namespace std;

//Global variables
static  string CHARACTER_CLASSES[] = {"Barbarian", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Sorcerer", "Warlock", "Wizard"};
static  string ALIGNMENTS[] = {"Lawful_Good", "Chaotic_Good", "Lawful_Neutral", "True_Neutral", "Chaotic_Neutral", "Lawful_Evil", "Chaotic_Evil"};
static  string BACKGROUNDS[] = {"Criminal", "Entertainer", "Gladiator", "Hermit", "Knight", "Noble", "Pirate", "Sage", "Spy"};
//static  int STARTING_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//atoi()
static string LEVELS[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
/*static  int DEXTERITY_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static  int CONSTITUTION_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static  int INTELLIGENCE_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static  int CHARISMA_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static  int WISDOM_LEVELS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};*/

class Attributes 
{
    /*look at these as "public" variables!!!!(they are actually functions{methods})
    The purpose of looking at these as variables is because we want the actual variables
    to be hidden! We put getters & setters so that the actual variables will remain
    hidden but can still be read and seen by others!!*/
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

/*The*/

//https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
/*????Probably want this to pick just 1 # every iteration because the user should be allowed to skip some
decisions, in which case we need to pick a random #?????*/
int RandomSelections()
{
    //?????for loop to figure out how many categories are required to pick for then shuffle throughthem?????
    //?????but maybe there is a way to directly access the elements????
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, 9);

    auto random_integer = uni(rng);

    return (random_integer % 10);
}

void DisplayAttributes(string options[])
{
    for(int i = 0; i < sizeof(options); i++)
        cout << to_string(i) + ". " << endl;
}

void setTrait(string input, string &trait, string options[])
{
    cout << "============================" << endl;
    if(input == "random" || input == "Random")
    {
        trait = options[RandomSelections()];
    }
    else
    {
        trait = input;
    }
}

//?????Some ideas to send this back to createCharacter since I assume this won't work?????
//?????1. Save this in like a string variable(I assume the attribute obj won't work)?????
string printAttributes(Attributes attribute)
{
    //!!!!You don't have to loop through anything or backtrack because our variables are already accessible!!! Know How??????
    //getMethods()
    cout << "Strength level: " + attribute.getStrength() << endl;
    cout << "Dexterity level: " + attribute.getDexterity() << endl;
    cout << "Constitution level: " + attribute.getConstitution() << endl;
    cout << "Intelligence level: " + attribute.getIntelligence() << endl;
    cout << "Charisma level: " + attribute.getCharisma() << endl;
    cout << "Wisdom level: " + attribute.getWisdom() << endl;
}


Attributes attributesSetUp()
{
    //????need to initialize user input variables?????
    //????Do we make these variables = to "" becuase we can't initialize in f(n)'s therefore new variables need to be assigned values????
    string input = "";
    string strengthLevel = "";
    string dexterityLevel = "";
    string constitutionLevel = "";
    string intelligenceLevel = "";
    string charismaLevel = "";
    string wisdomLevel = "";

    cout << "Please select your characters' Strength level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, strengthLevel, LEVELS);

    cout << "Please select your characters' Dexterity level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, dexterityLevel, LEVELS);

    cout << "Please select your characters' Constitution level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, constitutionLevel, LEVELS);
    
    cout << "Please select your characters' Intelligence level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, intelligenceLevel, LEVELS);

    cout << "Please select your characters' Charisma level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, charismaLevel, LEVELS);

    cout << "Please select your characters' Wisdom level: " << endl;
    DisplayAttributes(LEVELS);
    cin >> input;
    setTrait(input, wisdomLevel, LEVELS);

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
        Attributes attribute;   //???Do I want this object hidden???
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
    //cout << character.getName() << endl;
    cout << "Class: " + character.getCharacterClass() << endl;
    cout << "Alignment: " + character.getAlignment() << endl;
    cout << "Background: " + character.getBackground() << endl;
    cout << "Character level: " + character.getStartingLevel() << endl;
    printAttributes(character.getAttribute());
}

void DisplayStartingMenu()  //why did you make this a void and not just return a string (I'm guessing the "" has something to do with it!)?????
{
    string userSelectedOption = "";
    cout << "Welcome to the DnD character creation screen!\n";
    cout << "Please choose the character creation mode: \n";
    cout << "1. Manual\n";
    cout << "2. Random\n";

    /*if(userSelectedOption == "manual" || userSelected == "Manual")
    else if(userSelectedOption == "random" || userSelectedInput = "Random")
    else
    {
        DisplayStartingMenu();
    }*/
}



void DisplayOptions(string options[])
{
    for(int i = 0; i < sizeof(options)-1; i++) {
        cout << to_string(i) + ". " + options[i] << endl;
    }


    //????References vs. Pointers; the crap where they are saved in different memory?????
    /*
    if(options == STARTING_LEVELS)
    {
        for(int i = 0; i < sizeof(option); i++)
            cout << to_string(i) + ". " << endl;
    }
    else
    {
        for(int i = 0; i < sizeof(options); i++)
            cout << to_string(i) + ". " + options[i] << endl;
    
    }
    */
}

void DisplayLevels()
{
    for(int i = 0; i < 9; i++)
    {
        cout << "Level " + LEVELS[i] << endl;
    }
}



bool CorrectInput(string usersCharacterChoices, string listOfOptions[])
{
    if(usersCharacterChoices == "Random"){
        return true;
    }
    bool exists = false;

    for(int i = 0; i <= sizeof(listOfOptions); i++)
    {
        if(usersCharacterChoices == listOfOptions[i])
            exists = true;
    }

    return exists;
    /*if(exists == true)
        return exists;
    else if(0)
    {
        cout << "Please pick from the list only! Or check your spelling?" << endl;
        DisplayOptions(listOfOptions);
        //????I believe this should overwrite it correct?????
        cin >> usersCharacterChoices;
        CorrectInput(usersCharacterChoices, listOfOptions);
    }*/
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
        while(!characterCreationComplete)
        {
            if(name.empty())
            {
                //getline(cin, name);   //???Spaces in the name skip the next option(Ex. Richard Long)???
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
                if(!CorrectInput(input, ALIGNMENTS)) {
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
                if(!CorrectInput(input, BACKGROUNDS)) {
                    continue;
                }
                setTrait(input, background, BACKGROUNDS);
                cout << "" << endl;

            }
            if(level.empty())
            {
                cout << "Please choose a starting level: " << endl;
                DisplayLevels();
                cin >> input;
                if(!CorrectInput(input, LEVELS)) {
                    continue;
                }
                setTrait(input, level, LEVELS);
                cout << "" << endl;

            }
            
            characterCreationComplete = true;
            

        }
        //???Probably re-word this as select the # of the class???? 
        

        

       
       

        



        cout << name + " now it's time to pick your attribute stats!" << endl;
        playerAttributes = attributesSetUp();
        //????I assume this might not be best as I feel their might be a difference in
        //relation between finishing this in Attributes vs. here in Character?????
    }
    else if(mode == "random" || mode == "Random") 
    {
        cout << "Please enter a name for the character: ";
        cin >> name;
        cout << "" << endl;

        characterClass = CHARACTER_CLASSES[RandomSelections()];
        alignment = ALIGNMENTS[RandomSelections()];
        background = BACKGROUNDS[RandomSelections()];
        level = LEVELS[RandomSelections()];

        string strength = LEVELS[RandomSelections()];
        string dexterity = LEVELS[RandomSelections()];
        string constitution = LEVELS[RandomSelections()];
        string intelligence = LEVELS[RandomSelections()];
        string charisma = LEVELS[RandomSelections()];
        string wisdom = LEVELS[RandomSelections()];
        playerAttributes = Attributes(strength, dexterity, constitution, intelligence, charisma, wisdom);
        //???? ^ get randoms here and then send them straight to the constructor?????
    }
    else 
    {       //????This needs to loop????
            //????If it does how the heck does that work???????
        cout << "Incorrect Mode selected. Please enter either manuel or random" << endl;
    }


    // calling the character constructor
    Character playerCharacter = Character(name, characterClass, alignment, background, level, playerAttributes);     //????I understand but isn't this also creating a Character object called playerCharacter??????
    //?????I ask because in our "main" we already created a Character object called myCharacter so creating all these Character objects is confusing me????

    return playerCharacter;

}

int main()
{
    DisplayStartingMenu();
    string characterCreationMode = "";  //????What does this = I assume it's just ^ but how???????
    cin >> characterCreationMode;   //????What input are we taking(does this relate to userSelectedOption in DisplayStartingMenu() and if so then what does userSelectedOption =)????

    //This note is to inform the user that I didn't want to use a transformer becuase I don't know how :)
    cout << "NOTE: All options are case sensitive!!" << endl;
    Character myCharacter = CreateCharacter(characterCreationMode);
    printCharacter(myCharacter);
    return 0;
}

