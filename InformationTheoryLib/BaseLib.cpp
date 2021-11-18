/*
Lib name: Infomation Theory base lib
Author: Lan Botian
Description: Create a information source model and define some basic computational methods for source.
Date: 2021-10-31
Version: v-1.0
*/
#include "BaseLib.hpp"

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

/* 
   THIS FILE
   This file's format is cpp, which means it could store the fundemental mechanism of code. For readability, I 
   put all of the definitions of class or something into a file called BaseLib.hpp. And in this file, it mainly
   solve the technical methods and store the 'brain and blood' of my code.
   So, for more details of architecture, see file "BaseLib.hpp".

*/

/*
    Function name: Completeness Check
    Para: int prob[] - stands for the probability of source
          int len - stands for the length of array
    Description: To check if the array fuffill completeness of 1
                 if it is, return true
                 if it is not, return false
*/
bool CompletenessCheck(float prob[], unsigned int len){
    int i =0;
    float sum =0;
    for(i=0;i<len;i++){
        sum += prob[i];
    }
    if(sum == 1){
        return true;
    }
    //cout << "Error: Can't fullfill the completeness!" << endl;
    throw " probability space can't fullfill the completeness!";
    return false;
}

/*
    Function name: Cal_SelfInfo
    Para: float prob
    Description: Calculate one symbol self information
    return: I, self informationß
*/
float Cal_SelfInfo(float prob,unsigned int m){
    return -log(prob)/log(m);
}

/*
    Function name: Cal_SrcEntropy
    Para: int prob[] - stands for the probability of source
          int len - stands for the length of array
    Description: calculate source entropy
    return:entropy
*/
float Cal_SrcEntropy(float prob[], unsigned int len, unsigned int m){ 
    float entropy=0;
    int i = 0;
    for(i = 0; i<len;i++){
        entropy += prob[i]*Cal_SelfInfo(prob[i],m);
    }
    return entropy;
}


//Constructor
Dis_MemlessSrc::Dis_MemlessSrc(string name, bool single, unsigned int size, float prob[])
{
    /* Check the completeness of probability array*/
    /*if(CompletenessCheck(prob, size) == true){
        m_prob = prob;
    }
    else{
        cout << "Error!" <<endl;
    }*/
    try
    {
        CompletenessCheck(prob, size);
        m_prob = prob;
    }
    catch(const char* error)
    {
        cout << name << error << endl;
        exit(0);
    }


    //Data Initialize.
    m_name = name;
    m_single = single;
    m_size = size;
    if(m_single == true){
        m_symbnum = 1;
    }
    else if(m_single == false){
        unsigned int n;
        cout << "Please input symbols' num:" << endl;
        cin >> n;
        m_symbnum = n;
    }
    m_SrcEntropy = Cal_SrcEntropy(prob,size,m);
}

/*
    Function name: Print
    Para: Null
    Description: Print basic information of source
*/
void Dis_MemlessSrc::Print(){
    cout << endl;
    cout << "Discrete Memmoryless Src" << endl;
    cout << "--------------------------------------" << endl;
    cout << "           Name          |" << "    " << m_name << endl;
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    cout << "      Single or not      |" << "      " << m_single << endl;
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    cout << "        Symbol num       |" << "      " << m_symbnum << endl;
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Source Probability Size |" << "      " << m_size << endl;
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    cout << "      Source Entropy     |" << "      " << m_SrcEntropy << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
}

/*
    Function name: get_SrcEntropy
    Para: Null
    Description: get entropy of source
    return: m_SrcEntropy
*/
float Dis_MemlessSrc::get_SrcEntropy(){
    return Dis_MemlessSrc::m_SrcEntropy;
}

/*
    Function name: get_SrcSelfInfo
    Para: int loc   stands for location
    Description: get selfInfo in a specific position
    return: self information
*/
float Dis_MemlessSrc::get_SrcSelfInfo(int loc){
    return Cal_SelfInfo(m_prob[loc - 1],m);
}
