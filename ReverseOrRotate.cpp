/*The input is a string str of digits. Cut the string into chunks (a chunk here is a substring of the initial string) of size sz (ignore the last chunk if its size is less than sz).

If a chunk represents an integer such as the sum of the cubes of its digits is divisible by 2, reverse that chunk; otherwise rotate it to the left by one position. Put together these modified chunks and return the result as a string.

If

sz is <= 0 or if str is empty return ""
sz is greater (>) than the length of str it is impossible to take a chunk of size sz hence return "".
Examples:
revrot("123456987654", 6) --> "234561876549"
revrot("123456987653", 6) --> "234561356789"
revrot("66443875", 4) --> "44668753"
revrot("66443875", 8) --> "64438756"
revrot("664438769", 8) --> "67834466"
revrot("123456779", 8) --> "23456771"
revrot("", 8) --> ""
revrot("123456779", 0) --> "" 
revrot("563000655734469485", 4) --> "0365065073456944"*/

#include <string>

class RevRot
{
public:
    static std::string revRot(const std::string &strng, unsigned int sz);
};

std::string RevRot::revRot(const std::string &strng, unsigned int sz){
    std::string answer;
    int test = 0;
    
    if(sz <= 0 || strng.size() == 0 || strng.size() < sz)
        return "";
        
    for(int i=0; i < strng.size()/sz; i++){
        test = 0;
        for(int j=0; j < sz; j++){
            test += strng[(i*sz)+j];
        }
        if(test%2 == 0){
            for(int j=(sz-1); j >= 0; j--){
              answer.push_back(strng[(i*sz)+j]);
            }
        }else{
            for(int j=1; j < sz; j++){
              answer.push_back(strng[(i*sz)+j]);
            }
            answer.push_back(strng[i*sz]);
        }
      }
    return answer;
}
