//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
//subFunction
bool isVUA(string& ID)
{
    
    for (int i = 0; i < 3; i++)
    {
        if (ID[i] >= 97 && ID[i] <= 122)
        {
            return false;
        }
    }
    if ((ID[0] == 'V' && ID[1] == 'U' && ID[2] == 'A'))
    {
        return true;
    }
    return false;
}
bool isTHD(string& ID)
{
    int L = ID.length();
    for (int i = 1; i + 3 < L; i++)
    {
        if (ID[i] == 84 && ID[i + 1] == 72 && ID[i + 2] == 68)
        {
            return true;
        }
    }
    return false;
}
string Decimal(string input)
{
    if (input == "00") return "0";
    if (input == "01") return "1";
    if (input == "10") return "2";
    if (input == "11") return "3";
    return 0;
}
string SolveText(string input1)
{
    vector <string> data;
    vector <string> tempdata;
    vector <string> process;
    vector <int> location;
    vector <int> asciicount = { 0,0,0,0,0 };
    string finaldata;
    int N1 = input1.size();
    int position = 0;
    int count = 0;
    string temp;
    string ascii = " ";
    ///////////DECIMAL//////////////
    while (position < N1)
    {
        if (input1[position] != ' ')
        {
            temp.clear();
            temp += Decimal(input1.substr(position, 2));
            position += 2;
        }
        else
        {
            temp.clear();
            temp += ' ';
            position++;
        }
        data.push_back(temp);
    }
    ////////////ASCII//////////////
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == "0")
        {
            asciicount[0]++;
            if (asciicount[0] = 8)
            {
                asciicount[0] = 1;
            }
        }
        else if (data[i] == "1")
        {
            asciicount[1]++;
            if (asciicount[1] == 8)
            {
                asciicount[1] = 1;
            }
        }
        else if (data[i] == "2")
        {
            asciicount[2]++;
            if (asciicount[2] == 8)
            {
                asciicount[2] = 1;
            }
        }
        else if (data[i] == "3")
        {
            asciicount[3]++;
            if (asciicount[3] == 8)
            {
                asciicount[3] = 1;
            }
        }
        else if (data[i] == " ")
        {
            if (asciicount[0] != 0)
            {
                switch (asciicount[0])
                {
                case 1:
                    ascii = "E";
                    tempdata.push_back(ascii);
                    break;
                case 2:
                    ascii = "F";
                    tempdata.push_back(ascii);
                    break;
                case 3:
                    ascii = "G";
                    tempdata.push_back(ascii);
                    break;
                case 4:
                    ascii = "H";
                    tempdata.push_back(ascii);
                    break;
                case 5:
                    ascii = "I";
                    tempdata.push_back(ascii);
                    break;
                case 6:
                    ascii = "J";
                    tempdata.push_back(ascii);
                    break;
                case 7:
                    ascii = "K";
                    tempdata.push_back(ascii);
                    break;
                default:
                    break;
                }
            }
            if (asciicount[1] != 0)
            {
                switch (asciicount[1])
                {
                case 1:
                    ascii = "L";
                    tempdata.push_back(ascii);
                    break;
                case 2:
                    ascii = "M";
                    tempdata.push_back(ascii);
                    break;
                case 3:
                    ascii = "N";
                    tempdata.push_back(ascii);
                    break;
                case 4:
                    ascii = "O";
                    tempdata.push_back(ascii);
                    break;
                case 5:
                    ascii = "P";
                    tempdata.push_back(ascii);
                    break;
                case 6:
                    ascii = "Q";
                    tempdata.push_back(ascii);
                    break;
                case 7:
                    ascii = "R";
                    tempdata.push_back(ascii);
                    break;
                default:
                    break;
                }
            }
            if (asciicount[2] != 0)
            {
                switch (asciicount[2])
                {
                case 1:
                    ascii = "#";
                    tempdata.push_back(ascii);
                    break;
                case 2:
                    ascii = "T";
                    tempdata.push_back(ascii);
                    break;
                case 3:
                    ascii = "U";
                    tempdata.push_back(ascii);
                    break;
                case 4:
                    ascii = "V";
                    tempdata.push_back(ascii);
                    break;
                case 5:
                    ascii = "W";
                    tempdata.push_back(ascii);
                    break;
                case 6:
                    ascii = "X";
                    tempdata.push_back(ascii);
                    break;
                case 7:
                    ascii = "Y";
                    tempdata.push_back(ascii);
                    break;
                default:
                    break;
                }
            }
            if (asciicount[3] != 0)
            {
                switch (asciicount[3])
                {
                case 1:
                    ascii = "@";
                    tempdata.push_back(ascii);
                    break;
                case 2:
                    ascii = "A";
                    tempdata.push_back(ascii);
                    break;
                case 3:
                    ascii = "S";
                    tempdata.push_back(ascii);
                    break;
                case 4:
                    ascii = "Z";
                    tempdata.push_back(ascii);
                    break;
                case 5:
                    ascii = "B";
                    tempdata.push_back(ascii);
                    break;
                case 6:
                    ascii = "C";
                    tempdata.push_back(ascii);
                    break;
                case 7:
                    ascii = "D";
                    tempdata.push_back(ascii);
                    break;
                default:
                    break;
                }
            }
            asciicount = { 0,0,0,0,0 };
        }
    }
    //////////PROCESS#@/////////
    data.clear();
    count = 0;
    for (int i = 0; i < tempdata.size(); i++)
    {
        if (tempdata[i] == "#" || tempdata[i] == "@")
        {
            location.push_back(i);
        }
    }

    location.push_back(tempdata.size());

    if (location[0] != 0)
    {
        for (int i = 0; i < location[0]; i++)
        {
            data.push_back(tempdata[i]);
        }
    }

    for (int i = 0; i < location.size() - 1; i++)
    {
        if (tempdata[location[i]] == "#")
        {
            for (int j = location[i]; j < location[i + 1]; j++)
            {
                data.push_back(tempdata[j]);
            }
            data.push_back("U");
        }
        if (tempdata[location[i]] == "@")
        {
            for (int j = location[i]; j < location[i + 1]; j++)
            {
                process.insert(process.begin(), tempdata[j]);
            }
            for (int j = 0; j < process.size(); j++)
            {
                data.push_back(process[j]);
            }

        }
    }

    /////////////EXPORT////////////
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] != "#" && data[i] != "@")
        {
            finaldata = finaldata + data[i];
        }
    }
    return finaldata;
}

