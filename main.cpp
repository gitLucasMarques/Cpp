#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, std::string> criarMapaTraducao() {
  std::unordered_map<char, std::string> mapa;

  mapa['A'] = "⠁";
  mapa['B'] = "⠃";
  mapa['C'] = "⠉";
  mapa['D'] = "⠙";
  mapa['E'] = "⠑";
  mapa['F'] = "⠋";
  mapa['G'] = "⠛";
  mapa['H'] = "⠓";
  mapa['I'] = "⠊";
  mapa['J'] = "⠚";
  mapa['K'] = "⠅";
  mapa['L'] = "⠇";
  mapa['M'] = "⠍";
  mapa['N'] = "⠝";
  mapa['O'] = "⠕";
  mapa['P'] = "⠏";
  mapa['Q'] = "⠟";
  mapa['R'] = "⠗";
  mapa['S'] = "⠎";
  mapa['T'] = "⠞";
  mapa['U'] = "⠥";
  mapa['V'] = "⠧";
  mapa['W'] = "⠺";
  mapa['X'] = "⠭";
  mapa['Y'] = "⠽";
  mapa['Z'] = "⠵";
  mapa[','] = "⠂";
  mapa['.'] = "⠲";
  mapa['!'] = "⠖";
  mapa['?'] = "⠦";
  mapa[' '] = " ";
  mapa['\n'] = "\n";

  mapa['0'] = "⠴";
  mapa['1'] = "⠂";
  mapa['2'] = "⠆";
  mapa['3'] = "⠒";
  mapa['4'] = "⠲";
  mapa['5'] = "⠢";
  mapa['6'] = "⠖";
  mapa['7'] = "⠶";
  mapa['8'] = "⠦";
  mapa['9'] = "⠔";

  return mapa;
}

void imprimirTextoEmBraille(const std::string &texto,
                            const std::string &formato) {
  std::unordered_map<char, std::string> mapaTraducao = criarMapaTraducao();

  std::cout << "Formato selecionado: " << formato << std::endl;
  std::cout << "Texto em Braille:" << std::endl;

  for (char c : texto) {
    char upperC = std::toupper(c);
    if (mapaTraducao.find(upperC) != mapaTraducao.end()) {
      std::cout << mapaTraducao[upperC] << " ";
    } else {
      std::cout << c << " ";
    }
  }

  std::cout << std::endl;
}

int main() {
  std::string formato;
  int opcao;

  do {
    std::cout << "Formatos disponíveis para impressão:\n";
    std::cout << "1. Papel Cartão\n";
    std::cout << "2. A4\n";
    std::cout << "0. Encerrar o programa\n";
    std::cout << "Qual formato deseja imprimir?\nOpção: ";
    std::cin >> opcao;

    if (opcao == 0) {
      std::cout << "Encerrando o programa..." << std::endl;
      break;
    } else if (opcao == 1) {
      formato = "Papel Cartão";
    } else if (opcao == 2) {
      formato = "A4";
    } else {
      std::cout << "Opção inválida!" << std::endl;
      continue;
    }

    std::cin.ignore();

    std::string texto;
    std::cout << "Digite um texto (ou '0' para voltar ao menu): ";
    std::getline(std::cin, texto);

    if (texto == "0") {
      std::cout << "Voltando ao menu..." << std::endl;
      continue;
    }

    imprimirTextoEmBraille(texto, formato);

  } while (true);

  return 0;
}
