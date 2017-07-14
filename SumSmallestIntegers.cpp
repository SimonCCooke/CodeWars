/*Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 integers. No floats or empty arrays will be passed.

For example, when an array is passed like [19,5,42,2,77], the output should be 7.

[10,343445353,3453445,3453545353453] should return 3453455.

Hint: Do not modify the original array.*/

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    int n = 0;
    long lowest1 = numbers[0];
    long lowest2 = numbers[0];
    while(n<numbers.size()){
    if(numbers[n] < lowest1){
    lowest1 = numbers[n];
    }
    n++;
    }
    n=0;
    if(lowest1==lowest2){
    lowest2 = numbers[1];
    }
    while(n<numbers.size()){
    if(numbers[n] < lowest2 && numbers[n] != lowest1 ){
    lowest2 = numbers[n];
    }
    n++;
    }
    return (lowest1+lowest2);
}