////////////////////////////////////////////////////////////////////////////
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string input = input1[0] + " " + input1[1];
    string output = SolveText(input);
    return output;
}
int decode(const string A, const string B)
{
    int count = 0;
    string theA = A;
    string theB = B;
    for (int i = 0; i < (theA.size() - theB.size()); i++)
    {
        if (theA.substr(i, theB.size()) == theB)
        {
            count++;
        }
    }
    return count;
}
string findRoute(const string input3)
{
    //////////GETDATA////////
    int count = 0;
    int N;
    int B;
    string S = "";
    vector <int> location;
    for (int i = 0; i < input3.size(); i++)
    {
        if (input3[i] == ' ')
        {
            location.push_back(i);
        }
    }
    location.push_back(input3.size());
    N = stoi(input3.substr(0, location[0]));
    B = stoi(input3.substr(location[0], (location[1] - location[0])));
    S += input3.substr(location[1] + 1, location[2] - location[1] - 1);
    //////////////Resolve//////////////
    int x = 0;
    int y = 0;
    //////PROCESS S////
    string S2 = "";
    if (B < 0)
    {
        int move = 0 - B;
        move = move % S.size();
        S2 = S.substr(move, S.size() - move) + S.substr(0, move);
        S.clear();
        S += S2;
        S2.clear();
    }
    if (B > 0)
    {
        int move = 0;
        move = S.size() - B % S.size();
        S2 = S.substr(move, S.size() - move) + S.substr(0, move);
        S.clear();
        S += S2;
        S2.clear();
    }
    string Char = "UDLR";
    for (int i = 0; i < S.size(); i++)
    {
        int pos;
        if (S[i] == 'U')
        {
            pos = 0;
        }
        if (S[i] == 'D')
        {
            pos = 1;
        }
        if (S[i] == 'L')
        {
            pos = 2;
        }
        if (S[i] == 'R')
        {
            pos = 3;
        }
        pos = (pos + abs(N - 2 * i));
        pos = pos % 4;
        S2 += Char[pos];
    }
    S.clear();
    S += S2;
    S2.clear();
    //////READ S///////
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'U')
        {
            y++;
        }
        if (S[i] == 'D')
        {
            y--;
        }
        if (S[i] == 'R')
        {
            x++;
        }
        if (S[i] == 'L')
        {
            x--;
        }
    }
    return to_string(x) + "," + to_string(y);
}
string decodeVfunction(const string A, const string B)
{
    int count = 0;
    string datareturn = "";
    string theA = A;
    string theB = "V";
    for (int i = 0; i < (theA.size() - theB.size()); i++)
    {
        if (theA.substr(i, theB.size()) == theB)
        {
            count++;
        }
    }
    theA.clear();
    theA += B;
    for (int i = 0; i < (theA.size() - theB.size()); i++)
    {
        if (theA.substr(i, theB.size()) == theB)
        {
            count++;
        }
    }
    for (int i = 0; i < count + 1; i++)
    {
        datareturn += "V(";
    }
    datareturn += "0";
    for (int i = 0; i < count + 1; i++)
    {
        datareturn += ")";
    }

    return datareturn;
}
string findBetrayals(const string input5[], const int N5)
{
    int Char[26] = {};
    for (int i = 0; i < N5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                if (input5[i][j] == (k + 65))
                {
                    Char[k] += (6 - j);
                }
            }

        }

    }
    int MAX = 0;
    string theMAX;
    for (int i = 0; i < 26; i++)
    {
        if (Char[i] > MAX)
        {
            MAX = Char[i];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (Char[i] == MAX)
        {
            theMAX.push_back(65 + i);
        }
    }
    return theMAX.substr(0, 1);
}
int attack(const string input6[])
{
    int countPeople[10] = {};
    int MAX = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (input6[i][j] == '0')
            {
                countPeople[i]++;
            }
            if (input6[i][j] == '2')
            {
                countPeople[i] -= 99;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (MAX < countPeople[i])
        {
            MAX = countPeople[i];
        }
    }
    for (int i = 9; i != -1; i--)
    {
        if (countPeople[i] == MAX)
        {
            return i + 1;
        }

    }
    return -1;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    return -1;
}

#endif /* MONGOL_H */
