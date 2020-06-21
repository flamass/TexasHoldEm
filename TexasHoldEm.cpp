// Felipe Lamas Silva
// Ingeniería Civil en Telecomunicaciones
// Universidad de Concepción

#include <iostream>     // cout.
#include <fstream>      // ifstream.
#include <vector>       // vector.
#include <algorithm>    // sort.
#include <string>       // string.
#include <utility>      // pair, tuple.
#include <iomanip>      // setw.

using namespace std;

class Carta
{
    friend istream& operator>>(istream&, Carta&);
public:
    // Funciones de acceso.
    char n() const
    {
        return numero;
    }
    char p() const
    {
        return pinta;
    }
    // Constructor vacio.
    Carta(){}
    // Constructor con argumentos.
    Carta(char n, char p)
    {
        numero = n;
        pinta = p;
    }
private:
    char numero;
    char pinta;
};

class CartasEnMano: public Carta
{
    friend istream& operator>>(istream&, CartasEnMano&);
public:
    // Funciones de acceso.
    Carta c1() const
    {
        return carta1;
    }
    Carta c2() const
    {
        return carta2;
    }
    // Constructor vacio.
    CartasEnMano(){}
    // Constructor con argumentos.
    CartasEnMano(Carta c1, Carta c2)
    {
        carta1 = c1;
        carta2 = c2;
    }
private:
    Carta carta1, carta2;
};

class Mano: public Carta
{
    friend istream& operator>>(istream&, Mano&);
public:
    // Funciones de acceso.
    Carta c1() const
    {
        return carta1;
    }
    Carta c2() const
    {
        return carta2;
    }
    Carta c3() const
    {
        return carta3;
    }
    Carta c4() const
    {
        return carta4;
    }
    Carta c5() const
    {
        return carta5;
    }
    // Constructor vacio.
    Mano(){}
    // Constructor con argumentos.
    Mano(Carta c1, Carta c2, Carta c3, Carta c4, Carta c5)
    {
        carta1 = c1;
        carta2 = c2;
        carta3 = c3;
        carta4 = c4;
        carta5 = c5;
    }
private:
    Carta carta1, carta2, carta3, carta4, carta5;
};

istream& operator>>(istream& in, Carta& c)
{
    return in >> c.numero >> c.pinta;
}

istream& operator>>(istream& in, CartasEnMano& cem)
{
    return in >> cem.carta1 >> cem.carta2;
}

istream& operator>>(istream& in, Mano& m)
{
    return in >> m.carta1 >> m.carta2 >> m.carta3 >> m.carta4 >> m.carta5;
}

ostream& operator<<(ostream& out, const Carta& c)
{
    return out << c.n() << c.p();
}

ostream& operator<<(ostream& out, const CartasEnMano& cem)
{
    return out << cem.c1() << ' ' << cem.c2() << ' ';
}

ostream& operator<<(ostream& out, const Mano& m)
{
    return out << m.c1() << ' ' << m.c2() << ' ' << m.c3() << ' ' << m.c4() << ' ' << m.c5() << ' ';
}

bool operator==(const Carta& c1, const Carta& c2)
{
    return c1.n() == c2.n() && c1.p() == c2.p();
}

bool operator!=(const Carta& c1, const Carta& c2)
{
    return !(c1 == c2);
}

bool operator<(const Carta& c1, const Carta& c2)
{
    unsigned int n1, n2;
    if(c1.n() == '0')
    {
        n1 = 10;
    }
    else if(c1.n() == 'J')
    {
        n1 = 11;
    }
    else if(c1.n() == 'Q')
    {
        n1 = 12;
    }
    else if(c1.n() == 'K')
    {
        n1 = 13;
    }
    else if(c1.n() == 'A')
    {
        n1 = 14;
    }
    else
    {
        n1 = c1.n() - 48;
    }

    if(c2.n() == '0')
    {
        n2 = 10;
    }
    else if(c2.n() == 'J')
    {
        n2 = 11;
    }
    else if(c2.n() == 'Q')
    {
        n2 = 12;
    }
    else if(c2.n() == 'K')
    {
        n2 = 13;
    }
    else if(c2.n() == 'A')
    {
        n2 = 14;
    }
    else
    {
        n2 = c2.n() - 48;
    }

    return n1 < n2;
}

bool operator>(const Carta& c1, const Carta& c2)
{
    unsigned int n1, n2;
    if(c1.n() == '0')
    {
        n1 = 10;
    }
    else if(c1.n() == 'J')
    {
        n1 = 11;
    }
    else if(c1.n() == 'Q')
    {
        n1 = 12;
    }
    else if(c1.n() == 'K')
    {
        n1 = 13;
    }
    else if(c1.n() == 'A')
    {
        n1 = 14;
    }
    else
    {
        n1 = c1.n() - 48;
    }

    if(c2.n() == '0')
    {
        n2 = 10;
    }
    else if(c2.n() == 'J')
    {
        n2 = 11;
    }
    else if(c2.n() == 'Q')
    {
        n2 = 12;
    }
    else if(c2.n() == 'K')
    {
        n2 = 13;
    }
    else if(c2.n() == 'A')
    {
        n2 = 14;
    }
    else
    {
        n2 = c2.n() - 48;
    }

    return n1 > n2;
}

