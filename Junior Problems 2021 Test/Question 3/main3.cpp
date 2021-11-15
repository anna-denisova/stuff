#include "std_lib_facilities.h"

//Problem J3: Secret Instructions

int main()
{
    vector<string> instructions_vector_str;
    string line;
    int line_index = 0;
    
    while (getline(cin, line))
    {
        //ensures line is 5 chars
        if (line.size() != 5) {
            simple_error("enter 5 digits");
            return EXIT_FAILURE;
        }
        //ensures input is only digits
        for (char c : line) {
            if (c < '0' || c > '9') {
                simple_error("enter digits only");
                return EXIT_FAILURE;
            }
        }
        //ensures first line does not start with 00
        if (line_index == 0 &&line.substr(0, 2) == "00")
        {
            simple_error("starts with 00");
            return EXIT_FAILURE;
        }
        //ensures last three digits are not less than 100
        if (stoi(line.substr(2, 8)) < 100)
        {
            simple_error("last three digits less than 100");
            return EXIT_FAILURE;
        }
        //when input is 99999, break
        if (line == "99999")
        {
            break;
        }
        instructions_vector_str.push_back(line);
        line_index++;
    }

    int previous_direction;

    for (string s : instructions_vector_str)
    {
        // 01234
        // 0     -> index_1
        //  1    -> index_2
        //   234 -> index_345
        int index_1 = stoi(s.substr(0, 1));
        int index_2 = stoi(s.substr(1, 1));
        int index_345 = stoi(s.substr(2, 3));

        int sum_index_12 = index_1 + index_2;
        int remainder = sum_index_12  % 2;

        int direction;

        //left = 1
        //right = 2

        if (sum_index_12  == 0)
        {
            direction = previous_direction;
        }
        else if (remainder == 0)
        {
            direction = 2;
        }
        else
        {
            direction = 1;
        }

        previous_direction = direction;

        string str_direction;

        if (direction == 2){
            str_direction = "right";
        }else{
            str_direction = "left";
        }
        //outputs direction then number of steps 
        cout << str_direction << " " << index_345<<"\n";
    }

    return EXIT_SUCCESS;
}
