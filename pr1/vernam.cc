/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Seguridad en Sistemas informaticos
*
* @author Margarita Blanca Escobar Alonso alu0101567211@ull.edu.es
* @date Feb 5 2024
* @brief Este programa encripta un mensaje con una clave aleatoria
*
* @see 
*/

#include <string>
#include <iostream>
#include <bitset>
#include <random>

/*std::string generateRandomKey(size_t length) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);

  std::string key = "";
  for (size_t i = 0; i < length; ++i) {
    key += dist(gen) ? '1' : '0';
  }
  return key;
}
*/

void Cifrar(const std::string mensaje,const std::string randomkey){
    std::string mensajebinario;
    int longitud=0;
    for(int i=0; i < mensaje.size(); i++){
        mensajebinario += std::bitset<8>(mensaje[i]).to_string();
        longitud+=8;
    }
    std::cout << "Mensaje original en binario: " << mensajebinario << std::endl;
    std::cout << "Longitud del mensaje binario: " << longitud << std::endl;  

    if(randomkey.size() == mensajebinario.size()){
        std::cout << "Mensaje cifrado en binario: " << mensajebinario << std::endl;
        std::string mensajexor;
        std::string mensajecifrado;

        for(int i=0; i < randomkey.size(); i++){
            if(randomkey[i] == mensajebinario[i]){
                mensajexor+="0";
            }
            else{
                mensajexor+="1";
            }
        }
        std::string text = "";
        for (size_t i = 0; i < mensajexor.size(); i += 8) {
            std::bitset<8> bits(mensajexor.substr(i, 8));
            unsigned long charValue = bits.to_ulong();

            if (charValue >= 33 && charValue <= 126) {
                text+=static_cast<char>(charValue);
            } 
            else {
                std::cerr << "Advertencia: Valor binario no válido para ASCII imprimible: " << bits << std::endl;
                text+='?';
            }
        }
        std::cout << "Mensaje cifrado: " << text << std::endl;
    }
    else{
        std::cout << "la clave aleatoria y el mensaje cifrado en binario son de distinta longitud" << std::endl;
    }
}


int main(int argc, char *argv[]){

    std::string mensaje;
    std::string randomkey;

    int option;

    std::cout << "Seleccione la accion que quierer hacer:" << std::endl;
    std::cout << "1. cifrar un mensaje" << std::endl;
    std::cout << "2. descifrar un mensaje" << std::endl;
    std::cout << "3. Salir" << std::endl;

    while(std::cin >> option){
        switch (option){
            case 1:
                std::cout << "Mensaje original:";
                std::cin >> mensaje;
                std::cout << "Clave aleatoria:";
                std::cin >> randomkey;
                //randomkey = generateRandomKey(mensaje.size());
                Cifrar(mensaje, randomkey);
            break;
            case 2:
                std::cout << "Mensaje cifrado:";
                std::cin >> mensaje;
                std::cout << "Clave aleatoria:";
                std::cin >> randomkey;
                Cifrar(mensaje, randomkey);
            break;
            case 3:
                return 0;
            default:
            break;
        }
    }
    return 0;
}