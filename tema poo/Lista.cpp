#include "Lista.h"
#include "nod.h"
#include <iostream>
using namespace std;
//constructorul
Lista::Lista()
{
    prim=new nod;
    prim=NULL;
}

//destructorul
Lista::~Lista()
{ nod *q=new nod;
  nod *p=prim;
  while(p!=NULL)
    { q=p;
     p=p->geturm();
     delete q;
   }
 prim=NULL;

}

//constructorul de copiere
Lista::Lista(const Lista &L)
{    prim=new nod;
     prim=NULL;
    nod *p=new nod;
    for(p=L.prim;p!=NULL;p=p->urm)
    { this->addelem(p->info);

    }
    delete p;
}

//operatorul de atribuire
Lista& Lista::operator=(const Lista&L)
{ nod *q=new nod;
  nod *p=new nod;
//  prim=new nod;
  p=this->prim;
  while(p!=NULL)
    { q=p;
     p=p->geturm();
     delete q;
   }
    prim=new nod;
    prim=NULL;
    p=L.prim;
    while(p!=NULL)
    {
        this->addelem(p->getinfo());
        p=p->geturm();
    }
  return *this;
}

//adaugare element la inceputul listei
void Lista::addelem(int info)
{ nod *q=new nod(info,0);
  q->urm=prim;
  prim=q;
}

//informatia din primul nod
int Lista::firstinfo()
{ return prim->info;
}
//primul nod
nod* Lista::first()
{return prim;
}

//afisare lista
void Lista::afisarelista()
{ nod *p=prim;
  while(p!=NULL)
  { cout<<p->getinfo()<<" ";
    p=p->geturm();
  }
  cout<<"\n";
}

