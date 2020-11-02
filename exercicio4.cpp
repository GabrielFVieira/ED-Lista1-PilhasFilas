#include<iostream>
#include<queue>
#include<stack>

template<typename TElem>
void invertePilha1Fila(std::stack<TElem>* pilha) {
    std::queue<TElem> fila = std::queue<TElem>{};

    while (pilha->empty() != 1) {
        fila.push(pilha->top());
        pilha->pop();
    }

    while (fila.empty() != 1) {
        pilha->push(fila.front());
        fila.pop();
    }
}

template<typename TElem>
void invertePilha2Pilhas(std::stack<TElem>* pilha) {
    std::stack<TElem> pilhaAux1 = std::stack<TElem>{};
    std::stack<TElem> pilhaAux2 = std::stack<TElem>{};

    while (!pilha->empty()) {
        pilhaAux1.push(pilha->top());
        pilha->pop();
    }

    while (!pilhaAux1.empty()) {
        pilhaAux2.push(pilhaAux1.top());
        pilhaAux1.pop();
    }

    while (!pilhaAux2.empty()) {
        pilha->push(pilhaAux2.top());
        pilhaAux2.pop();
    }
}

template<typename TElem>
void invertePilha1Pilha(std::stack<TElem>* pilha) {
    std::stack<TElem> pilhaAux = std::stack<TElem>{};

    while (!pilha->empty()) {
        pilhaAux.push(pilha->top());
        pilha->pop();
    }

    *pilha = pilhaAux;
}