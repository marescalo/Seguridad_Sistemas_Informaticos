#include "vigenere.h"

std::string processtext(const std::string& text){
    std::string procesado;
    for(int i{0};i<text.length();i++){
        if(text[i] != 32){
            if(std::isalpha(text[i])){
                procesado+=text[i];
            }
            else{
                procesado+='?';
            }
        }
    }
    return procesado;
}

std::string extendedkey(const std::string& key, int textLength){
  std::string newKey;  // Cadena para almacenar la clave extendida
  int keyLength = key.length();  // Longitud de la clave original
  for (int i = 0; i < textLength; ++i) {  // Itera hasta que la longitud de la clave extendida coincida con la del texto
    newKey += key[i % keyLength];  // Repite la clave según sea necesario
  }
  return newKey;
}

std::string encrypt(const std::string& text, const std::string& key){
    std::string encryptedtext;
    for(int i=0 ; i < text.length(); i++){
        char c = ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
        encryptedtext += c;
    }
    return encryptedtext;
}

std::string uncrypt(const std::string& text, const std::string& key){
    std::string uncryptedtext;
    for(int i = 0; i < text.length(); i++){
        char c = (( text[i]- 'A') - (key[i] - 'A') + 26) % 26 + 'A';
        uncryptedtext += c;
    }
    return uncryptedtext;
} 