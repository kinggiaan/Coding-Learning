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

//Function
int ConvertStoI(string s) {
    int N = 0;
    if (s[0] != 45) {
        for (size_t i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '0': N = N * 10; break;
            case '1': N = N * 10 + 1; break;
            case '2': N = N * 10 + 2; break;
            case '3': N = N * 10 + 3; break;
            case '4': N = N * 10 + 4; break;
            case '5': N = N * 10 + 5; break;
            case '6': N = N * 10 + 6; break;
            case '7': N = N * 10 + 7; break;
            case '8': N = N * 10 + 8; break;
            case '9': N = N * 10 + 9; break;
            default: break;
            }
        }
    }
    else {
        for (size_t i = 1; i < s.length(); i++) {
            switch (s[i]) {
            case '0': N = N * 10; break;
            case '1': N = N * 10 - 1; break;
            case '2': N = N * 10 - 2; break;
            case '3': N = N * 10 - 3; break;
            case '4': N = N * 10 - 4; break;
            case '5': N = N * 10 - 5; break;
            case '6': N = N * 10 - 6; break;
            case '7': N = N * 10 - 7; break;
            case '8': N = N * 10 - 8; break;
            case '9': N = N * 10 - 9; break;
            default: break;
            }
        }

    }
    return N;
}

char ChangeShiftUDLR(char& S, int shift) {
    string core = "UDLR";


    while (core[0] != S) {
        char mot, hai, ba, bon;
        mot = core[0];
        hai = core[1];
        ba = core[2];
        bon = core[3];
        core[0] = hai;
        core[1] = ba;
        core[2] = bon;
        core[3] = mot;
    }
    for (int i = 1; i <= shift; i++) {
        char mot, hai, ba, bon;
        mot = core[0];
        hai = core[1];
        ba = core[2];
        bon = core[3];
        core[0] = hai;
        core[1] = ba;
        core[2] = bon;
        core[3] = mot;
    }

    S = core[0];

    return S;
}

