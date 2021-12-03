#ifndef __BASELIB_H__
#define __BASELIB_H__
/*
Lib name: Infomation Theory base lib
Author: Lan Botian
Description: Create a information source model and define some basic computational methods for source.
Date: 2021-10-31
Version: v-1.0
*/
#include <iostream>
#include <cmath>
using namespace std;

/*
    Basically speaking, information source have two different types. First, discrete source. Second, countinuous 
    information source. For discrete source, it could be separated more deeply, discrete memory source and discrete 
    memoryless source. For continuous source, it could also be separated into two additional parts, continuous 
    memory source and continuous memoryless souce.
    InfoLib will create four different class for every each one of them because of their different arttibutes. 
    Specifically, for discrete memory source, create a markov source because that is witch i've only learned in 
    information theory course.
*/


/*
    For short and considering in a more easy way, I named four types of information sourse as follows:
    Discrete memoryless source: Dis_MemlessSrc
    Discrete memory source: Dis_MemSrc
    Continuous memoryless source: Con_MemlessSrc
    Continuous memory source: Con_MemSrc
*/

void Heapify(int arr[], int index, int heapsize);
void HeapInsert(int arr[], int index);
void HeapSort(int arr[], int index, int heapsize);


class Dis_MemlessSrc{
    public:
    static const unsigned int m = 2;   // log under number
    float* m_prob;

    Dis_MemlessSrc(string name, bool single, unsigned int size, float prob[]);
    void Print();
    float get_SrcEntropy();
    float get_SrcSelfInfo(int loc);   // locate


    private:

    string m_name;
    bool m_single;         
    //if m_single is true, this source has only one symbol, if it is false, this source has muti symbols
    unsigned int m_symbnum; 
    //if m_single is ture, it is 1, if it is false, it is n wicth could be defined by user.
    unsigned int m_size;
    float m_SelfInfo;
    float m_SrcEntropy;

};






#endif
