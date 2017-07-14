/*###Task:

Your task is to write a function which returns the sum of following series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
###Rules:

You need to round the answer upto 2 decimal places and return it as String.
If the given value is 0 then it should return 0.00
You will only be given Natural Numbers as arguments.
###Examples:

SeriesSum(1) => 1 = "1"
SeriesSum(2) => 1 + 1/4 = "1.25"
SeriesSum(5) => 1 + 1/4 + 1/7 + 1/10 + 1/13 = "1.57"
NOTE: In PHP the function is called series_sum().*/

#include <math.h>
std::string seriesSum(int n)
{
    double series = 0;
    std::string answer;
    if(n == 0){
        answer = "0.00";
        return answer;
    }
    
    for(double i=0; i < n; i++){
        series += 1/(1+(3*i));     
    }
    series = round(series*100)/100;
    answer = std::to_string(series);
    answer.resize(4);
    return answer;
    // Happy Coding ^_^
}
