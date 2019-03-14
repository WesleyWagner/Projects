#include <iostream>
#include <complex.h>
#include <math.h>
#include <vector>
#include <fstream>

const float amp_a=0.5;//Amplitude sinal a
const float fna=30;//Frequencia sinal a
const float amp_b=0.5;//Amplitude sinal b
const float fnb=1;//Frequencia sinal b
const float M=5000;//Numero de amostras
const float fs=100;//Frequencia de amostragem
const float pi=3.141592;


using namespace std;

int main()
{
    vector<float> xn;
    //complex<float> amostras;

    ofstream myfile;
    myfile.open ("data.txt");
    //float index(M*fs);
    for(unsigned i=0; i < M; i++)
    {
        //complex<float> noise_a(amp_a*cos(i*fna/fs),amp_a*sin(i*fna/fs));?
        //complex<float> noise_b(amp_b*cos(i*fnb/fs),amp_b*sin(i*fnb/fs));?
        float noise_a(amp_a*sin(i*fna/fs));
        float noise_b(amp_b*sin(i*fna/fs));
        float amostra;
        amostra=noise_a+noise_b;
        xn.push_back(amostra);
    }
    unsigned cont(0);
    for (vector<float>::iterator it = xn.begin(); it != xn.end(); ++it)
    {
        //cout << "\nValor : " << *it;
        myfile << "("<<cont<<","<<*it<<")"<<"\n";
        cont++;
    }

    /*complex<float> a(2,1),b(2,-1);
    cout<<endl;
    cout<<"a*b="<<a*b<<endl;
    cout<<"a+b="<<a+b<<endl;
    cout<<"a-b="<<a-b<<endl;
    cout<<"a/b="<<a/b<<endl;*/

    //myfile <<"\nTotal de amostras registradas :"<<cont;
    //myfile <<"\nTotal de amostras M :"<<M;
    myfile.close();
    return 0;
}


