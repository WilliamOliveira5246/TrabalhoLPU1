#ifndef GERENTE_HPP
#define GERENTE_HPP

void lerCardapioSanduiches();
void lerCardapioSucos();

void adicionarSanduiche(std::string nome, float preco);
void adicionarSuco(std::string nome, float preco);

void alterarPrecoSanduiche(std::string nome, float preco);
void alterarPrecoSuco(std::string nome, float preco);

void excluirSanduiche(std::string nome);
void excluirSuco(std::string nome);

void listarSanduiches();
void listarSucos();

void salvarSanduiches();
void salvarSucos();

#endif