#include <iostream>
#include <sstream>
#include <string>

std::string line;
while (std::getline(cin, line)) // reads in a line
{
    std::istringstream stream(line);
    std::string spaceless;
    std::string word;
    while (stream >> word) // get words on the line without any whitespace
    {
        spaceless += word; // assemble without spaces
        if (spaceless ==  "shorttonnes")
        {
            std :: cout << spaceless;
        }
        else if (spaceless ==  "Someothertoken")
        {
            // do something else with spaceless
        }
        else if ( ... ) 
        {
            // rinse, repeat
        }
    }

}

