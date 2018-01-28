#include <iostream>
#include <fstream>
#include "CharacterData.hpp"

using namespace std;

std::string getFileContents (std::ifstream&);
         //Gets file contents
void ChoiceOneCar();
void ChoiceOneDoor();
void ChoiceTwoAmmo();
void ChoiceTwoParents();

int main()
{
    Player playerOne;
    char choiceOne;
    char repeat = 'n';
    do{

    std::ifstream Reader001 ("Text Files/Title_Card");             //Open file
    std::string textOut = getFileContents (Reader001);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader001.close();

    std::cout<<"Press enter to begin." << std::endl;
    cin.get();

    std::ifstream Reader002 ("Text Files/Intro_Segment_Name");             //Open file
    textOut = getFileContents (Reader002);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader002.close ();

    std::getline(cin, playerOne.name);
    std::cout << playerOne.name <<".  I always hated my name." << std::endl;

    std::ifstream Reader003 ("Text Files/Intro_Segment_ChoiceOne");             //Open file
    textOut = getFileContents (Reader003);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader003.close ();

    std::cin>>choiceOne;
    std::cin.ignore(20,'\n');

        switch (choiceOne)
        {
        case 'c':
        case 'C':
        ChoiceOneCar();
        break;

        case 'd':
        case 'D':
        ChoiceOneDoor();
        break;

        default:
        std::cout<<"You did not choose correctly. You died. Try again." << std::endl;

        }

        std::cout<<"Would you like to try again?  y/n ";
        std::cin>>repeat;
    }
while (repeat =='y');

    return 0;
}

void ChoiceOneCar()
{
    char choiceTwo;
    std::ifstream Reader001 ("Text Files/ChoiceOne_Car");             //Open file
    std::string textOut = getFileContents (Reader001);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader001.close();
    std::cin>>choiceTwo;
    std::cin.ignore(20, '\n');

     switch (choiceTwo)
        {
        case 'a':
        case 'A':
        ChoiceTwoAmmo();
        break;

        case 'p':
        case 'P':
        ChoiceTwoParents();
        break;

        default:
        std::cout<<"You did not choose correctly. You died. Try again." << std::endl;
        }


}

void ChoiceOneDoor()
{
     std::ifstream Reader001 ("Text Files/ChoiceOne_Door");             //Open file
    std::string textOut = getFileContents (Reader001);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader001.close();

}
void ChoiceTwoAmmo()
{
    std::ifstream Reader001 ("Text Files/ChoiceTwo_Ammo");             //Open file
    std::string textOut = getFileContents (Reader001);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader001.close();
}

void ChoiceTwoParents()
{
    std::ifstream Reader001 ("Text Files/ChoiceTwo_Parents");             //Open file
    std::string textOut = getFileContents (Reader001);       //Get file
    std::cout << textOut << std::endl;               //Print it to the screen
    Reader001.close();
}
std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }



  return 0;
}

