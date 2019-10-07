#ifndef FUNCIONARIOUSP_H
#define FUNCIONARIOUSP_H

class FuncionarioUSP {
public:
    FuncionarioUSP(int nusp);
    virtual ~FuncionarioUSP();

    int getNusp();
protected:
    int nusp;
};

#endif // FUNCIONARIOUSP_H
