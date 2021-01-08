#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <typeinfo>
#include <list>
#include <unistd.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

class Animal
{
protected:
    float masa;
    float lungime;
    string medViata;
    string sunet;
    string zona;
    string nume;
public:
    Animal()
    {
        masa=0;
        medViata="";
        sunet="";
        nume="";

        lungime=0;

    }
    ~Animal(){
        masa=0;
        medViata="";
        sunet="";
        nume="";

        lungime=0;
    }
    Animal(float L,float M,const string mediu,string num, string sun="")
    {
        lungime=L;
        masa=M;
        medViata=mediu;
        sunet=sun;
        nume=num;
    }
    string returntypeid()
    {
       return typeid(this).name();
    }
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    virtual float returnLung()
    {
        return lungime;
    }

    friend ostream& operator<<(ostream& os, Animal &A);
    friend istream& operator>>(istream& in, Animal &A);
    Animal& operator=(Animal &x)
    {
        if(this!=&x)
        {
            lungime=x.lungime;
            masa=x.masa;
            medViata=x.medViata;
            sunet=x.sunet;
            nume=x.nume;
        }
        else *this;

    }





};
void Animal::citire(istream &in)
{
    cout<<"\n Introdu Masa : ";
    in>>masa;
    cout<<"\n Introdu lungime : ";
    in>>lungime;
    cout<<"\n Introdu Sunetul : ";
    in>>sunet;
    cout<<"\n Introdu mediul de viata : ";
    in>>medViata;
    cout<<"\n Introdu numele : ";
    in>>nume;
}
void Animal::afisare(ostream &os)
{
    os<<"\n Nume : "<<nume;
    os<<"\n Masa: "<<masa;
    os<<"\n Mediu de viata : "<<medViata;
    os<<"\n Sunet : "<<sunet;
    os<<"\n Lungime :"<<lungime;


}
istream& operator>>(istream &in,Animal &A)
{
    A.citire(in);
    return in;


}

ostream& operator<<(ostream& os, Animal &A)
{
    A.afisare(os);
    return os;

}
class Vertebrate:public Animal
{
    bool oase=true;
public:
    Vertebrate():Animal() {};
    Vertebrate(float l,float mas,string medV,string num, string sun=""):Animal(l,mas,medV,num,sun) {};
        string returntypeid()
    {
       return typeid(this).name();
    }
};
class Nevertebrate:public Animal
{
    bool oase=false;
public:
    Nevertebrate():Animal() {};
    Nevertebrate(float l,float mas,const string medV,string num, string sun=""):Animal(l,mas,medV,num,sun) {};
        string returntypeid()
    {
       return typeid(this).name();
    }
};

class Peste:public Vertebrate
{
private:
    string culori;
    string tip;//carnivor,etc
    string favfood;
    float viteza;
    static int count_rap;
public:
    Peste():Vertebrate() {};
    Peste(float l,float v, string cul,string food,string t,float mas,string num,string sun=""):Vertebrate(l,mas,"acvatic",num,sun)
    {
        viteza=v;
        culori=cul;
        favfood=food;
        tip=t;
    }
    ~Peste()
    {
     culori="";
     tip="";//carnivor,etc
     favfood="";
     viteza=0;
     count_rap=0;
    }
    string returntip()
    {
        return "peste";

    }
    float returnLung()
    {
        return Animal::returnLung();
    }
    string getTip()
    {
        return tip;
    }
    void afisare(ostream &os);
    void citire(istream &is);
        string returntypeid()
    {
       return typeid(this).name();
    }
    friend ostream& operator<<(ostream& os, Peste &A);
    friend istream& operator>>(istream& in, Peste &P);
    Peste& operator=(Peste &x)
    {
        if(this!=&x)
        {
            Animal::operator=(x);
            viteza=x.viteza;
            culori=x.culori;
            favfood=x.favfood;
            tip=x.tip;
        }
        else
            return *this;

    }





};
void Peste::afisare(ostream &os)
{
    Animal::afisare(os);
    os<<"\n Culoare predominanta : "<<culori;
    os<<"\n Viteza in apa : "<<viteza;
    os<<"\n Tip : "<<tip;
    os<<"\n Mancare favorita : "<<favfood;

}
void Peste::citire(istream &in)
{
    Animal::citire(in);
    cout<<"\n Culoare predominanta : ";
    in>>culori;
    cout<<"\n Viteza in apa : ";
    in>>viteza;
    cout<<"\n Tip : ";
    in>>tip;
    cout<<"\n Mancare favorita : ";
    in>>favfood;

}
ostream& operator<<(ostream& os, Peste &A)
{
    A.afisare(os);
    return os;

}
istream& operator>>(istream& in, Peste &P)
{
    P.citire(in);
    return in;
}
class Pasare:public Vertebrate
{
private:
    string cularip;
    float viteza;
    float lungarip;
    string favfood;
public:
    Pasare():Vertebrate() {};
    Pasare(float la, float l,float v, string cul,string food,float mas,string num,string sun=""):Vertebrate(l,mas,"aer",num,sun)
    {

        viteza=v;
        lungarip=la;
        cularip=cul;
        favfood=food;
    }
    ~Pasare()
    {

        viteza=0;
        lungarip=0;
        cularip="";
        favfood="";
    }
        string returntypeid()
    {
       return typeid(this).name();
    }
    void afisare(ostream &os);
    void citire(istream &is);