bool operator<=(const Carta& c1, const Carta& c2)
{
    return c1 < c2 || c1 == c2;
}

bool operator>=(const Carta& c1, const Carta& c2)
{
    return c1 > c2 || c1 == c2;
}

bool compara(const Carta& c1, const Carta& c2)
{
    return c1 < c2;
}

unsigned int convertidorNumeroCartaInt(char nChar)
{
    unsigned int nRet;
    if(nChar == '0')
    {
        nRet = 10;
    }
    else if(nChar == 'J')
    {
        nRet = 11;
    }
    else if(nChar == 'Q')
    {
        nRet = 12;
    }
    else if(nChar == 'K')
    {
        nRet = 13;
    }
    else if(nChar == 'A')
    {
        nRet = 14;
    }
    else
    {
        nRet = nChar - 48;
    }

    return nRet;
}

vector<Carta> escaleraReal(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVec;
    mVec.push_back(cem.c1());
    mVec.push_back(cem.c2());
    mVec.push_back(cc.c1());
    mVec.push_back(cc.c2());
    mVec.push_back(cc.c3());
    mVec.push_back(cc.c4());
    mVec.push_back(cc.c5());

    sort(mVec.begin(), mVec.end(), compara);

    if((mVec.at(2).n() == '0' && mVec.at(3).n() == 'J' && mVec.at(4).n() == 'Q' && mVec.at(5).n() == 'K'
        && mVec.at(6).n() == 'A') && (mVec.at(2).p() == mVec.at(3).p() && mVec.at(3).p() == mVec.at(4).p()
        && mVec.at(4).p() == mVec.at(5).p()))
    {
        mVec.erase(mVec.begin(), mVec.begin() + 2);
    }
    else
    {
        mVec.clear();
    }
    return mVec;
}

