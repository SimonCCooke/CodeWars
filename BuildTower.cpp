/*Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Python: return a list;
JavaScript: returns an Array;
C#: returns a string[];
PHP: returns an array;
C++: returns a vector<string>;
Haskell: returns a [String];
Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ', 
  ' *** ', 
  '*****'
]
and a tower of 6 floors looks like below

[
  '     *     ', 
  '    ***    ', 
  '   *****   ', 
  '  *******  ', 
  ' ********* ', 
  '***********'
]
Go challenge Build Tower Advanced once you have finished this :)*/

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
    std::vector<std::string> tower;
    std::string towerFloor;
        for(int i=1; i <= nFloors; i++){
            for(int j=1; j <= (nFloors - i); j++){
                towerFloor += " ";
            }
            for(int k=1; k <= (i*2 - 1); k++){
                towerFloor += "*";
            }
            for(int j=1; j <= (nFloors - i); j++){
                towerFloor += " ";
            }
            tower.push_back(towerFloor);
            towerFloor.clear();
        }
        return tower;
    }
};
