#ifndef CLIENTE_HPP
#define CLIENTE_HPP

void abrirCarrinho();
void addSanduicheCarrinho(std::string nome);
void addSucoCarrinho(std::string nome);
void verCarrinho();
void excluirItemCarrinho(std::string nome);
float calcularValorCarrinho();
void salvarCarrinho();

#endif
