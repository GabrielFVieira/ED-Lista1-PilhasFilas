#include<iostream>
#include<stack>

template<typename TElem>
class Fila2Pilhas {
public:
    std::stack<TElem> pilha, pilhaAux;

    void cria() {
        pilha = std::stack<TElem>{};
        pilhaAux = std::stack<TElem>{};
    }

    TElem tamanho() {
        return pilha.size();
    }

    TElem vazio(){
        return tamanho() == 0;
    }

    TElem frente() {
        return pilha.top();
    }

    void emfileira(TElem x) {
        while(vazio() != 1) {
            pilhaAux.push(pilha.top());
            pilha.pop();
        }

        pilha.push(x);

        while(pilhaAux.empty() != 1) {
            pilha.push(pilhaAux.top());
            pilhaAux.pop();
        }
    }

    TElem desemfileira() {
        TElem vFrente = frente();
        pilha.pop();
        return vFrente;
    }
};