vector<Carta> escaleraDeColor(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVec;
    mVec.push_back(cem.c1());
    mVec.push_back(cem.c2());
    mVec.push_back(cc.c1());
    mVec.push_back(cc.c2());
    mVec.push_back(cc.c3());
    mVec.push_back(cc.c4());
    mVec.push_back(cc.c5());

    sort(mVec.begin(), mVec.end(), compara);
    reverse(mVec.begin(), mVec.end());

    vector<Carta> cartasDeCorazon, cartasDeDiamante, cartasDePica, cartasDeTrebol;

    for(vector<Carta>::iterator iter = mVec.begin(); iter != mVec.end(); ++iter)
    {
        if((*iter).p() == 'C')
        {
            cartasDeCorazon.push_back(*iter);
        }
        else if((*iter).p() == 'D')
        {
            cartasDeDiamante.push_back(*iter);
        }
        else if((*iter).p() == 'P')
        {
            cartasDePica.push_back(*iter);
        }
        else
        {
            cartasDeTrebol.push_back(*iter);
        }
    }
    mVec.clear();

    vector<vector<Carta> > cartas;
    cartas.push_back(cartasDeCorazon);
    cartas.push_back(cartasDeDiamante);
    cartas.push_back(cartasDePica);
    cartas.push_back(cartasDeTrebol);

    for(vector<vector<Carta> >::iterator iter1 = cartas.begin(); iter1 != cartas.end(); ++iter1)
    {
        if((*iter1).size() >= 5)
        {
            unsigned int verificador = convertidorNumeroCartaInt((*((*iter1).begin())).n()) - 1;
            mVec.push_back(*((*iter1).begin()));
            for(vector<Carta>::iterator iter2 = (*iter1).begin() + 1; iter2 != (*iter1).end(); ++iter2)
            {
                if(mVec.size() != 5)
                {
                    if(convertidorNumeroCartaInt((*iter2).n()) == verificador)
                    {
                        mVec.push_back(*iter2);
                        --verificador;
                    }
                    else
                    {
                        mVec.clear();
                        mVec.push_back(*iter2);
                        verificador = convertidorNumeroCartaInt((*iter2).n()) - 1;
                    }
                }
            }
            if(mVec.size() == 4 && (mVec.at(0)).n() == '5' && (mVec.at(1)).n() == '4' && (mVec.at(2)).n() == '3'
               && (mVec.at(3)).n() == '2')
            {
                for(vector<Carta>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
                {
                    if((*iter2).n() == 'A')
                    {
                        mVec.push_back(*iter2);
                        reverse(mVec.begin(), mVec.end());
                    }
                }
            }
        }
    }
    if(mVec.size() != 5)
    {
        mVec.clear();
    }
    return mVec;
}

vector<Carta> poker(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVec;
    mVec.push_back(cem.c1());
    mVec.push_back(cem.c2());
    mVec.push_back(cc.c1());
    mVec.push_back(cc.c2());
    mVec.push_back(cc.c3());
    mVec.push_back(cc.c4());
    mVec.push_back(cc.c5());

    sort(mVec.begin(), mVec.end(), compara);

    if(mVec.at(0).n() == mVec.at(1).n() && mVec.at(1).n() == mVec.at(2).n() && mVec.at(2).n() == mVec.at(3).n())
    {
        mVec.erase(mVec.begin() + 4, mVec.end() - 1);
    }
    else if(mVec.at(1).n() == mVec.at(2).n() && mVec.at(2).n() == mVec.at(3).n() && mVec.at(3).n() == mVec.at(4).n())
    {
        mVec.erase(mVec.begin(), mVec.begin() + 1);
        mVec.erase(mVec.begin() + 4, mVec.end() - 1);
    }
    else if(mVec.at(2).n() == mVec.at(3).n() && mVec.at(3).n() == mVec.at(4).n() && mVec.at(4).n() == mVec.at(5).n())
    {
        mVec.erase(mVec.begin(), mVec.begin() + 2);
    }
    else if(mVec.at(3).n() == mVec.at(4).n() && mVec.at(4).n() == mVec.at(5).n() && mVec.at(5).n() == mVec.at(6).n())
    {
        mVec.erase(mVec.begin(), mVec.begin() + 2);
    }
    else
    {
        mVec.clear();
    }
    return mVec;
}

vector<Carta> full(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVec;
    mVec.push_back(cem.c1());
    mVec.push_back(cem.c2());
    mVec.push_back(cc.c1());
    mVec.push_back(cc.c2());
    mVec.push_back(cc.c3());
    mVec.push_back(cc.c4());
    mVec.push_back(cc.c5());

    sort(mVec.begin(), mVec.end(), compara);

    vector<Carta> mVecAux;

    for(vector<Carta>::reverse_iterator riter = mVec.rbegin(); riter != mVec.rend(); ++riter)
    {
        if(mVecAux.size() != 5)
        {
            if((*riter).n() == (*(riter + 1)).n() && (*(riter + 1)).n() == (*(riter + 2)).n())
            {
                if(mVecAux.size() == 3)
                {
                    mVecAux.push_back(*riter);
                    mVecAux.push_back(*(riter + 1));
                    riter += 2;
                }
                else
                {
                    mVecAux.push_back(*riter);
                    mVecAux.push_back(*(riter + 1));
                    mVecAux.push_back(*(riter + 2));
                    riter += 2;
                }
            }
            else if((*riter).n() == (*(riter + 1)).n())
            {
                mVecAux.push_back(*riter);
                mVecAux.push_back(*(riter + 1));
                ++riter;
            }
        }
    }
    if(mVecAux.size() == 5)
    {
        mVec = mVecAux;
        mVecAux.clear();
        reverse(mVec.begin(), mVec.end());
    }
    else
    {
        mVec.clear();
        mVecAux.clear();
    }
    return mVec;
}

vector<Carta> color(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVec;
    mVec.push_back(cem.c1());
    mVec.push_back(cem.c2());
    mVec.push_back(cc.c1());
    mVec.push_back(cc.c2());
    mVec.push_back(cc.c3());
    mVec.push_back(cc.c4());
    mVec.push_back(cc.c5());

    sort(mVec.begin(), mVec.end(), compara);

    vector<Carta> cartasDeCorazones, cartasDeDiamantes, cartasDePicas, cartasDeTreboles;

    for(vector<Carta>::reverse_iterator riter = mVec.rbegin(); riter != mVec.rend(); ++riter)
    {
        if((*riter).p() == 'C' && cartasDeCorazones.size() != 5)
        {
            cartasDeCorazones.push_back(*riter);
        }
        else if((*riter).p() == 'D' && cartasDeDiamantes.size() != 5)
        {
            cartasDeDiamantes.push_back(*riter);
        }
        else if((*riter).p() == 'P' && cartasDePicas.size() != 5)
        {
            cartasDePicas.push_back(*riter);
        }
        else if((*riter).p() == 'T' && cartasDeTreboles.size() != 5)
        {
            cartasDeTreboles.push_back(*riter);
        }
    }

    vector<vector<Carta> > cartas;
    cartas.push_back(cartasDeCorazones);
    cartas.push_back(cartasDeDiamantes);
    cartas.push_back(cartasDePicas);
    cartas.push_back(cartasDeTreboles);

    for(vector<vector<Carta> >::iterator iter = cartas.begin(); iter != cartas.end(); ++iter)
    {
        if((*iter).size() == 5)
        {
            mVec = *iter;
        }
    }
    cartas.clear();
    cartasDeCorazones.clear();
    cartasDeDiamantes.clear();
    cartasDePicas.clear();
    cartasDeTreboles.clear();

    if(mVec.size() != 5)
    {
        mVec.clear();
    }
    else
    {
        reverse(mVec.begin(), mVec.end());
    }
    return mVec;
}

bool comparaUnique(const Carta& c1, const Carta& c2)
{
    return c1.n() == c2.n();
}

vector<Carta> escalera(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVecAux;
    mVecAux.push_back(cem.c1());
    mVecAux.push_back(cem.c2());
    mVecAux.push_back(cc.c1());
    mVecAux.push_back(cc.c2());
    mVecAux.push_back(cc.c3());
    mVecAux.push_back(cc.c4());
    mVecAux.push_back(cc.c5());

    sort(mVecAux.begin(), mVecAux.end(), compara);
    auto iterU = unique(mVecAux.begin(), mVecAux.end(), comparaUnique);
    mVecAux.resize(iterU - mVecAux.begin());
    reverse(mVecAux.begin(), mVecAux.end());

    vector<Carta> mVec;

    if(mVecAux.size() >= 5)
    {
        unsigned int verificador = convertidorNumeroCartaInt(mVecAux.at(0).n()) - 1;
        mVec.push_back(mVecAux.at(0));

        for(vector<Carta>::iterator iter = mVecAux.begin() + 1; iter != mVecAux.end(); ++iter)
        {
            if(mVec.size() != 5)
            {
                if(convertidorNumeroCartaInt((*iter).n()) == verificador)
                {
                    mVec.push_back(*iter);
                    --verificador;
                }
                else
                {
                    mVec.clear();
                    mVec.push_back(*iter);
                    verificador = convertidorNumeroCartaInt((*iter).n()) - 1;
                }
            }
        }
        if(mVec.size() == 4 && mVec.at(0).n() == '5' && mVec.at(1).n() == '4' && mVec.at(2).n() == '3'
           && mVec.at(3).n() == '2')
        {
            for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.end(); ++iter)
            {
                if((*iter).n() == 'A')
                {
                    mVec.push_back(*iter);
                    reverse(mVec.begin(), mVec.end());
                }
            }
        }
    }
    mVecAux.clear();

    if(mVec.size() != 5)
    {
        mVec.clear();
    }

    return mVec;
}

