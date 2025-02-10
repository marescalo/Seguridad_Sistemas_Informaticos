#include "vigenere.h"

int main() {
  std::string keyword;
  std::string text;

  std::cout << "Introduzca la palabra clave en mayusculas" << std::endl;
  std::cin >> keyword;

  std::cout << "Introduzca el texto original en mayusculas" << std::endl;
  std::cin.ignore();
  std::getline(std::cin, text);

  std::string plaintext = processtext(text);
  std::string extendedKey = extendedkey(keyword, plaintext.length());

  std::cout << "Seleccione la accion que quierer hacer:" << std::endl;
  std::cout << "1. cifrar un mensaje" << std::endl;
  std::cout << "2. descifrar un mensaje" << std::endl;
  std::cout << "3. Salir" << std::endl;

  int option;
  while (std::cin >> option) {
    switch (option) {
      case 1:{
        std::string textocifrado = encrypt(plaintext,extendedKey);
        std::cout << textocifrado << std::endl;
        break;}
      case 2:{
        std::string textodescifrado = uncrypt(plaintext,extendedKey);
        std::cout << textodescifrado << std::endl;
        break;}
      case 3:
        return 0;
        break;
      default:
        break;
    }
  }
  return 0;
}