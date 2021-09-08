#ifndef SPLIT_H
#define SPLIT_H
#include <string>
#include <iostream>

using namespace std;

class Split{
    private:
        string tiker;
        string data;
        int dividendo;
        int divisor;
    public:

        //Setters
        void setTiker(const string &);
        void setData(const string &);
        void setRatio(const string &);

        //Getters
        const string &getTiker()const;
        const string &getData()const;
        const int &getDividendo()const;
        const int &getDivisor()const;

        //Others
        static int readSplits(const string &, Split *&splits);
};

#endif