vector<Carta> trio(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVecAux;
    mVecAux.push_back(cem.c1());
    mVecAux.push_back(cem.c2());
    mVecAux.push_back(cc.c1());
    mVecAux.push_back(cc.c2());
    mVecAux.push_back(cc.c3());
    mVecAux.push_back(cc.c4());
    mVecAux.push_back(cc.c5());

    sort(mVecAux.begin(), mVecAux.end(), compara);
    reverse(mVecAux.begin(), mVecAux.end());

    vector<Carta> mVec;

    if((mVecAux.at(0).n() == mVecAux.at(1).n() && mVecAux.at(1).n() == mVecAux.at(2).n())
       || (mVecAux.at(1).n() == mVecAux.at(2).n() && mVecAux.at(2).n() == mVecAux.at(3).n())
       || (mVecAux.at(2).n() == mVecAux.at(3).n() && mVecAux.at(3).n() == mVecAux.at(4).n()))
    {
        for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.begin() + 5; ++iter)
        {
            mVec.push_back(*iter);
        }
    }
    else if((mVecAux.at(3).n() == mVecAux.at(4).n() && mVecAux.at(4).n() == mVecAux.at(5).n())
       || (mVecAux.at(4).n() == mVecAux.at(5).n() && mVecAux.at(5).n() == mVecAux.at(6).n()))
    {
        for(vector<Carta>::iterator iter = mVecAux.begin() + 2; iter != mVecAux.end(); ++iter)
        {
            mVec.push_back(*iter);
        }
    }
    mVecAux.clear();
    return mVec;
}

vector<Carta> dosPares(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVecAux;
    mVecAux.push_back(cem.c1());
    mVecAux.push_back(cem.c2());
    mVecAux.push_back(cc.c1());
    mVecAux.push_back(cc.c2());
    mVecAux.push_back(cc.c3());
    mVecAux.push_back(cc.c4());
    mVecAux.push_back(cc.c5());

    sort(mVecAux.begin(), mVecAux.end(), compara);
    reverse(mVecAux.begin(), mVecAux.end());

    vector<Carta> mVec;

    for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.end(); ++iter)
    {
        if((*iter).n() == (*(iter + 1)).n())
        {
            mVec.push_back(*iter);
            mVec.push_back(*(iter + 1));
            ++iter;
        }
    }
    if(mVec.size() == 4)
    {
        for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.end(); ++iter)
        {
            if((*iter).n() != mVec.at(0).n() && (*iter).n() != mVec.at(2).n())
            {
                mVec.push_back(*iter);
                break;
            }
        }
        sort(mVec.begin(), mVec.end(), compara);
    }
    else
    {
        mVec.clear();
    }
    return mVec;
}

