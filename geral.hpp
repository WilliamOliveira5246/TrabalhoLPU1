#ifndef MAIN_HPP
#define MAIN_HPP

#include<map>

extern std::map<std::string, float> sanduiches;
extern std::map<std::string, float> sucos;
extern std::map<std::string, float> carrinho;

void abrirCardapioSanduiches();
void abrirCardapioSucos();
void listarSanduiches();
void listarSucos();
void clear();
void pressQualquer();

#endif