/*dataand data1 are two strings with rainfall records of a few cities for months from January to December. The records of towns are separated by \n. The name of each town is followed by :.

data and towns can be seen in "Your Test Cases:".

Task:

function: mean(town, strng) should return the average of rainfall for the city town and the strng data or data1.
function: variance(town, strng) should return the variance of rainfall for the city town and the strng data or data1.
Examples:

mean("London", data), 51.19(9999999999996) 
variance("London", data), 57.42(833333333374)
Notes:

if functions mean or variance have as parameter town a city which has no records return -1
Don't truncate or round: the tests will pass if abs(your_result - test_result) <= 1e-2 or abs((your_result - test_result) / test_result) <= 1e-6 depending on the language (see function assertFuzzyEquals).
http://www.mathsisfun.com/data/standard-deviation.html
data and data1 are adapted from http://www.worldclimate.com*/

#include <string>
#include <math.h>

class Rainfall
{
public:
    static double mean(std::string town, const std::string &strng);
    static double variance(std::string town, const std::string &strng);
};

double Rainfall::mean(std::string town, const std::string &strng){
    int i = strng.find(town);
    if(i == std::string::npos)
        return -1;
    int num = 0;
    double total = 0;
    int months = 0;
    while(strng.compare(i,1, ":")!=0){
        i++;
        num++;
    }
    if(num!=town.length())
        return -1;
    num=0;
    i++;
    
    while(i < strng.find('\n',strng.find(town)) && i < strng.length()){
    months++;
        while(strng.compare(i,1, " ")!=0){
            i++;
        }
        i++;
        while(strng.compare(i+num,1, ".")!=0){
            num++;
        }
        while(num > 0){
            total+= (strng[i]-48)*pow(10,num-1);
            i++;
            num--;
        }
        i++;
        while( (strng.compare(i,1, ",")!=0) && ((i+num) < strng.find('\n',strng.find(town)))&& i < strng.length()){
            num++;
            total+= (strng[i]-48)*pow(10,num*(-1));
            i++;
        }
        num = 0;
        i++;
    }
    return total/months;
    
}

double Rainfall::variance(std::string town, const std::string &strng){    
    int i = strng.find(town);
    if(i == std::string::npos)
        return -1;
    double mean = Rainfall::mean(town, strng);
    int num = 0;
    double total = 0;
    double var = 0;
    int months = 0;
    while(strng.compare(i,1, ":")!=0){
        i++;
        num++;
    }
    if(num!=town.length())
        return -1;
    num=0;
    i++;
    std::cout << "\n";
    while(i < strng.find('\n',strng.find(town)) && i < strng.length()){
    months++;
        while(strng.compare(i,1, " ")!=0){
            i++;
        }
        i++;
        while(strng.compare(i+num,1, ".")!=0){
            num++;
        }
        while(num > 0){
            total+= (strng[i]-48)*pow(10,num-1);
            i++;
            num--;
        }
        i++;
        while( (strng.compare(i,1, ",")!=0) && ((i+num) < strng.find('\n',strng.find(town))) && i < strng.length()){
            num++;
            total+= (strng[i]-48)*pow(10,num*(-1));
            i++;
        }
        var += pow((total-mean),2);
        total = 0;
        num = 0;
        i++;
    }
    return var/months;
}
