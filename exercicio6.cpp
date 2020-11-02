#include<iostream>
#include<stack>

template<typename TElem>
class PilhaMin {
public:
    std::stack<TElem> pilha;

    void cria() {
        pilha = std::stack<TElem>{};
    }

    int tamanho() {
        return pilha.size();
    }

    bool vazio() {
        return tamanho() == 0;
    }

    TElem topo() {
        return pilha.top();
    }

    void empilha(TElem valor) {
        pilha.push(valor);
    }

    void desempilha() {
        pilha.pop();
    }

    TElem obterMinimo() {
        std::stack<TElem> pilhaAux = std::stack<TElem>{};

        TElem minimo = pilha.top();

        while (!pilha.empty()) {
            pilhaAux.push(pilha.top());
            
            if(pilha.top() < minimo) {
                minimo = pilha.top();
            }

            pilha.pop();
        }

        while (!pilhaAux.empty()) {
            pilha.push(pilhaAux.top());
            pilhaAux.pop();
        }
        
        return minimo;
    }
};

int main()
{
    PilhaMin<char> pilhaMin; 
    
    pilhaMin.cria();

    pilhaMin.empilha('g');
    pilhaMin.empilha('z');
    pilhaMin.empilha('t');
    pilhaMin.empilha('d');
    pilhaMin.empilha('u');
    
    printf("%c\n", pilhaMin.obterMinimo());

    while (!pilhaMin.vazio()) {
        printf("%c\n", pilhaMin.topo());
        pilhaMin.desempilha();
    }

    return 0;
}