#include<iostream>
#include<queue>

template<typename TElem>
class Pilha2Filas {
public:
    std::queue<TElem> fila, filaAux;

    void cria() {
        fila = std::queue<TElem>{};
        filaAux = std::queue<TElem>{};
    }

    TElem tamanho() {
        return fila.size();
    }

    TElem vazia(){
        return tamanho() == 0;
    }

    TElem topo() {
        return fila.front();
    }

    void empilha(TElem x) {
        while(vazia() != 1) {
            filaAux.push(fila.front());
            fila.pop();
        }

        fila.push(x);

        while(filaAux.empty() != 1) {
            fila.push(filaAux.front());
            filaAux.pop();
        }
    }

    TElem desempilha() {
        TElem vTopo = topo();
        fila.pop();
        return vTopo;
    }
};