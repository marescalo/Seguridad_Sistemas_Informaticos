#include "vernam.cc"

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