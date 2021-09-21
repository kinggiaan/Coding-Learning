//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix, const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string result="";
    //Buoc 1

    string s;
    string out[N1];
    char kytu[4][7]={{'E','F','G','H','I','J','K'},
                     {'L','M','N','O','P','Q','R'},
                     {'#','T','U','V','W','X','Y'},
                     {'@','A','S','Z','B','C','D'}};
    for(int i=0; i<N1; i++){
        s = input1[i];
        int t = 0;
        for(size_t j=0; j<s.length(); j++){
            if(s[j] != ' '){
                t = 2 * (s[j] - '0') + s[j+1] - '0';
                j++;
                out[i] += to_string(t);
                t = 0;
            }
            else {
                out[i] += " ";
                t = 0;
            }
        }
        out[i] += t;
    }
    // ket qua ra duoc out
    // Buoc 2
    string out1[N1];                 
    for(int i=0; i<N1; i++){
       s = out[i];
       int count=0; 
        for(size_t j=0; j<s.length(); j++){
            if(s[j] != ' '){
                count += 1;
            }
            else{
                count %= 7;
                // count = (count == 0)? 7 : count;
                if(count == 0){
                    count = 7;
                }
                int row = s[j-1] - '0';
                out1[i] += kytu[row][count-1]; // count dem tu 0
                count = 0;
            }
        } 
        int row = s[s.length() - 1] - '0';
        out1[i] += kytu[row][count-1];  
    }
    //ket qua co duoc mang out1
    // Ky tu dac biet #-35 va @-64
    string out2[N1];
    for(int i=0; i<N1; i++){
        for(size_t j=0; j<out1[i].length(); j++){
            if (out1[i][j] == '#'){
                bool decode = 0;
                for(size_t k=j+1; k<out1[i].length(); k++){
                    if((out1[i][k] == '#') || (out1[i][k] == '@')){
                        out2[i] +=  out1[i].substr(j+1,k-j-1); 
                        j = k-1;
                        decode = 1;
                        break;
                    }
                }
                if (decode == 0){
                    out2[i] += out1[i].substr(j+1, out1[i].length() - j - 1); 
                    j = out1[i].length() - 1;
                }
                if (out1[i][j]== 'Z'){
                    out2[i] += 'A';
                }
                else out2[i] += (out1[i][j] + 1); // ma ascii cua ky tu cuoi cung + 1
            }
            if(out1[i][j] == '@'){
                bool decode = 0;
                for(size_t k=j+1; k<out[i].length(); k++){
                    if((out1[i][k] == '#') || (out1[i][k] == '@')){
                        out2[i] += out1[i].substr(j+1,k-j-1);
                        reverse(out2[i].begin(),out2[i].end());
                        j = k-1;
                        decode = 1;
                    }
                }
                if(decode == 1){
                    out2[i] += out1[i].substr(j+1,out1[i].length() - j - 1);
                    reverse(out2[i].begin(),out2[i].end());
                    j = out1[i].length() - 1;
                }
            }
        }
    } // xuat ra dc out2[N1]
    for (int i = 0; i < N1; i++) {
        if (i == N1 - 1)
            result += out2[i];
        else result = result + out2[i] + "";
    }
    
    // check trong chuoi co VUA hay khong
    string strid;
    string out3[100];
    int VUA=0, THD=0;
    for(int i=0; i<NID; i++){
        strid = ID[i];
        if(strid.substr(0,3) == "VUA"){
            VUA += 1;
        }
        for(size_t i=1; i<strid.length()-1; i++){
            if(strid.substr(i,3) == "THD"){
                THD +=1;
            }
        }
    }
    if(VUA > 0){ /// Nếu có vua
    string chuoigoc;
    string daochuoi;
        for(int i=0; i<N1; i++){ // Buoc 1 
            string chan,le,chan1,le1;
            chuoigoc = out2[i];
            daochuoi = out2[i];
            for(size_t j=0; j<daochuoi.length(); j++){
                if(j%2 == 0){
                    chan += daochuoi[j];
                    for(size_t k=0; k<chan.length(); k++){
                        chan1 += chan[chan.length() - k -1];
                        chan1 += " ";
                    }
                    chan = chan1;
                }
                else {
                    le += daochuoi[j];
                    for(size_t k=0; k<le.length(); k++){
                        le += le[le.length() - k -1];
                    }
                    le = le1;
                }
                string phu;
                size_t e=0;
                for(size_t i=0; i<daochuoi.length(); i++){
                    if(chan[i] == ' '){
                        chan[i] = le[e];
                        e+=1;
                    }
                }
                int l = daochuoi.length();
                for(int i=0; i<l; i++){// Buoc 2
                    if(chuoigoc[i] < daochuoi[i]){
                        chuoigoc[i] = daochuoi[i];
                    }
                }
            }   
        }
        result = "";
        for (int i = 0; i < N1; i++) {
            if (i == N1 - 1)
                result += out2[i];
            else result = result + out2[i] + " ";
        }

    }
    if(THD >0){ // Nếu có tướng THD
        for(int i=0; i<N1; i++){
            string baomat,c,maxc;
            baomat = out2[i];
            for(size_t j=0; j<baomat.length(); j++){
                if(i%3 != 0){
                    c += baomat[i];
                }
            }
            maxc = c[0];
            for(size_t i=0; i<c.length(); i++){
                for(size_t j=0; j<c.length(); j++){
                    if(c[i] < c[j+1]){
                        c[i] = c[j+1];
                    }
                }
            }
        }
        result = "";
        for (int i = 0; i < N1; i++) {
            if (i == N1 - 1)
                result += out2[i];
            else result = result + out2[i] + " ";
        }
    }
    return result;
}
int decode(const string A, const string B)
{
    int la,lb,t=0;
    la = A.length();
    lb = B.length();
    for(int i = 0; i < la - lb + 1; i++){
        if(A.substr(i,lb) == B){
            t += 1;
        }
    }
    return t;
}
string findRoute(const string input3)
{
    string kytu = "UDLR";
    string strN,strB,S;
    int N, B;
    size_t t1=0;
    for(size_t i=0; i<input3.length(); i++){ // tach N B S tu chuoi input3 o dang string
        if(input3[i] == ' '){
            strN = input3.substr(0,i);
            t1 = i+1;
            break;
        }
    }
    for(size_t i=t1; i<input3.length(); i++){
        if(input3[i] == ' '){
            strB = input3.substr(t1,i-t1);
            t1 = i+1;
            break;
        }
    }
    S = input3.substr(t1,input3.length()-t1);
    N = stoi(strN);
    B = stoi(strB);
    string result;
    if(B < 0){ // vong chuoi S sang trai
        B = abs(B);
        for(int i=0; i<B;i++){
            S = S.substr(1,S.length()-1) + S[0];
        }
    }
    else if(B > 0){ // vong chuoi S sang phai
        for(int i=0; i<B; i++){
            S = S[S.length()-1] + S.substr(0,S.length()-1);
        }
    }
    else S += "";
    int t;
    for(size_t i=0; i<S.length(); i++){ // doi tung chu cai theo quy tac UDLRU...
            t = abs(N - 2*int(i));
        if(S[i] == 'U'){
            S[i] = kytu[t%4];
        }
        else if(S[i] == 'D'){
            if(t%4 == 0){
                S[i] = kytu[1];
            }
            else if(t%4 == 1){
                S[i] = kytu[2];
            }
            else if(t%4 == 2){
                S[i] = kytu[3];
            }
            else S[i] = kytu[0]; 
        }
        else if(S[i] == 'L'){
            if(t%4 == 0){
                S[i] = kytu[2];
            }
            else if(t%4 == 1){
                S[i] = kytu[3];
            }
            else if(t%4 == 2){
                S[i] = kytu[0];
            }
            else S[i] = kytu[1]; 
        }
        else {
            if(t%4 == 0){
                S[i] = kytu[3];
            }
            else if(t%4 == 1){
                S[i] = kytu[0];
            }
            else if(t%4 == 2){
                S[i] = kytu[1];
            }
            else S[i] = kytu[2]; 
        }
    }
    int x=0,y=0;
    for(size_t i=0; i<S.length(); i++){
        if(S[i] == 'U'){ 
            y += 1;
        }
        else if(S[i] == 'D'){
            y -= 1;
        }
        else if(S[i] == 'L'){
            x -= 1;
        }
        else {
            x += 1;
        }
    }
    result += '(';
    result += to_string(x);
    result += ',';
    result += to_string(y);
    result += ')';
    return result;
}
string decodeVfunction(const string A, const string B)
{
    string decodeV;
    size_t count1=0, count2=0, t;
    for(size_t i=0; i<A.length(); i++){
        if(A[i] == 'V'){
            count1 += 1;
        }
    }
    for(size_t i=0; i<B.length(); i++){
        if(B[i] == 'V'){
            count2 += 1;
        }
    }
    t = count1*count2;
    for(size_t i=0; i<size_t(t); i++){
        decodeV += 'V';
        decodeV += '(';
    }
    decodeV += '0';
    for(size_t i=0; i<t; i++){
        decodeV += ')';
    }
    return decodeV;
}
string findBetrayals(const string input5[], const int N5)
{
    char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int a[26];
    int x=7, max1, max2=0 ,max3=0, t=0;
    string result="";
    for(int i=0; i<26; i++){
        a[i] = 0;
    }
    for(int i=0; i<N5; i++){
        for(int j=0; j<6; j++){
            x -= 1;
            for(int k=0; k<26; k++){
                if(input5[i][j] == alphabet[k]){
                    a[k] += x;
                }
            } 
        }
        x = 7; 
    }
    max1 = a[0];
    for(int i=0; i<26; i++){
        if(a[i]>=max1){
            max1 = a[i];
        }
    }
    for(int i=0; i<26; i++){ // đưa những thằng có max1 vào
        if(result.length() < 3){
            if(a[i] == max1){
                result += alphabet[i];
                t += 1;
            }
        }
    }
    // tim max2
    
        for(int i=0; i<26; i++){
            if(result.length() < 3){
            if(max1 == a[i]){
                continue;
            }
            else if(a[i] > max2){
                max2 = a[i];
            }
        }
    }
    for(int i=0; i<26; i++){
        if(result.length() < 3){
            if(a[i] == max2){
                result += alphabet[i];
                t += 1;
            }
        }
    }
    // tim max3
    
        for(int i=0; i<26; i++){
        if(result.length() < 3){
            if((max1 == a[i]) || (max2 == a[i])){
                continue;
            }
            else if(a[i] > max3){
                max3 = a[i];
            }
        }
    }
    for(int i=0; i<26; i++){
        if(result.length() < 3){
            if(a[i] == max3){
                result += alphabet[i];
                t += 1;
            }
        }
    }
    return result;
}
int attack(const string input6[])
{
    int row = -1;
    int count0max = 0;
    for(int i=0; i<10; i++){
        int count0 = 0; // so luong so 0
        for(int j=0; j<10; j++){
            if(input6[i][j] == '2'){
                count0 = -1;
                break;
            }
            else if(input6[i][j] == '0'){
                count0 += 1;
            }
        }
        if(count0 >= count0max){
            count0max = count0;
            row = i;
        }
    }
    return row;
}
/*int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    int R;
    int N7, V, i, j;
    N7 = input7Str[0];
    V = input7Str[2];
    i = input7Str[4];
    j = input7Str[6];
    int a[N7][N7];
    int B[N7][N7];
    for(int i=0; i<N7; i++){ // cho gia tri ban dau cua a1 la 1
        for(int j=0; j<N7; j++){
            B[i][j] = 1;
        }
    }
    for(int i=0; i<k; i++){ // tao array tu input7Matrix[]
        string m;
        m = input7Matrix[i];
        for(size_t j=0; j<m.length(); j++){
            if(m[j] == ' '){
                for(int k=0; k<N7; k++){
                    for(int l=0; l<N7; l++){
                        a[k][l] = m[j-1];
                        B[k][l] *= a[k][l];
                    }
                }
            }
        }
    }
    int b;
    b = B[i][j];
    if(b < 0){
       for(int i=-1; i>b; i--){
           R = b - V*i;
           if((R >= 0) && (R < V)){
               return R;
           }
       } 
    }
    else R = b%V;
    return R;
}*/
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    int result[100][100];
    int count[100][100];
    int phu[100][100];
    int V, N7, col, row;
    int bd=0, kt=0;
    for(size_t i=0; i<input7Str.length(); i++){
        if(input7Str[i] == ' '){
         kt = i;
         break;
        }

    }
    N7 = stoi(input7Str.substr(0,kt));
    bd = kt + 1;
    while(input7Str[kt] != ' '){
         kt++;
    }
    V = stoi(input7Str.substr(bd,kt-bd));
   bd= kt + 1;
    while (input7Str[kt] != ' '){
        kt++;
    }
    row = stoi(input7Str.substr(bd,kt-bd));
    while (input7Str[kt] != ' '){
        kt++;
    }
    col = stoi(input7Str.substr(bd,kt-bd));
    //cout<< N7 <<"  "<<V<<"  "<< col <<"  "<<row<<endl;

    for(int i=0; i<k; i++){
        int poscol = 0, posrow = 0;
        size_t startM = 0, endM=0;
        size_t p=0;
        while(p<input7Matrix[i].length()){
            if(input7Matrix[i][p] == ' '){
                endM = p;
                phu[poscol][posrow]= stoi(input7Matrix[i].substr(startM,endM - startM));
                if(posrow == N7 -1){
                    posrow = 0;
                    poscol++;
                }
                else posrow++;
                startM = p + 1;
            }
            if(p == (input7Matrix[i].length() - 1)){
                endM = p;
                phu[poscol][posrow] = stoi(input7Matrix[i].substr(startM, endM - startM +1));
            }
            p++;
        }
        if(i == 0){
            for(int c=0; c<N7; c++){
                for(int r=0; r<N7; r++){
                    count[c][r] = phu[c][r];
                }
            }
        }
        else{
            for(int c=0; c<N7; c++){
                for(int r=0; r<N7; r++){
                    result[c][r] = 0;
                    for(int h = 0; h<N7; h++){
                        result[c][r] += count[c][h]*phu[h][r];
                    }
                }
            }
            for(int c=0; c<N7; c++){
                for(int r=0; r<N7; r++){
                    count[c][r] = result[c][r];
                }
            }
        }
    }
    int r = 0;
    if(result[row][col] > 0){
        for(int i=1; i<result[row][col]; i++){
            if(V >result[row][col]){
                r = result[row][col];
                break;
            }
            int g = result[row][col] - V*i;
            if((g<V) && (0<=g)){
                r = g;
                break;
            }
        }
    }
    else{
        for(int i = -1; i>result[row][col]; i--){
            if(abs(V) == abs(result[row][col])){
                r = 0;
                break;
            }
            int g=result[row][col] - (V*i);
            if((g<abs(V)) && (0<=g) && (V*i+g == result[row][col])){
                r = g;
                break;
            }
        }
    }
    return r;
}
#endif /* MONGOL_H */
