#include<iostream>
#include<stack>

using namespace std;

int prioridade(char c);

string converterEmNotacaoPolonesa(string expressao) {
    stack<char> operadores = stack<char>{}; // Pilha de operadores
    string resultado; // String de resultado
    char c, topo; // Variável para armazenar o valor do caracter atual e o do topo da pilha, respectivamente

    for(string::size_type i = 0; i < expressao.size(); i++) {
        c = expressao[i];

        if(isalpha(c)) { // Se for uma letra já adiciona no resultado
            resultado += c;
        } else if(c == '(') {
            operadores.push(c); // Caso seja um abre parênteses insere na pilha de operandos
        } else if(c == ')') { // Caso seja um fecha de parênteses remove todos os operandos da pilha até o próximo abre parênteses
            do { 
                topo = operadores.top();
                operadores.pop();

                if(topo != '(') { // Se for um abre parênteses não deve inserir no resultado, irá sair do loop na próxima interação
                    resultado += topo;
                }
            } while (topo != '(');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while(true) {    
                // Se a pilha de operadores estiver vazia não há topo para verificar
                if(operadores.empty()) {
                    operadores.push(c);
                    break;
                }

                topo = operadores.top();
                operadores.pop();

                // Verifica qual a maior prioridade, entre o topo e o caracter que se deseja colocar
                if(prioridade(c) > prioridade(topo)) {
                    operadores.push(topo);
                    operadores.push(c);
                    break;
                } else {
                    resultado += topo;
                }
            }
        }
    }

    // Esvazia a pilha colocando os operando restantes no final do resultado
    while (!operadores.empty()) {
        topo = operadores.top();
        operadores.pop();

        if(topo != '(') {
            resultado += topo;
        }
    }

    return resultado;
}

// Verifica a prioridade dos operandos * e / possuem prioridade superior a + e -,
// qualquer outro símbolo (no contexto  somente é possível ser um abre parênteses) possui prioridade 0
int prioridade(char c) {
    if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    }

    return 0;
}