vector<Carta> unPar(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVecAux;
    mVecAux.push_back(cem.c1());
    mVecAux.push_back(cem.c2());
    mVecAux.push_back(cc.c1());
    mVecAux.push_back(cc.c2());
    mVecAux.push_back(cc.c3());
    mVecAux.push_back(cc.c4());
    mVecAux.push_back(cc.c5());

    sort(mVecAux.begin(), mVecAux.end(), compara);
    reverse(mVecAux.begin(), mVecAux.end());

    vector<Carta> mVec;

    for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.end(); ++iter)
    {
        if((*iter).n() == (*(iter + 1)).n())
        {
            mVec.push_back(*iter);
            mVec.push_back(*(iter + 1));
            break;
        }
    }
    if(mVec.size() == 2)
    {
        for(vector<Carta>::iterator iter = mVecAux.begin(); iter != mVecAux.end(); ++iter)
        {
            if((*iter).n() != mVec.at(0).n())
            {
                mVec.push_back(*iter);
                if(mVec.size() == 5)
                {
                    break;
                }
            }
        }
        sort(mVec.begin(), mVec.end(), compara);
    }
    else
    {
        mVec.clear();
    }
    return mVec;
}

Mano cartaAlta(const CartasEnMano& cem, const Mano& cc)
{
    vector<Carta> mVecAux;
    mVecAux.push_back(cem.c1());
    mVecAux.push_back(cem.c2());
    mVecAux.push_back(cc.c1());
    mVecAux.push_back(cc.c2());
    mVecAux.push_back(cc.c3());
    mVecAux.push_back(cc.c4());
    mVecAux.push_back(cc.c5());

    sort(mVecAux.begin(), mVecAux.end(), compara);

    Mano m(mVecAux.at(2), mVecAux.at(3), mVecAux.at(4), mVecAux.at(5), mVecAux.at(6));

    return m;
}

Mano manoVectorAMano(const vector<Carta>& mVec)
{
    Mano m(mVec.at(0), mVec.at(1), mVec.at(2), mVec.at(3), mVec.at(4));
    return m;
}

