#include "main.h";

class StudentuDuomenys
{
    string studentoVardas, studentoPavarde;
    int namuDarbuSk, namuDarbuRez, egzaminoRez;
    double galutPazymys;
    vector <double> skaicius;

public:
    //konstruktorius be parametrų
    StudentuDuomenys()
    {
    };

   //konstruktorius su parametrais
    StudentuDuomenys(string studVa, string studPa, int ndSk, int ndRez, int egRez, double gaPaz)
    {
            studentoVardas = studVa;
            studentoPavarde = studPa;
            namuDarbuSk = ndSk;
            namuDarbuRez = ndRez;
            egzaminoRez = egRez;
    }

    //kopijavimo konstruktorius
    StudentuDuomenys(StudentuDuomenys &kopija)
    {
            studentoVardas = kopija.studentoVardas;
            studentoPavarde = kopija.studentoPavarde;
            namuDarbuSk = kopija.namuDarbuSk;
            namuDarbuRez = kopija.namuDarbuRez;
            egzaminoRez = kopija.egzaminoRez;
    }
    /* //destruktorius
     ~StudentuDuomenys(); */

    void ivestiDuomenis(string, string, int, int, int);
    void spausdinti();
    void spausdintiGalutPagalVidurki();
    void spausdintiGalutPagalMediana();
};

void StudentuDuomenys::ivestiDuomenis(string studVa, string studPa, int ndSk, int ndRez, int egRez)
{
            studentoVardas = studVa;
            studentoPavarde = studPa;
            namuDarbuSk = ndSk;
            namuDarbuRez = ndRez;
            egzaminoRez = egRez;
}

void StudentuDuomenys::spausdintiGalutPagalVidurki()
{
    double vidurkis = ((double)namuDarbuRez + (double)egzaminoRez)/(double)namuDarbuSk;
    double galutPazymys = 0.4 * vidurkis + 0.6 * egzaminoRez;
    cout << "Vardas    " << "Pavarde    "<<"Galutinis pazymys pagal vidurki "<<endl;
    cout <<"------------------------------------------------"<<endl;
    cout << studentoVardas<< "   " <<studentoPavarde<<"   " <<setprecision(3)<<galutPazymys<<endl;
}

 void StudentuDuomenys::spausdintiGalutPagalMediana()
{
double mediana;

    sort(skaicius.begin(), skaicius.end());

    for (int i = 0; i < skaicius.size(); ++i)
    {
    if (skaicius.size() % 2)
   {
       mediana = skaicius[skaicius.size() / 2];
   }
    else
{
    mediana = (skaicius[skaicius.size() / 2] + skaicius[skaicius.size() / 2 - 1]) / 2;
}
    }

    double galutPazymys = 0.4 * mediana + 0.6 * egzaminoRez;
    cout << "Vardas    " << "Pavarde    "<<"Galutinis pazymys pagal mediana "<<endl;
    cout <<"------------------------------------------------"<<endl;
    cout << studentoVardas<< "   " <<studentoPavarde<<"   " <<setprecision(3)<<galutPazymys<<endl;
}

int main()
{
    cout << "START" << endl;
    StudentuDuomenys sd;
    sd.ivestiDuomenis("Jonas", "Jonaitis", 3, 10, 9);
    sd.spausdintiGalutPagalVidurki();
     sd.spausdintiGalutPagalMediana();

    sd.ivestiDuomenis("Petras", "Petraitis", 3, 8, 8);
    sd.spausdintiGalutPagalVidurki();
    sd.spausdintiGalutPagalMediana();

    sd.ivestiDuomenis("Pranas", "Pranaitis", 3, 9, 10);
    sd.spausdintiGalutPagalVidurki();
    sd.spausdintiGalutPagalMediana();
    cout << "END" << endl;
}