    friend ostream& operator<<(ostream& os, Pasare &A);
    friend istream& operator>>(istream& in, Pasare &P);
    Pasare& operator=(Pasare &x)
    {
        if(this!=&x)
        {
            Animal::operator=(x);
            cularip=x.cularip;
            viteza=x.viteza;
            lungarip=x.lungarip;
            favfood=x.favfood;
        }
        else
            return *this;

    }


};
void Pasare::afisare(ostream &os)
{
    Animal::afisare(os);

}
void Pasare::citire(istream &is)
{
    Animal::citire(is);
    cout<<"\n Introdu viteza in aer : ";
    is>>viteza;
    cout<<"\n Introdu penajul : ";
    is>>cularip;
    cout<<"\n Introdu lungimea aripilor : ";
    is>>lungarip;
    cout<<"\n Introdu mancare favorita : ";
    is>>favfood;

}
ostream& operator<<(ostream& os, Pasare &A)
{
    A.afisare(os);
    return os;

}
istream& operator>>(istream& in, Pasare &P)
{
    P.citire(in);
    return in;

}
class Mamifere:public Vertebrate
{
private:
    string suprafata;//blana,piele etc idk
    string favfood;
    float viteza;
public:

    Mamifere():Vertebrate() {};
    Mamifere(string supr,string fav,float v,float l,float mas,string medV,string num, string sun=""):Vertebrate(l,mas,medV,num,sun)
    {
        suprafata=supr;
        favfood=fav;
        viteza=v;
    }
    ~Mamifere()
    {
        suprafata="";
        favfood="";
        viteza=0;

    }
    void afisare(ostream &os);
    void citire(istream &is);
    string returntypeid()
    {
       return typeid(this).name();
    }
    friend ostream& operator<<(ostream& os, Mamifere &A);
    friend istream& operator>>(istream& in, Mamifere &P);
    Mamifere& operator=(Mamifere &x)
    {
        if(this!=&x)
        {
            Animal::operator=(x);
            suprafata=x.suprafata;
            favfood=x.favfood;
            viteza=x.viteza;

        }
        else
            return *this;
    }
};
void Mamifere::afisare(ostream &os)
{
    Animal::afisare(os);
    os<<"\n La suprafata se poate observa : "<<suprafata;
    os<<"\n Mancarea favorita : "<<favfood;
    os<<"\n Viteza in "<<medViata<<" este de : "<<viteza;
}
ostream& operator<<(ostream& os, Mamifere &A)
{
    A.afisare(os);
    return os;

}
void Mamifere::citire(istream &is)
{
    Animal::citire(is);
    cout<<"\n Introdu cu ce este acoperit : ";
    is>>suprafata;
    cout<<"\n Introdu ce prefera sa manance : ";
    is>>favfood;
    cout<<"\n Introdu cu cat se deplaseaza in "<<medViata<<" : ";
    is>>viteza;
}
istream& operator>>(istream& is, Mamifere &P)
{
    P.citire(is);
    return is;
}
class Reptile:public Vertebrate
{
private:
    float lungimecoada;
    string tiplimba;
    string favfood;
    float viteza;
public:
    Reptile():Vertebrate() {};
    Reptile(float lc, string tl,string fav,float v,float l,float mas,string medV,string num, string sun=""):Vertebrate(l,mas,medV,num,sun)
    {
        lungimecoada=lc;
        tiplimba=tl;
        favfood=fav;
        viteza=v;
    }
    ~Reptile()
    {
         lungimecoada=0;
        tiplimba="";
        favfood="";
        viteza=0;
    }
        string returntypeid()
    {
       return typeid(this).name();
    }
    void afisare(ostream &os);
    void citire(istream &is);

