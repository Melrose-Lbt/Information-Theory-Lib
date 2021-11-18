#include "BaseLib.hpp"


int main(){
    float srcprob[5] = {0.1,0.3,0.2,0.25,0.15};
    float srcprob2[3] = {0.5,0.25, 0.25};
    Dis_MemlessSrc Src("MySrc",true,(unsigned int)5,srcprob);
    Dis_MemlessSrc Src2("YourSrc",true,(unsigned int)3, srcprob2);
    Src.Print();
    Src2.Print();
    cout << Src.get_SrcEntropy()<< endl;
    cout << Src2.get_SrcSelfInfo(2) << endl;
    cout << Src.m_prob << endl;
}