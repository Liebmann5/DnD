# DnD
Please create an OOP console only application in C++ to generate a Dungeons and Dragons (DnD) 5e character with the following requirements.

Please refer to the following when writing your application and feel free to contact ***** ****** with any questions regarding the requirements.
https://fastcharacter.com/
https://media.wizards.com/2016/dnd/downloads/5E_CharacterSheet_Fillable.pdf
https://www.dndbeyond.com/sources/basic-rules/step-by-step-characters
The application must compile using g++
Feel free to use whatever C++ standard you like, but at least C++11
The application will be checked with Compiler Explorer using the -Wall and -Wextra compiler arguments
https://gcc.godbolt.org/z/v4zx613Y6
This application should be interactive and terminate after a character has been created and displayed on console
The user should be able to generate an entirely random character (i.e. user selects the option “random character” and all character traits are randomly populated)
The user should be able to alternatively specify character traits sequentially
During “manual” character creation all available options for each trait should be listed
Each trait should have no more than 10 options (0 through 9), including a random option (i.e. the user specifies they would like a level 5 dwarf but wants to randomize the alignment)
Some options will need to be manually entered (i.e. character name)
At a minimum, the following traits should be part of the character creation. Any additional traits would be viewed as extra credit.
Name
Class
Alignment
Background
Starting Level
Ability scores should also be randomly generated or manually provided by the user. At a minimum, the following ability should be part of the character creation. Any additional traits would be viewed as extra credit.
Strength
Dexterity
Constitution
Intelligence
Wisdom
Charisma
Note: Assume the user may enter invalid options and consider handling them accordingly.