string Remove_A_Char(string& S, char c) {
    string temp;
    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == c) continue;
        temp += S[i];
    }
    S = temp;
    return S;
}
string ShiftString(string& S, int shift) {
    int nshift = 0;
    nshift = abs(shift) % S.length();
    if (nshift != 0) {
        string sub;
        if (shift < 0) {
            sub = S.substr(0, abs(nshift));
            for (int i = 0; i < abs(nshift); i++) {
                S[i] = ' ';

            }
            Remove_A_Char(S, ' ');
            S = S + sub;

        }
        if (shift > 0) {
            sub = S.substr(S.length() - nshift, nshift);
            for (size_t i = S.length(); i > S.length() - nshift - 1; i--) {
                S[i] = ' ';
            }
            Remove_A_Char(S, ' ');
            S = sub + S;
        }
        return S;
    }
    else return S;
}
int FindVUA(const string s) {
    int King = 0;
    if (s.length() < 3) return King;
    if (s.substr(0, 3) == "VUA") {
        King = 1;
    }
    else King = 0;

    return King;
}
int FindTHD(const string s) {
    int THD = 0;
    if (s.length() < 3) return THD;
    for (size_t i = 1; i < s.length() - 3; i++) {
        if (s.substr(i, 3) == "THD") {
            THD = 1; break;
        }
        else THD = 0;
    }
    return THD;
}
char ConvertBi2(string s) {
    char b=-1;
    if (s == "00") b = '0';
    if (s == "01") b = '1';
    if (s == "10") b = '2';
    if (s == "11") b = '3';
    return b;
}
char ConvertChar(string s) {
    char c=-1;
    size_t find = 0;
    char khong[8] = { '0','E','F','G','H','I','J','K' };
    char mot[8] = { '0','L','M','N','O','P','Q','R' };
    char hai[8] = { '0','#','T','U','V','W','X','Y' };
    char ba[8] = { '0','@','A','S','Z','B','C','D' };
    if (s.length() % 7 == 0) find = 7;
    else find = s.length() % 7;
    if (s[0] == '0') c = khong[find];
    if (s[0] == '1') c = mot[find];
    if (s[0] == '2') c = hai[find];
    if (s[0] == '3') c = ba[find];
    return c;
}
void RouteMoving(char c, int& x, int& y) {
    if (c == 'L') x = x - 1;
    if (c == 'R') x = x + 1;
    if (c == 'D') y = y - 1;
    if (c == 'U') y = y + 1;
}
string Reverse(string& s) {
    string temp;
    temp = "";
    size_t len = s.length();
    if ((len == 1) || (len == 0)) return s;
    for (size_t j = 0; j <= len - 1; j++) {
        temp += s[len - 1 - j];
    }
    s = temp;
    return s;

}
string ConvertSpec1(string& s,size_t j,string& temp) {
   size_t endspec = 0;
   if (s.length() == 1) return s;
   if (j == (s.length() - 1)) return s;
   for (size_t i = j + 1; j < s.length(); i++) {
      
       if ((s[i] == '#') || (s[i] == '@')) {
           endspec = i;
           break;
       }
       if (i == (s.length() - 1)) {
           endspec = 0;
           break;
       }
   }
   if (endspec == 0) {
       temp = s;
       if (s[size_t(s.length() - 1)] != 90) {
           char next = s[size_t(s.length() - 1)];
           next++;
           temp += next;
       }
       else {

           char next = 65;
           temp += next;
       }
   }
   else {
       s += " ";
       for (size_t a = 0; a < s.length()-1; a++) {
           if(a==endspec){
               temp += " " ;
               temp += s[a];
             
            }
           else temp += s[a];
       }
       if (temp[endspec-1] != 90) {
           char next = temp[endspec - 1];
           next++;
           temp[endspec]= next;
       }
       else {

           char next = 65;
           temp[endspec] = next;
       }
      
   }
   s = temp;
    return temp;
}
string ConvertSpec2_1(string& s, size_t j) {
    size_t end = 0;
    string temp;
    temp = "";
    if (s.length() == 1) return s;
    for (size_t i = j+1; i < s.length(); i++) {
        if ((s[i] == '#') || (s[i] == '@')) {
            end = i;
            break;
        }
        if (i == (s.length() - 1)) {
            end = 0;
            break;
        }
    }

    if (end == 0) {
        string phu = s.substr(j+1, s.length() -1 - j);
        size_t len = phu.length();
        if (!((len == 1) || (len == 0))) {
            for (size_t h = 0; h <= len - 1; h++) {
                temp += phu[len - 1 - h];
            }
        }
        else return s;

        int dem = j+1;
        for (size_t k = 0; k < len; k++) {
            s[dem] = temp[k];
            dem++;
        }
    }
    else {
        string phu = s.substr(j+1, end - j -1);
        size_t len = phu.length();
        if (!((len == 1) || (len == 0))) {
            for (size_t h = 0; h <= len - 1; h++) {
                temp += phu[len - 1 - h];
            }
        }
        else return s;

        int dem = j + 1;
        for (size_t k = 0; k < len; k++) {
            s[dem] = temp[k];
            dem++;
        }
    }

    return s;
}


string ChangPos(string& storage) {
    for (size_t h = 0; h < storage.length(); h++) {
        for (size_t t = h + 1; t < storage.length(); t++) {
            if (storage[h] > storage[t]) {
                char temp = storage[h];
                storage[h] = storage[t];
                storage[t] = temp;
            }
        }
    }
    return storage;
}