int main()
{
    CartasEnMano J1, J2;
    Mano CC;

    ifstream entrada("poker.txt");

    string figuraJugador1, figuraJugador2;
    string ganador;
    vector<tuple<string, string, string> > partidas;
    vector<pair<Mano, Mano> > manos;

    Mano manoJ1, manoJ2;

    unsigned int puntajeJugador1, puntajeJugador2;

    for(int i = 1; i <= 1000; ++i)
    {
        entrada >> J1 >> J2 >> CC;
        entrada.ignore(4);

        // Jugador 1.
        if(escaleraReal(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(escaleraReal(J1, CC));
            puntajeJugador1 = 10;
            figuraJugador1 = "Escalera Real";
        }
        else if(escaleraDeColor(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(escaleraDeColor(J1, CC));
            puntajeJugador1 = 9;
            figuraJugador1 = "Escalera de Color";
        }
        else if(poker(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(poker(J1, CC));
            puntajeJugador1 = 8;
            figuraJugador1 = "Póker";
        }
        else if(full(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(full(J1, CC));
            puntajeJugador1 = 7;
            figuraJugador1 = "Full";
        }
        else if(color(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(color(J1, CC));
            puntajeJugador1 = 6;
            figuraJugador1 = "Color";
        }
        else if(escalera(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(escalera(J1, CC));
            puntajeJugador1 = 5;
            figuraJugador1 = "Escalera";
        }
        else if(trio(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(trio(J1, CC));
            puntajeJugador1 = 4;
            figuraJugador1 = "Trío";
        }
        else if(dosPares(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(dosPares(J1, CC));
            puntajeJugador1 = 3;
            figuraJugador1 = "Dos Pares";
        }
        else if(unPar(J1, CC).size())
        {
            manoJ1 = manoVectorAMano(unPar(J1, CC));
            puntajeJugador1 = 2;
            figuraJugador1 = "Un Par";
        }
        else
        {
            manoJ1 = cartaAlta(J1, CC);
            puntajeJugador1 = 1;
            figuraJugador1 = "Carta Alta";
        }

        // Jugador 2.
        if(escaleraReal(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(escaleraReal(J2, CC));
            puntajeJugador2 = 10;
            figuraJugador2 = "Escalera Real";
        }
        else if(escaleraDeColor(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(escaleraDeColor(J2, CC));
            puntajeJugador2 = 9;
            figuraJugador2 = "Escalera de Color";
        }
        else if(poker(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(poker(J2, CC));
            puntajeJugador2 = 8;
            figuraJugador2 = "Póker";
        }
        else if(full(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(full(J2, CC));
            puntajeJugador2 = 7;
            figuraJugador2 = "Full";
        }
        else if(color(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(color(J2, CC));
            puntajeJugador2 = 6;
            figuraJugador2 = "Color";
        }
        else if(escalera(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(escalera(J2, CC));
            puntajeJugador2 = 5;
            figuraJugador2 = "Escalera";
        }
        else if(trio(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(trio(J2, CC));
            puntajeJugador2 = 4;
            figuraJugador2 = "Trío";
        }
        else if(dosPares(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(dosPares(J2, CC));
            puntajeJugador2 = 3;
            figuraJugador2 = "Dos Pares";
        }
        else if(unPar(J2, CC).size())
        {
            manoJ2 = manoVectorAMano(unPar(J2, CC));
            puntajeJugador2 = 2;
            figuraJugador2 = "Un Par";
        }
        else
        {
            manoJ2 = cartaAlta(J2, CC);
            puntajeJugador2 = 1;
            figuraJugador2 = "Carta Alta";
        }

        manos.push_back(make_pair(manoJ1, manoJ2));

        // Decidiendo ganadores.
        if(puntajeJugador1 > puntajeJugador2)
        {
            ganador = "Gana Jugador 1";
        }
        else if(puntajeJugador1 < puntajeJugador2)
        {
            ganador = "Gana Jugador 2";
        }
        else
        {
            if(puntajeJugador1 == 10)
            {
                ganador = "Empate";
            }
            else if(puntajeJugador1 == 9)
            {
                if(manoJ1.c1() > manoJ2.c1())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c1() < manoJ2.c1())
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 8)
            {
                Carta cartaVerificadoraJ1, cartaVerificadoraJ2;
                Carta cartaDeDesempateJ1, cartaDeDesempateJ2;
                if(manoJ1.c1().n() == manoJ1.c2().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c1();
                    cartaDeDesempateJ1 = manoJ1.c5();
                }
                else
                {
                    cartaVerificadoraJ1 = manoJ1.c5();
                    cartaDeDesempateJ1 = manoJ1.c1();
                }

                if(manoJ2.c1().n() == manoJ2.c2().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c1();
                    cartaDeDesempateJ2 = manoJ2.c5();
                }
                else
                {
                    cartaVerificadoraJ2 = manoJ2.c5();
                    cartaDeDesempateJ2 = manoJ2.c1();
                }

                if(cartaVerificadoraJ1 > cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadoraJ1 < cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempateJ1 > cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempateJ1 < cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 7)
            {
                Carta cartaVerificadoraJ1, cartaVerificadoraJ2;
                Carta cartaDeDesempateJ1, cartaDeDesempateJ2;
                if(manoJ1.c1().n() == manoJ1.c2().n() && manoJ1.c2().n() == manoJ1.c3().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c1();
                    cartaDeDesempateJ1 = manoJ1.c5();
                }
                else
                {
                    cartaVerificadoraJ1 = manoJ1.c5();
                    cartaDeDesempateJ1 = manoJ1.c1();
                }

                if(manoJ2.c1().n() == manoJ2.c2().n() && manoJ2.c2().n() == manoJ2.c3().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c1();
                    cartaDeDesempateJ2 = manoJ2.c5();
                }
                else
                {
                    cartaVerificadoraJ2 = manoJ2.c5();
                    cartaDeDesempateJ2 = manoJ2.c1();
                }

                if(cartaVerificadoraJ1 > cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadoraJ1 < cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempateJ1 > cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempateJ1 < cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 6)
            {
                if(manoJ1.c5() > manoJ2.c5())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c5() < manoJ2.c5())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c4() > manoJ2.c4())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c4() < manoJ2.c4())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c3() > manoJ2.c3())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c3() < manoJ2.c3())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c2() > manoJ2.c2())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c2() < manoJ2.c2())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c1() > manoJ2.c1())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c1() < manoJ2.c1())
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 5)
            {
                if(manoJ1.c5() > manoJ2.c5())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c5() < manoJ2.c5())
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 4)
            {
                Carta cartaVerificadoraJ1, cartaVerificadoraJ2;
                Carta cartaDeDesempate1J1, cartaDeDesempate2J1;
                Carta cartaDeDesempate1J2, cartaDeDesempate2J2;
                if(manoJ1.c1().n() == manoJ1.c2().n() && manoJ1.c2().n() == manoJ1.c3().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c1();
                    cartaDeDesempate1J1 = manoJ1.c5();
                    cartaDeDesempate2J1 = manoJ1.c4();
                }
                else
                {
                    cartaVerificadoraJ1 = manoJ1.c5();
                    cartaDeDesempate1J1 = manoJ1.c2();
                    cartaDeDesempate2J1 = manoJ1.c1();
                }

                if(manoJ2.c1().n() == manoJ2.c2().n() && manoJ2.c2().n() == manoJ2.c3().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c1();
                    cartaDeDesempate1J2 = manoJ2.c5();
                    cartaDeDesempate2J2 = manoJ2.c4();
                }
                else
                {
                    cartaVerificadoraJ2 = manoJ2.c5();
                    cartaDeDesempate1J2 = manoJ2.c2();
                    cartaDeDesempate2J2 = manoJ2.c1();
                }

                if(cartaVerificadoraJ1 > cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadoraJ1 < cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempate1J1 > cartaDeDesempate1J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempate1J1 < cartaDeDesempate1J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempate2J1 > cartaDeDesempate2J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempate2J1 < cartaDeDesempate2J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 3)
            {
                Carta cartaVerificadora1J1, cartaVerificadora2J1;
                Carta cartaVerificadora1J2, cartaVerificadora2J2;
                Carta cartaDeDesempateJ1, cartaDeDesempateJ2;
                if(manoJ1.c1().n() == manoJ1.c2().n())
                {
                    cartaVerificadora2J1 = manoJ1.c1();
                    if(manoJ1.c3().n() == manoJ1.c4().n())
                    {
                        cartaVerificadora1J1 = manoJ1.c3();
                        cartaDeDesempateJ1 = manoJ1.c5();
                    }
                    else
                    {
                        cartaVerificadora1J1 = manoJ1.c5();
                        cartaDeDesempateJ1 = manoJ1.c3();
                    }
                }
                else
                {
                    cartaVerificadora1J1 = manoJ1.c5();
                    cartaVerificadora2J1 = manoJ1.c3();
                    cartaDeDesempateJ1 = manoJ1.c1();
                }

                if(manoJ2.c1().n() == manoJ2.c2().n())
                {
                    cartaVerificadora2J2 = manoJ2.c1();
                    if(manoJ2.c3().n() == manoJ2.c4().n())
                    {
                        cartaVerificadora1J2 = manoJ2.c3();
                        cartaDeDesempateJ2 = manoJ2.c5();
                    }
                    else
                    {
                        cartaVerificadora1J2 = manoJ2.c5();
                        cartaDeDesempateJ2 = manoJ2.c3();
                    }
                }
                else
                {
                    cartaVerificadora1J2 = manoJ2.c5();
                    cartaVerificadora2J2 = manoJ2.c3();
                    cartaDeDesempateJ2 = manoJ2.c1();
                }

                if(cartaVerificadora1J1 > cartaVerificadora1J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadora1J1 < cartaVerificadora1J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaVerificadora2J1 > cartaVerificadora2J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadora2J1 < cartaVerificadora2J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempateJ1 > cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempateJ1 < cartaDeDesempateJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else if(puntajeJugador1 == 2)
            {
                Carta cartaVerificadoraJ1, cartaVerificadoraJ2;
                Carta cartaDeDesempate1J1, cartaDeDesempate2J1, cartaDeDesempate3J1;
                Carta cartaDeDesempate1J2, cartaDeDesempate2J2, cartaDeDesempate3J2;
                if(manoJ1.c1().n() == manoJ1.c2().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c1();
                    cartaDeDesempate1J1 = manoJ1.c5();
                    cartaDeDesempate2J1 = manoJ1.c4();
                    cartaDeDesempate3J1 = manoJ1.c3();
                }
                else if(manoJ1.c2().n() == manoJ1.c3().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c2();
                    cartaDeDesempate1J1 = manoJ1.c5();
                    cartaDeDesempate2J1 = manoJ1.c4();
                    cartaDeDesempate3J1 = manoJ1.c1();
                }
                else if(manoJ1.c3().n() == manoJ1.c4().n())
                {
                    cartaVerificadoraJ1 = manoJ1.c3();
                    cartaDeDesempate1J1 = manoJ1.c5();
                    cartaDeDesempate2J1 = manoJ1.c2();
                    cartaDeDesempate3J1 = manoJ1.c1();
                }
                else
                {
                    cartaVerificadoraJ1 = manoJ1.c4();
                    cartaDeDesempate1J1 = manoJ1.c3();
                    cartaDeDesempate2J1 = manoJ1.c2();
                    cartaDeDesempate3J1 = manoJ1.c1();
                }

                if(manoJ2.c1().n() == manoJ2.c2().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c1();
                    cartaDeDesempate1J2 = manoJ2.c5();
                    cartaDeDesempate2J2 = manoJ2.c4();
                    cartaDeDesempate3J2 = manoJ2.c3();
                }
                else if(manoJ2.c2().n() == manoJ2.c3().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c2();
                    cartaDeDesempate1J2 = manoJ2.c5();
                    cartaDeDesempate2J2 = manoJ2.c4();
                    cartaDeDesempate3J2 = manoJ2.c1();
                }
                else if(manoJ2.c3().n() == manoJ2.c4().n())
                {
                    cartaVerificadoraJ2 = manoJ2.c3();
                    cartaDeDesempate1J2 = manoJ2.c5();
                    cartaDeDesempate2J2 = manoJ2.c2();
                    cartaDeDesempate3J2 = manoJ2.c1();
                }
                else
                {
                    cartaVerificadoraJ2 = manoJ2.c4();
                    cartaDeDesempate1J2 = manoJ2.c3();
                    cartaDeDesempate2J2 = manoJ2.c2();
                    cartaDeDesempate3J2 = manoJ2.c1();
                }

                if(cartaVerificadoraJ1 > cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaVerificadoraJ1 < cartaVerificadoraJ2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempate1J1 > cartaDeDesempate1J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempate1J1 < cartaDeDesempate1J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempate2J1 > cartaDeDesempate2J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempate2J1 < cartaDeDesempate2J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else if(cartaDeDesempate3J1 > cartaDeDesempate3J2)
                {
                    ganador = "Gana Jugador 1";
                }
                else if(cartaDeDesempate3J1 < cartaDeDesempate3J2)
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
            else
            {
                if(manoJ1.c5() > manoJ2.c5())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c5() < manoJ2.c5())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c4() > manoJ2.c4())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c4() < manoJ2.c4())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c3() > manoJ2.c3())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c3() < manoJ2.c3())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c2() > manoJ2.c2())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c2() < manoJ2.c2())
                {
                    ganador = "Gana Jugador 2";
                }
                else if(manoJ1.c1() > manoJ2.c1())
                {
                    ganador = "Gana Jugador 1";
                }
                else if(manoJ1.c1() < manoJ2.c1())
                {
                    ganador = "Gana Jugador 2";
                }
                else
                {
                    ganador = "Empate";
                }
            }
        }
        partidas.push_back(make_tuple(figuraJugador1, figuraJugador2, ganador));
    }

    ofstream salida("PartidasDeTexasHoldEm.txt");

    string lineaParaArchivo(144, '-');

    salida << setw(91) << endl << "Ganadores de las mil partidas de Texas Hold 'Em" << endl << endl;
    salida << lineaParaArchivo << endl << endl;

    salida << setw(24) << "Partida" << setw(24) << "Mano Jugador 1" << setw(20) << "Figura Jugador 1";
    salida << setw(19) << "Mano Jugador 2" << setw(21) << "Figura Jugador 2" << setw(15) << "Ganador" << endl << endl;
    salida << lineaParaArchivo << endl << endl;
    int i = 1;
    unsigned int sangria = 24;

    vector<pair<Mano, Mano> >::iterator iterManos = manos.begin();

    for(vector<tuple<string, string, string> >::iterator iterPartidas = partidas.begin(); iterPartidas != partidas.end(); ++iterPartidas)
    {
        if(i == 10 || i == 100 || i == 1000)
        {
            --sangria;
        }
        salida << setw(sangria) << "Partida " << i << ": " << setw(8) << (*iterManos).first;
        salida << "   " << (get<0> (*iterPartidas));
        if((get<0> (*iterPartidas)) == "Escalera de Color")
        {
            salida << "    ";
        }
        else if((get<0> (*iterPartidas)) == "Escalera Real")
        {
            salida << "        ";
        }
        else if((get<0> (*iterPartidas)) == "Carta Alta")
        {
            salida << "           ";
        }
        else if((get<0> (*iterPartidas)) == "Dos Pares")
        {
            salida << "            ";
        }
        else if((get<0> (*iterPartidas)) == "Escalera")
        {
            salida << "             ";
        }
        else if((get<0> (*iterPartidas)) == "Un Par")
        {
            salida << "               ";
        }
        else if((get<0> (*iterPartidas)) == "Póker" || (get<0> (*iterPartidas)) == "Color")
        {
            salida << "                ";
        }
        else
        {
            salida << "                 ";
        }
        salida << (*iterManos).second;
        salida << "    " << (get<1> (*iterPartidas));
            if((get<1> (*iterPartidas)) == "Escalera de Color")
        {
            salida << "    ";
        }
        else if((get<1> (*iterPartidas)) == "Escalera Real")
        {
            salida << "        ";
        }
        else if((get<1> (*iterPartidas)) == "Carta Alta")
        {
            salida << "           ";
        }
        else if((get<1> (*iterPartidas)) == "Dos Pares")
        {
            salida << "            ";
        }
        else if((get<1> (*iterPartidas)) == "Escalera")
        {
            salida << "             ";
        }
        else if((get<1> (*iterPartidas)) == "Un Par")
        {
            salida << "               ";
        }
        else if((get<1> (*iterPartidas)) == "Póker" || (get<1> (*iterPartidas)) == "Color")
        {
            salida << "                ";
        }
        else
        {
            salida << "                 ";
        }
        salida << (get<2> (*iterPartidas)) << endl;
        ++i;
        ++iterManos;
    }
    entrada.close();
    salida.close();

    int contadorVictoriasJugador1 = 0, contadorVictoriasJugador2 = 0, contadorEmpates = 0;
    for(vector<tuple<string, string, string> >::iterator iterP = partidas.begin(); iterP != partidas.end(); ++iterP)
    {
        if(get<2> (*iterP) == "Gana Jugador 1")
        {
            contadorVictoriasJugador1++;
        }
        else if(get<2> (*iterP) == "Gana Jugador 2")
        {
            contadorVictoriasJugador2++;
        }
        else
        {
            contadorEmpates++;
        }
    }

    string linea(80, '-');

    cout << endl << setw(56) << "Resumen Juegos de Texas Hold 'Em"<< endl << endl;
    cout << linea << endl << endl;
    cout << setw(26) << contadorVictoriasJugador1 << " Partidas Ganadas por Jugador 1" << endl;
    cout << setw(26) << contadorVictoriasJugador2 << " Partidas Ganadas por Jugador 2" << endl;
    cout << setw(26) << contadorEmpates << " Partidas Empatadas" << endl << endl;
    cout << linea << endl << endl;

    cout << "En el archivo 'PartidasDeTexasHoldEm.txt' se muestran los resultados de las mil partidas de Texas Hold 'Em." << endl;

    return 0;
}
