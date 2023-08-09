#include <cstdlib>
#include <iostream>

using namespace std;

// class A
class A
{
  private:
    int iAPrivate;
  protected:
    int iAProtected;
  public:
    int iAPublic;
};


// class B erbt public von class A
class B : public A
{
  public:
    B();
};

B::B()
{
  //iAPrivate = 1;
  //iAProtected = 2;
  //iAPublic = 3;
}



// class C erbt protected von class A
class C : protected A
{
  public:
    C();
};

C::C()
{
  //iAPrivate = 1;
  //iAProtected = 2;
  //iAPublic = 3;
}


// class D erbt private von class A
class D : private A
{
  public:
    D();
};

D::D()
{
  //iAPrivate = 1;
  //iAProtected = 2;
  //iAPublic = 3;
}


// Hauptprogramm
int main(int argc, char *argv[])
{
    
  B EinB;
  C EinC;
  D EinD;
    
  //EinB.iAPrivate = 1;
  EinB.iAProtected = 2;
  //EinB.iAPublic = 3;
    
    
	//EinC.iAPrivate = 1;
  //EinC.iAProtected = 2;
  //EinC.iAPublic = 3;

  //EinD.iAPrivate = 1;
  //EinD.iAProtected = 2;
  //EinD.iAPublic = 3;
    

  system("PAUSE");
  return EXIT_SUCCESS;
}
