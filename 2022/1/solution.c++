#include <iostream>
#include <fstream>
#include <String>
using namespace std;

bool isNewMax(int currentMax, int value);
int getMaxArr(int arr[], int size);

void solve()
{
    fstream textData;
    textData.open("data.txt", ios::in);

    if(textData.is_open())
    {
        int topThreeMax[] = {0, 0, 0};
        int size = sizeof(topThreeMax)/sizeof(int);
        int currentValue = 0;
        string tp;
        while(getline(textData, tp))
        {
            if(tp.empty())
            {
                for(int i = 0; i < size; i++)
                {
                    if(currentValue > topThreeMax[i])
                    {
                        topThreeMax[i] = currentValue;
                        break;
                    }
                }
                currentValue = 0;
            }
            else
            {
                currentValue += atoi(tp.c_str());
            }
        }
        textData.close();
        int maxOfThree = topThreeMax[0] + topThreeMax[1] + topThreeMax[2];
        int richestElf = getMaxArr(topThreeMax, size);
        cout << "topThreeMax: " << maxOfThree << endl;
        cout << "RichestElf: " << richestElf << endl;
        
    }
}

int getMaxArr(int array[], int size)
{
    int max = array[0];
    for(int i = 1; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

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
    solve();
    return 0;
}