//Main function

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    int VUA = 0, THD = 0;
    string result;
    for (int i = 0; i < NID; i++) {
        VUA = FindVUA(ID[i]);
        THD = FindTHD(ID[i]);
        if (VUA || THD) break;
    }
    vector<string> storage;

    for (int in = 0; in < N1; in++) {
        size_t pos = 0;
        string bi;
        bi = "";
        while (pos < input1[in].length()) {
            if (input1[in][pos] != ' ') {
                bi += ConvertBi2(input1[in].substr(pos, 2));
                pos += 2;
            }
            else {
                bi += ' ';
                pos++;
            }
        }
        storage.push_back(bi);
    }

   
    for (size_t i = 0; i < storage.size(); i++) {
        {
            size_t start = 0, end = 0;
            string temp;
            for (size_t pos = 0; pos < storage[i].length(); pos++) {
                if (storage[i][pos] == ' ') {
                    end = pos;
                    temp += ConvertChar(storage[i].substr(start, end - start));
                    start = pos + 1;
                    temp += ' ';

                }
                if (pos == (storage[i].length()) - 1) {
                    temp = temp + ConvertChar(storage[i].substr(start, pos - start + 1));
                }
            }
            storage[i] = temp;
            Remove_A_Char(storage[i], ' ');
        }
        {
            string temp = "";
            for (size_t j = 0; j < storage[i].length(); j++) {
                if ((storage[i][j] == '#') || (storage[i][j] == '@')) {
                    if (storage[i][j] == '#') {
                       ConvertSpec1(storage[i], j,temp);
                       //storage[i]=temp;
                    }
                    if (storage[i][j] == '@') {
                        ConvertSpec2_1(storage[i],j);
                    }


                }
                
            }
          
            Remove_A_Char(storage[i], '#');
            Remove_A_Char(storage[i], '@');
            } //Problem with # and @
        if (VUA) {
            string sle;
            string schan;
            size_t len = storage[i].length();
            for (size_t j = 0; j < len; j++) {
                if (j % 2 == 0) {
                    schan += ' ';
                    schan += storage[i][j];
                }
                else sle += storage[i][j];

            }
            sle = Reverse(sle);
            schan = Reverse(schan);
            int k = 0;
            for (size_t j = 0; j < schan.length(); j++) {
                if (schan[j] == ' ') {
                    schan[j] = sle[k];
                    k++;
                }
            }


            for (size_t j = 0; j < storage[i].length() + 1; j++) {
                if (storage[i][j] > schan[j]) storage[i][j] = storage[i][j];
                else storage[i][j] = schan[j];
            }
        }


        if (THD) {
            if (storage[i].length() == 1) {
                storage[i] = "";
            }
            else {
                for (size_t pos = 0; pos < storage[i].length(); pos++) {
                    if (pos % 3 == 0) {
                        storage[i][pos] = ' ';
                    }
                }
                Remove_A_Char(storage[i], ' ');
                storage[i] = ChangPos(storage[i]);
            }
        }
    }
    
    for (size_t i = 0; i < storage.size(); i++) {
        if (i != size_t(N1 - 1)) result += storage[i] + ' ';
        else result += storage[i];
    }
    storage.clear();

    return result;
}
int decode(const string A, const string B)
{

    int count = 0;
    for (size_t i = 0; i < A.size(); i++) {
        if (A.substr(i, B.length()) == B) {
            count++;
        }
    }
    return count;
}
string findRoute(const string input3)
{
    int start = 0, end = 0;
    int N = 0, B = 0;
    string SN, SB, S;
    for (size_t i = 0; i < input3.length(); i++) {
        if (' ' == input3[i])
        {
            end = i;
            break;
        }
    }
    SN = input3.substr(0, end);
    N = ConvertStoI(SN);

    start = end + 1;
    for (size_t i = start; i < input3.length(); i++) {
        if (' ' == input3[i])
        {
            end = i;
            break;
        }
    }

    SB = input3.substr(start, end - start);
    B = ConvertStoI(SB);

    start = end + 1;
    for (size_t i = start; i < input3.length(); i++) {
        if (' ' == input3[i])
        {
            end = i;
            break;
        }
    }

    S = input3.substr(start, end - start);

    ShiftString(S, B);

    int shift = 0;
    
    for (size_t i = 0; i < S.length(); i++) {
        int up; up= N - 2 * i;
        shift = abs(up);
        ChangeShiftUDLR(S[i], shift);
    }

    int x = 0, y = 0;
    for (size_t i = 0; i < S.length(); i++) {
        RouteMoving(S[i], x, y);
    }
    string ans = '(' + to_string(x) + ',' + to_string(y) + ')';
    return ans;
}
string decodeVfunction(const string A, const string B)
{
    int demA, demB, count;
    demA = 0; demB = 0; count = 0;
    for (size_t i = 0; i < A.length(); i++) {
        if (A[i] == 'V') demA++;
    }
    for (size_t i = 0; i < B.length(); i++) {
        if (B[i] == 'V') demB++;
    }
    count = demA * demB;
    string result = "0";
    if (count != 0) {
        for (int i = 1; i <= count; i++) {
            result = "V(" + result + ')';
        }
    }
    return result;
}
string findBetrayals(const string input5[], const int N5)
{
    int* sum = new int[91];
    int Max1 = 0, Max2 = 0, Max3 = 0, Alpha1 = 0, Alpha2 = 0, Alpha3 = 0;
    string s = "123";
    for (int i = 65; i <= 90; i++) {
        sum[i] = 0;
    }
    for (int in = 0; in < N5; in++) {
        for (int i = 0; i < 6; i++) {
            sum[int(input5[in][i])] = sum[int(input5[in][i])] + 6 - i;
        }
    }
    for (int i = 65; i <= 90; i++) {
        if (sum[i] > Max3) {
            Max3 = sum[i];
            Alpha3 = i;
        }
    }
    for (int i = 65; i <= 90; i++) {
        if ((sum[i] > Max2) && (sum[i] <= Max3)) {
            if (Alpha3 == i) continue;
            Max2 = sum[i];
            Alpha2 = i;
        }
    }
    for (int i = 65; i <= 90; i++) {
        if ((sum[i] > Max1) && (sum[i] <= Max2)) {
            if ((Alpha3 == i) || (Alpha2 == i)) continue;
            Max1 = sum[i];
            Alpha1 = i;
        }
    }

    s[0] = Alpha3;
    s[1] = Alpha2;
    s[2] = Alpha1;
    delete[] sum;
    return s;
}
int attack(const string input6[])
{
    int* check0 = new int[10];
    int* check2 = new int[10];
    int weakest = -1, weak = 0;
    for (int i = 0; i < 10; i++) {
        check0[i] = 0;
        check2[i] = 0;
    }
    for (int s = 0; s < 10; s++) {
        for (size_t i = 0; i < input6[s].length(); i++) {
            if (input6[s][i] == '0') check0[s]++;
            if (input6[s][i] == '2') check2[s]++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if ((check0[i] >= weak) && (check0[i] != 0)) {
            if (check0[i] == 0) continue;

            if (check2[i] == 0)
            {
                weak = check0[i];
                weakest = i;
            }
        }
    }
    delete[] check0;
    delete[] check2;
    return weakest;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    int result[100][100];
    int count[100][100];
    int phu[100][100];
    int V, N7, col, row;
    int bd = 0, kt = 0;
    for (size_t i = 0; i < input7Str.length(); i++) {
        if (input7Str[i] == ' ') {
            kt = i;
            break;
        }

    }
    N7 = stoi(input7Str.substr(0, kt));
    bd = kt + 1;
    while (input7Str[kt] != ' ') {
        kt++;
    }
    V = stoi(input7Str.substr(bd, kt - bd));
    bd = kt + 1;
    while (input7Str[kt] != ' ') {
        kt++;
    }
    col = stoi(input7Str.substr(bd, kt - bd));
    while (input7Str[kt] != ' ') {
        kt++;
    }
    row = stoi(input7Str.substr(bd, kt - bd));
    cout << N7 << "  " << V << "  " << col << "  " << row << endl;

    return -1;
    //cout << N7 << " " << V << " " << nrow << " " << ncol << endl;
    /*for (int i = 0; i < k; i++) {
        int pco = 0, prow = 0;
        size_t smatrix = 0, ematrix = 0;
        size_t pos = 0;
        while (pos < input7Matrix[i].length()) {
            if (input7Matrix[i][pos] == ' ') {
                ematrix = pos;
                temp[pco][prow] = ConvertStoI(input7Matrix[i].substr(smatrix, ematrix - smatrix));


                if (prow == N7 - 1) {
                    prow = 0;
                    pco++;
                }
                else prow++;
                smatrix = pos + 1;
            }
            if (pos == (input7Matrix[i].length() - 1)) {
                ematrix = pos;
                temp[pco][prow] = ConvertStoI(input7Matrix[i].substr(smatrix, ematrix - smatrix + 1));
            }

            pos++;
        }
        if (i == 0) {
            for (int col = 0; col < N7; col++) {
                for (int row = 0; row < N7; row++) {
                    cal[col][row] = temp[col][row];
                }
            }

        }
        else {
            for (int col = 0; col < N7; col++) {
                for (int row = 0; row < N7; row++) {
                    ans[col][row] = 0;
                    for (int h = 0; h < N7; h++) {
                        ans[col][row] += cal[col][h] * temp[h][row];
                    }
                }
            }

            for (int col = 0; col < N7; col++) {
                for (int row = 0; row < N7; row++) {
                    cal[col][row] = ans[col][row];
                }
            }


        }
    }
    
   
    int R = 0;
    if (ans[nrow][ncol] > 0) {
        for (int i = 1; i < ans[nrow][ncol]; i++) {
            if (V > ans[nrow][ncol]) {
                R = ans[nrow][ncol];
                break;
            }
            int k = ans[nrow][ncol] - V * i;
            if ((k < V) && (0 <= k)) {
                R = k; break;
            }
        }
    }
    else {
        for (int i = -1; i > ans[nrow][ncol]; i--) {
            if (abs(V) == abs(ans[nrow][ncol])) {
                R = 0;
                break;
            }
            int k = ans[nrow][ncol] - (V * i);
                if ((k < abs(V)) && (0 <= k) && (V * i + k == ans[nrow][ncol])) {
                    R = k; break;
            }
        }
    }

    return R;
   */
}

#endif /* MONGOL_H */
