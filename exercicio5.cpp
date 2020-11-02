#include<iostream>
#include<queue>
#include<stack>

template<typename TElem>
void inverteFila1Pilha(std::queue<TElem>* fila) {
    std::stack<TElem> pilha = std::stack<TElem>{};

    while (!fila->empty()) {
        pilha.push(fila->front());
        fila->pop();
    }

    while (!pilha.empty()) {
        fila->push(pilha.top());
        pilha.pop();
    }
}