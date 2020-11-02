#include <iostream>
#include <cassert>

constexpr int MAXN = 100000;
template<typename TElem>
class DequeSequencial {
public:
    TElem elementos [MAXN];
    int n;

    void cria() {
        this->n = 0;
    }

    int size() {
        return this->n;
    }

    void insereInicio(TElem x) {
        for (int i = this->n - 1; i >= 0; i--) {
            this->elementos[i+1] = this->elementos[i];
        }
        
        this->elementos[0] = x;
        this->n++;
    }

    void insereFim(TElem x) {
        this->elementos[n] = x;
        this->n++;
    }

    TElem removeInicio(){
        TElem inicio = this->elementos[0];

        for (int i = 1; i < this->n; i++) {
            this->elementos[i-1] = this->elementos[i];
        }

        this->n--;
        return inicio;
    }

    TElem removeFim(){
        this->n--;
        return this->elementos[this->n];
    }

    TElem buscaInicio(){
        return this->elementos[0];
    }

    TElem buscaFim(){
        return this->elementos[this->n-1];
    }
};

//static_assert(DequeTAD<DequeSequencial<char>, char>);

template<typename TElem>
class NoDequeEncadeado {
    public:
        TElem dado;
        NoDequeEncadeado<TElem>* prox;
        NoDequeEncadeado<TElem>* ant;
};

template<typename TElem>
class DequeEncadeado {
public:
    NoDequeEncadeado<TElem>* inicio;
    NoDequeEncadeado<TElem>* fim;
    int n;

    void cria() {
        this->n = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    void libera() {
        while(this->n > 0) {
            removeInicio();
        }
    }

    int size() {
        return this->n;
    }

    void insereInicio(TElem x) {
        auto* no = new NoDequeEncadeado<TElem>{.dado = x, .prox = this->inicio};

        if(this->inicio != 0) {
            this->inicio->ant = no;
        } else {
            this->fim = no;
        }

        this->inicio = no;
        this->n++;
    }

    void insereFim(TElem x) {
        auto* no = new NoDequeEncadeado<TElem>{.dado = x, .ant = this->fim};

        if(this->fim != 0) {
            this->fim->prox = no;
        } else {
            this->inicio = no;
        }

        this->fim = no;
        this->n++;
    }

    TElem removeInicio(){
        NoDequeEncadeado<TElem>* novoInicio = this->inicio->prox;

        if(novoInicio != 0) {
            novoInicio->ant = 0;
        }

        TElem valorInicio = this->inicio->dado;
        
        if(this->inicio == this->fim) {
            this->fim = novoInicio;
        }

        delete this->inicio;
        this->inicio = novoInicio;
        this->n--;

        return valorInicio;
    }

    TElem removeFim(){
        NoDequeEncadeado<TElem>* novoFim = this->fim->ant;

        if(novoFim != 0) {
            novoFim->prox = 0;
        }

        TElem valorFim = this->fim->dado;

        if(this->fim == this->inicio) {
            this->inicio = novoFim;
        }

        delete this->fim;
        this->fim = novoFim;
        this->n--;

        return valorFim;
    }

    TElem buscaInicio(){
        return this->inicio->dado;
    }

    TElem buscaFim(){
        return this->fim->dado;
    }
};

//static_assert(DequeTAD<DequeEncadeado<char>, char>);
/*
template<typename Agregado, typename TElem>
concept bool DequeTAD = requires(Agregado a, TElem t) {
    { a.insereInicio(t) }

    { a.insereFim(t) }

    { a.removeInicio() }

    { a.removeFim() }

    { a.buscaInicio() }

    { a.buscaFim() }
};*/