    friend ostream& operator<<(ostream& os, Reptile &A);
    friend istream& operator>>(istream& in, Reptile &P);
    Reptile& operator=(Reptile &x)
    {
        if(this!=&x)
        {
            Animal::operator=(x);
            lungimecoada=x.lungimecoada;
            tiplimba=x.tiplimba;
            favfood=x.favfood;
            viteza=x.viteza;
        }
        else
            return *this;

    }
};
void Reptile::afisare(ostream &os)
{
    Animal::afisare(os);
    os<<"\n Lungime coada : "<<lungimecoada;
    os<<"\n Tip limba : "<<tiplimba;
    os<<"\n Viteza in "<<medViata<<" este de : "<<viteza;

}
ostream& operator<<(ostream& os, Reptile &A)
{
    A.afisare(os);
    return os;
}
void Reptile::citire(istream &is)
{
    Animal::citire(is);
    cout<<"\n Introdu lungimea cozi : ";
    is>>lungimecoada;
    cout<<"\n Introdu tipul de limba : ";
    is>>tiplimba;
    cout<<"\n Introdu mancarea favorita : ";
    is>>favfood;
    cout<<"\n Introdu viteza cu care se misca in : "<<medViata<<" : ";
    is>>viteza;
}
istream& operator>>(istream& is, Reptile &P)
{
    P.citire(is);
    return is;

}
int Peste::count_rap=0;
///----------------------------------------------------
template <class t> class AtlasZoologic
{
    t *v;
    int nr;
public:
    AtlasZoologic(t *p=NULL, int n=0)
    {
        nr=n;
        if (n!=0)
        {
            v=new t[n];
            for(int i=0; i<n; i++)
            {
                v[i]=p[i];
            }
        }
    }
    AtlasZoologic(AtlasZoologic &a)
    {
        nr=a.nr;
        v=new t[nr];
        for(int i=0; i<nr; i++)
        {
            v[i]=a.v[i];
        }
    }
    ~AtlasZoologic()
    {
        delete [] v;
    }
    t get_v(int i)
    {
        return v[i];
    }
    friend istream& operator >>(istream &in, AtlasZoologic <t> &g)
    {
        cout<<"\nIntroduceti numarul de animale : ";
        in>>g.nr;
        g.v=new t[g.nr];
        cout<<"\nIntroduceti animalele: \n";
        for(int i=0; i<g.nr; i++)
        {
            in>>g.v[i];
            cout<<"\n";
        }
        return in;
    }// idk de ce nu merge afara ca in mod normal, am inteles ca e ceva legat de template dar nu mi pot da seama
    ///-fix it later^
    friend ostream& operator <<(ostream &out, AtlasZoologic<t> &g)
    {
        out<<"\n In Atlasul Zoologic se gasesc urmatoarele "<<g.nr<<" animale :"<<"\n";
        for(int i=0; i<g.nr; i++)
            out<<g.v[i]<<"\n";
        return out;
    }
    operator+=(t p)
    {
        int i=nr;
        nr+=1;
        if (nr==1)
            v[0]=p;
        else
        {
            t *aux;
            aux=new t[nr+1];
            for(int i=0; i<nr-1; i++)
                aux[i]=v[i];
            aux[nr-1]=p;
            delete [] v;
            v=new t[nr];
            for(int i=0; i<nr; i++)
            {
                v[i]=aux[i];
            }
            delete [] aux;

        }
    }
};
template <> class AtlasZoologic <Peste>
{
private:
    Peste *v;
    int nr;
    int nr_prunu=0;
public:
    AtlasZoologic(Peste *p=NULL, int n=0)
    {
        nr=n;
        if (n!=0)
        {
            v=new Peste[n];
            for(int i=0; i<n; i++)
            {
                v[i]=p[i];
                if(p[i].getTip()=="rapitor")
                    if(p[i].returnLung()>1)
                        nr_prunu+=1;
            }
        }
    }
    AtlasZoologic(AtlasZoologic &a)
    {
        nr=a.nr;
        nr_prunu=a.nr_prunu;
        v=new Peste[nr];
        for(int i=0; i<nr; i++)
        {
            v[i]=a.v[i];
        }
    }
    ~AtlasZoologic()
    {
        delete [] v;
    }
    Peste get_v(int i)
    {
        return v[i];
    }
    friend istream& operator >>(istream &in, AtlasZoologic <Peste> &g)
    {
        cout<<"\nIntroduceti numarul de animale : ";
        in>>g.nr;
        g.v=new Peste[g.nr];
        cout<<"\nIntroduceti animalele: \n";
        for(int i=0; i<g.nr; i++)
        {
            in>>g.v[i];
            if(g.v[i].getTip()=="rapitor")
                if(g.v[i].returnLung()>1)
                    g.nr_prunu+=1;
            cout<<"\n";
        }
        return in;
    }// idk de ce nu merge afara ca in mod normal, am inteles ca e ceva legat de template dar nu mi pot da seama
    ///-fix it later^
    friend ostream& operator <<(ostream &out, AtlasZoologic<Peste> &g)
    {
        out<<"\n In Atlasul Zoologic Peste se gasesc urm "<<g.nr<<" , din care "<<g.nr_prunu<<" rapitori :"<<"\n";
        for(int i=0; i<g.nr; i++)
            out<<g.v[i]<<"\n";
        return out;
    }
    operator+=(Peste p)
    {
        nr+=1;
        if(p.getTip()=="rapitor")
            if(p.returnLung()>1)
                nr_prunu+=1;
        if(nr==1)
        {
            v=new Peste;
            v[0]=p;

        }
        else if (nr!=0)
        {
            Peste *aux;
            aux=new Peste[nr+1];
            for(int i=0; i<nr-1; i++)
                aux[i]=v[i];
            aux[nr-1]=p;
            delete [] v;
            v=new Peste[nr];
            for(int i=0; i<nr; i++)
            {
                v[i]=aux[i];
            }
            delete [] aux;

        }
    }

};
void tip(Animal *&p, int &i)
{
there:
    string s;
    system("cls");
    cout<<"\n";
    cout<<"\n Tipurile de animale sunt : peste,mamifer,reptila,pasare.";
    cout<<"\n Introduceti tipul de animal "<<i+1<<": ";
    cin>>s;
    int k=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]+32;
        else if(s[i]>='a' && s[i]<='z')
            k=k;
        else
            k++;
    }
    if(k>0)
    {
        cout<<"\nAi introdus un caracter gresit! Apasa ENTER pentru a introduce din nou tipul.";
        getch();
        goto there;

    }

    try
    {
        if(s=="peste")
        {
            p=new Peste;
            cin>>*p;
            i++;
        }
        else if(s=="mamifer")
        {
            p=new Mamifere;
            cin>>*p;
            i++;
        }
        else if(s=="pasare")
        {
            p=new Pasare;
            cin>>*p;
            i++;
        }
        else if(s=="reptila")
        {

            p=new Reptile;
            cin>>*p;
            i++;
        }
        else

            throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"\nNu ati introdus un animal existent. Incercati unul din lista celor de mai sus\n ";
    }
    system("cls");

}
int meniu()
{
    int optiune;
    cout<<"\n O zi buna!\n========================================";
    cout<<"\n Alegeti Varianta de lucru :";
    cout<<"\n 1.List";
    cout<<"\n 2.AtlasZooo";
    cout<<"\n Optiunea este : ";
    cin>>optiune;
    return optiune;


}
int main()
{

//    cout<<P.returntip();
//    Peste P();
//    Animal **v;
//    v=new Animal*[1];
//    //    Peste(float l,float v, string cul,string food,string t,float mas,string sun=""):Vertebrate(l,mas,"acvatic",sun)
//
//    Animal *p=new Peste(11,20,"alb verde","rechini","rapitor",1,"Bitch","suc succ");
//    v[0]=p;
//    cout<<*v[0];
//    Mamifere M;
//    cin>>M;
//
//AtlasZoologic <Peste> A;
//cin>>A;
//cout<<A;
//Peste R(2,2,"Verde Rosu","alge","rapitor",2,"Pestiuc","GLoglop");
//A+=R;
//cout<<A;
//int i=0;
//int n=3;
//list<Animal*> Animale(1);
//    Animal *p=new Peste(11,20,"alb verde","rechini","rapitor",1,"Bitch","suc succ");
//
//for (std::list<Animal*>::iterator it=Animale.begin(); it != Animale.end(); ++it)
//{       //*it=new Peste(11,20,"alb verde","rechini","rapitor",1,"Bitch","suc succ");
//        tip(*it,i);
//        std::cout<<**it;}
    start:
    system("cls");
    int opt=meniu();
    if(opt==1)
    {
        system("cls");
        int n,i=0;
        cout<<"\nIntrodu numarul de elemente : ";
        cin>>n;
        list<Animal*> Animale(n);
        for (std::list<Animal*>::iterator it=Animale.begin(); it != Animale.end(); ++it)
            tip(*it,i);
        cout<<"\n Lista de "<<n<< " elemente este : \n";
        for (std::list<Animal*>::iterator it=Animale.begin(); it != Animale.end(); ++it)
            std::cout<<**it<<"\n";

    }
    else if(opt==2)
    {
        system("cls");
        cout<<"\n Introdu tipul de Atlas : "<<"\n 1.Reptile"<<"\n 2.Peste"<<"\n 3.Mamifere"<<"\n 4.Pasari";
        cout<<"\n Introdu cifra : ";
        cin>>opt;
        if(opt==2)
        {
            int n=0;
            AtlasZoologic <Peste> AP;
            cin>>AP;
            cout<<"\n";
            system("cls");
            cout<<AP;
            cout<<"\n Ai descoperit pesti noi in zona ta ? Introdu cati : ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                Peste Nou;
                cin>>Nou;
                AP+=Nou;

            }
             cout<<"\n";
            system("cls");
            cout<<AP;


        }
        else if(opt==1)
        {
            int n=0;
            AtlasZoologic <Reptile> AR;
            cin>>AR;
            system("cls");
            cout<<"\n";
            cout<<AR;
            cout<<"\n Ai descoperit reptile noi in zona ta ? Introdu cate(0 pentru nimic) : ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                Reptile Nou;
                cin>>Nou;
                AR+=Nou;

            }
            system("cls");
            cout<<AR;


        }
        else if(opt==3)
        {
            int n=0;
            AtlasZoologic <Mamifere> AM;
            cin>>AM;
            system("cls");
            cout<<"\n";
            cout<<AM;
            cout<<"\n Ai descoperit mamifere noi in zona ta ? Introdu cate(0 pentru nimic)  : ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                Mamifere Nou;
                cin>>Nou;
                AM+=Nou;

            }
            system("cls");
            cout<<AM;


        }
        else if(opt==4)
        {
            int n=0;
            AtlasZoologic <Pasare> Apas;
            cin>>Apas;
            system("cls");
            cout<<"\n";
            cout<<Apas;
            cout<<"\n Ai descoperit mamifere noi in zona ta ? Introdu cate(0 pentru nimic)  : ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                Pasare Nou;
                cin>>Nou;
                Apas+=Nou;

            }
            system("cls");
            cout<<Apas;


        }
    }
    cout<<"\n\n Ce vrei sa facem in continuarea? Continuam ? 1/0 : ";cin>>opt;
    if(opt==1)
        goto start;
        else
            cout<<"\n O zi buna! ";
    return 0;
}
