#include <iostream>
#include <fstream>
#include <String>
using namespace std;


bool isNewMax(int currentMax, int value)
{
    if(currentMax < value)
    {
        return true;
    }
    return false;
}

int main()
{
    fstream textData;
    textData.open("data.txt", ios::in);

    if(textData.is_open())
    {
        int currentMax = 0;
        int currentValue = 0;
        string tp;
        while(getline(textData, tp))
        {
            if(tp.empty())
            {
                if(isNewMax(currentMax, currentValue))
                {
                    currentMax = currentValue;
                    cout << "newMax: " << currentMax << endl;
                }
                currentValue = 0;
            }
            else
            {
                currentValue += atoi(tp.c_str());
                cout << "CurrentValue: " << currentValue << endl;
            }
        }
    textData.close();
    cout << "CurrentMax: " << currentMax << endl;

    }


}