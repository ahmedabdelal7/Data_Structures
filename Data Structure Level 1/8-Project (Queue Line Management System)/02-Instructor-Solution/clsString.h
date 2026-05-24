#pragma once
#include <iostream>
#include <vector>
using namespace std;
class clsString
{
private:
    string _Value;

public:
    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        this->_Value = Value;
    }

    static short CountWords(string str) {

        string Delim = " ";
        short pos = 0;
        string sWord = "";
        short Counter = 0;

        while ((pos = str.find(Delim)) != string::npos)
        {

            sWord = str.substr(0, pos);
            if (sWord != "") {
                Counter++;//1 2
            }

            str.erase(0, pos + Delim.length());
        }

        if (str != "")
            Counter++;
        return Counter;

    }

    short CountWords() {
        return CountWords(this->_Value);
    }

    //-------
    static void PrintFirstLetterOfEachWord(string myString) {
        bool IsFirstLetter = true;
        for (int i = 0; i < myString.length(); i++) {
            //my work 
            //if (i ==0 ) {
            //	cout << myString[i] << endl;
            //}
            //else if (myString[i] != ' ' && myString[i-1] == ' ' ) {
            //	cout << myString[i] << endl;
            //}
            //abo hadhood work
            if (myString[i] != ' ' && IsFirstLetter)
                cout << myString[i] << endl;

            IsFirstLetter = (myString[i] == ' ' ? true : false);
        }
    }

    static void Swap(string& A, string& B) {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }


    void PrintFirstLetterOfEachWord() {
        PrintFirstLetterOfEachWord(_Value);
    }
    //-------
    static string UpperFirstLetterOfEachWord(string& myString) {

        bool IsFirstLetter = true;

        for (int i = 0; i < myString.length(); i++) {

            if (myString[i] != ' ' && IsFirstLetter) {

                myString[i] = toupper(myString[i]);

            }
            IsFirstLetter = (myString[i] == ' ' ? true : false);

        }
        return myString;
    }

    void UpperFirstLetterOfEachWord() {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }
    //-------
    static string LowerFirstLetterOfEachWord(string& myString) {

        bool IsFirstLetter = true;

        for (int i = 0; i < myString.length(); i++) {

            if (myString[i] != ' ' && IsFirstLetter) {

                myString[i] = tolower(myString[i]);

            }
            IsFirstLetter = (myString[i] == ' ' ? true : false);

        }
        return myString;
    }

    void LowerFirstLetterOfEachWord() {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }
    //-------
    static string ToUpper(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = toupper(s[i]);
        }
        return s;
    }

    void ToUpper() {
        _Value = ToUpper(_Value);
    }
    //-------
    static string ToLower(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    void ToLower() {
        _Value = ToLower(_Value);
    }
    //-------
    static string InvertStringCase(string s) {

        for (int i = 0; i < s.length(); i++)
            s[i] = (islower(s[i]) ? toupper(s[i]) : tolower(s[i]));

        return s;

    }

    void InvertStringCase() {
        _Value = InvertStringCase(_Value);
    }

    static char InvertLetterCase(char c) {
        if (isupper(c))
            return tolower(c);
        else
            return toupper(c);
    }
    //-------
    enum enWhatToCount { Capital = 1, Small = 2, Punc = 3, All = 4, Digit = 5 };

    static short CountLetters(string s, enWhatToCount CountLetters = All) {

        short count = 0;

        if (CountLetters == All)
            return s.length();

        for (short i = 0; i < s.length(); i++)
        {
            if (CountLetters == Capital && isupper(s[i]))
                count++;

            else if (CountLetters == Small && islower(s[i]))
                count++;

            else if (CountLetters == Punc && ispunct(s[i]))
                count++;

            else if (CountLetters == Digit && isdigit(s[i]))
                count++;



        }return count;


    }

    short CountLetters(enWhatToCount Count = All) {
        return CountLetters(_Value, Count);


    }
    //-------
    static short CountSpecificLetter(string s, char c, bool IsMatchCase = false) {

        short count = 0;

        for (short i = 0; i < s.length(); i++)
        {
            if (IsMatchCase) {

                count += (s[i] == c ? 1 : 0);
            }
            else
                count += (tolower(s[i]) == tolower(c) ? 1 : 0);
        }
        return count;

    }

    short CountSpecificLetter(char c, bool IsMatchCase = false)
    {
        return CountSpecificLetter(_Value, c, IsMatchCase);
    }
    //-------
    static bool IsVowel(char c) {
        c = toupper(c);
        return ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'));

    }

    static short CountVowel(string s) {

        short Count = 0;

        for (short i = 0; i < s.length(); i++)
        {
            Count += IsVowel(s[i]) ? 1 : 0;

        }
        return Count;

    }

    short CountVowel() {
        return CountVowel(_Value);
    }
    //-------

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            // if (sWord != "")
            // {
            vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }


    vector <string> Split(string Delim = " ") {

        return Split(_Value, Delim);

    }
    //-------
    static string TrimLeft(string s)
    {

        for (short i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
                return s.substr(i, s.length() - 1);
        }

    }

    void TrimLeft() {
        _Value = TrimLeft(_Value);

    }

    static string TrimRight(string s)
    {

        //while (s[s.length()-1] == ' ') {
        //	s.erase(s.length()-1, s.length() - 2);
        //}
        //return  s;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            //isalpha(s[i])
            if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
                return s.substr(0, i + 1);
        }
    }

    void TrimRight() {
        _Value = TrimRight(_Value);
    }

    static string Trim(string s) {

        return TrimRight(TrimLeft(s));
    }

    void Trim() {
        _Value = Trim(_Value);
    }
    //-------
    static string Join(vector <string> vString, string delim) {

        string word;

        for (string& T : vString) {
            word += T + delim;
        }
        return word.substr(0, word.length() - delim.length());

    }

    static string Join(string arrString[], short Length, string delim) {

        string word;
        for (short i = 0; i < Length; i++)
        {
            word += arrString[i] + delim;
        }
        return word.substr(0, word.length() - delim.length());

    }

    //-------
    static string RemovePunc(string s) {
        string S2;
        for (short i = 0; i < s.length(); i++)
        {
            if (!ispunct(s[i])) {
                S2 += s[i];
            }
        }
        return S2;
    }

    void RemovePunc() {
        _Value = RemovePunc(_Value);
    }
    //-------
    static string ReverseWords(string s) {

        vector <string>vWords = Split(s, " ");
        vector<string>::iterator iter = vWords.end();
        string rString;

        while (iter != vWords.begin())
        {
            rString += *(--iter) + " ";

        }

        return rString.substr(0, rString.length() - 1);
    }

    void ReverseWords() {
        _Value = ReverseWords(_Value);
    }
    //-------

    static short Length(string s) {
        return s.length();
    }
    short Length() {
        return Length(_Value);
    }
    //-------




    void SetValue(string Value) {

        this->_Value = Value;

    }

    string GetValue() {
        return this->_Value;
    }


    _declspec(property(get = GetValue, put = SetValue))string Value;
};
